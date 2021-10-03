#ifndef ETHERNET_H
#define ETHERNET_H
#include "Transport.h"
#include <string>

class Ethernet: public Transport {
public:
    using Transport::Transport;
    void setTarget(std::string&& host, std::uint16_t port);
    void setRecievePort(std::uint16_t port);
    void init(const IBuilder& bldr) override;
private:
    struct {
        std::string   host {};
        std::uint16_t port {0};
    } _target;
    std::uint16_t _port;


    // Transport interface
public:
    std::string getType() const;
};

#endif // ETHERNET_H
