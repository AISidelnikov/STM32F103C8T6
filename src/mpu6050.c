#include "mpu6050.h"

extern I2C_HandleTypeDef hi2c1;

static int16_t accel_x_raw = 0;
static int16_t accel_y_raw = 0;
static int16_t accel_z_raw = 0;

static int16_t gyro_x_raw = 0;
static int16_t gyro_y_raw = 0;
static int16_t gyro_z_raw = 0;

static int16_t temp_raw = 0;


mpu_t* mpu6050_init(void) {
    uint8_t check;
    uint8_t data;

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, 1000);
    
    if(check == 0x68) {
        data = 0x00;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &data, 1, 1000);
        data = 0x07;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &data, 1, 1000);

        data = 0x00;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, 1000);
        data = 0x00;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 1000);
    }
    return (mpu_t*)malloc(sizeof(mpu_t));
}

void mpu_read_accel(mpu_t *mpu) {
    uint8_t rec_data[6] = {0};

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, rec_data, 6, 1000);
    accel_x_raw = (uint16_t)(rec_data[0] << 8 | rec_data[1]);
    accel_y_raw = (uint16_t)(rec_data[2] << 8 | rec_data[3]);
    accel_z_raw = (uint16_t)(rec_data[4] << 8 | rec_data[5]);

    mpu->accel_x = (accel_x_raw / 16384.0) * 100;
    mpu->accel_y = (accel_y_raw / 16384.0) * 100;
    mpu->accel_z = (accel_z_raw / 16384.0) * 100;
}

void mpu_read_gyro(mpu_t *mpu) {
    uint8_t rec_data[6] = {0};

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, rec_data, 6, 1000);
    gyro_x_raw = (uint16_t)(rec_data[0] << 8 | rec_data[1]);
    gyro_y_raw = (uint16_t)(rec_data[2] << 8 | rec_data[3]);
    gyro_z_raw = (uint16_t)(rec_data[4] << 8 | rec_data[5]);

    mpu->gyro_x = (gyro_x_raw / 131.0) * 100;
    mpu->gyro_y = (gyro_y_raw / 131.0) * 100;
    mpu->gyro_z = (gyro_z_raw / 131.0) * 100;
}

void mpu_read_temp(mpu_t *mpu) {
    uint8_t rec_data[2] = {0};

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, TEMP_OUT_H_REG, 1, rec_data, 2, 1000);
    temp_raw = (uint16_t)(rec_data[0] << 8 | rec_data[1]);
    mpu->temp = (temp_raw / 340.0 + 36.53);
}


