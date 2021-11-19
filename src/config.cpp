
#include <libKitsunemimiConfig/config_handler.h>
#include <libKitsunemimiCommon/logger.h>

namespace Kitsunemimi
{
namespace Hanami
{

void
registerBasicConfigs(ErrorContainer &error)
{
    REGISTER_BOOL_CONFIG(   "DEFAULT", "debug",    error, false,      false);
    REGISTER_STRING_CONFIG( "DEFAULT", "log_path", error, "/var/log", false);
}

/**
 * @brief register configs
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
    }

    for(const std::string& groupName : configGroups)
    {
        REGISTER_INT_CONFIG(    groupName, "port",    error, 0,  false);
        REGISTER_STRING_CONFIG( groupName, "address", error, "", true);
    }
}

}
}
