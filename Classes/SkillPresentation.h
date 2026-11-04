// 데이터 기반 스킬 연출 노드.
#pragma once
#include "cocos2d.h"
#include <array>
#include <functional>
#include <memory>
#include <string>
#include <vector>

class SkillPresentation : public cocos2d::Node {
public:
    struct SkillChoice {
        std::string id, name, heroId, modelJson, modelAtlas, portraitJson, portraitAtlas, cutPath,
            timelinePath;
        bool playable = false;
        float duration = 0;
        std::vector<std::string> limitations;
    };

    struct Callbacks {
        std::function<void(bool skipped)> onComplete;
        std::function<void()> onHit;
        std::function<void(const std::string&)> onDiagnostic;
    };

    static SkillPresentation* create(const std::string& skillId, const Callbacks&, std::string& error);
    static const std::vector<SkillChoice>& catalog();
    static std::array<std::string, 4> initialSkillIds();
    ~SkillPresentation() override;
    void update(float delta) override;
    void onExit() override;
    void skip();
    void setPaused(bool paused);

    void bindBattleStage(cocos2d::Node* stage, cocos2d::Node* background, cocos2d::Node* opponents,
                         cocos2d::Vec2 actorHome, cocos2d::Vec2 targetHome);
    std::string diagnostic() const;

private:
    SkillPresentation();
    bool load(const std::string&, const Callbacks&, std::string&);
    void finish(bool skipped, bool remove);
    void dispatch(size_t index);
    struct Impl;
    std::unique_ptr<Impl> impl_;
};
