
#include <libKitsunemimiConfig/config_handler.h>
#include <libKitsunemimiCommon/logger.h>

namespace Kitsunemimi
{
namespace Hanami
{

void
registerBasicConfigs()
{
    REGISTER_BOOL_CONFIG("DEFAULT", "debug", false, false);
}

/**
 * @brief register configs
 */
void
registerBasicConnectionConfigs(const std::vector<std::string> &configGroups)
{
    REGISTER_INT_CONFIG("DEFAULT", "port", 0);
    REGISTER_STRING_CONFIG("DEFAULT", "address", "");

    for(const std::string& groupName : configGroups)
    {
        REGISTER_INT_CONFIG(groupName, "port", 0);
        REGISTER_STRING_CONFIG(groupName, "address", "");
    }
}

/**
 * @brief validate config for a specific group
 *
 * @param groupName group-name to validate
 *
 * @return true, if config is valid, else false
 */
bool
checkConfigs(const std::string &groupName)
{
    bool success = false;

    // check address
    const std::string address = GET_STRING_CONFIG(groupName, "address", success);
    assert(success);
    if(address == "")
    {
        Kitsunemimi::ErrorContainer error;
        error.errorMessage = "address in group " + groupName + " was not set in config-file";
        LOG_ERROR(error);
        return false;
    }
    // TODO: check if address is valid ip

    return true;
}

/**
 * @brief validate config
 *
 * @param configGroups list of config-groups the check
 * @param createServer if true, check also the DEFAULT-section
 *
 * @return true, if config is valid, else false
 */
bool
checkConfigs(const std::vector<std::string> &configGroups,
             const bool createServer)
{
    if(createServer)
    {
        if(checkConfigs("DEFAULT") == false) {
            return false;
        }
    }

    // check client-configs
    for(const std::string& groupName : configGroups)
    {
        if(checkConfigs(groupName) == false) {
            return false;
        }
    }

    return true;
}

}
}
