#pragma once

#include <vector>

#include <QJsonObject>

class CLevelManager
{
public:
    void loadLevel(int level);
    void nextLevel();

    const QJsonObject &getCurrentLevel() const;

private:
    std::vector<QJsonObject> levels_;
    int currentLevelIndex_;
};