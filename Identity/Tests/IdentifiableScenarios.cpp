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
    Identity::IdToken<int> idToken1(token);
    
    VERIFY_EQUAL(token, idToken1.token());
}

SCENARIO( IdentifiableToken, "Construction/Normal", "unit,identity", "IdToken can be constructed with token and id values." )
{
    std::string token = "test";
    
    int intId = 2;
    Identity::IdToken<int> idToken1(token, intId);
    
    VERIFY_EQUAL(token, idToken1.token());
    VERIFY_EQUAL(intId, idToken1.identity());

    std::string guidId = "01234567-89ab-cdef-0123-456789abcdef";
    Identity::IdToken<std::string> idToken2(token, guidId);
    
    VERIFY_EQUAL(token, idToken2.token());
    VERIFY_EQUAL(guidId, idToken2.identity());
}
