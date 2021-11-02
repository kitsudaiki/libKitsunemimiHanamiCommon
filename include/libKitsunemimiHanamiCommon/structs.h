#ifndef STRUCTS_H
#define STRUCTS_H

#include <libKitsunemimiHanamiCommon/enums.h>
#include <libKitsunemimiCommon/common_items/data_items.h>

namespace Kitsunemimi
{
namespace Hanami
{

struct MessageResponse
{
    HttpResponseTypes type = OK_RESPONE;
    DataItem* respnseContent = nullptr;
};

}
}

#endif // STRUCTS_H
