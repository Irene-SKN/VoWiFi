#ifndef __ZMF_AUDIO_H__
#define __ZMF_AUDIO_H__
#if __GNUC__
#pragma GCC visibility push(default)
#endif
/**
 * @file zmf_audio.h
 * @brief ZMF audio interfaces
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize Audio module of ZMF(Zero Media Framework).
 * @param  applicationContext For Windows, it can be the handle of the window,
 *                            The notification event will be sent to that window.
 *                            Or it can be callback function of type ZmfEventListenCallback.
 *                            For Android, it must be the Context.
 *                            For iOS, it should be NULL and is ignored.
 * @return                    0 on succeed, otherwise failed.
 */
int Zmf_AudioInitialize(void *applicationContext);

/**
 * @brief Destory Audio module of ZMF module. All resources will be released.
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_AudioTerminate (void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @brief AEC mode.
 */
typedef enum {
    ZmfAecAuto                          = -1, /**< @brief Auto select mode. */
    ZmfAecOff                           = 0, /**< @brief Disable AEC. */
    ZmfAecOn                            = 1, /**< @brief Enable AEC. */
} ZmfAecMode;

/**
 * @brief AGC mode.
 */
typedef enum {
    ZmfAgcAuto                          = -1, /**< @brief Auto select mode. */
    ZmfAgcOff                           = 0, /**< @brief Disable AGC. */
    ZmfAgcOn                            = 1, /**< @brief Enable AGC. */
} ZmfAgcMode;

/**
 * @brief Session Mode.
 */
typedef enum {
    ZmfSessionAutoMode                  = 0, /**< @brief Auto select mode, i.e. do nothing. */
    ZmfSessionDefault                   = 1, /**< @brief Default mode. if not support, do nothing */
    ZmfSessionVoiceChat                 = 2, /**< @brief Voice mode, if not support, set Default mode */
    ZmfSessionVideoChat                 = 3, /**< @brief Video mode, if not support, set Default mode */
    /** mask flags */
    ZmfSessionMixWithOthers             = 1<<31, /** @brief Mix with other App sound, only ios supported */
    ZmfSessionDuckOthers                = 1<<30, /** @brief Duck other App sound, only ios supported */
} ZmfSessionMode;

/**
 * @brief Audio device state mode.
 */
typedef enum {
    ZmfAudioDeviceActive                  = 1, /**< @brief audio device enabled and plugged. */
    ZmfAudioDeviceDisabled                = 2, /**< @brief audio device disabled. */
    ZmfAudioDeviceNotPresent              = 3, /**< @brief audio device not present. */
    ZmfAudioDeviceUnplugged               = 4, /**< @brief audio device enabled but unplugged. */
} ZmfAudioDeviceStateMode;

#ifdef __OBJC__
#import <Foundation/Foundation.h>
/**
 * @defgroup ZmfAudioDeviceId Audio Device ID
 * @{
 */

/** @brief Device ID string of Remote IO. */
extern const char * const ZmfAudioDeviceRemote;

/** @brief Device ID string of Voice Processing IO. */
extern const char * const ZmfAudioDeviceVoice;

/**
 * @}
 */

/**
 * @defgroup ZmfAudioNotificationParameters Audio Notification Parameters.
 * @{
 */

/**
 * @brief An NSString object containing a string that identifies
 * audio input device ID.
 */
extern NSString * const ZmfAudioInput;

/**
 * @brief An NSString object containing a string that identifies
 * audio output device ID.
 */
extern NSString * const ZmfAudioOutput;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the samping rate in Hz.
 */
extern NSString * const ZmfSamplingRate;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the channel number.
 */
extern NSString * const ZmfChannelNumber;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the request type for Automatic Gain Control(AGC).
 * For a list of possible values, @ref ZmfAgcMode.
 */
extern NSString * const ZmfAutoGainControl;

/**
 * @brief An NSNumber object containing an integer that identifies
 * the request type for Acoustic Echo Cancellation(AEC).
 * For a list of possible values, @ref ZmfAecMode.
 */
extern NSString * const ZmfAcousticEchoCancel;

/**
 * @brief An NSString object containing a string that identifies
 * the reason of error.
 */
extern NSString * const ZmfAudioError;

/**
 * @}
 */

/**
 * @defgroup ZmfAudioNotifications Audio Notifications.
 * @{
 */

/**
 * @brief Post when the ZMF module request to start recording audio data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioInput,
 * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which provide detail
 * information for the request.
 */
extern NSString * const ZmfAudioInputRequestStart;

