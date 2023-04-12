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

namespace TUCUT::Identity
{
  class Token
  {
  public:
    explicit Token (std::string const & token)
    : mToken(token)
    { }

    explicit Token (std::string && token)
    : mToken(std::move(token))
    { }

    Token (Token const & src)
    : mToken(src.mToken)
    { }

    Token (Token && src)
    : mToken(std::move(src.mToken))
    { }

    Token & operator = (Token const &) = delete;
    Token & operator = (Token &&) = delete;

    std::string token () const
    {
      return mToken;
    }

    std::string toString () const
    {
      return "(" + token() + ")";
    }

    bool operator == (Token const & rhs) const
    {
      return mToken == rhs.mToken;
    }

    bool operator != (Token const & rhs) const
    {
      return not operator==(rhs);
    }

  private:
    std::string mToken;
  };

  template <typename T>
  class IdToken : public Token
  {
  public:
    explicit IdToken (std::string const & token, T identity = 0)
    : Token(token),
      mId(identity)
    { }

    IdToken (IdToken const & src)
    : Token(src),
      mId(src.mId)
    { }

    IdToken (IdToken && src)
    : Token(std::move(src)),
      mId(std::move(src.mId))
    { }

    IdToken & operator = (IdToken const &) = delete;
    IdToken & operator = (IdToken &&) = delete;

    T identity () const
    {
      return mId;
    }

    std::string toString () const
    {
      return "(" + token() + ":" + std::to_string(mId) + ")";
    }

    bool operator == (IdToken const & rhs) const
    {
      return Token::operator==(rhs) && mId == rhs.mId;
    }

    bool operator != (IdToken const & rhs) const
    {
      return not operator==(rhs);
    }

  private:
    T mId;
  };

  template <>
  class IdToken<std::string> : public Token
  {
  public:
    explicit IdToken (std::string const & token,
      std::string const & identity = "")
    : Token(token),
      mId(identity)
    { }

    IdToken (IdToken const & src)
    : Token(src),
      mId(src.mId)
    { }

    IdToken (IdToken && src)
    : Token(std::move(src)),
      mId(std::move(src.mId))
    { }

    IdToken & operator = (IdToken const &) = delete;
    IdToken & operator = (IdToken &&) = delete;

    std::string identity () const
    {
      return mId;
    }

    std::string toString () const
    {
      return "(" + token() + ":" + mId + ")";
    }

    bool operator == (IdToken const & rhs) const
    {
      return Token::operator==(rhs) && mId == rhs.mId;
    }

    bool operator != (IdToken const & rhs) const
    {
      return not operator==(rhs);
    }

  private:
    std::string mId;
  };

  template <typename T>
  class Identifiable
  {
  public:
    virtual ~Identifiable () = default;

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
    Identifiable (std::string const & token, T identity)
    : mIdToken(new IdToken<T>(token, identity))
    { }

    Identifiable (IdToken<T> const & idToken)
    : mIdToken(new IdToken<T>(idToken))
    { }

    Identifiable (Identifiable const & src)
    : mIdToken(new IdToken<T>(*src.mIdToken))
    { }

    Identifiable (Identifiable && src)
    : mIdToken(src.mIdToken.release())
    { }

    Identifiable & operator = (Identifiable const & rhs)
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
      std::unique_ptr<IdToken<T>>
        thisIdToken(mIdToken.release());
      std::unique_ptr<IdToken<T>>
        otherIdToken(other.mIdToken.release());

      mIdToken.reset(otherIdToken.release());
      other.mIdToken.reset(thisIdToken.release());
    }

  private:
    std::unique_ptr<IdToken<T>> mIdToken;
  };
} // namespace TUCUT::Identity

#endif // TUCUT_Identity_Identifiable_h




