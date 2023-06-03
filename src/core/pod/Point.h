#pragma once

#include <QObject>
#include <qvariant.h>

#include <ostream>

struct Point
{
public:
    int x;
    int y;

    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }

    bool operator==(const Point &other) const { return x == other.x && y == other.y; }
};

class PointWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)

public:
    explicit PointWrapper(QObject *parent = nullptr)
        : QObject(parent)
        , point{}
    {}

    PointWrapper(const Point &point, QObject *parent = nullptr)
        : QObject(parent)
        , point(point)
    {}

    PointWrapper(const PointWrapper &other)
        : QObject(other.parent())
        , point{other.point}
    {}

    PointWrapper &operator=(const PointWrapper &other)
    {
        if (this != &other) {
            point = other.point;
        }
        return *this;
    }

    PointWrapper &operator=(PointWrapper &&other)
    {
        if (this != &other) {
            point = std::move(other.point);
        }
        return *this;
    }

    ~PointWrapper() override = default;

    void setX(int x)
    {
        if (point.x == x) {
            return;
        }
        point.x = x;
        emit xChanged();
    }

    void setY(int y)
    {
        if (point.y == y) {
            return;
        }
        point.y = y;
        emit yChanged();
    }

    //operator+()
    PointWrapper &operator+=(const PointWrapper &other)
    {
        point.x += other.point.x;
        point.y += other.point.y;
        return *this;
    }

    PointWrapper operator+(const PointWrapper &other)
    {
        PointWrapper result = *this;
        result += other;
        return result;
    }

    //operator-()
    PointWrapper &operator-=(const PointWrapper &other)
    {
        point.x -= other.point.x;
        point.y -= other.point.y;
        return *this;
    }

    PointWrapper operator-(const PointWrapper &other)
    {
        PointWrapper result = *this;
        result -= other;
        return result;
    }

    //operator+=()
    PointWrapper &operator+=(int value)
    {
        point.x += value;
        point.y += value;
        return *this;
    }

    PointWrapper operator+(int value)
    {
        PointWrapper result = *this;
        result += value;
        return result;
    }

    Q_INVOKABLE int x() const { return point.x; }
    Q_INVOKABLE int y() const { return point.y; }

    Point value() const { return point; }

    friend std::ostream &operator<<(std::ostream &os, const PointWrapper &point_wrapper)
    {
        os << "x: " << point_wrapper.x() << " y: " << point_wrapper.y();
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const PointWrapper *point_wrapper)
    {
        os << "x: " << point_wrapper->x() << " y: " << point_wrapper->y();
        return os;
    }

    friend bool operator==(const PointWrapper &lhs, const PointWrapper &rhs)
    {
        return lhs.point.x == rhs.point.x && lhs.point.y == rhs.point.y;
    }

signals:
    void xChanged();
    void yChanged();

private:
    Point point;
};
