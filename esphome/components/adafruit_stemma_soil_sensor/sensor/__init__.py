import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from .. import (
    AdafruitSTEMMASoilSensor,
    adafruit_stemma_soil_sensor_ns,
    CONF_ADAFRUIT_STEMMA_SOIL_SENSOR,
)
from esphome.const import (
    CONF_ID,
    CONF_MOISTURE,
    CONF_TEMPERATURE,
    DEVICE_CLASS_TEMPERATURE,
    ICON_THERMOMETER,
    STATE_CLASS_MEASUREMENT,
    STATE_CLASS_NONE,
    UNIT_CELSIUS,
)

AdafruitSTEMMASoilSensorMoisture = adafruit_stemma_soil_sensor_ns.class_(
    "AdafruitSTEMMASoilSensorMoisture",
    sensor.Sensor,
    cg.PollingComponent,
)
AdafruitSTEMMASoilSensorTemperature = adafruit_stemma_soil_sensor_ns.class_(
    "AdafruitSTEMMASoilSensorTemperature",
    sensor.Sensor,
    cg.PollingComponent,
)

CONFIG_SCHEMA = cv.typed_schema(
    {
        CONF_MOISTURE: sensor.sensor_schema(
            AdafruitSTEMMASoilSensorMoisture,
            # TODO other attributes?
            accuracy_decimals=0,
            state_class=STATE_CLASS_NONE,
        ).extend(
            {
                cv.GenerateID(CONF_ADAFRUIT_STEMMA_SOIL_SENSOR): cv.use_id(
                    AdafruitSTEMMASoilSensor),
            }
        ).extend(cv.polling_component_schema('60s')),
        CONF_TEMPERATURE: sensor.sensor_schema(
            AdafruitSTEMMASoilSensorTemperature,
            unit_of_measurement=UNIT_CELSIUS,
            icon=ICON_THERMOMETER,
            accuracy_decimals=1,
            device_class=DEVICE_CLASS_TEMPERATURE,
            state_class=STATE_CLASS_MEASUREMENT,
        ).extend(
            {
                cv.GenerateID(CONF_ADAFRUIT_STEMMA_SOIL_SENSOR): cv.use_id(
                    AdafruitSTEMMASoilSensor),
            }
        ).extend(cv.polling_component_schema('60s')),
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await sensor.register_sensor(var, config)
    adafruit_stemma_soil_sensor = await cg.get_variable(
        config[CONF_ADAFRUIT_STEMMA_SOIL_SENSOR])
    cg.add(var.set_parent(adafruit_stemma_soil_sensor))
