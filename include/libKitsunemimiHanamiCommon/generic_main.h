/**
 * @file        generic_main.h
 *
 * @author      Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 * @copyright   Apache License Version 2.0
 *
 *      Copyright 2021 Tobias Anker
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#ifndef KITSUNEMIMI_HANAMI_COMMON_GENERIC_MAIN_H
#define KITSUNEMIMI_HANAMI_COMMON_GENERIC_MAIN_H

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

#endif // KITSUNEMIMI_HANAMI_COMMON_GENERIC_MAIN_H
