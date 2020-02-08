#ifndef __ZMF_VIDEO_H__
#define __ZMF_VIDEO_H__
#ifdef __OBJC__
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif
#endif
#if __GNUC__
#pragma GCC visibility push(default)
#endif
/**
 * @file zmf_video.h
 * @brief ZMF video interfaces
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize Video module of ZMF(Zero Media Framework).
 * @param  applicationContext For Windows, it can be the handle of the window,
 *                            The notification event will be sent to that window.
 *                            Or it can be callback function of type ZmfEventListenCallback.
 *                            For Android, it must be the Context.
 *                            For iOS, it should be NULL and is ignored.
 * @return                    0 on succeed, otherwise failed.
 */
int Zmf_VideoInitialize(void *applicationContext);

/**
 * @brief Destroy Video module of ZMF module. All resources will be released.
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_VideoTerminate (void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @brief Face direction of capture device.
 */
typedef enum {
    ZmfVideoFaceUnknown             = 0, /**< @brief Facing unknown. */
    ZmfVideoFaceFront               = 1, /**< @brief Facing front. */
    ZmfVideoFaceBack                = 2, /**< @brief Facing back. */
} ZmfVideoFaceType;

/**
 * @brief Coordinate rotation angle.
 */
typedef enum {
    ZmfRotationFixedScreen          = -2,  /**< @brief  The screen keep a fixed angle with the device.  it's DEFAULT */
    ZmfRotationAutoScreen           = -1,  /**< @brief  screen will rotating by gravity sensor */
    ZmfRotationAngle0               = 0,   /**< @brief 0 degree. */
    ZmfRotationAngle90              = 90,  /**< @brief 90 degrees CCW. */
    ZmfRotationAngle180             = 180, /**< @brief 180 degrees CCW. */
    ZmfRotationAngle270             = 270, /**< @brief 270 degrees CCW. */
} ZmfRotationAngle;

/**
 * @brief Mirror type.
 */
typedef enum {
    ZmfMirrorNone                   = 0, /**< @brief None mirror */
    ZmfMirrorHorizontal             = 1, /**< @brief Horizontal mirror. */
    ZmfMirrorVertical               = 2, /**< @brief Vertical mirror. */
    ZmfMirrorFlipFromLeft           = 4, /**< @brief left to right animation only supported on ios. */
    ZmfMirrorFlipFromTop            = 8, /**< @brief top to down animation only supported on ios. */
    ZmfMirrorAuto                   = 3, /**< @brief Auto selection */
} ZmfMirrorType;

/**
 * @brief Built-in Render Effect type.
 */
typedef enum {
    ZmfRenderEffectNone             = 0, /**< @brief none effect. */
    /** Blur effect,
     *  JSON params:
     *   "hoffset": number of width pixel offset, default is 2
     *   "voffset": number of height pixel offset, defualt is 2
     *   "iterate": number of repetitions, default is 3
     *    "pixels": number of the blur radius
    *      "sigma":
     */
    ZmfRenderEffectBlur             = 1,
    ZmfRenderEffectGrey             = 2, /**< @brief grey. */
    ZmfRenderEffectMask             = 3, /**< @brief mask. */
    /** Magnifier effect,
     *  JSON params:
     *    "dx": translation width offset relative to magnifier center x
     *    "dy": translation height offset relative to magnifier center y
     *     "x": width coordinate of magnifier center, range from 0 to 1
     *     "y": height coordinate of magnifier center, range from 0 to 1
     *  "zoom": zoom parameter, default is 2
     *"radius": number of radius, relative to min(width, height), default is 0.2
     */
    ZmfRenderEffectMagnifier        = 4,
    ZmfRenderEffectOldTime          = 5,
    ZmfRenderEffectPhotoVerse       = 6,
    ZmfRenderEffectLomo             = 7,
    /** Blur effect,
     *  JSON params:
     *   "hoffset": number of width pixel offset, default is 2
     *   "voffset": number of height pixel offset, defualt is 2
     *   "iterate": number of repetitions, default is 3
     *    "pixels": number of the blur radius
    *      "sigma":
     *         "x": number of center
     *         "y": number of center
     *    "radius": number of radius, ratio of min(w,h), default is 0.2
     *       "exp": number of alpha exp, default is 1.0
     */
    ZmfRenderEffectDepthOfField     = 8,
    /**
    * Convert equirectangular to rectilinear
    * option JSON param:
    *  "status": turn on/off this effect. This will also reset all parameters.
    *           0: turn off effect;
    *           1: turn on effect;
    *  "yaw":  azimuth angle of gnomonic center, in degree, valid range [0,360], default 0
    *  "pitch": elevation angle of gnomonic center, in degree, valid range [-180,180], default 0
    *  "roll": roll angle around gnomonic axis, in degree, valid range [0,360], default 0
    *  "fov": horizontal field of view in degree, valid range (0,180), default 90.
    *         Warning: fov too close to 0 will greatly reduce image resolution
    *                  fov too close to 180 will greatly distort image.
    *         Suggest range: 45-135.
    *            if not specified, it is calculated from width using fixed aspect ratio 2:1.
    *  "reset": reset parameters to default. valid value: any number.
    */
    ZmfRenderEffectErtToRect        = 9,
} ZmfRenderEffectType;

