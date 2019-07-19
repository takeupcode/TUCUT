//
//  TokenReaderScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/13/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../TokenReader.h"

using namespace std;
using namespace TUCUT;

SCENARIO( TokenReader, "Construction/Normal", "unit,protocol", "TokenReader can open proto file." )
{
    Protocol::TokenReader reader1("Messages/Empty.proto");
    Protocol::TokenReader reader2("Messages/Message.proto");
}

SCENARIO( TokenReader, "Construction/NotFound", "unit,protocol", "TokenReader cannot open nonexisting proto file." )
{
    bool expectedExceptionThrown = false;
    try
    {
        Protocol::TokenReader reader("Messages/NotFound.proto");
    }
    catch (const std::runtime_error &)
    {
        expectedExceptionThrown = true;
    }

    VERIFY_TRUE(expectedExceptionThrown);
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty proto." )
{
    Protocol::TokenReader reader("Messages/Empty.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty proto with single-line comment." )
{
    Protocol::TokenReader reader("Messages/EmptyCommentSingleLine.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate empty proto with single-line comment with no line feed." )
{
    Protocol::TokenReader reader("Messages/EmptyCommentSingleLineEOF.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(62, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty proto with multi-line comment." )
{
    Protocol::TokenReader reader("Messages/EmptyCommentMultiLine.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(7, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate empty proto with multi-line comment with no end." )
{
    Protocol::TokenReader reader("Messages/EmptyCommentMultiLineEOF.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty proto with many comments." )
{
    Protocol::TokenReader reader("Messages/EmptyComment.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(12, iter1.line());
    VERIFY_EQUAL(3, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text." )
{
    Protocol::TokenReader reader("Messages/Text.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Just", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("some", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(6, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(11, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("on", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("a", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(19, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("single", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("line", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(32, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(33, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text with a single-line comment." )
{
    Protocol::TokenReader reader("Messages/TextCommentSingleLine.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate random text with a single-line comment with no line feed." )
{
    Protocol::TokenReader reader("Messages/TextCommentSingleLineEOF.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(32, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text with a multi-line comment." )
{
    Protocol::TokenReader reader("Messages/TextCommentMultiLine.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(3, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate random text with a multi-line comment with no end." )
{
    Protocol::TokenReader reader("Messages/TextCommentMultiLineEOF.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(4, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text with adjacent comments." )
{
    Protocol::TokenReader reader("Messages/TextCommentNoSpace.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("more", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text with a string." )
{
    Protocol::TokenReader reader("Messages/TextString.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(6, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("With /* a */ \\\"string\\\" // that looks like a comment.", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(7, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(60, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(61, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text with multiple delimiters." )
{
    Protocol::TokenReader reader("Messages/TextDelimiterMultiple.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(2, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(6, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(7, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("[", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(8, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("]", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("(", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(10, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(")", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(11, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(12, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(13, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(",", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(15, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(16, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate an empty string." )
{
    Protocol::TokenReader reader("Messages/TextStringEmpty.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(2, iter1.column()); // The text (empty) and the end quote are both found on the same column.

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(2, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(3, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate random text with an unterminated string." )
{
    Protocol::TokenReader reader("Messages/TextStringEOF.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(6, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("With an unterminated string.", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(7, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(35, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate random text with a string on multiple lines." )
{
    Protocol::TokenReader reader("Messages/TextStringMultiLine.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(6, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("With a string on", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(7, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("multiple", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("lines", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(10, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(15, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(43, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate random text with unterminated strings ending with escape." )
{
    Protocol::TokenReader reader("Messages/TextStringEndingEscape.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("unterminated string with \\", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(2, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("another at the end \\", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(2, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(22, iter1.column());
}

SCENARIO( TokenReader, "Iteration/EOF", "unit,protocol", "TokenReader can iterate random text with unterminated strings at end of line and file." )
{
    // The empty token after the first quote is needed to differentiate
    // this scenario from a legitimate "text"
    Protocol::TokenReader reader("Messages/TextStringEndingQuote.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(2, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(2, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate random text with whitespace." )
{
    Protocol::TokenReader reader("Messages/TextWhitespace.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Just", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(3, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("some", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(12, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("text", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("on", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(10, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("various", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(19, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("lines", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(27, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(32, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(7, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty message." )
{
    Protocol::TokenReader reader("Messages/Message.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("empty", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(2, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty message with whitespace." )
{
    Protocol::TokenReader reader("Messages/MessageWhitespace.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(3, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("empty", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(15, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(6, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(9, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate empty message with comments." )
{
    Protocol::TokenReader reader("Messages/MessageComment.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("empty", *iter1);
    VERIFY_EQUAL(2, iter1.line());
    VERIFY_EQUAL(50, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(4, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(5, iter1.line());
    VERIFY_EQUAL(3, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(5, iter1.line());
    VERIFY_EQUAL(6, iter1.column());
}

SCENARIO( TokenReader, "Iteration/Normal", "unit,protocol", "TokenReader can iterate full message." )
{
    Protocol::TokenReader reader("Messages/MessageEverything.proto");
    auto iter1 = reader.begin();
    auto iter2 = reader.end();

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("import", *iter1);
    VERIFY_EQUAL("", *iter2);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("public", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(8, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(15, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("MessageNamespace.proto", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("\"", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(38, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(1, iter1.line());
    VERIFY_EQUAL(39, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("package", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Uv", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(11, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("W", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(12, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(13, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Xyz", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(3, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL(5, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M1", *iter1);
    VERIFY_EQUAL(5, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(6, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("oneof", *iter1);
    VERIFY_EQUAL(7, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("choices", *iter1);
    VERIFY_EQUAL(7, iter1.line());
    VERIFY_EQUAL(11, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(8, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("string", *iter1);
    VERIFY_EQUAL(9, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("str", *iter1);
    VERIFY_EQUAL(9, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(9, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(9, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(9, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("bool", *iter1);
    VERIFY_EQUAL(10, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("b", *iter1);
    VERIFY_EQUAL(10, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(10, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("200", *iter1);
    VERIFY_EQUAL(10, iter1.line());
    VERIFY_EQUAL(18, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(10, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(11, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(12, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("package", *iter1);
    VERIFY_EQUAL(14, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Uv", *iter1);
    VERIFY_EQUAL(14, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(14, iter1.line());
    VERIFY_EQUAL(11, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL(16, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M2", *iter1);
    VERIFY_EQUAL(16, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(17, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL(18, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M3", *iter1);
    VERIFY_EQUAL(18, iter1.line());
    VERIFY_EQUAL(13, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(19, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("required", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Abc", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(18, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Def", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Simple", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("s", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(33, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(35, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(37, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(20, iter1.line());
    VERIFY_EQUAL(38, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(21, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("enum", *iter1);
    VERIFY_EQUAL(23, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("E1", *iter1);
    VERIFY_EQUAL(23, iter1.line());
    VERIFY_EQUAL(10, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(24, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("option", *iter1);
    VERIFY_EQUAL(25, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("allow_alias", *iter1);
    VERIFY_EQUAL(25, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(25, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("true", *iter1);
    VERIFY_EQUAL(25, iter1.line());
    VERIFY_EQUAL(30, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(25, iter1.line());
    VERIFY_EQUAL(34, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("None", *iter1);
    VERIFY_EQUAL(26, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(26, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("0", *iter1);
    VERIFY_EQUAL(26, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(26, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("All", *iter1);
    VERIFY_EQUAL(27, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(27, iter1.line());
    VERIFY_EQUAL(13, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(27, iter1.line());
    VERIFY_EQUAL(15, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(27, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Everything", *iter1);
    VERIFY_EQUAL(28, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(28, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(28, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(28, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(29, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("required", *iter1);
    VERIFY_EQUAL(39, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M1", *iter1);
    VERIFY_EQUAL(39, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("msg1", *iter1);
    VERIFY_EQUAL(39, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(39, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(39, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(39, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(40, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M3", *iter1);
    VERIFY_EQUAL(40, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("msg3", *iter1);
    VERIFY_EQUAL(40, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(40, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("2", *iter1);
    VERIFY_EQUAL(40, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(40, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("E1", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("e1", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("3", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("[", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("default", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(33, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("None", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(35, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("]", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(39, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(41, iter1.line());
    VERIFY_EQUAL(40, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("double", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("d1", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("4", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("[", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("default", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(37, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("3", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(39, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(40, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("14", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(41, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("]", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(43, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(42, iter1.line());
    VERIFY_EQUAL(44, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(43, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("float", *iter1);
    VERIFY_EQUAL(43, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("f1", *iter1);
    VERIFY_EQUAL(43, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(43, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("5", *iter1);
    VERIFY_EQUAL(43, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(43, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("repeated", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("int32", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("i1", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("6", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("[", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(27, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("packed", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(35, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("true", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(37, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("]", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(41, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(44, iter1.line());
    VERIFY_EQUAL(42, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(45, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("int64", *iter1);
    VERIFY_EQUAL(45, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("i64", *iter1);
    VERIFY_EQUAL(45, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(45, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("7", *iter1);
    VERIFY_EQUAL(45, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(45, iter1.line());
    VERIFY_EQUAL(27, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(46, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("uint32", *iter1);
    VERIFY_EQUAL(46, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("ui32", *iter1);
    VERIFY_EQUAL(46, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(46, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("8", *iter1);
    VERIFY_EQUAL(46, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(46, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(47, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("uint64", *iter1);
    VERIFY_EQUAL(47, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("ui64", *iter1);
    VERIFY_EQUAL(47, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(47, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("9", *iter1);
    VERIFY_EQUAL(47, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(47, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(48, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("sint32", *iter1);
    VERIFY_EQUAL(48, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("si32", *iter1);
    VERIFY_EQUAL(48, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(48, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("10", *iter1);
    VERIFY_EQUAL(48, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(48, iter1.line());
    VERIFY_EQUAL(30, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(49, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("sint64", *iter1);
    VERIFY_EQUAL(49, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("si64", *iter1);
    VERIFY_EQUAL(49, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(49, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("11", *iter1);
    VERIFY_EQUAL(49, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(49, iter1.line());
    VERIFY_EQUAL(30, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(50, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("fixed32", *iter1);
    VERIFY_EQUAL(50, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("fx32", *iter1);
    VERIFY_EQUAL(50, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(50, iter1.line());
    VERIFY_EQUAL(27, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("12", *iter1);
    VERIFY_EQUAL(50, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(50, iter1.line());
    VERIFY_EQUAL(31, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(51, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("fixed64", *iter1);
    VERIFY_EQUAL(51, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("fx64", *iter1);
    VERIFY_EQUAL(51, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(51, iter1.line());
    VERIFY_EQUAL(27, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("13", *iter1);
    VERIFY_EQUAL(51, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(51, iter1.line());
    VERIFY_EQUAL(31, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(52, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("sfixed32", *iter1);
    VERIFY_EQUAL(52, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("sfx32", *iter1);
    VERIFY_EQUAL(52, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(52, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("14", *iter1);
    VERIFY_EQUAL(52, iter1.line());
    VERIFY_EQUAL(31, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(52, iter1.line());
    VERIFY_EQUAL(33, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(53, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("sfixed64", *iter1);
    VERIFY_EQUAL(53, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("sfx64", *iter1);
    VERIFY_EQUAL(53, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(53, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("15", *iter1);
    VERIFY_EQUAL(53, iter1.line());
    VERIFY_EQUAL(31, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(53, iter1.line());
    VERIFY_EQUAL(33, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(54, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("bool", *iter1);
    VERIFY_EQUAL(54, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("b", *iter1);
    VERIFY_EQUAL(54, iter1.line());
    VERIFY_EQUAL(19, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(54, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("16", *iter1);
    VERIFY_EQUAL(54, iter1.line());
    VERIFY_EQUAL(23, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(54, iter1.line());
    VERIFY_EQUAL(25, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("required", *iter1);
    VERIFY_EQUAL(55, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("string", *iter1);
    VERIFY_EQUAL(55, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("str1", *iter1);
    VERIFY_EQUAL(55, iter1.line());
    VERIFY_EQUAL(21, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(55, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("17", *iter1);
    VERIFY_EQUAL(55, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(55, iter1.line());
    VERIFY_EQUAL(30, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(56, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("bytes", *iter1);
    VERIFY_EQUAL(56, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("bts", *iter1);
    VERIFY_EQUAL(56, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(56, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("18", *iter1);
    VERIFY_EQUAL(56, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(56, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("optional", *iter1);
    VERIFY_EQUAL(57, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("E3", *iter1);
    VERIFY_EQUAL(57, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("e3", *iter1);
    VERIFY_EQUAL(57, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(57, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("19", *iter1);
    VERIFY_EQUAL(57, iter1.line());
    VERIFY_EQUAL(22, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(57, iter1.line());
    VERIFY_EQUAL(24, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(58, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("enum", *iter1);
    VERIFY_EQUAL(60, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("E3", *iter1);
    VERIFY_EQUAL(60, iter1.line());
    VERIFY_EQUAL(6, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(61, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Good", *iter1);
    VERIFY_EQUAL(62, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(62, iter1.line());
    VERIFY_EQUAL(10, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("0", *iter1);
    VERIFY_EQUAL(62, iter1.line());
    VERIFY_EQUAL(12, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(62, iter1.line());
    VERIFY_EQUAL(13, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("Better", *iter1);
    VERIFY_EQUAL(63, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(63, iter1.line());
    VERIFY_EQUAL(12, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(63, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(63, iter1.line());
    VERIFY_EQUAL(15, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(64, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("message", *iter1);
    VERIFY_EQUAL(66, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M4", *iter1);
    VERIFY_EQUAL(66, iter1.line());
    VERIFY_EQUAL(9, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("{", *iter1);
    VERIFY_EQUAL(67, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("repeated", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(5, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M2", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(14, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(".", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(16, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("M3", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(17, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("msg23", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(20, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("=", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(26, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("1", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(28, iter1.column());

    ++iter1;

    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL(";", *iter1);
    VERIFY_EQUAL(68, iter1.line());
    VERIFY_EQUAL(29, iter1.column());

    ++iter1;
    
    VERIFY_TRUE(iter1 != iter2);
    VERIFY_EQUAL("}", *iter1);
    VERIFY_EQUAL(69, iter1.line());
    VERIFY_EQUAL(1, iter1.column());

    ++iter1;

    VERIFY_FALSE(iter1 != iter2);
    VERIFY_EQUAL("", *iter1);
    VERIFY_EQUAL(70, iter1.line());
    VERIFY_EQUAL(1, iter1.column());
}
