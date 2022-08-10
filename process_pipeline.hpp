#pragma once
#include <vector>
#include "process_node.hpp"
class process_pipeline {
public:
    inline void add_node(process_node *node) {
        if (node) {
            nodes_.push_back(node);
        }
    }
    void remove_node(process_node *node) {
        if (!node) {
            return;
        }
        int size = nodes_.size();
        for (int i = 0;i < size;i++) {
            if (nodes_[i] == node) {
                nodes_.erase(std::begin(nodes_) + i);
            }
        }
    }
    inline void clear_nodes() {
        nodes_.clear();
    }
    void process(const char *data, size_t len) {
        if (!data || !len) {
            return;
        }
        for (auto &node : nodes_) {
            node->process(data, len);
        }
    }
private:
    std::vector<process_node *>nodes_;
};