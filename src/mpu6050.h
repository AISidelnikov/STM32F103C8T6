#ifndef _MPU6050_H_
#define _MPU6050_H_
#include "main.h"
#include "string.h"

#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75
#define TEMP_OUT_H_REG 0x41

typedef struct {
    int accel_x;
    int accel_y;
    int accel_z;
    
    int gyro_x;
    int gyro_y;
    int gyro_z;

    int temp;
}mpu_t;

mpu_t* mpu6050_init(void);
void mpu_read_accel(mpu_t *mpu);
void mpu_read_gyro(mpu_t *mpu);
void mpu_read_temp(mpu_t *mpu);

#endif