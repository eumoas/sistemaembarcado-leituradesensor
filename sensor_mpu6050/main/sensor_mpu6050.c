#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_err.h"
#include "esp_log.h"
#include "mpu6050.h"

static const char *TAG = "MPU6050";

void app_main(void)
{
    // 1. I2C: SDA transporta os dados e SCL fornece o sinal de clock.
    const i2c_config_t config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = GPIO_NUM_8,
        .scl_io_num = GPIO_NUM_9,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,
    };
    ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &config));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));

    // 2. Cria o sensor no endereco 0x68 (AD0 ligado ao GND).
    mpu6050_handle_t sensor = mpu6050_create(I2C_NUM_0, MPU6050_I2C_ADDRESS);
    if (sensor == NULL) {
        ESP_LOGE(TAG, "Nao foi possivel criar o sensor");
        return;
    }

    // 3. Confirma a identidade, ajusta as escalas e tira do modo de repouso.
    uint8_t device_id = 0;
    ESP_ERROR_CHECK(mpu6050_get_deviceid(sensor, &device_id));
    if (device_id != 0x68) {
        ESP_LOGE(TAG, "Identificacao inesperada: 0x%02x", device_id);
        mpu6050_delete(sensor);
        return;
    }
    ESP_ERROR_CHECK(mpu6050_config(sensor, ACCE_FS_2G, GYRO_FS_250DPS));
    ESP_ERROR_CHECK(mpu6050_wake_up(sensor));
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP_LOGI(TAG, "Sensor iniciado! SDA=8, SCL=9, endereco=0x68");

    // 4. Le e imprime uma amostra por segundo, enquanto o programa estiver ativo.
    while (1) {
        mpu6050_acce_value_t aceleracao;
        mpu6050_gyro_value_t rotacao;
        mpu6050_temp_value_t temperatura;

        esp_err_t erro = mpu6050_get_acce(sensor, &aceleracao);
        if (erro == ESP_OK) {
            erro = mpu6050_get_gyro(sensor, &rotacao);
        }
        if (erro == ESP_OK) {
            erro = mpu6050_get_temp(sensor, &temperatura);
        }

        if (erro == ESP_OK) {
            printf("Aceleracao (g): X=%.2f Y=%.2f Z=%.2f\n",
                   aceleracao.acce_x, aceleracao.acce_y, aceleracao.acce_z);
            printf("Rotacao (graus/s): X=%.2f Y=%.2f Z=%.2f\n",
                   rotacao.gyro_x, rotacao.gyro_y, rotacao.gyro_z);
            printf("Temperatura: %.2f C\n\n", temperatura.temp);
        } else {
            ESP_LOGE(TAG, "Falha na leitura: %s. Confira as conexoes.",
                     esp_err_to_name(erro));
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