/**
 * @brief Post when the ZMF module request to stop recording audio data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioInput,
 * which provide detail information for the request.
 */
extern NSString * const ZmfAudioInputRequestStop;

/**
 * @brief Post when the ZMF module has received first audio input data after
 * @ref Zmf_AudioInputStart is invoked.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioInput,
 * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which indicate the actual
 * parameters of the audio data recorded.
 */
extern NSString * const ZmfAudioInputDidStart;

/**
 * @brief Post when the ZMF module request to start playing audio data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioOutput,
 * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which provide detail
 * information for the request.
 */
extern NSString * const ZmfAudioOutputRequestStart;

/**
 * @brief Post when the ZMF module request to stop playing audio data.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioOutput,
 * which provide detail information for the request.
 */
extern NSString * const ZmfAudioOutputRequestStop;

/**
 * @brief Post when the ZMF module has delivered first audio output data after
 * @ref Zmf_AudioOutputStart is invoked.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioOutput,
 * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which indicate the actual
 * parameters of the audio data.
 */
extern NSString * const ZmfAudioOutputDidStart;

/**
 * @brief Post when the ZMF Audio module has received an interruption during working,
 * and then enter into an interrupted status.
 *
 * The ZMF Audio module will stop working (input/output) automatically.
 */
extern NSString * const ZmfAudioInterrupted;

/**
 * @brief Post when the ZMF Audio module has received a 'should resume' message
 * at the interrupted status.
 *
 * The ZMF Audio module will restore working (input/output) automatically.
 */
extern NSString * const ZmfAudioDidResume;

/** @brief Post when the ZMF Audio module has an error occurred.
 *
 * The userInfo dictionary of this notification contains @ref ZmfAudioError
 */
extern NSString * const ZmfAudioErrorOccurred;

/** @brief Post when the ZMF Audio mode changed
 *
 * The object of this notification is NSNumber of mode.
 */
extern NSString * const ZmfAudioSessionMode;
/**
 * @}
 */

#endif /* __OBJC__ */

#ifdef _WIN32

/**
 * @brief Event number for audio notifications.
 *
 * The wParam of the event is the type of notification.
 * For a list of possible values, @ref ZmfAudioEventType.
 *
 * The lParam of the event may contain a JSON object which depends on the
 * type of notification.
 */
#define ZmfAudioEvent           WM_APP + 130

/**
 * @defgroup ZmfNotificationParameters Audio Notification Parameters.
 * @{
 */

/**
 * @brief A String object containing a string that identifies
 * ID of audio input device.
 */
#define ZmfAudioInput           "AudioInput"

/**
* @brief A String object containing a string that identifies
* ID of audio output device.
*/
#define ZmfAudioOutput          "AudioOutput"

/**
 * @brief A Number object containing an integer that identifies
 * the samping rate in Hz.
 */
#define ZmfSamplingRate         "SamplingRate"

/**
 * @brief A Number object containing an integer that identifies
 * the channel number.
 */
#define ZmfChannelNumber        "ChannelNumber"

/**
 * @brief A Number object containing an integer that identifies
 * the request type for Automatic Gain Control(AGC).
 * For a list of possible values, @ref ZmfAgcMode.
 */
#define ZmfAutoGainControl      "AutoGainControl"

/**
 * @brief A Number object containing a integer that identifies
 * the request type for Acoustic Echo Cancellation(AEC).
 * For a list of possible values, @ref ZmfAecMode.
 */
#define ZmfAcousticEchoCancel   "AcousticEchoCancel"

/**
 * @brief A Number object containing a integer that identifies
 * audio device state.
 * For a list of possible values, @ref ZmfAudioDeviceStateMode.
 */
#define ZmfAudioDeviceState   "State"

/**
 * @brief A String object containing a string that describes error reason.
 * the format match 'input <id>|output <id>|audio: <reason>'.
 */
#define ZmfAudioError           "AudioError"

/**
 * @}
 */

/**
 * @brief Type of audio notifications.
 */
