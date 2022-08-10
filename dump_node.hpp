#pragma once
#include <stdio.h>
#include "process_node.hpp"
class dump_node : public process_node {
public:
    virtual int process(const char *data, size_t len) {
        printf("dump node works now!\n");
        for (size_t index = 0;index < len;index++) {
            printf("data[%zd]:%0x\n", index, data[index]);
        }
        return 0;
    }
};