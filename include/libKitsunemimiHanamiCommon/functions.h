/**
 * @file        functions.h
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

#ifndef KITSUNEMIMI_HANAMI_COMMON_FUNCTIONS_H
#define KITSUNEMIMI_HANAMI_COMMON_FUNCTIONS_H

#include <chrono>
#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <iomanip>

/**
 * @brief convert chrono-timestamp into a string in UTC time
 *
 * @param time chrono-timeshamp, which should be converted
 * @param format format to convert into
 *
 * @return string with the converted timestamp
 */
inline const std::string
serializeTimePoint(const std::chrono::high_resolution_clock::time_point &time,
                   const std::string &format = "UTC: %Y-%m-%d %H:%M:%S")
{
    std::time_t tt = std::chrono::system_clock::to_time_t(time);
    std::tm tm = *std::gmtime(&tt);
    std::stringstream ss;
    ss << std::put_time(&tm, format.c_str() );
    return ss.str();
}

#endif // KITSUNEMIMI_HANAMI_COMMON_FUNCTIONS_H
