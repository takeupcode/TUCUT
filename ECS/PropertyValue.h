//  PropertyValue.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_PropertyValue_h
#define TUCUT_ECS_PropertyValue_h

#include <memory>
#include <string>

namespace TUCUT::ECS
{
  class PropertyValue
  {
  public:
    static std::unique_ptr<PropertyValue>
    createStringPropertyValue (
      std::string const & value = "",
      bool readOnly = false);

    static std::unique_ptr<PropertyValue>
    createIntegerPropertyValue (
      int value = 0,
      bool readOnly = false);

    static std::unique_ptr<PropertyValue>
    createFloatingPropertyValue (
      double value = 0.0,
      bool readOnly = false);

    static std::unique_ptr<PropertyValue>
    createBooleanPropertyValue (
      bool value = false,
      bool readOnly = false);

    virtual ~PropertyValue () = default;

    virtual std::unique_ptr<PropertyValue> clone () const = 0;

    virtual bool isString () const;
    virtual bool isInteger () const;
    virtual bool isFloating () const;
    virtual bool isBoolean () const;

    virtual std::string getString () const;
    virtual int getInteger () const;
    virtual double getFloating () const;
    virtual bool getBoolean () const;

    virtual void setString (std::string const & value);
    virtual void setInteger (int value);
    virtual void setFloating (double value);
    virtual void setBoolean (bool value);

  protected:
    PropertyValue (bool readOnly)
    : mReadOnly(readOnly)
    { }

    PropertyValue (PropertyValue const & src) = delete;
    PropertyValue (PropertyValue && src) = delete;
    PropertyValue & operator = (
      PropertyValue const & rhs) = delete;
    PropertyValue & operator = (PropertyValue && rhs) = delete;

    bool mReadOnly;
  };

  class StringPropertyValue : public PropertyValue
  {
  public:
    virtual ~StringPropertyValue () = default;

    std::unique_ptr<PropertyValue> clone () const override
    {
      return std::unique_ptr<PropertyValue>(
        new StringPropertyValue(mValue, mReadOnly));
    }

    bool isString () const override
    {
      return true;
    }

    std::string getString () const override
    {
      return mValue;
    }

    void setString (std::string const & value) override
    {
      if (mReadOnly)
      {
        return;
      }

      mValue = value;
    }

  protected:
    friend class PropertyValue;

    StringPropertyValue (
      std::string const & value, bool readOnly)
    : PropertyValue(readOnly), mValue(value)
    { }

  private:
    std::string mValue;
  };

  class IntegerPropertyValue : public PropertyValue
  {
  public:
    virtual ~IntegerPropertyValue () = default;

    std::unique_ptr<PropertyValue> clone () const override
    {
      return std::unique_ptr<PropertyValue>(
        new IntegerPropertyValue(mValue, mReadOnly));
    }

    bool isInteger () const override
    {
      return true;
    }

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

    std::unique_ptr<PropertyValue> clone () const override
    {
      return std::unique_ptr<PropertyValue>(
        new FloatingPropertyValue(mValue, mReadOnly));
    }

    bool isFloating () const override
    {
      return true;
    }

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

    std::unique_ptr<PropertyValue> clone () const override
    {
      return std::unique_ptr<PropertyValue>(
        new BooleanPropertyValue(mValue, mReadOnly));
    }

    bool isBoolean () const override
    {
      return true;
    }

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
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_PropertyValue_h
