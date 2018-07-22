//
//  IdentifiableScenarios.cpp
//  TestTUCUT
//
//  Created by Wahid Tanner on 6/24/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../Identifiable.h"

using namespace std;
using namespace TUCUT;

SCENARIO( IdentifiableToken, "Construction/Normal", "unit,identity", "IdToken can be constructed with a token value." )
{
    std::string token = "test";
    Identity::Identifiable::IdToken idToken(token);
    
    VERIFY_EQUAL(token, idToken.token());
}

SCENARIO( IdentifiableToken, "Construction/Normal", "unit,identity", "IdToken can be constructed with token and id values." )
{
    std::string token = "test";
    std::string identity = "01234567-89ab-cdef-0123-456789abcdef";
    Identity::Identifiable::IdToken idToken(token, identity);
    
    VERIFY_EQUAL(token, idToken.token());
    VERIFY_EQUAL(identity, idToken.identity());
}