typedef enum {
    ZmfRenderMatchNone              = 0,
    /**
     * JSON param:
     *  "epsilon":
     * "duration":
     * "position":
     *     "fovy":
     * "attitude":
     */
    ZmfRenderMatchAttitude          = 1,
    ZmfRenderMatchLight             = 2,
    /**
     * JSON param:
     *  "timestamp":
     *     "action":"ResetEffect"
     */
    ZmfRenderMatchTimeStamp         = 3,
} ZmfRenderMatchType;

typedef enum {
    ZmfRenderView,
    ZmfRenderViewFx,
    ZmfRenderImmersive,
    ZmfRenderImmersiveFx
} ZmfRenderType;

/**
 * @brief Built-in Capture Effect.
 */
typedef int ZmfCaptureEffectType;
enum {
    ZmfCaptureEffectNone             = 0, /**< @brief none effect. */
    /**
     * option JSON param:
     *      "fps":  the minimum FPS
     * "exposure":  the percent(0-100]
     */
    ZmfCaptureSmartExposure          = 1,
    ZmfCaptureGammaCorrection        = 1<<1,
    ZmfCaptureContrastEnhance        = 1<<2,
    ZmfCaptureFaceEnhance            = 1<<3,
     /**
     * option JSON param:
     *  "image":  the backlot jpg file path
     *  "width":  the width of image.
     *  "height": the height of image.
     */
    ZmfCaptureVirtualBacklot         = 1<<4,
    /**
    * Convert equirectangular to rectilinear
    * option JSON param:
    *  "status": turn on/off this effect. This will also reset all parameters.
    *           0: turn off effect;
    *           1: turn on effect;
    *  "yaw":  azimuth angle of gnomonic center, in degree, valid range [0,360], default 0
    *  "pitch": elevation angle of gnomonic center, in degree, valid range [-180,180], default 0
    *  "roll": roll angle around gnomonic axis, in degree, valid range [0,360], default 0
    *  "fov": horizontal field of view in degree, valid range (0,180), default 90.
    *         Warning: fov too close to 0 will greatly reduce image resolution
    *                  fov too close to 180 will greatly distort image.
    *         Suggest range: 45-135.
    *            if not specified, it is calculated from width using fixed aspect ratio 2:1.
    *  "reset": reset parameters to default. valid value: any number.
    */
    ZmfCaptureErtToRect             = 1<<5,
    /**
     * @brief video capture will use h264 capture format
     * if video device support h264 output.
     * Otherwise, video capture will use default yuv or mjpg as capture format.
     * Currently, h264 capture is supported when capture module is UVC (default is CamView)
     * and camera support uvc 1.5 (such as Ricoh Theta S).
     */
    ZmfCapturePreferH264        = 1<<6,
    ZmfCaptureBrightnessNotification      = 1<<7,
};

/**
 * @brief Video source type.
 */
typedef enum {
    ZmfVideoSourcePeer              = 0, /**< @brief Image is from peer. */
    ZmfVideoSourceCapture           = 1, /**< @brief Image is from capture device. */
    ZmfVideoSourceFile              = 2, /**< @brief Image is from file. */
} ZmfVideoSourceType;

