#include <iostream>

using namespace std;
#include "Factory.h"


class TransportType {
public:
    void set (std::string&& val){
        _value = Transport::Type::Max;

        if (val == "eth"){
            _value = Transport::Type::Ethernet;
        }
        if (val == "serial"){
            _value = Transport::Type::Serial;
        }
    }

    void set(Transport::Type val) {
        _value = val;
    }
    int toInt(){
        return static_cast<int>(_value);
    }
    Transport::Type _value {Transport::Type::Max};
};

std::istream &operator>>(std::istream& is, TransportType& target) {
    std::string val;
    is >> val;
    target.set(std::move(val));
    return is;
}

std::ostream& operator<<(std::ostream& stream, TransportType& target) {
    stream << "Type value as Int[ " << target.toInt() << "]";
    return stream;
}

int main() {
    Factory factory;
    std::cout << "print type eth|serial of item" << std::endl;
    TransportType type;
    std::cin >> type;
    std::cout << type << std::endl;
    return 0;
}
