//  PropertyGroup.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_PropertyGroup_h
#define TUCUT_ECS_PropertyGroup_h

#include "PropertyValue.h"

#include <string>
#include <unordered_map>

namespace TUCUT::ECS
{
  class PropertyGroup
  {
  public:
    PropertyGroup ();

    PropertyGroup (PropertyGroup const & src);

    PropertyGroup (PropertyGroup && src);

    virtual ~PropertyGroup () = default;

    std::unique_ptr<PropertyGroup> clone () const;

    PropertyGroup & operator = (PropertyGroup const & rhs);
    PropertyGroup & operator = (PropertyGroup && rhs);

    bool addValue (std::string const & valueName,
      std::string const & value, bool readOnly = false);
    bool addValue (std::string const & valueName,
      char const * value, bool readOnly = false);
    bool addValue (std::string const & valueName,
      int value, bool readOnly = false);
    bool addValue (std::string const & valueName,
      double value, bool readOnly = false);
    bool addValue (std::string const & valueName,
      bool value, bool readOnly = false);

    void removeValue (std::string const & valueName);

    PropertyValue * getValue (std::string const & valueName);

    PropertyValue const * getValue (
      std::string const & valueName) const;

  private:
    using ValueMap = std::unordered_map<
      std::string, std::unique_ptr<PropertyValue>>;

    std::unique_ptr<ValueMap> mValues;
  };
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_PropertyGroup_h
