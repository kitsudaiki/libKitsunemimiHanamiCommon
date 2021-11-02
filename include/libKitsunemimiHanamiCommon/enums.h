/**
 * @file        internal_messages.h
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

#ifndef ENUMS_H
#define ENUMS_H

#include <stdint.h>

namespace Kitsunemimi
{
namespace Hanami
{

enum HttpRequestType
{
    GET_TYPE = 0,
    POST_TYPE = 1,
    PUT_TYPE = 2,
    DELETE_TYPE = 3
};

enum HttpResponseTypes
{
    // 1xx Informational
    CONTINUE_RESPONE           = 100,
    SWITCHIN_PROTOCOLS_RESPONE = 101,
    PROCESSING_RESPONE         = 102,
    EARLY_HINTS_RESPONE        = 103,

    // 2xx Succesful
    OK_RESPONE                     = 200,
    CREATED_RESPONE                = 201,
    ACCEPTED_RESPONE               = 202,
    NON_AUTHORITATIVE_INFO_RESPONE = 203,
    NO_CONTENT_RESPONE             = 204,
    RESET_CONTENT_RESPONE          = 205,
    PARTIAL_CONTENT_RESPONE        = 206,
    MULTI_STATUS_RESPONE           = 207,
    ALREADY_REPORETED_RESPONE      = 208,
    IM_USED_RESPONE                = 226,

    // 3xx Redirection
    MULTIPLE_CHOICES_RESPONE    = 300,
    MOVED_PERMANENTALLY_RESPONE = 301,
    FOUND_RESPONE               = 302,
    SEE_OTHER_RESPONE           = 303,
    NOT_MODIFIED_RESPONE        = 304,
    USE_PROXY_RESPONE           = 305,
    SWITCH_PROXY_RESPONE        = 306,
    TEMPORARY_REDIRECT_RESPONE  = 307,
    PERMANENT_REDIRECT_RESPONE  = 308,

    // 4xx Client Error
    BAD_REQUEST_RESPONE                     = 400,
    UNAUTHORIZED_RESPONE                    = 401,
    PAYMENT_REQUIRED_RESPONE                = 402,
    FORBIDDEN_RESPONE                       = 403,
    NOT_FOUND_RESPONE                       = 404,
    MOTHOD_NOT_ALLOWED_RESPONE              = 405,
    NOT_ACCEPTABLE_RESPONE                  = 406,
    PROXY_AUTHENTICATION_REQUIRED_RESPONE   = 407,
    REQUEST_TIMEOUT_RESPONE                 = 408,
    CONFLICT_RESPONE                        = 409,
    GONE_RESPONE                            = 410,
    LENGTH_REQUIRED_RESPONE                 = 411,
    PRECONDITION_FAILED_RESPONE             = 412,
    PAYLOAD_TOO_LARGE_RESPONE               = 413,
    URI_TOO_LONG_RESPONE                    = 414,
    UNSUPPORTED_MEDIA_TYPE_RESPONE          = 415,
    RANGE_NOT_SATISFIEABLE_RESPONE          = 416,
    EXPECTEATION_FAILED_RESPONE             = 417,
    I_AM_NOT_A_TEAPOT_RESPONE               = 418,
    MISDIRECTED_REQUEST_RESPONE             = 421,
    UNPROCESSABLE_ENTITY_RESPONE            = 422,
    LOCKED_RESPONE                          = 423,
    FAILED_REPENDENCY_RESPONE               = 424,
    TOO_EARLY_RESPONE                       = 425,
    UPGRADE_REQUIRED_RESPONE                = 426,
    PRECONDTION_REQUIRED_RESPONSE           = 428,
    TOO_MANY_REQUESTES_RESPONE              = 429,
    REQUEST_HEADER_FIELDS_TOO_LARGE_RESPONE = 431,
    UNAVAILABLE_FOR_LEGAL_REASONS_RESPONE   = 451,

    // 5xx Server Error
    INTERNAL_SERVER_ERROR_RESPONE           = 500,
    NOT_IMPLEMENTED_RESPONE                 = 501,
    BAD_GATEWAY_RESPONE                     = 502,
    SERVICE_UNAVAILABLE_RESPONE             = 503,
    GATEWAY_TIMEOUT_RESPONE                 = 504,
    HTTP_VERSION_NOT_SUPPORTED_RESPONE      = 505,
    VARIANT_ALSO_NEGOTIATES_RESPONE         = 506,
    INSUFFICIENT_STORAGE_RESPONE            = 507,
    LOOP_DETECTED_RESPONE                   = 508,
    NOT_EXTENDED_RESPONE                    = 510,
    NETWORK_AUTHENTICATION_REQUIRED_RESPONE = 511
};

enum SakuraObjectType
{
    TREE_TYPE = 0,
    BLOSSOM_TYPE = 1,
};

}
}

#endif // ENUMS_H
