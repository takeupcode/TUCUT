//
//  StringLiteral.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 8/2/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//
#ifndef TUCUT_Text_StringLiteral_h
#define TUCUT_Text_StringLiteral_h

namespace TUCUT::Text
{
  template <typename CharType>
  class StringLiteralBase
  {
  private:
    static constexpr size_t fnvPrime =
      (sizeof(size_t) == 8 ? 1099511628211u : 16777619u);
    static constexpr size_t fnvOffset =
      (sizeof(size_t) ==
      8 ? 14695981039346656037u : 2166136261u);

  public:
    constexpr size_t size () const
    {
      return mSize +
        ((mpPrevious != nullptr) ? mpPrevious->size() : 0);
    }

    constexpr CharType operator [] (size_t index) const
    {
      return (mpPrevious != nullptr) ?
        ((index >= mpPrevious->size()) ?
          charFromHere(index - mpPrevious->size()) :
          (*mpPrevious)[index]) :
        charFromHere(index);
    }

    constexpr size_t hash () const
    {
      return (size() != 0) ?
        hashRecursive(size() - 1, fnvOffset) :
        fnvOffset * fnvPrime;
    }

  protected:
    template <size_t Size>
    constexpr StringLiteralBase (
      CharType const (&string) [Size],
      StringLiteralBase<CharType> const * previous = nullptr)
    : mpString(string), mSize(Size - 1), mpPrevious(previous)
    { }

    constexpr StringLiteralBase (
      StringLiteralBase<CharType> const & src,
      StringLiteralBase<CharType> const * previous = nullptr)
    : mpString(src.mpString), mSize(src.mSize),
      mpPrevious(previous)
    { }

    constexpr CharType charFromHere (size_t index) const
    {
      return (index < mSize) ? mpString[index] : '\0';
    }

    constexpr size_t hashRecursive (
      size_t index, size_t currentHash) const
    {
      return (mpPrevious != nullptr) ?
        ((index >= mpPrevious->size()) ?
          (index != 0) ?
            hashRecursive(index - 1,
              (currentHash ^ mpString[
                index - mpPrevious->size()]) * fnvPrime) :
              (currentHash ^ mpString[index]) * fnvPrime :
          mpPrevious->hashRecursive(index, currentHash)) :
        (index != 0) ?
          hashRecursive(index - 1,
            (currentHash ^ mpString[index]) * fnvPrime) :
            (currentHash ^ mpString[index]) * fnvPrime;
    }

    CharType const * const mpString;
    size_t const mSize;
    StringLiteralBase<CharType> const * const mpPrevious;
  };

  class StringLiteral : public StringLiteralBase<char>
  {
  public:
    template <size_t Size>
    constexpr StringLiteral (
      char const (&string) [Size],
      StringLiteral const * previous = nullptr)
    : StringLiteralBase<char>::StringLiteralBase(
        string, previous)
    { }

    constexpr StringLiteral (
      StringLiteral const & src,
      StringLiteral const * previous = nullptr)
    : StringLiteralBase<char>::StringLiteralBase(src, previous)
    { }

    template <size_t Size>
    constexpr StringLiteral operator + (
      char const (&string) [Size]) const
    {
      return StringLiteral(string, this);
    }

    constexpr StringLiteral operator + (StringLiteral rhs) const
    {
      return StringLiteral(rhs, this);
    }
  };

  class WStringLiteral : public StringLiteralBase<wchar_t>
  {
  public:
    template <size_t Size>
    constexpr WStringLiteral (
      wchar_t const (&string) [Size],
      WStringLiteral const * previous = nullptr)
    : StringLiteralBase<wchar_t>::StringLiteralBase(
        string, previous)
    { }

    constexpr WStringLiteral (
      WStringLiteral const & src,
      WStringLiteral const * previous = nullptr)
    : StringLiteralBase<wchar_t>::StringLiteralBase(
        src, previous)
    { }

    template <size_t Size>
    constexpr WStringLiteral operator + (
      wchar_t const (&string) [Size]) const
    {
      return WStringLiteral(string, this);
    }

    constexpr WStringLiteral operator + (
      WStringLiteral const & rhs) const
    {
      return WStringLiteral(rhs, this);
    }
  };
} // namespace TUCUT::Text

#endif // TUCUT_Text_StringLiteral_h
