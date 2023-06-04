#include "CWall.h"
#include "Logger.h"

CWall::CWall(CGameEngine* gameEngine, const Point& position)
    : QObject(nullptr)
    , id_(getId())
    , gameEngine_(gameEngine)
    , position_(std::make_unique<PointWrapper>(position, this))
    , isDestroyable_(true)
    , isDrawn_(false)
{}

void CWall::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Wall tank is drawn " << position_.get();
}

bool CWall::isDestroyable() const
{
    return isDestroyable_;
}

PointWrapper* CWall::position() const
{
    return position_.get();
}
int CWall::id() const
{
    return id_;
}
