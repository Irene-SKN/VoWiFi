#ifndef __ZMF_UTILS_H__
#define __ZMF_UTILS_H__
#include <stdarg.h>
#if __GNUC__
#pragma GCC visibility push(default)
#endif
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ZmfLogDebug     = 0,
    ZmfLogInfo      = 1,
    ZmfLogWarn      = 2,
    ZmfLogError     = 3,
} ZmfLogLevel;

void Zmf_LogV(int iLogLevel, const char *format, va_list argv);

/**
 * The pixel format supported by ZMF
 */
typedef enum {
    ZmfPixelFormatI420              = 1,
    ZmfPixelFormatIYUV              = 2,
    ZmfPixelFormatRGB24             = 3,
    ZmfPixelFormatABGR              = 4,
    ZmfPixelFormatARGB              = 5,
    ZmfPixelFormatARGB4444          = 6,
    ZmfPixelFormatRGB565            = 7,
    ZmfPixelFormatARGB1555          = 8,
    ZmfPixelFormatYUY2              = 9,
    ZmfPixelFormatYV12              = 10,
    ZmfPixelFormatUYVY              = 11,
    ZmfPixelFormatMJPG              = 12,
    ZmfPixelFormatNV21              = 13,
    ZmfPixelFormatNV12              = 14,
    ZmfPixelFormatBGRA              = 15
} ZmfPixelFormatType;

/**
 * utility for convert pixel from I420
 *
 * @param[in] dstFrame      the buffer to save the convert result
 * @param[in] dstFormat     the convert result pixel format @see ZmfPixelFormatType
 * @param[in] srcFrame      the source I420 buffer
 * @param[in] srcWidth      the width of image
 * @param[in] srcHeight     the height of image
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_ConvertFromI420 (void* dstFrame, int dstFormat,
                          const void* srcFrame, int srcWidth, int srcHeight);

/**
 * utility for convert pixel from YV12 
 *
 * @param[in] dstFrame      the buffer to save the convert result
 * @param[in] dstFormat     the convert result pixel format @see ZmfPixelFormatType
 * @param[in] srcFrame      the source I420 buffer
 * @param[in] srcWidth      the width of image
 * @param[in] srcHeight     the height of image
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_ConvertFromYV12 (void* dstFrame, int dstFormat,
                          const void* srcFrame, int srcWidth, int srcHeight);
/**
 * utility for convert pixel to I420
 *
 * @param[in] dstFrame      the I420 buffer to save the convert result
 * @param[in] srcFormat     the srouce pixel format @see ZmfPixelFormatType
 * @param[in] srcFrame      the source buffer
 * @param[in] srcBufLen     the source buffer length
 * @param[in] srcWidth      the width of image
 * @param[in] srcHeight     the height of image
 * @param[in] crop_x,crop_y the crop offset at left-top
 * @param[in,out] iWidth    the desired width at least align 4,
 *                          return the cropped width of dstframe.
 * @param[in,out] iHeight   the desired height at least align 4.
 *                          return the cropped height of dstframe.
 * @param[in] rotateAngle   the clockwise rotation angle
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_ConvertToI420(void* dstframe,
                       int srcFormat, const void* srcFrame, unsigned srcBufLen,
                       int srcWidth, int srcHeight, int crop_x, int crop_y,
                       int *dstWidth, int *dstHeight, int rotateAngle);

/**
 * utility for scale i420
 *
 * @param[in] srcFrame      the source buffer
 * @param[in] srcWidth      the source width of image
 * @param[in] srcHeight     the source height of image
 * @param[in] dstFrame      the I420 buffer to save the convert result
 * @param[in] dstWidth      the target width of image
 * @param[in] dstHeight     the target height of image
 *
 * @return                  0 on succeed, otherwise failed.
 */
int  Zmf_ScaleI420(void* srcframe, int srcWidth, int srcHeight,
                   void* dstframe, int dstWidth, int dstHeight);

/**
 * utility for mirror i420
 *
 * @param[in] srcFrame      the source buffer
 * @param[in] dstFrame      the I420 buffer to save the convert result
 * @param[in] width         image width
 * @param[in] height        image height
 *
 * @return                  0 on succeed, otherwise failed.
 */
int Zmf_MirrorI420UpDown(void* src_frame, void* dst_frame,
                     int width, int height);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif
