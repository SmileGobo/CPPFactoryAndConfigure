#ifndef FACTORY_H
#define FACTORY_H

#include <functional>
#include <memory>
#include <array>
#include "Transport.h"

class Factory {
public:
    Factory();
    Transport::Ptr create(const Transport::Type type, std::uint32_t id);
private:
    using _Creator = std::function<Transport::Ptr (std::uint32_t)>;
    using _Creators = std::array<_Creator, static_cast<std::size_t>(Transport::Type::Max)>;
    _Creators _ctors;
};

#endif // FACTORY_H
