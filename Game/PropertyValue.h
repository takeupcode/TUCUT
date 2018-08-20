//
//  PropertyValue.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_PropertyValue_h
#define TUCUT_Game_PropertyValue_h

#include <string>
#include <memory>

namespace TUCUT {
namespace Game {

class PropertyValue
{
public:
    static std::unique_ptr<PropertyValue> createStringPropertyValue (const std::string & value = "", bool readOnly = false);
    static std::unique_ptr<PropertyValue> createIntegerPropertyValue (int value = 0, bool readOnly = false);
    static std::unique_ptr<PropertyValue> createFloatingPropertyValue (double value = 0.0, bool readOnly = false);
    static std::unique_ptr<PropertyValue> createBooleanPropertyValue (bool value = false, bool readOnly = false);

    virtual ~PropertyValue () = default;
    
    virtual std::string getString () const;
    virtual int getInteger () const;
    virtual double getFloating () const;
    virtual bool getBoolean () const;

    virtual void setString (const std::string & value);
    virtual void setInteger (int value);
    virtual void setFloating (double value);
    virtual void setBoolean (bool value);

protected:
    PropertyValue (bool readOnly)
    : mReadOnly(readOnly)
    { }
    
    bool mReadOnly;
};

class StringPropertyValue : public PropertyValue
{
public:
    virtual ~StringPropertyValue () = default;
    
    std::string getString () const override
    {
        return mValue;
    }
    
    void setString (const std::string & value) override
    {
        if (mReadOnly)
        {
            return;
        }
        
        mValue = value;
    }

protected:
    friend class PropertyValue;
    
    StringPropertyValue (const std::string & value, bool readOnly)
    : PropertyValue(readOnly), mValue(value)
    { }
    
private:
    std::string mValue;
};

class IntegerPropertyValue : public PropertyValue
{
public:
    virtual ~IntegerPropertyValue () = default;
    
    int getInteger () const override
    {
        return mValue;
    }
    
    void setInteger (int value) override
    {
        if (mReadOnly)
        {
            return;
        }
        
        mValue = value;
    }
    
protected:
    friend class PropertyValue;
    
    IntegerPropertyValue (int value, bool readOnly)
    : PropertyValue(readOnly), mValue(value)
    { }
    
private:
    int mValue;
};

class FloatingPropertyValue : public PropertyValue
{
public:
    virtual ~FloatingPropertyValue () = default;
    
    double getFloating () const override
    {
        return mValue;
    }
    
    void setFloating (double value) override
    {
        if (mReadOnly)
        {
            return;
        }
        
        mValue = value;
    }
    
protected:
    friend class PropertyValue;
    
    FloatingPropertyValue (double value, bool readOnly)
    : PropertyValue(readOnly), mValue(value)
    { }
    
private:
    double mValue;
};

class BooleanPropertyValue : public PropertyValue
{
public:
    virtual ~BooleanPropertyValue () = default;
    
    bool getBoolean () const override
    {
        return mValue;
    }
    
    void setBoolean (bool value) override
    {
        if (mReadOnly)
        {
            return;
        }
        
        mValue = value;
    }
    
protected:
    friend class PropertyValue;
    
    BooleanPropertyValue (bool value, bool readOnly)
    : PropertyValue(readOnly), mValue(value)
    { }
    
private:
    bool mValue;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_PropertyValue_h
