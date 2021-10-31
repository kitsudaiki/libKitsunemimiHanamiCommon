#ifndef UUID_H
#define UUID_H

#include <stdint.h>
#include <string>
#include <uuid/uuid.h>

struct kuuid
{
    char uuid[UUID_STR_LEN];
    uint8_t padding[3];

    const std::string toString() const {
        return std::string(uuid);
    }

    // total size: 40 Bytes
};

/**
 * @brief generate a new uuid with external library
 *
 * @return new uuid
 */
inline const kuuid
generateUuid()
{
    uuid_t binaryUuid;
    kuuid result;

    uuid_generate_random(binaryUuid);
    uuid_unparse_lower(binaryUuid, result.uuid);

    return result;
}

#endif // UUID_H
