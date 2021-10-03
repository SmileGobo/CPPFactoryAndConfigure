#include "Ethernet.h"
#include "IBuilder.h"
#include <Poco/Format.h>
void Ethernet::setTarget(std::string&& host, uint16_t port){
    _target.host = std::forward<std::string>(host);
    _target.port = port;
}

void Ethernet::setRecievePort(uint16_t port) {
    _port = port;
}

void Ethernet::init(const IBuilder &bldr) {
    bldr.configure(*this);
}

std::string Ethernet::getType() const {
    return Poco::format(
        "Type::Ethernet: target{ host: %s, port: %hu}, server: %hu",
        _target.host,
        _target.port,
        _port
    );

}