/**
 * @brief Video render mode.
 */
typedef enum {
    /**
     * @brief Auto selection mode.
     *
     * When the aspect of image and render area is matched, it act as
     * @ref ZmfRenderFullScreen. Otherwise, it act as @ref ZmfRenderFullContent.
     * IOS platform will resize the window, other won't
     */
    ZmfRenderAuto                   = 0,

    /** like ZmfRenderAuto, but high accuracy, only ios supported */
    ZmfRenderMatch                  = 4,

    /**
     * @brief Scale image to fill the entire render area, and remain the aspect
     * ratio unchanged.
     */
    ZmfRenderFullScreen             = 1,

    /**
     * @brief Scale image to display all content in render area, and remain the
     * aspect ratio unchanged.
     */
    ZmfRenderFullContent            = 2,

    /**
     * @brief Auto selection mode, like ZmfRenderAuto, but not resize the window
     *
     * When the aspect of image and render area is matched, it act as
     * @ref ZmfRenderFullScreen. Otherwise, it act as @ref ZmfRenderFullContent.
     *
     */
    ZmfRenderFullAuto               = 3,

} ZmfRenderMode;

#ifdef __OBJC__
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
__attribute__((visibility("default")))
@interface ZmfView : UIView
@end
#else
__attribute__((visibility("default")))
@interface ZmfGLView : NSOpenGLView
@end
__attribute__((visibility("default")))
@interface ZmfView : NSView
@end
#endif
/**
 * @defgroup ZmfVideoDeviceId Video Device ID
 * @{
 */

/** @brief Capture device ID string for rear camera. */
extern const char * ZmfVideoCaptureBack;

/** @brief Capture device ID string for front camera. */
extern const char * ZmfVideoCaptureFront;

/** @brief Capture device ID string for rear ar camera. */
extern const char * ZmfARCaptureBack;

/** @brief Capture device ID string for front ar camera. */
extern const char * ZmfARCaptureFront;

/**
 * @}
 */

/**
 * @defgroup ZmfVideoNotificationParameters Video Notification Parameters.
 * @{
 */

/**
 * @brief An NSString object containing a string that identifies
 * ID of video capture device.
 */
extern NSString * const ZmfCapture;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the facing type of capture device.
 * For a list of possible values, @ref ZmfVideoFaceType.
 */
extern NSString * const ZmfFace;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the width in pixel.
 */
extern NSString * const ZmfWidth;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the height in pixel.
 */
extern NSString * const ZmfHeight;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the angle in degree.
 */
extern NSString * const ZmfAngle;

/**
 * @brief An NSString object containing an integer that identifies
 * the render source.
 */
extern NSString * const ZmfRender;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the render source type.
 * For a list of possible values, @ref ZmfVideoSourceType.
 */
extern NSString * const ZmfSourceType;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the handle of render window.
 */
extern NSString * const ZmfWindow;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the frame rate in fps.
 */
extern NSString * const ZmfFrameRate;


/**
 * @brief A NSNumber containing a boolean that identifies
 * the exposure state.
 */
extern NSString * const ZmfExposure;

/**
 * @brief A NSNumber containing a integer that identifies
 * the current video average brightness(0 ~ 255).
 */
extern NSString * const ZmfBrightness;

/**
 * @brief A NSNumber containing a boolean that identifies
 * the backlot state, 1 means detect the backlot, otherwise not.
 */
extern NSString * const ZmfBacklot;


/**
 * @brief An NSString object containing a string that describes error.
 * the format match 'camera <id>|render <id>|video: <reason>'.
 */
extern NSString * const ZmfVideoError;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the matching.
 */
extern NSString * const ZmfMatching;

/**
 * @}
 */

/**
 * @defgroup ZmfVideoNotifications Video Notifications.
 * @{
 */

/**
 * @brief Post when the ZMF module request to start capture video data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfCapture,
 * @ref ZmfWidth, @ref ZmfHeight and @ref ZmfFrameRate, which provide detail
 * information for the request.
 */
extern NSString * const ZmfVideoCaptureRequestStart;