typedef enum {
    /**
     * @brief Post when the ZMF module request to start recording audio data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioInput,
     * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which provide detail
     * information for the request.
     */
    ZmfAudioInputRequestStart           = 1,

    /**
     * @brief Post when the ZMF module request to stop recording audio data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioInput,
     * which provide detail information for the request.
     */
    ZmfAudioInputRequestStop            = 2,

    /**
     * @brief Post when the ZMF module has received first audio input data after
     * @ref Zmf_AudioInputStart is invoked.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioInput,
     * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which indicate the actual
     * parameters of the audio data recorded.
     */
    ZmfAudioInputDidStart               = 3,

    /**
     * @brief Post when the ZMF module request to start playing audio data.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioOutput,
     * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which provide detail
     * information for the request.
     */
    ZmfAudioOutputRequestStart          = 4,

    /**
     * @brief Post when the ZMF module request to stop playing audio data.
     *
     * The userInfo dictionary of this notification contains @ref ZmfAudioOutput,
     * which provide detail information for the request.
     */
    ZmfAudioOutputRequestStop           = 5,

    /**
     * @brief Post when the ZMF module has delivered first audio output data after
     * @ref Zmf_AudioOutputStart is invoked.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioOutput,
     * @ref ZmfSamplingRate and @ref ZmfChannelNumber, which indicate the actual
     * parameters of the audio data.
     */
    ZmfAudioOutputDidStart              = 6,

    /** @brief Post when the ZMF Audio module has detected audio output device changed.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioOutput,
     * @ref ZmfAudioDeviceState.
     */
    ZmfAudioOutputStateChanged          = 8,

    /** @brief Post when the ZMF Audio module has an error occurred.
     *
     * The lParam of this event is a JSON object contains @ref ZmfAudioError
     */
    ZmfAudioErrorOccurred               = 7,
} ZmfAudioEventType;

#endif /* _WIN32 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Set audio session mode
 * @return        0 on succeed, otherwise failed.
 */
int Zmf_AudioSessionSetMode (ZmfSessionMode enAudioMode);

/**
 * @brief Get count of audio input devices.
 * @return  The total count of audio input devices.
 */
int Zmf_AudioInputGetCount (void);

/**
 * @brief Set volume of audio input device, only supported on Windows
 *
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_AudioInputSetVolume(int percent);

/**
 * @brief Get the name of audio input device.
 * @param  iIndex   The index of audio input device, from 0 to count - 1.
 * @param  acId     Pointer the buffer contains ID string.
 * @param  acName   Pointer the buffer contains utf8 name string.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_AudioInputGetName (int iIndex, char acId[512], char acName[512]);

/**
 * @brief Start audio input device to record data.
 * @param  pcId           The ID of audio input device.
 * @param  iSamplingRate  Sampling rate in Hz, 0 for auto selection.
 * @param  iChannelNumber Channel number, 0 for auto selection.
 * @param  enAecMode      AEC mode @ref ZmfAecMode.
 * @param  enAgcMode      AGC mode @ref ZmfAgcMode.
 * @return                0 on succeed, otherwise failed.
 */
int Zmf_AudioInputStart (const char* pcId, int iSamplingRate, int iChannelNumber,
                         ZmfAecMode enAecMode, ZmfAgcMode enAgcMode);

/**
 * @brief Stop audio input device.
 * @param  pcId  The ID of audio input device.
 * @return       0 on succeed, otherwise failed.
 */
int Zmf_AudioInputStop (const char* pcId);

/**
 * @brief Stop all audio input devices.
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_AudioInputStopAll (void);

/**
 * @brief Get count of audio output devices.
 * @return  The total count of audio output devices.
 */
int Zmf_AudioOutputGetCount (void);

/**
 * @brief Set volume of audio output device, only supported on Windows
 *
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_AudioOutputSetVolume(int percent);
/**
 * @brief Get the name of audio output device.
 * @param  iIndex   The index of audio output device, from 0 to count - 1.
 * @param  acId     Pointer the buffer contains ID string.
 * @param  acName   Pointer the buffer contains name utf8 string.
 * @return          0 on succeed, otherwise failed.
 */
int Zmf_AudioOutputGetName (int iIndex, char acId[512], char acName[512]);

/**
 * @brief Start audio output device to play data.
 * @param  pcId           The ID of audio output device.
 * @param  iSamplingRate  Sampling rate in Hz, 0 for auto selection.
 * @param  iChannelNumber Channel number, 0 for auto selection.
 * @return                0 on succeed, otherwise failed.
 */
int Zmf_AudioOutputStart (const char* pcId, int iSamplingRate, int iChannelNumber);

/**
 * @brief Stop audio output device.
 * @param  pcId The ID of audio output device.
 * @return      0 on succeed, otherwise failed.
 */
int Zmf_AudioOutputStop (const char* pcId);

/**
 * @brief Stop all audio output devices.
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_AudioOutputStopAll (void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif /* __ZMF_AUDIO_H__ */
