#include <iostream>

#include <libKitsunemimiHanamiCommon/messages.h>

int main()
{
    Kitsunemimi::Hanami::ErrorLog_Message test;

    u_int8_t buffer[10000];
    const uint64_t size = test.createBlob(buffer, 10000);
    test.read(buffer, size);
    if(Kitsunemimi::Hanami::isHanamiProtocol(buffer, size)) {
        std::cout<<"yeah"<<std::endl;
    }
    return 0;
}
