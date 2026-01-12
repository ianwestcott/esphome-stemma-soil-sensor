import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import ICON_EMPTY, UNIT_EMPTY, CONF_ID

DEPENDENCIES = ["i2c"]

MULTI_CONF = True

adafruit_stemma_soil_sensor_ns = cg.esphome_ns.namespace("adafruit_stemma_soil_sensor")
AdafruitSTEMMASoilSensor = adafruit_stemma_soil_sensor_ns.class_(
    "AdafruitSTEMMASoilSensor", cg.PollingComponent, i2c.I2CDevice
)

CONF_ADAFRUIT_STEMMA_SOIL_SENSOR = "adafruit_stemma_soil_sensor"

CONFIG_SCHEMA = (
    cv.COMPONENT_SCHEMA.extend({
        cv.GenerateID(): cv.declare_id(AdafruitSTEMMASoilSensor),
    })
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x36))
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)
