#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "../adafruit_stemma_soil_sensor.h"

namespace esphome::adafruit_stemma_soil_sensor {

class AdafruitSTEMMASoilSensorMoisture : public sensor::Sensor, public PollingComponent {
 public:
  void setup() override;
  void update() override;

  void set_parent(AdafruitSTEMMASoilSensor *parent) { parent_ = parent; }

 protected:
  AdafruitSTEMMASoilSensor *parent_;
};

}  // namespace esphome::adafruit_stemma_soil_sensor
