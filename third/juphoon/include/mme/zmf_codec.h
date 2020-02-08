#ifndef __ZMF_CODEC_H__
#define __ZMF_CODEC_H__
#if __GNUC__
#pragma GCC visibility push(default)
#endif
/**
 * @file zmf_codec.h
 * @brief ZMF codec interfaces
 */

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Parameters of video codec.
 */

typedef struct {
    /* 'Base','Main', 'Extd', 'High' */
    char                    cProfile[4];
    /* '10','1b','11','12',...,'51' */
    char                    cLevel[2];
    char                    bErrorConcealOn;
    char                    bSmallNalu;
} ZmfVideoCodecH264;

typedef struct {
    char                    bPictureLossIndicationOn;
    char                    feedbackModeOn;
    char                    bErrorConcealOn;
} ZmfVideoCodecVP8;

typedef union {
    ZmfVideoCodecH264       H264;
    ZmfVideoCodecVP8        VP8;
} ZmfVideoCodecSpecific;

typedef struct {
    /* video settings */
    unsigned                width;
    unsigned                height;
    /* kbps */
    unsigned                startBitrate;
    unsigned                maxBitrate;
    unsigned                minBitrate;
    unsigned                maxFramerate;
    unsigned int            qpMax;
    unsigned int            qpMin;
    ZmfVideoCodecSpecific   codecSpecific;
} ZmfVideoCodec;
/**
 * @}
 */

/**
 * @brief Parameters of audio codec.
 */

typedef struct {
    unsigned                bandMode;
} ZmfAudioCodecAMR;

typedef union {
    ZmfAudioCodecAMR        AMR;
} ZmfAudioCodecSpecific;

typedef struct {
    unsigned                sampleRate;
    unsigned                bitrate;
    ZmfAudioCodecSpecific   codecSpecific;
} ZmfAudioCodec;
/**
 * @}
 */

typedef union {
    ZmfVideoCodec           video;
    ZmfAudioCodec           audio;
} ZmfCodec;

typedef enum {
    /* Set/Get next frame whelther is keyframe. */
    ZmfCodecKeyFrame = 0,
    ZmfCodecBitrate,
    ZmfCodecFramerate,
    ZmfAmrBandMode,
    ZmfCodecWidth,
    ZmfCodecHeight,
    ZmfCodecPacketLoss,
    ZmfCodecRtt,
    ZmfCodecErrorConceal,
    /* deocder need frame stream, otherwise NALU in sequence */ 
    ZmfCodecStream,
    /* H264 & H265 */
    ZmfCodecH264SPS,
    ZmfCodecH265SPS = ZmfCodecH264SPS,
    ZmfCodecH264PPS,
    ZmfCodecH265PPS = ZmfCodecH264PPS,
    /* H265 */
    ZmfCodecH265VPS,
} ZmfCodecKey;

#define ZMF_CODEC_FALLBACK_SOFTWARE -13

/**
 * codec result callback
 * @param[in] user_data  The argument from at @see codecNew()
 * @param[in] buf,length The codec result data.
 * @param[in] cookie     The argument from at @see codecDo().
 * @param[in] bLastFrag  the result data whelther is last fragment.
 */
typedef void (*ZmfCodecOut)(void* user_data, const char* buf, unsigned length,
                            void* cookie, int bLastFrag);

/**
 * @brief Type of Codec class.
 */
typedef struct {
    /**
     * @brief Create new codec instance
     * @param callback The codec receive callback
     * @param user_data The callback user data
     * @return  0  on succeed, otherwise failed.
     */
    void* (*codecNew)(const char* codecName, ZmfCodecOut callback, void* user_data);

    /**
     * @brief execute codec instance
     * @param[in] handle     The codec instance pointer.
     * @param[in] in,in_len  The source data.
     * @param[in] timeStampMs The operation time stampe ms.
     * @param[in] bLastFrag  The result whelther is last fragment.
     * @param[in] cookie     The argument used at @see ZmfCodecOut.
     * @return  0 on succeed, otherwise failed.
     */
    int (*codecDo)(void *handle, void* in, unsigned in_len, unsigned timeStampMs,
                   void* cookie, int bLastFrag);

    /**
     * @brief reset codec instance
     * @param handle  The codec instance pointer.
     * @param settings The codec settings parameters. 
     * @return  0  on succeed, otherwise failed.
     */
    int (*codecReset)(void *handle, ZmfCodec* settings);

    /**
     * @brief set codec dynamic parameters.
     * @param handle    The codec instance pointer.
     * @param key       The name of parameters @ref ZmfCodecKey
     * @param value     The value of parameters. 
     * @param value_size  The bytes of value 
     * @return  0  on succeed, otherwise failed.
     */
    int (*codecSet)(void *handle, ZmfCodecKey key, const void *value, int value_size);

    /**
     * @brief get codec dynamic parameters.
     * @param handle    The codec instance pointer.
     * @param key       The name of parameters @ref ZmfCodecKey
     * @param value     The value of parameters. 
     * @param value_size  The bytes of value 
     * @return  0  on succeed, otherwise failed.
     */
    int (*codecGet)(void *handle, ZmfCodecKey key, void *value, int value_size);

    /**
     * @brief delete codec instance.
     * @param handle    The codec instance pointer.
     * @return  0  on succeed, otherwise failed.
     */
    int (*codecDelete)(void *handle);
} ZmfCodecClass;

/**
 * @}
 */
/**
 * @defgroup constant codec name
 * @{
 */

#define ZMF_BUILTIN_DECODER_H264  "zmf.builtin.H264.decoder"
#define ZMF_BUILTIN_ENCODER_H264  "zmf.builtin.H264.encoder"

#define ZMF_BUILTIN_DECODER_H265  "zmf.builtin.H265.decoder"
#define ZMF_BUILTIN_ENCODER_H265  "zmf.builtin.H265.encoder"

/** common codec */
#define ZMF_DECODER_H264  "H264.decoder"
#define ZMF_ENCODER_H264  "H264.encoder"
#define ZMF_DECODER_H265  "H265.decoder"
#define ZMF_ENCODER_H265  "H265.encoder"

/** record codec */
#define ZMF_FILE_ENCODER_H264 "FILE.H264.encoder"

/**
 * @}
 */

/**
 * @brief register external Codec 
 * @param  codecName      The codec name, must keep valid globally
 * @param  klass   The codec class @ref ZmfCodecClass, must keep valid globally.
 * @return  0 on succeed, otherwise failed.
 */
int Zmf_CodecRegister(const char* codecName, const ZmfCodecClass *klass);

/**
 * @brief Get Codec 
 * @param  codecName        The codec name,liking com.juphoon.H264.decoder
 * @return  0 on failed.
 */
const ZmfCodecClass* Zmf_CodecGetClass(const char* codecName);

/**
 * @brief Get list of codec name
 * after call, *count is the number of codec.
 * @param  codecNames      The codec name array 
 * @param  count           the array size of codecNames
 * @return size of codecNames on succeed, otherwise failed.
 */
int Zmf_CodecGetList(const char* codecNames[], int *count);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif
