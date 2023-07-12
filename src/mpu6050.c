#include "mpu6050.h"

extern I2C_HandleTypeDef hi2c1;

static int16_t accel_x_raw = 0;
static int16_t accel_y_raw = 0;
static int16_t accel_z_raw = 0;

static int16_t gyro_x_raw = 0;
static int16_t gyro_y_raw = 0;
static int16_t gyro_z_raw = 0;

static int16_t temp_raw = 0;

static mpu_t mpu;
extern char string_func[16];
extern MENUS cur_pos;

void mpu6050_init(void) {
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

void mpu_read_accel(void) {
    uint8_t rec_data[6] = {0};

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, rec_data, 6, 1000);
    accel_x_raw = (uint16_t)(rec_data[0] << 8 | rec_data[1]);
    accel_y_raw = (uint16_t)(rec_data[2] << 8 | rec_data[3]);
    accel_z_raw = (uint16_t)(rec_data[4] << 8 | rec_data[5]);

    mpu.accel_x = (accel_x_raw / 16384.0) * 100;
    mpu.accel_y = (accel_y_raw / 16384.0) * 100;
    mpu.accel_z = (accel_z_raw / 16384.0) * 100;
}
void mpu_str_accelx(void) {
    mpu_read_accel();
    sprintf(string_func, "x = %+04d", mpu.accel_x);
}
void mpu_str_accely(void) {
    mpu_read_accel();
    sprintf(string_func, "y = %+04d", mpu.accel_y);
}
void mpu_str_accelz(void) {
    mpu_read_accel();
    sprintf(string_func, "z = %+04d", mpu.accel_z);
}

void mpu_read_gyro(void) {
    uint8_t rec_data[6] = {0};

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, rec_data, 6, 1000);
    gyro_x_raw = (uint16_t)(rec_data[0] << 8 | rec_data[1]);
    gyro_y_raw = (uint16_t)(rec_data[2] << 8 | rec_data[3]);
    gyro_z_raw = (uint16_t)(rec_data[4] << 8 | rec_data[5]);

    mpu.gyro_x = (gyro_x_raw / 131.0) * 100;
    mpu.gyro_y = (gyro_y_raw / 131.0) * 100;
    mpu.gyro_z = (gyro_z_raw / 131.0) * 100;
}
void mpu_str_gyrox(void) {
    mpu_read_gyro();
    sprintf(string_func, "x = %+04d", mpu.gyro_x);
}
void mpu_str_gyroy(void) {
    mpu_read_gyro();
    sprintf(string_func, "y = %+04d", mpu.gyro_y);
}
void mpu_str_gyroz(void) {
    mpu_read_gyro();
    sprintf(string_func, "z = %+04d", mpu.gyro_z);
}

void mpu_read_temp(void) {
    uint8_t rec_data[2] = {0};

    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, TEMP_OUT_H_REG, 1, rec_data, 2, 1000);
    temp_raw = (uint16_t)(rec_data[0] << 8 | rec_data[1]);
    mpu.temp = (temp_raw / 340.0 + 36.53);
}
void mpu_str_tempc(void) {
    mpu_read_temp();
    sprintf(string_func, "t = %+04d", mpu.temp);
}
void mpu_str_tempf(void) {
    mpu_read_temp();
    sprintf(string_func, "t = %+04d", (int)(mpu.temp * 9 / 5 + 32));
}
void mpu_str_tempk(void) {
    mpu_read_temp();
    sprintf(string_func, "t = %+04d", (int)(mpu.temp + 273));
}


