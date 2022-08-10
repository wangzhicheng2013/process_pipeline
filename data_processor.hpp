#pragma once
class data_processor {
public:
    virtual void process(const char *data, size_t len) = 0;
};