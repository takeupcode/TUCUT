//
//  Identifiable.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 2/28/13.
//  Copyright © 2013 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Identity_Identifiable_h
#define TUCUT_Identity_Identifiable_h

#include <memory>
#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace TUCUT {
namespace Identity {
    
class Token
{
public:
    explicit Token (const std::string & token)
    : mToken(token)
    { }
    
    explicit Token (std::string && token)
    : mToken(std::move(token))
    { }
    
    Token (const Token & src)
    : mToken(src.mToken)
    { }
    
    Token (Token && src)
    : mToken(std::move(src.mToken))
    { }
    
    std::string token () const
    {
        return mToken;
    }
    
    std::string toString () const
    {
        return "(" + token() + ")";
    }
    
    bool operator == (const Token & rhs) const
    {
        return mToken == rhs.mToken;
    }
    
    bool operator != (const Token & rhs) const
    {
        return !operator==(rhs);
    }
    
private:
    Token & operator = (const Token &) = delete;
    Token & operator = (Token &&) = delete;
    
    std::string mToken;
};
    
template <typename T>
class IdToken : public Token
{
public:
    explicit IdToken (const std::string & token, T identity = 0)
    : Token(token),
    mId(identity)
    { }
    
    IdToken (const IdToken & src)
    : Token(src),
    mId(src.mId)
    { }
    
    IdToken (IdToken && src)
    : Token(std::move(src)),
    mId(src.mId)
    { }
    
    T identity () const
    {
        return mId;
    }
    
    std::string toString () const
    {
        return "(" + token() + ":" + std::to_string(mId) + ")";
    }
    
    bool operator == (const IdToken & rhs) const
    {
        return Token::operator==(rhs) && mId == rhs.mId;
    }
    
    bool operator != (const IdToken & rhs) const
    {
        return !operator==(rhs);
    }
    
private:
    IdToken & operator = (const IdToken &) = delete;
    IdToken & operator = (IdToken &&) = delete;
    
    T mId;
};

template <>
class IdToken<std::string> : public Token
{
public:
    explicit IdToken (const std::string & token)
    : Token(token),
    mId(boost::uuids::random_generator()())
    { }
    
    IdToken (const std::string & token, const std::string & identity)
    : Token(token),
    mId(boost::uuids::string_generator()(identity))
    { }
    
    IdToken (const IdToken & src)
    : Token(src),
    mId(src.mId)
    { }
    
    IdToken (IdToken && src)
    : Token(std::move(src)),
    mId(std::move(src.mId))
    { }
    
    std::string identity () const
    {
        return to_string(mId);
    }
    
    std::string toString () const
    {
        return "(" + token() + ":" + identity() + ")";
    }
    
    bool operator == (const IdToken & rhs) const
    {
        return Token::operator==(rhs) && mId == rhs.mId;
    }
    
    bool operator != (const IdToken & rhs) const
    {
        return !operator==(rhs);
    }
    
private:
    IdToken & operator = (const IdToken &) = delete;
    IdToken & operator = (IdToken &&) = delete;
    
    boost::uuids::uuid mId;
};

template <typename T>
class Identifiable
{
public:
    virtual ~Identifiable ()
    { }
    
    IdToken<T> idToken ()
    {
        return *mIdToken;
    }
    
    IdToken<T> & idToken () const
    {
        return *mIdToken;
    }

    std::string token () const
    {
        return mIdToken->token();
    }
    
    T identity () const
    {
        return mIdToken->identity();
    }

protected:
    Identifiable (const std::string & token, T identity = 0)
    : mIdToken(new IdToken<T>(token, identity))
    { }
    
    Identifiable (const IdToken<T> & idToken)
    : mIdToken(new IdToken<T>(idToken))
    { }
    
    Identifiable (const Identifiable & src)
    : mIdToken(new IdToken<T>(*src.mIdToken))
    { }
    
    Identifiable (Identifiable && src)
    : mIdToken(src.mIdToken.release())
    { }
    
    Identifiable & operator = (const Identifiable & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        mIdToken.reset(new IdToken(*rhs.mIdToken));
        
        return *this;
    }
    
    Identifiable & operator = (Identifiable && rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        mIdToken.reset(rhs.mIdToken.release());
        
        return *this;
    }
    
    void swap (Identifiable & other)
    {
        std::unique_ptr<IdToken<T>> thisIdToken(mIdToken.release());
        std::unique_ptr<IdToken<T>> otherIdToken(other.mIdToken.release());
        
        mIdToken.reset(otherIdToken.release());
        other.mIdToken.reset(thisIdToken.release());
    }
    
private:
    std::unique_ptr<IdToken<T>> mIdToken;
};

template <>
class Identifiable<std::string>
{
public:
    virtual ~Identifiable ()
    { }
    
    IdToken<std::string> idToken ()
    {
        return *mIdToken;
    }
    
    IdToken<std::string> & idToken () const
    {
        return *mIdToken;
    }

    std::string token () const
    {
        return mIdToken->token();
    }
    
    std::string identity () const
    {
        return mIdToken->identity();
    }
    
protected:
    Identifiable (const std::string & token, const std::string & identity)
    : mIdToken(new IdToken<std::string>(token, identity))
    { }
    
    Identifiable (const IdToken<std::string> & idToken)
    : mIdToken(new IdToken<std::string>(idToken))
    { }
    
    Identifiable (const Identifiable & src)
    : mIdToken(new IdToken<std::string>(*src.mIdToken))
    { }
    
    Identifiable (Identifiable && src)
    : mIdToken(src.mIdToken.release())
    { }
    
    Identifiable & operator = (const Identifiable & rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        mIdToken.reset(new IdToken(*rhs.mIdToken));
        
        return *this;
    }
    
    Identifiable & operator = (Identifiable && rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        mIdToken.reset(rhs.mIdToken.release());
        
        return *this;
    }
    
    void swap (Identifiable & other)
    {
        std::unique_ptr<IdToken<std::string>> thisIdToken(mIdToken.release());
        std::unique_ptr<IdToken<std::string>> otherIdToken(other.mIdToken.release());
        
        mIdToken.reset(otherIdToken.release());
        other.mIdToken.reset(thisIdToken.release());
    }
    
private:
    std::unique_ptr<IdToken<std::string>> mIdToken;
};

} // namespace Identity
} // namespace TUCUT

#endif // TUCUT_Identity_Identifiable_h




