#ifndef __ZMF_DEV_H__
#define __ZMF_DEV_H__
#include "zmf_audio.h"
#include "zmf_video.h"
#include "zmf_sensor.h"
#include "zmf_codec.h"
#include "zmf_ext.h"
#if __GNUC__
#pragma GCC visibility push(default)
#endif
#ifdef __cplusplus
extern "C" {
#endif
#define ZMF_ID_LEN		512
#define ZMF_JSON_LEN    512
#define ZMF_JSON_VIDEOCAPTURE_REQUEST_START "{\"Capture\":\"%s\",\"Width\":%d,\"Height\":%d,\"FrameRate\":%d}"
#define ZMF_JSON_VIDEOCAPTURE_REQUEST_CHANGE "{\"Capture\":\"%s\",\"Width\":%d,\"Height\":%d,\"FrameRate\":%d}"
#define ZMF_JSON_VIDEOCAPTURE_DID_STARTED   "{\"Capture\":\"%s\",\"Face\":%d,\"Width\":%d,\"Height\":%d,\"Angle\":%d}"
#define ZMF_JSON_VIDEOCAPTURE_STATUS        "{\"Capture\":\"%s\",\"Exposure\":%d,\"Brightness\":%d,\"Backlot\":%d}"
#define ZMF_JSON_VIDEOCAPTURE_REQUEST_STOP  "{\"Capture\":\"%s\"}"
#define ZMF_JSON_VIDEORENDER_REQUEST_ADD    "{\"Render\":\"%s\",\"SourceType\":%d,\"Width\":%d,\"Height\":%d}"
#define ZMF_JSON_VIDEORENDER_REQUEST_REMOVE "{\"Render\":\"%s\",\"SourceType\":%d,\"Window\":%ld}"
#define ZMF_JSON_VIDEORENDER_DID_RECEIVED   "{\"Render\":\"%s\",\"SourceType\":%d,\"Window\":%ld,\"Width\":%d,\"Height\":%d}"
#define ZMF_JSON_VIDEORENDER_DID_RESIZED    "{\"Render\":\"%s\",\"SourceType\":%d,\"Window\":%ld,\"Width\":%d,\"Height\":%d}"
#define ZMF_JSON_VIDEORENDER_DID_STARTED    "{\"Render\":\"%s\",\"SourceType\":%d,\"Window\":%ld,\"Width\":%d,\"Height\":%d}"
#define ZMF_JSON_AUDIOOUTPUT_REQUEST_START  "{\"AudioOutput\":\"%s\",\"SamplingRate\":%d,\"ChannelNumber\":%d}"
#define ZMF_JSON_AUDIOOUTPUT_DID_STARTED    "{\"AudioOutput\":\"%s\",\"SamplingRate\":%d,\"ChannelNumber\":%d}"
#define ZMF_JSON_AUDIOOUTPUT_REQUEST_STOP   "{\"AudioOutput\":\"%s\"}"
#define ZMF_JSON_AUDIOOUTPUT_STATE_CHANGED  "{\"AudioOutput\":\"%s\",\"State\":%d}"
#define ZMF_JSON_AUDIOINPUT_REQUEST_START   "{\"AudioInput\":\"%s\",\"SamplingRate\":%d,\"ChannelNumber\":%d,\"AcousticEchoCancel\":%d,\"AutoGainControl\":%d}"
#define ZMF_JSON_AUDIOINPUT_DID_STARTED     "{\"AudioInput\":\"%s\",\"SamplingRate\":%d,\"ChannelNumber\":%d}"
#define ZMF_JSON_AUDIOINPUT_REQUEST_STOP    "{\"AudioInput\":\"%s\"}"
#define ZMF_JSON_VIDEOCAPTURE_SETTING       "{\"Width\":%d,\"Height\":%d,\"FrameRate\":%d}"
#define ZMF_JSON_AUDIOOUTPUT_SETTING        "{\"SamplingRate\":%d,\"ChannelNumber\":%d,\"FrameRate\":%d}"
#define ZMF_JSON_AUDIOINPUT_SETTING         "{\"SamplingRate\":%d,\"ChannelNumber\":%d,\"AcousticEchoCancel\":%d,\"AutoGainControl\":%d}"

#define ZMF_JSON_VIDEORENDER_DID_MATCH      "{\"Render\":\"%s\",\"SourceType\":%d,\"Window\":%ld,\"Matching\":%d}"

/* must sync with zmf ZmfAudioEventType and ZmfVideoEventType */
typedef enum {
	EN_ZMF_EVENT_VIDEOCAPTURE_REQUEST_START     = 20,
    EN_ZMF_EVENT_VIDEOCAPTURE_REQUEST_CHANGE    = 30,
	EN_ZMF_EVENT_VIDEOCAPTURE_REQUEST_STOP      = 21,
	EN_ZMF_EVENT_VIDEOCAPTURE_DID_STARTED       = 22,
	EN_ZMF_EVENT_VIDEOCAPTURE_STATUS            = 33,

    EN_ZMF_EVENT_VIDEORENDER_REQUEST_ADD        = 25,
    EN_ZMF_EVENT_VIDEORENDER_REQUEST_REMOVE     = 29,
    EN_ZMF_EVENT_VIDEORENDER_DID_RECEIVED       = 26,
    EN_ZMF_EVENT_VIDEORENDER_DID_RESIZED        = 28,
    EN_ZMF_EVENT_VIDEORENDER_DID_STARTED        = 27,

	EN_ZMF_EVENT_AUDIOOUTPUT_REQUEST_START      = 4,
    EN_ZMF_EVENT_AUDIOOUTPUT_REQUEST_STOP       = 5,
    EN_ZMF_EVENT_AUDIOOUTPUT_DID_STARTED        = 6,
    EN_ZMF_EVENT_AUDIO_ERROR_OCCURRED           = 7,
    EN_ZMF_EVENT_AUDIOOUTPUT_STATE_CHANGED      = 8,

	EN_ZMF_EVENT_AUDIOINPUT_REQUEST_START       = 1,
    EN_ZMF_EVENT_AUDIOINPUT_REQUEST_STOP        = 2,
    EN_ZMF_EVENT_AUDIOINPUT_DID_STARTED         = 3,

    EN_ZMF_EVENT_VIDEO_ERROR_OCCURRED           = 31,
    EN_ZMF_EVENT_VIDEORENDER_DID_MATCH          = 32,
} EN_ZMF_EVENT_TYPE;

typedef enum {
    EN_ZMF_VIDEO_CAPTURE_AUTO       = 0,
    EN_ZMF_VIDEO_CAPTURE_FRONT      = ZmfVideoFaceFront,
    EN_ZMF_VIDEO_CAPTURE_BACK       = ZmfVideoFaceBack,
} EN_ZMF_VIDEO_CAPTURE_FACE;

typedef enum {
    EN_ZMF_MIRROR_AUTO              = ZmfMirrorAuto,
    EN_ZMF_MIRROR_HORI              = ZmfMirrorHorizontal,
    EN_ZMF_MIRROR_VERT              = ZmfMirrorVertical,
} EN_ZMF_MIRROR_TYPE;

typedef enum {
    EN_ZMF_VIDEO_PEER               = ZmfVideoSourcePeer,
    EN_ZMF_VIDEO_CAPTURE            = ZmfVideoSourceCapture,
    EN_ZMF_VIDEO_FILE               = ZmfVideoSourceFile,
} EN_ZMF_VIDEO_SOURCE;

typedef enum {
    EN_ZMF_ORIENT_PORTRAIT          = ZmfRotationAngle0,
    EN_ZMF_ORIENT_LANDSCAPE_RIGHT   = ZmfRotationAngle90,
    EN_ZMF_ORIENT_PORTRAIT_UPSIDEDOWN = ZmfRotationAngle180,
    EN_ZMF_ORIENT_LANDSCAPE_LEFT    = ZmfRotationAngle270
} EN_ZMF_ORIENT_MODE;

typedef enum {
    EN_ZMF_RENDER_AUTO              = ZmfRenderAuto,
    EN_ZMF_RENDER_MATCH             = ZmfRenderMatch,
    EN_ZMF_RENDER_FULL_SCREEN       = ZmfRenderFullScreen,
    EN_ZMF_RENDER_FULL_CONTENT      = ZmfRenderFullContent,
    EN_ZMF_RENDER_FULL_AUTO         = ZmfRenderFullAuto,
} EN_ZMF_RENDER_FULL_MODE;

typedef void (*PFN_LOG_CALLBACK)    (int iLogLevel, const char *str);

void Zmf_VideoCaptureRequestStart   (const char *captureId, int iWidth, int iHeight, int iFps);
void Zmf_VideoCaptureRequestChange  (const char *captureId, int iWidth, int iHeight, int iFps);
void Zmf_VideoCaptureRequestStop    (const char *captureId);

void Zmf_AudioOutputRequestStart    (const char *outputId, int iSampleRateHz, int iChannels);
void Zmf_AudioOutputRequestStop     (const char *outputId);
void Zmf_AudioOutputStateChanged    (const char* outputId, int state);

void Zmf_AudioInputRequestStart     (const char *inputId, int iSampleRateHz, int iChannels, int bAEC, int bAGC);
void Zmf_AudioInputRequestStop      (const char *inputId);

void Zmf_VideoRenderRequestAdd      (const char* provideId, int sourceType, int iWidth, int iHeight);

int Zmf_LogSetCallback      (void* pfnCb);

/* deprecated */
typedef struct {
    int iWidth;
    int iHeight;
    int iMaxFps;
} ST_ZMF_VIDEO_CAPTURE_CAPABILITY;

int Zmf_VideoCaptureGetCapability(const char *outputId, ST_ZMF_VIDEO_CAPTURE_CAPABILITY *pstCaps, int *piSize);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif


