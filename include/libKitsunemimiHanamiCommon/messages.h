/**
 * @file        messages.h
 *
 * @author      Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 * @copyright   Apache License Version 2.0
 *
 *      Copyright 2020 Tobias Anker
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

#ifndef HANAMI_MESSAGES_H
#define HANAMI_MESSAGES_H

#include <stdint.h>
#include <string>

#include <libKitsunemimiCommon/buffer/data_buffer.h>

namespace Kitsunemimi
{
namespace Hanami
{

//==================================================================================================

class HanamiMessage
{

public:
    enum EntryType
    {
        UNDEFINED_ENTRY_TYPE = 0,
        INT64_ENTRY_TYPE = 1,
        UINT64_ENTRY_TYPE = 2,
        FLOAT64_ENTRY_TYPE = 3,
        BOOL_ENTRY_TYPE = 4,
        STRING_ENTRY_TYPE = 5,
        BYTE_ENTRY_TYPE = 6,
        FLOAT32_LIST_ENTRY_TYPE = 7,
    };

    struct Entry
    {
        uint8_t type = UNDEFINED_ENTRY_TYPE;
        uint8_t padding[7];
        uint64_t valSize = 0;
    }; // size: 16

    struct MessageHeader
    {
        const char protocolIdent[6] = {'h', 'a', 'n', 'a', 'm', 'i'};
        uint8_t type = 0;
        uint8_t padding[1];
        uint64_t messageSize = 0;
    }; // size: 16

    HanamiMessage();
    virtual ~HanamiMessage();

    virtual bool read(void* data, const uint64_t dataSize) = 0;
    virtual uint64_t createBlob(uint8_t* result, const uint64_t bufferSize) = 0;

protected:
    uint8_t m_type = 0;
    uint64_t m_pos = 0;

    uint64_t initBlob(uint8_t* result, const uint64_t totalMsgSize);
    uint64_t appendUint(uint8_t* result, const uint64_t &val);
    uint64_t appendString(uint8_t* result, const std::string &val);
    uint64_t appendData(uint8_t* result, const void* data, const uint64_t &dataSize);
    uint64_t appendFloatList(uint8_t* result, const float* values, const uint64_t &numberOfValues);

    bool initRead(const void* data, const uint64_t dataSize);
    bool readUint(const void* data, uint64_t& output);
    bool readString(const void* data, std::string& output);
    bool readBinary(void* data, void** resultData, uint64_t &resultDataSize);
    bool readFloatList(void* data, float** resultData, uint64_t &numberOfValues);
};

//==================================================================================================

/**
 * @brief check if the incoming bytes are a serializied hanami-message
 *
 * @param data data to check
 * @param dataSize number of bytes of data
 *
 * @return true, if data are the beginning of a hanami-message
 */
inline bool
isHanamiProtocol(void* data, const uint64_t dataSize)
{
    if(dataSize < sizeof(HanamiMessage::MessageHeader)) {
        return false;
    }

    const uint64_t* start = static_cast<const uint64_t*>(data);
    return ((*start) & 0xFFFFFFFFFFFF0000) == 0x68616e616d690000;
}

//==================================================================================================

class ErrorLog_Message
        : public HanamiMessage
{
public:
    ErrorLog_Message();
    ~ErrorLog_Message();

    std::string userUuid = "";
    std::string component = "";
    std::string errorMsg = "";
    std::string context = "";
    std::string values = "";

    bool read(void* data, const uint64_t dataSize);
    uint64_t createBlob(uint8_t* result, const uint64_t bufferSize);
};

//==================================================================================================

}  // namespace Hanami
}  // namespace Kitsunemimi

#endif // HANAMI_MESSAGES_H
