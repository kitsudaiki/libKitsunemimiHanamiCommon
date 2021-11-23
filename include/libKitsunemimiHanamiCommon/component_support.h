/**
 * @file        component_support.h
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

#ifndef KITSUNEMIMI_HANAMI_COMMON_COMPONENT_SUPPORT_H
#define KITSUNEMIMI_HANAMI_COMMON_COMPONENT_SUPPORT_H

#include <libKitsunemimiConfig/config_handler.h>

namespace Kitsunemimi
{
namespace Hanami
{

enum Components
{
    KYOUKO = 0,
    MISAKA = 1,
    AZUKI = 2,
    SAGIRI = 3,
    NAGATO = 4,
    IZUNA = 5
};

struct SupportedComponents
{
    bool support[6];

    SupportedComponents()
    {
        support[0] = false;
        support[1] = false;
        support[2] = false;
        support[3] = false;
        support[4] = false;
        support[5] = false;
    }
};

static SupportedComponents supportedComponents = SupportedComponents();

}
}

#endif // KITSUNEMIMI_HANAMI_COMMON_COMPONENT_SUPPORT_H
