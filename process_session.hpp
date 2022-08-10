#pragma once
#include <vector>
#include "data_processor.hpp"
#include "process_pipeline.hpp"
class process_session : public data_processor {
public:
    inline void add_pipeline(process_pipeline *pipeline) {
        if (pipeline) {
            pipelines_.push_back(pipeline);
        }
    }
    void remove_pipeline(process_pipeline *pipeline) {
        if (!pipeline) {
            return;
        }
        int size = pipelines_.size();
        for (int i = 0;i < size;i++) {
            if (pipelines_[i] == pipeline) {
                pipelines_.erase(std::begin(pipelines_) + i);
            }
        }
    }
    inline void clear_pipeline() {
        pipelines_.clear();
    }
    virtual void process(const char *data, size_t len) {
        for (auto &pipeline : pipelines_) {
            pipeline->process(data, len);
        }
    }
private:
    std::vector<process_pipeline *>pipelines_;
};