/**
 * @brief Post when the ZMF module request to change video capture parameters.
 *
 * The userInfo dictionary of this notification contains @ref ZmfCapture,
 * @ref ZmfWidth, @ref ZmfHeight and @ref ZmfFrameRate, which provide detail
 * information for the request.
 */
extern NSString * const ZmfVideoCaptureRequestChange;

/**
 * @brief Post when the ZMF module request to stop capture.
 *
 * The userInfo dictionary of this notification contains @ref ZmfCapture,
 * which provide detail information for the request.
 */
extern NSString * const ZmfVideoCaptureRequestStop;

/**
 * @brief Post when the ZMF module has received first video data after
 * @ref Zmf_VideoCaptureStart invoked.
 *
 * The userInfo dictionary of this notification contains @ref ZmfCapture,
 * @ref ZmfFace, @ref ZmfWidth, and @ref ZmfHeight,
 * which indicate the actual parameters of the video data captured.
 */
extern NSString * const ZmfVideoCaptureDidStart;

/**
 * @brief Post when the ZMF module video capture status changed.
 * The userInfo dictionary contains the info of ZmfExposure, ZmfBrightness and ZmfBacklot
 */
extern NSString * const ZmfVideoCaptureStatus;

/**
 * @brief Post when the ZMF module request to start rendering video data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfRender.
 */
extern NSString * const ZmfVideoRenderRequestAdd;

/**
 * @brief Post when the ZMF module has received the first image after
 * @ref Zmf_VideoRenderAdd invoked.
 */
extern NSString * const ZmfVideoRenderDidReceive;

/**
 * @brief Post when the ZMF module has delivered the first image to render after
 * @ref Zmf_VideoRenderStart and  @ref Zmf_VideoRenderAdd invoked.
 */
extern NSString * const ZmfVideoRenderDidStart;

/**
 * @brief Post when the rendering image size has changed.
 *
 * The userInfo dictionary of this notification contains @ref ZmfRender,
 * @ref ZmfWindow, @ref ZmfWidth and @ref ZmfHeight.
 */
extern NSString * const ZmfVideoRenderDidResize;

/**
 * @brief Post when the ZMF module has stop rendering video data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfRender,
 * @ref ZmfWindow.
 */
extern NSString * const ZmfVideoRenderRequestRemove;

/**
 * @brief Post when the ZMF module has matched rendering video data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfRender,
 * @ref ZmfWindow, and @ref ZmfMatching
 */
extern NSString * const ZmfVideoRenderDidMatch;

/**
 * @}
 */

#endif /* __OBJC__ */

#ifdef _WIN32

/**
 * @brief Event number for video notifications.
 *
 * The wParam of the event is the type of notification.
 * For a list of possible values, @ref ZmfVideoEventType.
 *
 * The lParam of the event may contain a JSON object which depends on the
 * type of notification.
 */
#define ZmfVideoEvent                   ZmfAudioEvent + 10

/**
 * @defgroup ZmfVideoNotificationParameters Video Notification Parameters.
 * @{
 */

/**
 * @brief A String object containing an string that identifies
 * ID of video capture device.
 */
#define ZmfCapture "Capture"

/**
 * @brief A Number object containing an integer that identifies
 * the facing type of capture device.
 * For a list of possible values, @ref ZmfVideoFaceType.
 */
#define ZmfFace "Face"

/**
 * @brief A Number object containing an integer that identifies
 * the width in pixel.
 */
#define ZmfWidth "Width"

/**
 * @brief A Number object containing an integer that identifies
 * the height in pixel.
 */
#define ZmfHeight "Height"


/**
 * @brief A Number object containing an integer that identifies
 * the angle in degree.
 */
#define ZmfAngle "Angle"

/**
 * @brief A String object containing a string that identifies
 * the unique render name.
 *
 */
#define ZmfRender "Render"

/**
 * @brief A Number object containing an integer that identifies
 * the render source type.
 *
 * @ref ZmfVideoSourceType.
 */
#define ZmfSourceType "SourceType"

/**
 * @brief A Number object containing an integer that identifies
 * the handle of render window.
 */
#define ZmfWindow "Window"

/**
 * @brief A Number object containing an integer that identifies
 * the frame rate in fps.
 */
