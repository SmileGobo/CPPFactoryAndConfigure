#ifndef JSSONBUILDER_H
#define JSSONBUILDER_H
#include "IBuilder.h"
#include <Poco/JSON/Object.h>

class JSSONBuilder: public IBuilder{
public:
    JSSONBuilder(Poco::JSON::Object::Ptr config);
    void configure(Ethernet& item) const  override;
    void configure(Serial& item) const override;

private:
    Poco::JSON::Object::Ptr _config;
};

#endif // JSSONBUILDER_H
