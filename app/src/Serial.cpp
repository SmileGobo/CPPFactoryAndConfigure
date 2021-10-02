#include "Serial.h"


void Serial::setDevice(std::string &&val) {
    _device = std::forward<std::string>(val);
}

void Serial::setBaudrate(uint32_t val){
    _baudrate = val;
}

std::string Serial::getType() const {
    return "Type::Serial";
}


