#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <cstdint>
#include <memory>

class Transport {
public:
    virtual ~Transport() = default;
    enum class Type {
        Ethernet,
        Serial,
        Max
    };

    using Ptr =std::shared_ptr<Transport>;
    Transport(std::uint32_t id);

    // чисто для демонстрации
    virtual std::string getType() const = 0;
private:
    std::uint32_t  _id;
};


#endif // TRANSPORT_H
