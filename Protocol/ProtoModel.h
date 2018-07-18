//
//  ProtoModel.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/16/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_ProtoModel_h
#define TUCUT_Protocol_ProtoModel_h

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "TokenReader.h"
#include "Nameable.h"
#include "EnumModel.h"
#include "EnumValueModel.h"
#include "MessageModel.h"
#include "MessageFieldModel.h"
#include "OptionModel.h"
#include "Packageable.h"

namespace TUCUT {
namespace Protocol {
        
class ProtoModel : public Nameable, public Packageable, public OptionModelContainer, public EnumModelContainer,
                   public MessageModelContainer
{
public:
    typedef MessageModel::MessageFieldModelCollection MessageFieldModelCollection;
    typedef EnumModel::EnumValueModelCollection EnumValueModelCollection;
    typedef MessageModel::OneofModelCollection OneofModelCollection;
    typedef std::shared_ptr<EnumModel> SPEnumModel;
    typedef std::unordered_map<std::string, SPEnumModel> NamedEnumCollection;
    typedef std::shared_ptr<MessageModel> SPMessageModel;
    typedef std::unordered_map<std::string, SPMessageModel> NamedMessageCollection;
    typedef std::vector<std::string> ImportedProtoNameCollection;

    explicit ProtoModel (const std::string & fileName);

    ProtoModel (const ProtoModel & src);

    void completeModel ();

    void addField (TokenReader::iterator current, MessageFieldModelCollection::value_type & field);
    void completeField ();

    void addEnum (TokenReader::iterator current, EnumModelCollection::value_type & enumeration);
    void completeEnum ();

    void addEnumValue (TokenReader::iterator current, EnumValueModelCollection::value_type & value);
    void completeEnumValue ();

    void addMessage (TokenReader::iterator current, MessageModelCollection::value_type & message);
    void completeMessage ();

    void addOneof (TokenReader::iterator current, OneofModelCollection::value_type & oneof);
    void completeOneof ();

    virtual void addOption (TokenReader::iterator current, const OptionModelCollection::value_type & option);

    virtual void addImportedProtoName (TokenReader::iterator current, const std::string & protoName);

    void addPrivateEnumType (TokenReader::iterator current, const SPEnumModel & enumerationModel);

    void addPublicEnumType (TokenReader::iterator current, const SPEnumModel & enumerationModel);

    void addPrivateMessageType (TokenReader::iterator current, const SPMessageModel & messageModel);

    void addPublicMessageType (TokenReader::iterator current, const SPMessageModel & messageModel);

    const ImportedProtoNameCollection * importedProtoNames () const;

    const NamedEnumCollection * privateEnumTypes () const;

    const NamedEnumCollection * publicEnumTypes () const;

    const NamedMessageCollection * privateMessageTypes () const;

    const NamedMessageCollection * publicMessageTypes () const;

    ProtoModel & operator = (const ProtoModel & rhs);

private:
    bool typeExists (const std::string & fullName) const;
    EnumModel * typeAsEnum (const std::string & fullName) const;
    MessageModel * typeAsMessage (const std::string & fullName) const;

    void updateMessageFields (MessageModel * pMessageModel, const std::string & parentMessages = "");

    MessageModelCollection mMessageQueue;
    MessageFieldModelCollection::value_type mCurrentField;
    OneofModelCollection::value_type mCurrentOneof;
    EnumModelCollection::value_type mCurrentEnum;
    EnumValueModelCollection::value_type mCurrentEnumValue;
    ImportedProtoNameCollection mImportedProtoNames;
    NamedEnumCollection mPrivateEnumTypes;
    NamedEnumCollection mPublicEnumTypes;
    NamedMessageCollection mPrivateMessageTypes;
    NamedMessageCollection mPublicMessageTypes;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_ProtoModel_h
