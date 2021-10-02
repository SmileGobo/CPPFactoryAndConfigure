#ifndef SERIAL_H
#define SERIAL_H
#include "Transport.h"


#include <string>
class Serial: public Transport{
public:
    using Transport::Transport; //тырим конструктор

    void setDevice(std::string&& val);
    void setBaudrate(std::uint32_t val);

    std::string getType() const override;
private:
    std::string _device;
    std::uint32_t _baudrate;

};

#endif // SERIAL_H
