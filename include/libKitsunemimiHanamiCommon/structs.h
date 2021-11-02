#ifndef KITSUNEMIMI_HANAMI_COMMON_STRUCTS_H
#define KITSUNEMIMI_HANAMI_COMMON_STRUCTS_H

#include <libKitsunemimiHanamiCommon/enums.h>
#include <libKitsunemimiCommon/common_items/data_items.h>

namespace Kitsunemimi
{
namespace Hanami
{

struct ResponseMessage
{
    HttpResponseTypes type = NO_CONTENT_RESPONE;
    std::string respnseContent = "";
};

struct RequestMessage
{
    HttpRequestType httpType = GET_TYPE;
    std::string id = "";
    std::string inputValues = "{}";
};

}
}

#endif // KITSUNEMIMI_HANAMI_COMMON_STRUCTS_H
