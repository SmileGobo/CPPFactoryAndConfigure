#include "Serial.h"

#include "IBuilder.h"
#include <Poco/Format.h>
void Serial::setDevice(std::string&& val) {
    _device = std::forward<std::string>(val);
}

void Serial::setBaudrate(uint32_t val){
    _baudrate = val;
}

std::string Serial::getType() const {
    return Poco::format("Type::Serial {baud: %u, device: %s}", _baudrate, _device);
}

// двойная диспетчирезация
void Serial::init(const IBuilder &bldr) {
    bldr.configure(*this);
}


