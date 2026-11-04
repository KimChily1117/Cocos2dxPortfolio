// 프로필 저장과 불러오기.
#pragma once
#include "core/GameModel.h"
#include <string>

namespace aster {

class SaveStore {
public:
    explicit SaveStore(std::string path) : path_(std::move(path)) {}

    bool load(Profile& profile, std::string& error) const;
    bool save(const Profile& profile, std::string& error) const;

    const std::string& path() const {
        return path_;
    }

private:
    std::string path_;
};
}
