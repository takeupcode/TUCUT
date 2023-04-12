//
//  ImportParser.h
//  TUCUT
//
//  Created by Wahid Tanner on 10/12/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//
#ifndef TUCUT_Protocol_ImportParser_h
#define TUCUT_Protocol_ImportParser_h

#include "ParserInterface.h"

namespace TUCUT::Protocol
{
  class ImportParser : public ParserInterface
  {
  public:
    virtual bool parse (
      TokenReader::iterator current,
      TokenReader::iterator end,
      bool firstChance,
      std::shared_ptr<ProtoModel> model);
  };
} // namespace TUCUT::Protocol

#endif // TUCUT_Protocol_ImportParser_h
