#ifndef APPLICATION_H
#define APPLICATION_H

#include <Poco/Util/Application.h>
#include <Transport.h>
class Application: public Poco::Util::Application {
public:
    Application();

    // Subsystem interface
protected:
    void initialize(Poco::Util::Application &app);
    void defineOptions(Poco::Util::OptionSet &options);

    // Application interface
protected:
    int main(const std::vector<std::string> &args);

private:
    Transport::Ptr _instance {};
};

#endif // APPLICATION_H
