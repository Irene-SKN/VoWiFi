#ifndef __ZMF_EXT_H__
#define __ZMF_EXT_H__
#include "zmf_utils.h"
#if defined(ANDROID)
#include <jni.h>
#endif
#if __GNUC__
#pragma GCC visibility push(default)
#endif
#ifdef __cplusplus
extern "C" {
#endif
/**
 * zmf video file format:
 * [HEAD][LAYER]*
 * HEAD -> uint16_t<WIDHT>, uint16_t <HEIGHT>, uint8_t <FPS>
 * LAYER-> ZmfFileVideoLayer, [Fragment]*
 * Fragment -> uint16_t<LENGTH>, [DATA]
 *
 * - WIDHT, HEIGHT, LENGTH is big endian
 * - DATA is byte buffer
 */
typedef struct {
    /** the number of fragment in one layer */
    unsigned char numFragments;
    /** fragment level = fragPriority << 8 |  fragSvcLevel
     * 0x80 is last layer bit in one image frame, i.e. ZmfVideoCaptureEncoder.bLastFrag
     * 0x70 is layer index, i.e. ZmfVideoCaptureEncoder.simulcastIdx
     */
    unsigned char fragPriority;
    /** 0x40 is keyframe bit */
    unsigned char fragSvcLevel;
} ZmfFileVideoLayer;

/**
 * runtime state of external capture encoder
 */
typedef struct {
    /** [in] codec name */
    const char* plName;
    /** [in] encoded data length */
    unsigned bufLength : 32;
    /** [in] fragment level */
    unsigned fragLevel : 16;
    /** [in] whelther the current captured buffer is last fragment ine one layer */
    unsigned bLastFrag : 1;
    /** [in] whelther the current captured buffer is last layer in one frame*/
    unsigned bLastLayer: 1;
    /** [in] layer index */
    unsigned simulcastIdx : 6;
    /** [in] whelther the current layer is keyframe */
    unsigned bKeyFrame : 1;
    /** [out] set next output keyframe */ 
    unsigned nextKeyFrame : 1;
    /** [out] set new framerate [0-64] */
    unsigned newFrameRate : 6; 
    /** [out] notify percent loss [0-100] */
    unsigned packetLoss   : 16;
    /** [out] set new bitrate, kbps */
    unsigned newBitRate   : 16;
    /** [out] notify rtt, ms */
    unsigned rtt          : 16;
} ZmfVideoCaptureEncoder;

#if defined(ANDROID)

/**
 * plugin library name prefixed as ZmfPLuginLibPrefix will be auto loaded when ZMF is initialized
 */
#define ZmfPLuginLibPrefix "libspm-"

/**
 * required function that will be called when plugin library is loaded
 * in this function, plugin can register callbacks into zmf, such as
 *     Zmf_VideoCaptureAddCallback: to process camera raw data before encoding
 *     Zmf_VideoRenderAddCallback: to process video render data
 *     Zmf_AudioOutputAddCallback: to process decoded audio data before delivering to speaker
 *     Zmf_AudioInputAddCallback: to process audio data from microphone before encoding 
 * note: JNIENV is here for convenience to make JNI call if needed. 
 *       JNIENV is defined in C++ version.
 */
int loadZmfPlugin(JNIEnv *env);

/**
 * optional function that will be called when plugin library is unloaded.
 */
void unloadZmfPlugin();

#endif


/** the callback to receive captured image
 * iImgAngle - iCamOrient equal to device rotate angle.
 * if encoder is NULL, the pixel format of buf must be ZmfPixelFormatI420
 *
 * @param[in] pUser     the user data registered by Zmf_VideoCaptureAddCallback
 * @param[in] captureId the id of captured image
 * @param[in] iFace     the capture Face @see ZmfVideoFaceType
 * @param[in] iImgAngle the image rotated angle (CW)
 * @param[in] iCaptureOrient the capturer fixed orient
 * @param[in,out] iWidth  the image width
 * @param[in,out] iHeight the image height
 * @param[in,out] buf     the image data I420 buffer
 * @param[in,out] encoder capture encoder
 */
typedef void (*ZmfVideoCaptureCallback)(void* pUser, const char* captureId, int iFace, 
                                        int iImgAngle, int iCaptureOrient, int* iWidth, int* iHeight,
                                        unsigned char *buf, ZmfVideoCaptureEncoder* encoder);

/**
 * The callback to receive video render data 
 *
 * @param[in] pUser         the user data registered by Zmf_AddVideoRenderCallback
 * @param[in] renderId      video render unique name
 * @param[in] sourceType    video render source type @see ZmfVideoSourceType
 * @param[in] iAngle        
 * @param[in] iMirror 
 * @param[in] iWidth
 * @param[in] iHeight
 * @param[in] buf           I420 render data
 *
 * @return                  if process render data should return > 0, other 0
 *
 * @remarks
 *  if buf == 0 or iWidth ==0 or iHeight == 0, means the render will close,
 *  so should call Zmf_OnVideoRenderRequestRemove.
 */
typedef int  (*ZmfVideoRenderCallback)(void* pUser, const char* renderId, int sourceType, int iAngle,
                                       int iMirror, int* iWidth, int* iHeight, unsigned char *buf,
                                       unsigned long timeStamp);

/** the callback to fill audio output buffer
 * @param[in] pUser  the user data registered by Zmf_AddAudioOutputCallback
 */
typedef int  (*ZmfAudioOutputCallback)(void* pUser, const char* outputId, int iSampleRateHz, int iChannels,
                                       unsigned char *buf, int len);

/** the callback to receive audio input data 
 *
 * @param[in] pUser  the user data registered by Zmf_AddAudioInputCallback
 * @param[in] inputId       unique name of the audio input
 * @param[in] iSampleRateHz  the sample rating of the pcm data
 * @param[in] iChannels     the channel number of the pcm data
 * @param[in] buf           the pcm data
 * @param[in] len           the pcm data length
 * @param[in,out] micLevel  
 * @param[in] playDelayMS   the play delay ms
 * @param[in] recDelayMS    the record dely ms
 * @param[in] clockDrift    the clock drift ms
 */
typedef void (*ZmfAudioInputCallback)(void* pUser, const char* inputId, int iSampleRateHz, int iChannels,
                                      unsigned char *buf, int len, int *micLevel,
                                      int playDelayMS, int recDelayMS, int clockDrift);
/**
 * The Event Callback
 *
 */
typedef void (*ZmfEventListenCallback) (int iEventType, const char *json, int len);


/**
 * The sensor data input data entry to ZMF
 *
 */
void Zmf_OnSensorData       (const ZmfSensorData *sensor);

/**
 * The audio input data entry to ZMF, each callback will obtain the data.
 * Multiple data will mix in the callback of the jssmme Engine,
 * and the first input will be main channel.
 *
 * @param[in] inputId       unique name of the audio input
 * @param[in] sampleRateHz  the sample rating of the pcm data
 * @param[in] iChannels     the channel number of the pcm data
 * @param[in] buf           the pcm data
 * @param[in] len           the pcm data length
 * @param[in,out] micLevel  
 * @param[in] playDelayMS
 * @param[in] recDelayMS
 * @param[in] clockDrift
 *
 */
void Zmf_OnAudioInput       (const char *inputId, int sampleRateHz, int iChannels, unsigned char *buf, int len,
                             int *micLevel, int playDelayMS, int recDelayMS, int clockDrift);

/**
 * The outlet which audio output can get data from.
 *
 * @param[in] outputId      unique name of the audio output
 * @param[in] sampleRateHz  the sample rating of the pcm data
 * @param[in] iChannels     the channel number of the pcm data
 * @param[in] buf           the pcm data to be filled
 * @param[in] len           the pcm data length
 */
void Zmf_OnAudioOutput      (const char *outputId, int sampleRateHz, int iChannels, unsigned char *buf, int len);

/**
 * The video capture data entry to ZMF
 * iImgAngle - iCamOrient equal to device rotate angle.
 * if encoder is NULL, the pixel format of bufI420 must be ZmfPixelFormatI420
 *
 * @param[in] captureId     unique name of the video capture
 * @param[in] iFace         the capture face, @see ZmfVideoFaceType
 * @param[in] iImgAngle     the image rotated angle (CW)
 * @param[in] iCamAngle     the camera fixed orient
 * @param[in,out] iWidth    the image width at least align 4,
 *                          return the cropped width of bufI420.
 * @param[in,out] iHeight   the image height at least align 4.
 *                          return the cropped height of bufI420.
 * @param[in] bufI420       the image data
 * @param[in,out] encoder   the capture encoder
 */
void Zmf_OnVideoCapture     (const char *captureId, int iFace, int iImgAngle, int iCamAngle,
                             int *iWidth, int *iHeight, unsigned char *bufI420,
                             ZmfVideoCaptureEncoder* encoder);

void Zmf_OnH264AnnexBCapture     (const char *captureId, int iFace, int iImgAngle, int iCamAngle,
                             int *iWidth, int *iHeight, unsigned char *bufI420,
                             ZmfVideoCaptureEncoder* encoder);                             


/**
 * The video render data entry to ZMF
 *
 * @param[in] renderId      unique name of the video render source
 * @param[in] sourceType    the render source type, @see ZmfVideoSourceType
 * @param[in] iAngle        the image rotated angle (CW)ZmfVideoCaptureCallback
 * @param[in] iWidth        the image width
 * @param[in] iHeight       the image height
 * @param[in] bufI420       the image data I420 buffer
 */
void Zmf_OnVideoRender      (const char *renderId, int sourceType, int iAngle, int iMirror,
                             int *iWidth, int *iHeight, unsigned char *bufI420, unsigned long timeStamp);

/**
 * add video capture data callback
 *
 * @param[in] pUser         the callback user data
 * @param[in] pfnCb         the callback
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_VideoCaptureAddCallback    (void *pUser, ZmfVideoCaptureCallback pfnCb);

/**
 * remove video capture data callback
 *
 * @param[in]  pUser        the callback user data
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_VideoCaptureRemoveCallback (void *pUser);

/**
 * add render data callback
 *
 * @param[in] pUser         the callback user data
 * @param[in] pfnCb         the callback
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_VideoRenderAddCallback     (void *pUser, ZmfVideoRenderCallback pfnCb);

/**
 * remove render data callback
 *
 * @param[in]  pUser        the callback user data
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_VideoRenderRemoveCallback  (void *pUser);

/**
 * remove speak data callback
 *
 * @param[in]  pUser        the callback user data
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_AudioOutputAddCallback     (void *pUser, ZmfAudioOutputCallback pfnCb);

/**
 * remove speak data callback
 *
 * @param[in]  pUser        the callback user data
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_AudioOutputRemoveCallback  (void *pUser);

/**
 * add mic data callback
 *
 * @param[in] pUser         the callback user data
 * @param[in] pfnCb         the callback
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_AudioInputAddCallback      (void *pUser, ZmfAudioInputCallback pfnCb);

/**
 * remove mic data callback
 *
 * @param[in]  pUser        the callback user data
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_AudioInputRemoveCallback   (void *pUser);

/**
 * trigger ZmfVideoRenderDidReceive event
 *
 * @param[in] renderId      unique name of the render
 * @param[in] hWnd          the window which the render has been added
 * @param[in] iWidth        the width of image
 * @param[in] iHeight       the height of image
 */
void Zmf_OnVideoRenderDidReceived  (const char *renderId, void* hWnd, int iWidth, int iHeight);

/**
 * trigger ZmfVideoRenderDidResize event
 *
 * @param[in] renderId      unique name of the render
 * @param[in] hWnd          the window which the render has been added
 * @param[in] iWidth        the new width of image
 * @param[in] iHeight       the new height of image
 */
void Zmf_OnVideoRenderDidResized   (const char *renderId, void* hWnd, int iWidth, int iHeight);

/**
 * trigger ZmfVideoRenderDidStart event
 *
 * @param[in] renderId      unique name of the render
 * @param[in] hWnd          the window which the render has been added
 */
void Zmf_OnVideoRenderDidStarted   (const char *renderId, void* hWnd, int iWidth, int iHeight);

/**
 * trigger ZmfVideoRenderRequestRemove event
 *
 * @param[in] renderId      unique name of the render
 * @param[in] hWnd          the window which the render has been added
 */
void Zmf_OnVideoRenderRequestRemove(const char *renderId, void* hWnd);

/**
 * trigger ZmfVideoRenderDidMatch event
 *
 * @param[in] renderId      unique name of the render
 * @param[in] hWnd          the window which the render has been added
 * @param[in] matching      the percent of mathcing
 */
void Zmf_OnVideoRenderDidMatch (const char *renderId, void* hWnd, int matching);

/**
 * tell ZMF the video capture has stopped
 * 
 * @param[in] captureId     unique name of the device
 */
void Zmf_OnVideoCaptureDidStop     (const char *captureId);

/**
 * tell ZMF the video capture exposure state changed
 *
 * @param[in] captureId     unique name of the video capture
 * @param[in] bExposure     bExposure 0 means the exposure is off , others on.
 * @param[in] brightness    brightnesss 0~255 means the average brightness of the video images.
 * @param[in] bBacklot      bBacklot 1 means detect the backlot, otherwise not.  
 */
void Zmf_OnVideoCaptureStatus   (const char *captureId, int bExposure, int brightness, int bBacklot);

/**
 * tell ZMF the audio output has stopped
 *
 * @param[in] outputId      unique name of the device
 */
void Zmf_OnAudioOutputDidStop      (const char *outputId);

/**
 * tell ZMF the audio input has stopped
 *
 * @param[in] inputId       unique name of the device
 */
void Zmf_OnAudioInputDidStop       (const char *inputId);

/**
 * Set Audio Event Callback
 */
int Zmf_AudioSetListener   (ZmfEventListenCallback pfnAudioListen);

/**
 * Set Video Event Callback
 */
int Zmf_VideoSetListener   (ZmfEventListenCallback pfnVideoListen);

/**
 * Set  Log level
 */
void Zmf_LogSetLevel (int iLogLevel);

/** Font layout info */
typedef struct {
    unsigned        shadowRGBA;
    float           shadowBlurRadius;
    float           shadowOffsetX, shadowOffsetY;
    unsigned        outlineRGBA;
    float           outlineWidth;
    unsigned        fontRGBA;
    float           fontSize;
    unsigned        boundingWidth;
    float           scale;
    char            fontName[1024];
} ZmfFontLayout;

/** I420 Buffer */
typedef struct _ZmfI420Stencil {
    unsigned char   *bufI420;
    unsigned        width, height;
} ZmfI420Stencil;

/**
 * alloc I420 buffer
 *
 * @param[in] str   string
 * @param[in] info  layout info
 * @return I420 buffer
 */
ZmfI420Stencil* Zmf_I420StencilFromString(const char*str, ZmfFontLayout* info);

/**
 * delete I420 buffer
 */
void Zmf_I420StencilDelete(ZmfI420Stencil *stencil);

/**
 * blend I420
 *
 * @param[in] aligns Alignment @ref ZmfAlignmentType
 */
int Zmf_I420StencilBlend(const ZmfI420Stencil*stencil, unsigned dstX, unsigned dstY, unsigned char *dstI420, unsigned dstW, unsigned dstH);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif
