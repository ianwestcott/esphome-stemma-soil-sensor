#include "sensor_moisture.h"
#include "esphome/core/log.h"

namespace esphome::adafruit_stemma_soil_sensor {

static const char *const TAG = "adafruit_stemma_soil_sensor.moisture";

void AdafruitSTEMMASoilSensorMoisture::setup() {
  ESP_LOGCONFIG(TAG, "Setting up Adafruit STEMMA soil moisture sensor...");
}

void AdafruitSTEMMASoilSensorMoisture::update() {
  // TODO don't hard-code pin
  float value = this->parent_->myself.touchRead(0);
  if (value < 1)
    ESP_LOGW(TAG, "ignoring unusually low moisture reading of %d", value);
  else
    this->publish_state(value);
}

}  // namespace esphome::adafruit_stemma_soil_sensor

