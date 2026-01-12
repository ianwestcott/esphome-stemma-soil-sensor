#include "adafruit_stemma_soil_sensor.h"
#include "Adafruit_seesaw.h"
#include "esphome/core/log.h"

namespace esphome::adafruit_stemma_soil_sensor {

void AdafruitSTEMMASoilSensor::setup() {
  myself.begin(0x36);
}

void AdafruitSTEMMASoilSensor::update() { }

} // namespace esphome::adafruit_stemma_soil_sensor
