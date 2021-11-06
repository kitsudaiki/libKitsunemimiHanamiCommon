
#include <libKitsunemimiConfig/config_handler.h>
#include <libKitsunemimiCommon/logger.h>

namespace Kitsunemimi
{
namespace Hanami
{

void
registerBasicConfigs()
{
    REGISTER_BOOL_CONFIG(   "DEFAULT", "debug",    false,      false);
    REGISTER_STRING_CONFIG( "DEFAULT", "log_path", "/var/log", false);
}

/**
 * @brief register configs
 */
void
registerBasicConnectionConfigs(const std::vector<std::string> &configGroups,
                               const bool createServer)
{
    if(createServer)
    {
        REGISTER_INT_CONFIG(    "DEFAULT", "port",      0,  false);
        REGISTER_STRING_CONFIG( "DEFAULT", "address",   "", true);
        REGISTER_STRING_CONFIG( "DEFAULT", "endpoints", "", true);
    }

    for(const std::string& groupName : configGroups)
    {
        REGISTER_INT_CONFIG(    groupName, "port",    0,  false);
        REGISTER_STRING_CONFIG( groupName, "address", "", true);
    }
}

}
}
