#include "Ethernet.h"

void Ethernet::setTarget(std::string&& host, uint16_t port){
    _target.host = std::forward<std::string>(host);
    _target.port = port;
}

void Ethernet::setRecievePort(uint16_t port) {
    _port = port;
}

std::string Ethernet::getType() const {
    return "Type::Ethernet";
}
