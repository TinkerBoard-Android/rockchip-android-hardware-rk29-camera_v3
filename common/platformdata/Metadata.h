/*
 * Copyright (C) 2013-2017 Intel Corporation
 * Copyright (c) 2017, Fuzhou Rockchip Electronics Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _METADATA_H
#define _METADATA_H

#include <hardware/camera3.h>
#include <system/camera_metadata.h>
#ifdef CAMERA_RKISP2_SUPPORT
#include <rkcamera_vendor_tags.h>
#endif

struct metadata_value_t {
    const char * name;
    int value;
};

/**
 * \struct metadata_tag_t
 * Struct to help in the parsing of the XML configuration file.
 * It is used to store relevant information of the static metadata tags
 */
struct metadata_tag_t {
    const char * name;/*!> name of the metadata tag*/
    int value;      /*!> enum value of the metadata tag*/
    int type;       /*!> enum, type of data (int,byte, float, rational)*/
    const metadata_value_t *enumTable; /*!> table to convert enum text to value */
    const int tableLength; /*!> length of the table */
    bool isArray;       /*!> true if this value is an array (this also include tuples)*/
    int dimSize[3];     /*!> sizes for each dimension of the array*/
    int arrayTypedef;   /*!> enum describing the type of data stored in the
                            array. The enum values are generated from the XML
                            model. It is declared in MetadataInfoAutoGen.h */
};

NAMESPACE_DECLARATION {

#define ELEMENT(array) (sizeof(array)/sizeof((array)[0]))
#define METAID2STR(array,value) metaId2String((array),ELEMENT(array),(value))
#define META_CONTROL2STR(array,value) METAID2STR(android_control_##array##_values, value)

const char *metaId2String(const metadata_value_t array[], int size, int value);

} NAMESPACE_DECLARATION_END

/* ******************************************************
 * ******************************************************
 * INCLUDE AUTOGENERATED DEFINITION FROM XML DATA
 *
 * ******************************************************
 ****************************************************** */

#include "MetadataInfoAutoGen.h"

#endif // _METADATA_H
