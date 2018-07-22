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
        
class Identifiable
{
public:
    class IdToken
    {
    public:
        explicit IdToken (const std::string & token)
        : mToken(token),
        mId(boost::uuids::random_generator()())
        { }
        
        IdToken (const std::string & token, const std::string & identity)
        : mToken(token),
        mId(boost::uuids::string_generator()(identity))
        { }
        
        IdToken (const IdToken & src)
        : mToken(src.mToken),
        mId(src.mId)
        { }
        
        IdToken (IdToken && src)
        : mToken(std::move(src.mToken)),
        mId(std::move(src.mId))
        { }
        
        ~IdToken ()
        { }
        
        std::string token () const
        {
            return mToken;
        }
        
        std::string identity () const
        {
            return to_string(mId);
        }
        
        std::string toString () const
        {
            return "(" + mToken + ": " + to_string(mId) + ")";
        }
        
        bool operator == (const IdToken & rhs) const
        {
            return mToken == rhs.mToken && mId == rhs.mId;
        }
        
        bool operator != (const IdToken & rhs) const
        {
            return !operator==(rhs);
        }
        
        bool tokenEqual (const IdToken & other) const
        {
            return mToken == other.mToken;
        }
        
        bool tokenNotEqual (const IdToken & other) const
        {
            return mToken != other.mToken;
        }
        
        bool tokenLess (const IdToken & other) const
        {
            return mToken < other.mToken;
        }
        
        bool tokenGreater (const IdToken & other) const
        {
            return mToken > other.mToken;
        }
        
        bool tokenLessEqual (const IdToken & other) const
        {
            return mToken <= other.mToken;
        }
        
        bool tokenGreaterEqual (const IdToken & other) const
        {
            return mToken >= other.mToken;
        }
        
    private:
        IdToken & operator = (const IdToken &) = delete;
        IdToken & operator = (IdToken &&) = delete;
        
        std::string mToken;
        boost::uuids::uuid mId;
    };

    virtual ~Identifiable ()
    { }
    
    IdToken idToken () const
    {
        return *mIdToken;
    }
    
protected:
    Identifiable (const std::string & token)
    : mIdToken(new IdToken(token))
    { }
    
    Identifiable (const std::string & token, const std::string & identity)
    : mIdToken(new IdToken(token, identity))
    { }
    
    Identifiable (const IdToken & idToken)
    : mIdToken(new IdToken(idToken))
    { }
    
    Identifiable (const Identifiable & src)
    : mIdToken(new IdToken(*src.mIdToken))
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
        std::unique_ptr<IdToken> thisIdToken(mIdToken.release());
        std::unique_ptr<IdToken> otherIdToken(other.mIdToken.release());
        
        mIdToken.reset(otherIdToken.release());
        other.mIdToken.reset(thisIdToken.release());
    }
    
private:
    std::unique_ptr<IdToken> mIdToken;
};
    
} // namespace Identity
} // namespace TUCUT

#endif // TUCUT_Identity_Identifiable_h




