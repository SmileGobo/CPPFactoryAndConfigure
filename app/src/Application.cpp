#include "Application.h"
#include <Poco/Util/Option.h>
#include "TrasnsportType.h"
#include <Poco/JSON/Parser.h>
#include "JSSONBuilder.h"
#include "Factory.h"
#include <fstream>
Application::Application()
{

}

void Application::initialize(Poco::Util::Application& app) {
    logger().information("Name of config: %s", config().getString("config"));
    std::ifstream file(config().getString("config"));
    Poco::JSON::Parser parser;
    auto config = parser.parse(file).extract<Poco::JSON::Object::Ptr>();
    JSSONBuilder bldr(config->getObject("config"));
    TransportType ttype;
    ttype.set(config->getValue<std::string>("type"));
    Factory fctry;
    _instance = fctry.create(ttype.get(), 0);
    if (_instance){
        _instance->init(bldr);
    }

}

void Application::defineOptions(Poco::Util::OptionSet& options) {
    Poco::Util::Option cfg("config", "c", "params file for instance");
    cfg.required(true).argument("config").binding("config");

    options.addOption(cfg);
}

int Application::main(const std::vector<std::string>& args) {
    if (!_instance){
        logger().error("instance not init!");
        return Application::EXIT_CONFIG;
    }
    logger().information(" instance [%s]", _instance->getType());
    return Application::EXIT_OK;
}
