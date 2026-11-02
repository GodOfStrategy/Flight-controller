#ifndef TVC_CONTROLLER_H
#define TVC_CONTROLLER_H

#include "main.h"

typedef struct
{
  float pitch_deg;
  float roll_deg;
  float pitch_rate_deg_s;
  float roll_rate_deg_s;
  float altitude_m;
  float vertical_speed_m_s;
  uint8_t imu_valid;
  uint8_t altitude_valid;
} TVC_State_t;

typedef struct
{
  float pitch_servo_deg;
  float roll_servo_deg;
  uint8_t active;
  uint8_t fault;
} TVC_Output_t;

typedef struct
{
  float target_altitude_m;
  float max_servo_deg;
  float min_altitude_m;
  float max_altitude_m;
  float max_rate_deg_s;
  float pitch_kp;
  float pitch_kd;
  float roll_kp;
  float roll_kd;
  float altitude_trim_limit_deg;
  float altitude_kp;
  float altitude_kd;
} TVC_Config_t;

void TVC_Init(const TVC_Config_t *config);
void TVC_Update(const TVC_State_t *state, float dt_s, TVC_Output_t *output);

#endif
