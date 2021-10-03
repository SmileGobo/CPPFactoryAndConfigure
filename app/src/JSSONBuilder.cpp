#include "JSSONBuilder.h"


JSSONBuilder::JSSONBuilder(Poco::JSON::Object::Ptr config):
    _config(config)
{

}
#include "Ethernet.h"
void JSSONBuilder::configure(Ethernet &item) const {
    static struct {
        struct {
            std::string Host = "host";
            std::string Port = "port";
        } Target;
        std::string Server = "server";
    } Field;

    item.setRecievePort(_config->getValue<std::uint16_t>(Field.Server));
    auto target = _config->getObject("target");
    item.setTarget(
        target->getValue<std::string>(Field.Target.Host),
        target->getValue<std::uint16_t>(Field.Target.Port)
    );

}

#include "Serial.h"
void JSSONBuilder::configure(Serial &item) const {
    static struct {
        std::string Device   = "device";
        std::string Baudrate = "baudrate";
    } Field;

    item.setDevice(_config->getValue<std::string>(Field.Device));
    item.setBaudrate(_config->getValue<std::uint32_t>(Field.Baudrate));
}


