#pragma once

#include <QObject>

#include "IDrawable.h"

/**
 * @brief The IBase class is an abstract base class that inherits from IDrawable.
 * 
 * This class represents an interface for a base object that can be drawn on a canvas.
 * It provides a pure virtual function initialize() that must be implemented by derived classes.
 * 
 * @note This class is part of the com.example namespace.
 */
class IBase : public IDrawable
{
public:
    /**
     * @brief A virtual destructor for the IBase class.
     * 
     * This destructor is declared as virtual to ensure that the correct destructor is called
     * when deleting an object of a derived class through a pointer to the base class.
     */
    virtual ~IBase() = default;

    /**
     * @brief Initializes the base object.
     * 
     * This pure virtual function must be implemented by derived classes to initialize the base object.
     * 
     * @note This function does not return a value.
     * 
     * @throws std::runtime_error if an error occurs during initialization.
     */
    virtual void initialize() = 0;
};

/**
 * @brief The Q_DECLARE_INTERFACE macro is used to declare the IBase interface to the Qt meta-object system.
 * 
 * This macro is necessary for the IBase interface to be recognized by the Qt meta-object system and
 * to enable features such as dynamic_cast and qobject_cast.
88 */

Q_DECLARE_INTERFACE(IBase, "com.example.IBase")