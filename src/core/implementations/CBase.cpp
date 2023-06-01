#include "CBase.h"

#include "Logger.h"

void CBase::initialize()
{
    Log(INFO) << "Base is initialized";
}

void CBase::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Base is drawn";
}
PointWrapper *CBase::position() const
{
    return position_.get();
}