#define ZmfFrameRate "FrameRate"

/**
 * @brief A Number containing a boolean that identifies
 * the exposure state.
 */
#define ZmfExposure "Exposure"

/**
 * @brief A NSNumber containing a integer that identifies
 * the current video average brightness(0 ~ 255).
 */
#define ZmfBrightness "Brightness"

/**
 * @brief A NSNumber containing a boolean that identifies
 * the backlot state, 1 means detect the backlot, otherwise not.
 */
#define ZmfBacklot "Backlot"


/**
 * @brief A String object containing a string that describes error.
 * the format match 'camera <id>|render <id>|video: <reason>'.
 */
#define ZmfVideoError "VideoError"

/**
 * @brief A number object containing an integer that identifies
 * the matching.
 */
#define ZmfMatching "Matching"

/**
 * @}
 */

/**
 * @brief Type of video notifications.
 */
typedef enum  {
    /**
     * @brief Post when the ZMF module request to start capture video data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfCapture,
     * @ref ZmfWidth, @ref ZmfHeight and @ref ZmfFrameRate, which provide detail
     * information for the request.
     */
    ZmfVideoCaptureRequestStart         = 20,

    /**
     * @brief Post when the ZMF module request to change capture video data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfCapture,
     * @ref ZmfWidth, @ref ZmfHeight and @ref ZmfFrameRate, which provide detail
     * information for the request.
     */
    ZmfVideoCaptureRequestChange        = 30,

    /**
     * @brief Post when the ZMF module request to stop capture.
     *
     * The lParam of this event is a JSON object contains @ref ZmfCapture,
     * which provide detail information for the request.
     */
    ZmfVideoCaptureRequestStop          = 21,

    /**
     * @brief Post when the ZMF module has received first video data after
     * @ref Zmf_VideoCaptureStart invoked.
     *
     * The lParam of this event is a JSON object contains @ref ZmfCapture,
     * @ref ZmfFace, @ref ZmfWidth, and @ref ZmfHeight, @ref ZmfAngle,
     * which indicate the actual parameters of the video data captured.
     */
    ZmfVideoCaptureDidStart            = 22,

    /**
     * @brief Post when the ZMF module video capture status changed.
     * The userInfo dictionary contains the info of ZmfExposure, ZmfBrightness and ZmfBacklot
     */
    ZmfVideoCaptureStatus              = 33,

    /**
     * @brief Post when the ZMF module request to start rendering video data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfRender,
     * @ref ZmfWidth and @ref ZmfHeight.
     */
    ZmfVideoRenderRequestAdd            = 25,

    /**
     * @brief Post when the ZMF module has received the first image after
     * @ref Zmf_VideoRenderAdd invoked.
     */
    ZmfVideoRenderDidReceive            = 26,

    /**
     * @brief Post when the first image has delivery to render after
     * @ref Zmf_VideoRenderStart and @ref Zmf_VideoRenderAdd invoked.
     */
    ZmfVideoRenderDidStart              = 27,

    /**
     * @brief Post when the rendering image size has changed.
     *
     * The lParam of this event is a JSON object contains @ref ZmfRender,
     * @ref ZmfWindow, @ref ZmfWidth and @ref ZmfHeight.
     */
    ZmfVideoRenderDidResize             = 28,

    /**
     * @brief Post when the ZMF module request to stop rendering video data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfRender,
     * @ref ZmfWindow
     */
    ZmfVideoRenderRequestRemove         = 29,

    /** @brief Post when the ZMF Video module has an error occurred.
     *
     * The lParam of this event is a JSON object contains @ref ZmfVideoError
     */
    ZmfVideoErrorOccurred               = 31,

    /** @brief Post when the ZMF module render matching.
     *
     * The lParam of this event is a JSON object contains @ref ZmfRender,
     * @ref ZmfWindow, and @ref ZmfMatching
     */
    ZmfVideoRenderDidMatch              = 32,

} ZmfVideoEventType;

#endif /* _WIN32 */

