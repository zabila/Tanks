#include "CConcreteWall.h"
#include "Logger.h"

CConcreteWall::CConcreteWall()
{
    isDestroyble_ = false;
}
void CConcreteWall::draw()
{
    Log(INFO) << "CConcreteWall::draw()";
}

bool CConcreteWall::isDestroyble() const
{
    return isDestroyble_;
}
