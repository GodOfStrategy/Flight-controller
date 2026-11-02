#include "tvc_controller.h"

static TVC_Config_t controller_config;
static uint8_t controller_initialized;

static float clamp_float(float value, float minimum, float maximum)
{
  if (value < minimum)
  {
    return minimum;
  }
  if (value > maximum)
  {
    return maximum;
  }
  return value;
}

void TVC_Init(const TVC_Config_t *config)
{
  if (config != NULL)
  {
    controller_config = *config;
    controller_initialized = 1U;
  }
}

void TVC_Update(const TVC_State_t *state, float dt_s, TVC_Output_t *output)
{
  float altitude_error;
  float altitude_trim;
  float pitch_command;
  float roll_command;
  float max_step;

  if (output == NULL)
  {
    return;
  }

  output->pitch_servo_deg = 0.0f;
  output->roll_servo_deg = 0.0f;
  output->active = 0U;
  output->fault = 1U;

  if ((controller_initialized == 0U) || (state == NULL) ||
      (state->imu_valid == 0U) || (state->altitude_valid == 0U) ||
      (dt_s <= 0.0f) || (dt_s > 0.1f))
  {
    return;
  }

  if ((state->altitude_m < controller_config.min_altitude_m) ||
      (state->altitude_m > controller_config.max_altitude_m))
  {
    return;
  }

  altitude_error = controller_config.target_altitude_m - state->altitude_m;
  altitude_trim = (controller_config.altitude_kp * altitude_error) -
                  (controller_config.altitude_kd * state->vertical_speed_m_s);
  altitude_trim = clamp_float(altitude_trim,
                              -controller_config.altitude_trim_limit_deg,
                              controller_config.altitude_trim_limit_deg);

  pitch_command = (controller_config.pitch_kp * (-state->pitch_deg)) -
                  (controller_config.pitch_kd * state->pitch_rate_deg_s) +
                  altitude_trim;
  roll_command = (controller_config.roll_kp * (-state->roll_deg)) -
                 (controller_config.roll_kd * state->roll_rate_deg_s) +
                 altitude_trim;

  pitch_command = clamp_float(pitch_command, -controller_config.max_servo_deg,
                              controller_config.max_servo_deg);
  roll_command = clamp_float(roll_command, -controller_config.max_servo_deg,
                             controller_config.max_servo_deg);

  max_step = controller_config.max_rate_deg_s * dt_s;
  output->pitch_servo_deg = clamp_float(pitch_command,
                                        output->pitch_servo_deg - max_step,
                                        output->pitch_servo_deg + max_step);
  output->roll_servo_deg = clamp_float(roll_command,
                                       output->roll_servo_deg - max_step,
                                       output->roll_servo_deg + max_step);
  output->active = 1U;
  output->fault = 0U;
}
