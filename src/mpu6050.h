#ifndef _MPU6050_H_
#define _MPU6050_H_
#include "main.h"
#include "string.h"
#include "menu.h"

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

void mpu6050_init(void);
void mpu_read_accel(void);
void mpu_read_gyro(void);
void mpu_read_temp(void);

void mpu_str_accelx(void);
void mpu_str_accely(void);
void mpu_str_accelz(void);

void mpu_str_gyrox(void);
void mpu_str_gyroy(void);
void mpu_str_gyroz(void);

void mpu_str_tempc(void);
void mpu_str_tempf(void);
void mpu_str_tempk(void);

#endif