#ifdef __cplusplus
extern "C" {
#endif
/** deprecated, use Zmf_CameraGetCount */
#define Zmf_VideoCaptureGetCount Zmf_CameraGetCount
/** deprecated, use Zmf_CameraGetName */
#define Zmf_VideoCaptureGetName Zmf_CameraGetName
/**
 * @brief Get count of video capture devices.
 * @return  The total count of video capture devices.
 */
int Zmf_CameraGetCount (void);

/**
* @brief Get count of Desktop devices, only supported on Windows
* @return  The total count of video capture devices.
*/
int Zmf_DesktopGetCount(void);

/**
* @brief Get count of Windows, only supported on Windows
* @return  The total count of video capture devices.
*/
int Zmf_WindowGetCount(void);

/**
 * @brief Get the name of specific capture device.
 * @param  iIndex    The index of capture device, from 0 to count - 1.
 * @param  acId      Pointer the buffer contains unique name utf8 string.
 * @param  acName    Pointer the buffer contains friendly name utf8 string.
 * @return        0  on succeed, otherwise failed.
 */
int Zmf_CameraGetName (int iIndex, char acId[512], char acName[512]);

/**
* @brief Get the name of specific desktop device, only supported on Windows
* @param  iIndex    The index of capture device, from 0 to count - 1.
* @param  acId      Pointer the buffer contains unique name utf8 string.
* @param  acName    Pointer the buffer contains friendly name utf8 string.
* @return        0  on succeed, otherwise failed.
*/
int Zmf_DesktopGetName(int iIndex, char acId[512], char acName[512]);

/**
* @brief Get the name of specific windows, only supported on Windows
* @param  iIndex    The index of capture device, from 0 to count - 1.
* @param  acId      Pointer the buffer contains unique name utf8 string.
* @param  acName    Pointer the buffer contains friendly name utf8 string.
* @return        0  on succeed, otherwise failed.
*/
int Zmf_WindowGetName(int iIndex, char acId[512], char acName[512]);

/**
 * @brief Get the face and angle of specific capture device.
 * @param  pcId      The ID of capture device.
 * @param  piFace    Capture device face @ref ZmfVideoFaceType
 * @param  piAngle   Capture device angle @ref ZmfRotationAngle
 * @return  orient angle >0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureGetOrient (const char *pcId, int *piFace, int *piAngle);

/**
 * @brief Start running video capture device.
 * @param  pcId       The ID of capture device.
 * @param  iWidth     The captured image width in pixel, just expected value.
 * @param  iHeight    The captured image height in pixel, just expected value.
 * @param  iFrameRate The captured frame rate in fps, just expected value.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureStart (const char *pcId, int iWidth, int iHeight, int iFrameRate);

/**
 * @brief rotate the image from the capture device
 * @param  pcId       The ID of capture device.
 * @param  enAngle    The rotation angle, @ref ZmfRotationAngle.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureRotate (const char *pcId, ZmfRotationAngle enAngle);

/**
 * @brief Set the face of specific capture device.
 * @param  pcId      The ID of capture device.
 * @param  iFace     Capture device face @ref ZmfVideoFaceType
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureFace (const char *pcId, int iFace);

/** deprecated, use Zmf_VideoCaptureListenRotation/Zmf_VideoRenderListenRotation*/
#define Zmf_VideoCaptureEnableRotation(bEnable, fixedDeviceAngle) do{\
    Zmf_VideoCaptureListenRotation(bEnable != 0 ? ZmfRotationMaskAll : 0, fixedDeviceAngle);\
    Zmf_VideoRenderListenRotation(bEnable != 0 ? ZmfRotationMaskAll : 0, fixedDeviceAngle); \
}while(0)

/**
 * @brief Coordinate rotation angle Mask.
 */
typedef enum {
    ZmfRotationMask0               = 1<<0, /**< @brief 0 degree. */
    ZmfRotationMask90              = 1<<1, /**< @brief 90 degrees CCW. */
    ZmfRotationMask180             = 1<<2, /**< @brief 180 degrees CCW. */
    ZmfRotationMask270             = 1<<3, /**< @brief 270 degrees CCW. */
    ZmfRotationMaskAll             = 0xF,
} ZmfRotationMask;

