#include "adafruit_stemma_soil_sensor.h"
#include "Adafruit_seesaw.h"
#include "esphome/core/log.h"

namespace esphome::adafruit_stemma_soil_sensor {

// static const char *TAG = "empty_i2c_sensor.sensor";

void AdafruitSTEMMASoilSensor::setup() {
  myself.begin(0x36);
}

void AdafruitSTEMMASoilSensor::update() {
  // TODO enable temperature sensor
  // float temperature = myself.getTemp();
  // temperature_sensor->publish_state(temperature);
  float humidity = myself.touchRead(0);
  humidity_sensor->publish_state(humidity);
}

void AdafruitSTEMMASoilSensor::dump_config() {
  // TODO is this needed?
}

} // namespace esphome::adafruit_stemma_soil_sensor
