/**
 * @file        config.cpp
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

#include <libKitsunemimiConfig/config_handler.h>
#include <libKitsunemimiCommon/logger.h>

namespace Kitsunemimi
{
namespace Hanami
{

/**
 * @brief registerBasicConfigs
 * @param error
 */
void
registerBasicConfigs(ErrorContainer &error)
{
    REGISTER_BOOL_CONFIG(   "DEFAULT", "debug",    error, false,      false);
    REGISTER_STRING_CONFIG( "DEFAULT", "log_path", error, "/var/log", false);
}

/**
 * @brief registerBasicConnectionConfigs
 * @param configGroups
 * @param createServer
 * @param error
 */
void
registerBasicConnectionConfigs(const std::vector<std::string> &configGroups,
                               const bool createServer,
                               ErrorContainer &error)
{
    if(createServer)
    {
        REGISTER_INT_CONFIG(    "DEFAULT", "port",      error, 0,  false);
        REGISTER_STRING_CONFIG( "DEFAULT", "address",   error, "", true);
        REGISTER_STRING_CONFIG( "DEFAULT", "endpoints", error, "", true);
        REGISTER_STRING_CONFIG( "DEFAULT", "database",  error, "", true);
    }

    for(const std::string& groupName : configGroups)
    {
        REGISTER_INT_CONFIG(    groupName, "port",      error, 0,  false);
        REGISTER_STRING_CONFIG( groupName, "address",   error, "", false);
    }
}

}
}
