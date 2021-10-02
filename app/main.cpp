#include <iostream>

using namespace std;
#include "Factory.h"

int main() {
    Factory factory;
    struct {
        Transport::Type value {Transport::Type::Max};
        std::string str{};
    } type;

    std::cin >> type.str;
    if (type.str == "eth"){
        type.value = Transport::Type::Ethernet;
    }
    if (type.str == "serial"){
        type.value = Transport::Type::Serial;
    }
    factory.create()
    return 0;
}
