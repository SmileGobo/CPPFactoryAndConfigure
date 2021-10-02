#include "Factory.h"
#include <stdexcept>
#include "Serial.h"
#include "Ethernet.h"

template <typename T>
struct Creator{
    Transport::Ptr operator() (std::uint32_t id){
        return std::make_shared<T>(id);
    }
};

constexpr std::size_t type2index(Transport::Type t){
    return static_cast<std::size_t>(t);
}

Factory::Factory():
    _ctors({
       nullptr,
       nullptr
    })
{
    _ctors[type2index(Transport::Type::Serial)] = Creator<Serial>();
    _ctors[type2index(Transport::Type::Ethernet)] = Creator<Ethernet>();
}

Transport::Ptr Factory::create(const Transport::Type type, uint32_t id) {
    if (type == Transport::Type::Max){
        return nullptr;
    }
    return _ctors[type2index(type)](id);
}
