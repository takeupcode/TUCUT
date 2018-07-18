//
//  TokenReader.h
//  TUCUT
//
//  Created by Wahid Tanner on 9/11/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Protocol_TokenReader_h
#define TUCUT_Protocol_TokenReader_h

#include <fstream>
#include <memory>
#include <string>

namespace TUCUT {
namespace Protocol {
        
class TokenReader
{
private:
    struct TokenReaderData
    {
        TokenReaderData (std::ifstream * protoStream);

        void reset ();
        
        // All begin iterators share this data;
        bool mEnd;
        bool mStringMode;
        char mDelimiter;
        int mLine;
        int mCurrentTokenLine;
        int mColumn;
        int mCurrentTokenColumn;
        std::string mCurrentToken;
        std::unique_ptr<std::ifstream> mProtoStream;
    };

public:
    class TokenIterator
    {
    private:
        static const std::string Whitespace;
        static const std::string Delimiters;

    public:
        TokenIterator (); // Constructs an end iterator.
        TokenIterator (const TokenIterator & src);

        TokenIterator & operator = (const TokenIterator & rhs);

        bool operator == (const TokenIterator & rhs) const;
        bool operator != (const TokenIterator & rhs) const;

        TokenIterator & operator ++ ();

        std::string operator * () const;
        const std::string * operator -> () const;

        int line () const;
        int column () const;

    private:
        friend class TokenReader;
        
        TokenIterator (TokenReaderData * pData); // Constructs a begin iterator.

        void moveNext ();

        bool atEnd () const;

        TokenIterator operator ++ (int) = delete; // We don't support this.

        TokenReaderData * mpData;
    };

    typedef TokenIterator iterator;

    TokenReader (const std::string & protoFileName);
    ~TokenReader ();

    iterator begin ();
    iterator end ();

private:
    std::unique_ptr<TokenReaderData> mData;
};

} // namespace Protocol
} // namespace TUCUT

#endif // TUCUT_Protocol_TokenReader_h
