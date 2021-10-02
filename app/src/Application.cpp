#include "Application.h"
#include <Poco/Util/Option.h>
#include <TrasnsportType.h>

Application::Application()
{

}

void Application::initialize(Poco::Util::Application& app) {

}

void Application::defineOptions(Poco::Util::OptionSet& options) {
    Poco::Util::Option cfg("config", "c", "params file for instance");
    cfg.required(true).argument("config");

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
