#include "sensor_temperature.h"
#include "esphome/core/log.h"

namespace esphome::adafruit_stemma_soil_sensor {

static const char *const TAG = "adafruit_stemma_soil_sensor.temperature";

void AdafruitSTEMMASoilSensorTemperature::setup() {
  ESP_LOGCONFIG(TAG, "Setting up Adafruit STEMMA moisture sensor temperature...");
}

void AdafruitSTEMMASoilSensorTemperature::update() {
  float value = this->parent_->myself.getTemp();
  this->publish_state(value);
}

}  // namespace esphome::adafruit_stemma_soil_sensor
