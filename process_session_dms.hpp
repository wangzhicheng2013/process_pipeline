#pragma once
#include "process_session.hpp"
#include "display_node.hpp"
#include "dump_node.hpp"
class process_session_dms : public process_session {
public:
    process_session_dms() = default;
    virtual ~process_session_dms() {
        if (dms_pipeline_) {
            delete dms_pipeline_;
            dms_pipeline_ = nullptr;
        }
        if (displayer_) {
            delete displayer_;
            displayer_ = nullptr;
        }
        if (dumpper_) {
            delete dumpper_;
            dumpper_ = nullptr;
        }
    }
    bool init() {
        dms_pipeline_ = new process_pipeline;
        if (!dms_pipeline_) {
            return false;
        }
        displayer_ = new display_node;
        if (!displayer_) {
            return false;
        }
        dumpper_ = new dump_node;
        if (!dumpper_) {
            return false;
        }
        dms_pipeline_->add_node(displayer_);
        dms_pipeline_->add_node(dumpper_);
        this->add_pipeline(dms_pipeline_);
        return true;
    }
private:
    process_pipeline *dms_pipeline_ = nullptr;
    display_node *displayer_ = nullptr;
    dump_node *dumpper_ = nullptr;
};