//
//  PropertyGroup.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_PropertyGroup_h
#define TUCUT_Game_PropertyGroup_h

#include <string>
#include <unordered_map>

#include "PropertyValue.h"

namespace TUCUT {
namespace Game {

class PropertyGroup
{
public:
    PropertyGroup ();
    
    PropertyGroup (const PropertyGroup & src);
    
    PropertyGroup (PropertyGroup && src);

    virtual ~PropertyGroup () = default;
    
    std::unique_ptr<PropertyGroup> clone () const;
    
    PropertyGroup & operator = (const PropertyGroup & rhs);
    PropertyGroup & operator = (PropertyGroup && rhs);

    bool addValue (const std::string & valueName, const std::string & value, bool readOnly = false);
    bool addValue (const std::string & valueName, const char * value, bool readOnly = false);
    bool addValue (const std::string & valueName, int value, bool readOnly = false);
    bool addValue (const std::string & valueName, double value, bool readOnly = false);
    bool addValue (const std::string & valueName, bool value, bool readOnly = false);

    void removeValue (const std::string & valueName);

    PropertyValue * getValue (const std::string & valueName);

    const PropertyValue * getValue (const std::string & valueName) const;

private:
    using ValueMap = std::unordered_map<std::string, std::unique_ptr<PropertyValue>>;
    
    std::unique_ptr<ValueMap> mValues;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_PropertyGroup_h
