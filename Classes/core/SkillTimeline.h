// 스킬 시간표를 재생 시간에 따라 진행하는 결정적 시계.
#pragma once
#include <cstddef>
#include <vector>

namespace aster {
struct SkillCue {
    double time = 0;
    double duration = 0;
    size_t sourceIndex = 0;
};

class SkillTimeline {
public:
    void reset(std::vector<SkillCue> cues, double duration);
    std::vector<size_t> advance(double delta);
    void stop();

    bool complete() const {
        return stopped_ || (cursor_ == cues_.size() && elapsed_ >= duration_);
    }

    double elapsed() const {
        return elapsed_;
    }

    double duration() const {
        return duration_;
    }

private:
    std::vector<SkillCue> cues_;
    size_t cursor_ = 0;
    double elapsed_ = 0, duration_ = 0;
    bool stopped_ = false;
};
}
