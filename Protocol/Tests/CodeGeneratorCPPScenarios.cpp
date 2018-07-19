//
//  CodeGeneratorCPPScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/18/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../CodeGeneratorManager.h"
#include "../ProtoParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create common base classes." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("Empty.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT", true);
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create empty file." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("Empty.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with empty message." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("Message.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with message and all fields." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageAllFields.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with enums." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("EnumMultiple.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with multiple enums." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();
    
    auto generator = pManager->generator("CPlusPlus");
    
    Protocol::ProtoParser parser("EnumMultipleMessage.proto");
    auto model = parser.parse();
    
    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with enum and values." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("EnumValue.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with imports, message, and enum." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("ImportPublic.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with message fields." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageField.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with nested messages." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageNested.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with oneof fields." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageOneof.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with nested message, fields, and oneof fields." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageOneofMultiple.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with package." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageNamespace.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with multiple enum packages." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("EnumMultiplePackage.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with multiple message packages." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageMultiplePackage.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

SCENARIO( CodeGeneratorCPP, "Operation/Normal", "unit", "CPP generator can create file with enum and message field types." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");

    Protocol::ProtoParser parser("MessageFieldReference.proto");
    auto model = parser.parse();

    generator->generateCode("Generated", model.get(), "TestTUCUT");
}

namespace A
{
    namespace B
    {
        // Every class starts by forward declaring each nested class with unique name.
        // Then the class itself gets forward declared.
        class M_N;
        class M_O;
        class M;

        // The nested enums don't need to be forward declared and come next.
        enum class M_D // Not sure why but the name M_E gives an error.
        {
            test = 0
        };

        class M_N_X;
        class M_N; // This forward declaration will get repeated but that is okay.

        // Nested classes are defined as if they are not nested. The name will follow this convention.
        class M_N_X
        {
        public:
            static int valueX ()
            {
                return 3;
            }
            M_O * pO; // Without this system, there would be no way to declare this pointer.
        };

        class M_N
        {
        public:
            typedef M_N_X X;

            static int valueN ()
            {
                return 1;
            }
            M_O * pO; // This pointer also could not have been declared because there is no way to forward declare M::O.
        };

        class M_O
        {
        public:
            static int valueO ()
            {
                return 2;
            }
            M_N * pN; // This pointer would have been fine previously because M::N would have been complete.
        };

        class M
        {
        public:
            typedef M_D D;
            typedef M_N N;
            typedef M_O O;
        };
    }
}

SCENARIO( CodeGeneratorCPP, "Structure/Nested", "unit", "Nested classes can declare pointers to each other." )
{
    // The consumer can still use the classes as if they were nested with their original names.
    verifyEqual(1, A::B::M::N::valueN());
    verifyEqual(2, A::B::M::O::valueO());
    verifyEqual(3, A::B::M::N::X::valueX());
}
