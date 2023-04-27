#include "atom_willy.h"

AtomWilly::AtomWilly(uint8_t ledc_channel, int pwm_min_width, int pwm_max_width, double ledc_freq, uint8_t ledc_timer_bit)
  :ledc_channel_(ledc_channel),
  ledc_timer_bit_(ledc_timer_bit),
  ledc_freq_(ledc_freq),
  pwm_min_width_(pwm_min_width),
  pwm_max_width_(pwm_max_width)
{
  ledcSetup(ledc_channel_, ledc_freq_, ledc_timer_bit_);
}

void AtomWilly::attach(uint8_t output_pin){
  output_pin_ = output_pin;
  ledcAttachPin(output_pin_, ledc_channel_);
}

void AtomWilly::write(int value){
  uint32_t output = map(constrain(value, 0, 180), 0, 180, pwm_min_width_, pwm_max_width_);

  this->writeMicroseconds(output);
}

void AtomWilly::writeMicroseconds(int value) {
  uint32_t scale = (uint32_t)(pow(2, ledc_timer_bit_));
  uint32_t period = 1e6 / ledc_freq_;

  uint32_t output = map(constrain(value, pwm_min_width_, pwm_max_width_),
                        0,
                        period,
                        0,
                        scale);

  ledcWrite(ledc_channel_, output);
}

void AtomWilly::detach(){
  ledcDetachPin(output_pin_);
}