#ifndef __ZMF_SENSOR_H__
#define __ZMF_SENSOR_H__
#if __GNUC__
#pragma GCC visibility push(default)
#endif
/**
 * @file zmf_motion.h
 * @brief ZMF Motion interfaces
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ZmfSensorGrvity             =1,
    ZmfSensorAcceleration       =2,
    ZmfSensorRotationRate       =4,
    ZmfSensorAttitude           =8,
    ZmfSensorLight              =16,
} ZmfSensorType;

typedef enum {
    ZmfSensorFastest,
    ZmfSensorGame,
    ZmfSensorUI,
    ZmfSensorNormal
} ZmfSensorMode;

typedef struct {
    unsigned                types;

    /** The elapsed millisend time from the start */
    unsigned                timeStampMs;

    /** The gravity acceleration vector 
     * expressed in the device's reference frame.
     */
    float                   gravity[3];

    /**  the total acceleration of the device
     * is equal to gravity plus the acceleration the user imparts to the device
     */
    float                   acceleration[3];

    float                   rotationRate[3];

    float                   pitch, roll, yaw;

    float                   brightness;

} ZmfSensorData;

typedef void (*ZmfSensorCallback)(void* pUser, const ZmfSensorData *sensor);

int Zmf_SensorInitialize    (void*  applicationContext);
int Zmf_SensorTerminate     (void);

int Zmf_SensorGetTypes      (unsigned *sensorTypes);

int Zmf_SensorStart         (unsigned sensorTypes, unsigned sensorMode);
int Zmf_SensorStop          ();

int Zmf_SensorAddCallback   (void *pUser, ZmfSensorCallback callback);
int Zmf_SensorRemoveCallback(void *pUser);

/**  Get the device’s attitude at a point in time.
 * @param[out] pitch     Angle in the horizontal plane of the device, ranging from 0 to M_PI.
 * @param[out] yaw       The orientation of the device orientation, ranging from -M_PI to M_PI.
 *                       It is 0 when the device is oriented in its natural position,
 *                       M_PI_2 when its right side is at the top, M_PI or -M_PI when it is upside down,
 *                       and -M_PI_2 when its left side is to the top.
 * @param[out] roll
 */

int Zmf_SensorDataGetAttitude (const ZmfSensorData *sensor, float *pitch, float *roll, float *yaw);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#if __GNUC__
#pragma GCC visibility pop
#endif
#endif /* __ZMF_SENSOR_H__ */
