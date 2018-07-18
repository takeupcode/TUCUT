//
//  CodeGeneratorInterface.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/16/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_CodeGeneratorInterface_h
#define TUCUT_Protocol_CodeGeneratorInterface_h

#include <memory>
#include <string>

#include "ProtoModel.h"

namespace TUCUT {
namespace Protocol {
        
class CodeGeneratorInterface
{
public:
    virtual ~CodeGeneratorInterface ()
    { }

    virtual void generateCode (const std::string & outputFolder, const ProtoModel * protoModel,
                               const std::string & projectName = "", bool generateCommonCode = false) const = 0;

protected:
    CodeGeneratorInterface ()
    { }

private:
    CodeGeneratorInterface (const CodeGeneratorInterface & src) = delete;
    CodeGeneratorInterface & operator = (const CodeGeneratorInterface & rhs) = delete;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_CodeGeneratorInterface_h
