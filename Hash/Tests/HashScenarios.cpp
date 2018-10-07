//
//  HashScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 9/17/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../Hash.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Hash, "Construction/Normal", "unit,hash", "Hash and adapter can be constructed." )
{
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<24> adapt24(fnvGen);
}

SCENARIO( Hash, "Construction/Normal", "unit,hash", "Hash and adapter can be constructed with seed." )
{
    Hash::FNVHashGenerator32 fnvGen32(12345);
    Hash::FNVHashGenerator64 fnvGen64(12345);
}

SCENARIO( Hash, "Operation/Normal", "unit,hash", "Hash adapter can return hash of string literal." )
{
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<24> adapt24(fnvGen);
    
    const char * str1 = "abc";
    typename Hash::HashAdapter<24>::HashValue hash1 = adapt24.getHash(str1, 3);
    typename Hash::HashAdapter<24>::HashValue hash2 = adapt24.getHash(str1);
    
    VERIFY_TRUE(hash1 == hash2);

    const char * str2 = "def";
    typename Hash::HashAdapter<24>::HashValue hash3 = adapt24.getHash(str2, 3);
    
    VERIFY_FALSE(hash1 == hash3);
}

SCENARIO( Hash, "Operation/Normal", "unit,hash", "Hash adapter can return hash of string." )
{
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<24> adapt24(fnvGen);
    
    std::string str1 = "abc";
    typename Hash::HashAdapter<24>::HashValue hash1 = adapt24.getHash(str1.c_str(), str1.length());
    typename Hash::HashAdapter<24>::HashValue hash2 = adapt24.getHash(str1);
    
    VERIFY_TRUE(hash1 == hash2);
    
    std::string str2 = "def";
    typename Hash::HashAdapter<24>::HashValue hash3 = adapt24.getHash(str2.c_str(), str2.length());
    
    VERIFY_FALSE(hash1 == hash3);
}

SCENARIO( Hash, "Operation/Normal", "unit,hash", "Hash adapter can return hash of int." )
{
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<24> adapt24(fnvGen);
    
    int value1 = 10;
    typename Hash::HashAdapter<24>::HashValue hash1 = adapt24.getHash(reinterpret_cast<char *>(&value1), 4);
    typename Hash::HashAdapter<24>::HashValue hash2 = adapt24.getHash(value1);
    
    VERIFY_TRUE(hash1 == hash2);
    
    int value2 = 20;
    typename Hash::HashAdapter<24>::HashValue hash3 = adapt24.getHash(reinterpret_cast<char *>(&value2), 4);
    
    VERIFY_FALSE(hash1 == hash3);
}

SCENARIO( Hash, "Operation/Normal", "unit,hash", "Hash generator can use seeds." )
{
    Hash::FNVHashGenerator32 fnvGen1(123);
    Hash::HashAdapter<24> adapt1(fnvGen1);
    Hash::FNVHashGenerator32 fnvGen2(123);
    Hash::HashAdapter<24> adapt2(fnvGen2);
    Hash::FNVHashGenerator32 fnvGen3(124);
    Hash::HashAdapter<24> adapt3(fnvGen3);

    int value = 10;
    typename Hash::HashAdapter<24>::HashValue hash1 = adapt1.getHash(value);
    typename Hash::HashAdapter<24>::HashValue hash2 = adapt2.getHash(value);

    VERIFY_TRUE(hash1 == hash2);
    
    typename Hash::HashAdapter<24>::HashValue hash3 = adapt3.getHash(value);
    
    VERIFY_FALSE(hash1 == hash3);
}
