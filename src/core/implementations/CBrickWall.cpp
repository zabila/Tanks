#include "CBrickWall.h"
#include "Logger.h"

CBrickWall::CBrickWall()
{
    isDestroyble_ = true;
}

void CBrickWall::draw()
{
    Log(INFO) << "CBrickWall::draw()";
}

bool CBrickWall::isDestroyble() const
{
    return isDestroyble_;
}