/**
 * @brief Listens device rotation event automatically, or in response to rotation angle fixture
 * @param rotationMask      whether Listens event or fixed angle, @ref ZmfRotationMask
 * @param fixedDeviceAngle  if rotationMask is 0, this is fixed angle
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureListenRotation(int rotationMask, int fixedDeviceAngle);

/**
 * @brief Listens device rotation event automatically, or in response to rotation angle fixture
 * @param rotationMask      whether Listens event or fixed angle, @ref ZmfRotationMask
 * @param fixedDeviceAngle  if rotationMask is 0, this is fixed angle
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderListenRotation(int rotationMask, int fixedDeviceAngle);

/** deprecated, use Zmf_ScreenSetOrientation */
#define Zmf_VideoCaptureSetScreenOrientation    Zmf_VideoScreenOrientation
/**
 * @brief Set screen orientation (window coordinates),
 *        the CCW angle of screen to the device.
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoScreenOrientation(int screenOrient);

/**
 * @brief Set the effect type of specific capture.
 * @param  enEffectType  Effect type, @ref ZmfCaptureEffectType
 * @param  strJson  Effect param, json string
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureEffect (ZmfCaptureEffectType enEffectType, const char* strJson);

/**
 * @brief Stop running video capture device.
 * @param  pcId      The ID of capture device.
 * @return  0        on succeed, otherwise failed.
 */
int Zmf_VideoCaptureStop (const char *pcId);

/**
 * @brief Stop all running video capture devices.
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureStopAll (void);

/**
 * @breif  Focus at the point which is touched on the screen.
 * @param  captureId The ID of capture device.
 * @param  pWnd      The handle of window to render on.
 * @param  pointX    The position X of touch relative to the view to display, value range from 0 to 1.
 * @param  pointY    The position Y of touch relative to the view to display, value range from 0 to 1.
 * @return           0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureHandleFocusMetering(const char* captureId,void *pWnd,float pointX,float pointY);

/**
 * @breif  Lens focus at the Position to be set.
 * @param  captureId      The ID of capture device.
 * @param  lensPosition   The position of lens to be set, value range from 0 to 1.
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoCaptureHandleFocusWithLensPosition(const char* captureId,float lensPosition);

/**
 * @brief Initialize resource and start render on specific window.
 * @param  pWnd   The handle of window to render on.
 * @param  enRenderType ZmfRenderType
 * @return        0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderStart (void *pWnd, ZmfRenderType enRenderType);

/**
 * @brief Stop render and destroy resource.
 * @param  pWnd The handle of window to render on.
 * @return    0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderStop (void *pWnd);

/**
 * @brief Attach render source to specific window.
 * @param  pWnd    The handle of window to render on.
 * @param  renderId The render source notified by @ref ZmfVideoRenderRequestAdd.
 * @param  iOrder  The Z-Order value render source. It must assign different
 *                 value for each render source. Render with larger value
 *                 overlapped on render with smaller value.
 * @param  enMode  Render mode, @ref ZmfRenderMode.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderAdd (void *pWnd, const char* renderId, int iOrder, ZmfRenderMode enMode);

/**
 * @brief replace render oldRenderId with newRenderId
 * @param  pWnd    The handle of window to render on.
 * @param  oldRenderId The current render id, used by @ref Zmf_VideoRenderAdd.
 * @param  newRenderId The new render id
 */
int Zmf_VideoRenderReplace(void *pWnd, const char* oldRenderId, const char *newRenderId);

