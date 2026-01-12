#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"
#include "Adafruit_seesaw.h"

namespace esphome::adafruit_stemma_soil_sensor {

  class AdafruitSTEMMASoilSensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
   public:

    Adafruit_seesaw myself;

    void setup() override;
    void update() override;
  };

} // namespace esphome::adafruit_stemma_soil_sensor
