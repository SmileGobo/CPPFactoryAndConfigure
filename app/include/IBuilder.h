#ifndef IBUILDER_H
#define IBUILDER_H


class Ethernet;
class Serial;

class IBuilder {
public:
    virtual ~IBuilder() = default;
    virtual void configure(Ethernet& item) const = 0;
    virtual void configure(Serial& item) const = 0;
};

#endif // IBUILDER_H
