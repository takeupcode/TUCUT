//
//  MessageFieldModel.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/3/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_MessageFieldModel_h
#define TUCUT_Protocol_MessageFieldModel_h

#include <memory>
#include <string>

#include "Nameable.h"
#include "OptionModel.h"
#include "Packageable.h"

// Every model header includes its container header.
#include "MessageFieldModelContainer.h"

namespace TUCUT {
namespace Protocol {
        
class EnumModel;
class MessageModel;
class ProtoModel;

class MessageFieldModel : public Nameable, public Packageable, public OptionModelContainer
{
public:
    enum class Requiredness
    {
        required = 0,
        optional = 1,
        repeated = 2
    };

    enum class FieldCategory
    {
        unknown = 0,
        boolType = 1,
        numericType = 2,
        stringType = 3,
        bytesType = 4,
        enumType = 5,
        messageType = 6
    };

    MessageFieldModel (Requiredness requiredness, const std::string & fieldType,
                       const std::string & name, unsigned int index);

    MessageFieldModel (const MessageFieldModel & src);

    Requiredness requiredness () const;

    std::string fieldType () const;

    std::string fieldTypePackage () const;

    FieldCategory fieldCategory () const;

    std::string defaultValue () const;
    void setDefaultValue (const std::string & defaultValue);

    void updateFieldCategoryToEnum (const EnumModel * pReferencedType);
    void updateFieldCategoryToMessage (const MessageModel * pReferencedType);

    unsigned int index () const;

    MessageFieldModel & operator = (const MessageFieldModel & rhs);

private:
    void setFieldCategory ();

    Requiredness mRequiredness;
    FieldCategory mFieldCategory;
    std::string mDefaultValue;
    std::string mFieldType;
    std::string mFieldTypePackage;
    unsigned int mIndex;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_MessageFieldModel_h
