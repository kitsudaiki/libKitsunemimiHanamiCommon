/**
 * @file        config.h
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

#ifndef HANAMI_COMMON_CONFIG_H
#define HANAMI_COMMON_CONFIG_H

#include <libKitsunemimiConfig/config_handler.h>

namespace Kitsunemimi
{
namespace Hanami
{

/**
 * @brief register configs
 */
void
registerConfigs()
{
    REGISTER_BOOL_CONFIG("DEFAULT", "debug", false, false);
}

}
}

#endif // HANAMI_COMMON_CONFIG_H
