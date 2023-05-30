#include "CLevelManager.h"
#include "Logger.h"
#include "implementations/Logger/LogStream.h"

void CLevelManager::loadLevel(int level)
{
    Log(INFO) << "Loading level" << level;
}

void CLevelManager::nextLevel()
{
    Log(INFO) << "Next level from" << currentLevelIndex_++ << "to" << currentLevelIndex_ << " of "
              << levels_.size() << "levels";
}

const QJsonObject &CLevelManager::getCurrentLevel() const
{
    if (currentLevelIndex_ >= levels_.size() || currentLevelIndex_ < 0) {
        throw std::out_of_range("Level index out of range");
    }
    return levels_.at(currentLevelIndex_);
}
