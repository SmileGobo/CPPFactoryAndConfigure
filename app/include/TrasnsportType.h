#ifndef TRASNSPORTTYPE_H
#define TRASNSPORTTYPE_H

#include <iostream>
#include "Transport.h"
class TransportType {
public:
    inline void set (std::string&& val){
        _value = Transport::Type::Max;

        if (val == "eth"){
            _value = Transport::Type::Ethernet;
        }
        if (val == "serial"){
            _value = Transport::Type::Serial;
        }
    }

    inline void set(Transport::Type val) {
        _value = val;
    }
    int toInt(){
        return static_cast<int>(_value);
    }

    inline Transport::Type get() const {
        return _value;
    }
private:
    Transport::Type _value {Transport::Type::Max};
};

inline std::istream &operator>>(std::istream& is, TransportType& target) {
    std::string val;
    is >> val;
    target.set(std::move(val));
    return is;
}

inline std::ostream& operator<<(std::ostream& stream, TransportType& target) {
    stream << "Type value as Int[" << target.toInt() << "]";
    return stream;
}

#endif // TRASNSPORTTYPE_H
