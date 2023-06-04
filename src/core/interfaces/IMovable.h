#pragma once

#include <type_traits>

#include "pod/Enums.h"

class IMovable : public IDrawable
{
public:
    virtual ~IMovable() = default;
    virtual void move(MyEnum::Direction direction) = 0;
    virtual int speed() const = 0;
    virtual bool isCollide(IDrawable* drown_object) const = 0;
};
Q_DECLARE_INTERFACE(IMovable, "com.example.IMovable")

template<class T1, class T2, typename Func>
void checkCollisionAndDoAction(T1* first, T2* second, Func action)
{
    if (std::is_base_of<IMovable, T1>::value && std::is_base_of<IDrawable, T2>::value) {
        action(first->isCollide(second));
    }
}

static std::string toString(MyEnum::Direction direction)
{
    switch (direction) {
    case MyEnum::Direction::UP:
        return "UP";
    case MyEnum::Direction::DOWN:
        return "DOWN";
    case MyEnum::Direction::LEFT:
        return "LEFT";
    case MyEnum::Direction::RIGHT:
        return "RIGHT";
    default:
        return "UNKNOWN";
    }
}
