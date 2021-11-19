#ifndef GENERIC_MAIN_H
#define GENERIC_MAIN_H

#include <libKitsunemimiArgs/arg_parser.h>
#include <libKitsunemimiCommon/logger.h>
#include <libKitsunemimiConfig/config_handler.h>

namespace Kitsunemimi
{
namespace Hanami
{

bool
initMain(int argc,
         char *argv[],
         const std::string &name,
         bool (*registerArguments)(Kitsunemimi::Args::ArgParser*,
                                   Kitsunemimi::ErrorContainer &),
         void (*registerConfigs)(Kitsunemimi::ErrorContainer &),
         Kitsunemimi::ErrorContainer &error)
{
    Kitsunemimi::initConsoleLogger(true);

    // create and init argument-parser
    Kitsunemimi::Args::ArgParser argParser;
    registerArguments(&argParser, error);

    // parse cli-input
    if(argParser.parse(argc, argv, error) == false) {
        return false;
    }

    // init config-file
    std::string configPath = argParser.getStringValue("config");
    if(configPath == "") {
        configPath = "/etc/" + name + "/" + name + ".conf";
    }
    if(Kitsunemimi::Config::initConfig(configPath, error) == false) {
        return false;
    }
    registerConfigs(error);
    if(Kitsunemimi::Config::isConfigValid() == false) {
        return false;
    }

    // get config-parameter for logger
    bool success = false;
    const bool enableDebug = GET_BOOL_CONFIG("DEFAULT", "debug", success);
    if(success == false) {
        return false;
    }

    const std::string logPath = GET_STRING_CONFIG("DEFAULT", "log_path", success);
    if(success == false) {
        return false;
    }

    // init logger
    Kitsunemimi::initConsoleLogger(enableDebug);
    Kitsunemimi::initFileLogger(logPath, name, enableDebug);

    return true;
}

}
}

#endif // GENERIC_MAIN_H
