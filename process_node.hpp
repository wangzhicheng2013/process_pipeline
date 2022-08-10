#pragma once
class process_node {
public:
    virtual int process(const char *data, size_t len) = 0;
};