/**
 * @brief Take an snapshot of video render.
 * @param  renderId  The render source notified by @ref ZmfVideoRenderRequestAdd.
 * @param  iWidth    The file image width in pixel, -1 keep origin.
 * @param  iHeight   The file image height in pixel, -1 keep origin.
 * @param  jpgFileName  The file path name.
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderSnapshot(const char *renderId, int iWidth, int iHeight, const char *jpgFileName);

/**
 * @brief Detach render source from specific window.
 * @param  pWnd    The handle of window.
 * @param  renderId The render source used by @ref Zmf_VideoRenderAdd.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderRemove (void *pWnd, const char* renderId);

/**
 * @brief Detach all render sources from specific window.
 * @param  pWnd    The handle of window.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderRemoveAll(void *pWnd);

/**
 * @brief Move render area of specific render source.
 *
 * The origin of coordination is the top left point of window.
 * X-axis positive direction is from left to right.
 * Y-axis positive direction is from top to bottom.
 * The valid range is from 0.0 to 1.0.
 *
 * @param  pWnd    The handle of window.
 * @param  renderId The render source.
 * @param  fLeft   The X position of top left point of render area.
 *                 Default is 0.0.
 * @param  fTop    The Y position of top left point of render area.
 *                 Default is 0.0.
 * @param  fRight  The X position of right bottom point of render area.
 *                 Default is 1.0.
 * @param  fBottom The Y position of right bottom point of render area.
 *                 Default is 1.0.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderMove (void *pWnd, const char* renderId, float fLeft, float fTop,
                         float fRight, float fBottom);

/**
 * @brief Set the mirror type of specific render source.
 * @param  pWnd    The handle of window.
 * @param  renderId The render source.
 * @param  enType  Mirror type, @ref ZmfMirrorType
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderMirror (void *pWnd, const char* renderId, ZmfMirrorType enType);


/**
 * @brief  Set whether continuously update or freeze of specific render source.
 * @param  pWnd     The handle of window.
 * @param  renderId The render source.
 * @param  bEnable  boolean value
 * @return        0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderFreeze (void *pWnd, const char* renderId, int bEnable);

/**
 * @brief Set coordination rotation angle according to the coordination
 * of the window.
 * @param  pWnd    The handle of window.
 * @param  enAngle The rotation angle, @ref ZmfRotationAngle.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderRotate (void *pWnd, ZmfRotationAngle enAngle);

/**
 * @brief Set the effect type of specific render.
 * @param  pWnd    The handle of window.
 * @param  renderId The render source.
 * @param  enEffectType  Effect type, @ref ZmfRenderEffectType
 * @param  strJson  Effect param, json string
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderEffect(void *pWnd, const char* renderId, ZmfRenderEffectType enEffectType, const char* strJson);

/**
 * @brief Set the match type of specific render.
 * @param  pWnd    The handle of window.
 * @param  renderId The render source.
 * @param  enMatchType  Effect type, @ref ZmfRenderEffectType
 * @param  strJson  Effect param, json string
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderMatch(void *pWnd, const char* renderId, ZmfRenderMatchType enMatchType, const char* strJson);

/**
 * @brief get the location point of specific render.
 * @param  pWnd    The handle of window.
 * @param  renderId The render source.
 * @param  location point
 * @return 0 on succeed, otherwise failed.
 */
int Zmf_VideoRenderGetLocation(void *pWnd, const char* renderId, float* location);

/**
* @brief Take an snapshot of video capture.
* @param  pcId      The ID of capture device.
* @param  iWidth    The captured image width in pixeld
* @param  iHeight   The captured image height in pixel
* @return 0 on succeed, otherwise failed.
*/
int Zmf_VideoCaptureSnapshot(const char *pcId, int iWidth, int iHeight, const char *jpgFileName);

/**
 * @brief Initialize AR module of ZMF(Zero Media Framework).
 * @return                    0 on succeed, otherwise failed.
 */
int Zmf_ARInit();

/**
 * @brief terminate AR module of ZMF(Zero Media Framework).
 * @return                    0 on succeed, otherwise failed.
 */
int Zmf_ARTerm();

/**
 * @brief Start running ar capture device.
 * @param  pcId       The ID of capture device: @ref ZmfARCaptureFront or ZmfARCaptureBack
 *                  currently only ZmfARCaptureFront is supported on some ios devices.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_ARCaptureStart(const char *pcId);

/**
 * @brief stop running ar capture device.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_ARCaptureStop();

/**
 * @brief Set background image: used to replace background in image captured by AR camera.
 * @param  pcImageFile  image file name, including full path. Only support jpg
 * @param  width, height currently only support 1280*720.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_ARSetBackgroundImage(const char *pcImageFile, int width, int height);

/**
 * @brief Set background image: used to replace background in image captured by AR camera.
 * @param  image  platform dependent image: on iOS, it it UIImage.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_ARSetBackgroundImage2(void* image);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif /* __ZMF_VIDEO_H__ */

