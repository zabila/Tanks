#pragma once

class QQmlApplicationEngine;
class IController
{
public:
    virtual ~IController() = default;
    virtual void initialize(QQmlApplicationEngine *) = 0;
};