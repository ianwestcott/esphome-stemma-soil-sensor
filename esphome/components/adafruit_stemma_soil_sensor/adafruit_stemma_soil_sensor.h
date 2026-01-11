#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"
#include "Adafruit_seesaw.h"

namespace esphome::adafruit_stemma_soil_sensor {

  class AdafruitSTEMMASoilSensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
   public:

    Adafruit_seesaw myself;
    // TODO enable temperature sensor
    // Sensor *temperature_sensor = new Sensor();
    // TODO instantiate this separately
    Sensor *humidity_sensor = new Sensor();

    // Update every 60s by default (value in ms)
    AdafruitSTEMMASoilSensor() : PollingComponent(60000) { }

    void setup() override {
      myself.begin(0x36);
    }

    void update() override {
      // float temperature = myself.getTemp();
      // temperature_sensor->publish_state(temperature);
      float humidity = myself.touchRead(0);
      humidity_sensor->publish_state(humidity);
    }

    void dump_config() override {

    }
  };

} // namespace esphome::adafruit_stemma_soil_sensor
