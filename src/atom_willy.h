#ifndef ATOM_WILLY
#define ATOM_WILLY

#include <Arduino.h>

class AtomWilly {
  private:
    uint8_t ledc_channel_;
    uint8_t ledc_timer_bit_;
    double ledc_freq_;
    int pwm_min_width_; // [us]
    int pwm_max_width_; // [us]
    uint8_t output_pin_;

  public:
    AtomWilly(uint8_t ledc_channel, int pwm_min_width=500, int pwm_max_width=2400, double ledc_freq=50.0, uint8_t ledc_timer_bit=16);
    void attach(uint8_t output_pin);
    void write(int value);
    void writeMicroseconds(int value);
    void detach();
};

#endif