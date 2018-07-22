//
//  StringLiteral.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Wahid Tanner on 8/2/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Text_StringLiteral_h
#define TUCUT_Text_StringLiteral_h

namespace TUCUT {
namespace Text {
        
template <typename CharType>
class StringLiteralBase
{
private:
    static constexpr std::size_t fnvPrime = (sizeof(std::size_t) == 8 ? 1099511628211u : 16777619u);
    static constexpr std::size_t fnvOffset = (sizeof(std::size_t) == 8 ? 14695981039346656037u : 2166136261u);

public:
    constexpr std::size_t size () const
    {
        return mSize + ((mpPrevious != nullptr) ? mpPrevious->size() : 0);
    }

    constexpr CharType operator [] (std::size_t index) const
    {
        return (mpPrevious != nullptr) ?
            ((index >= mpPrevious->size()) ?
                charFromHere(index - mpPrevious->size()) :
                (*mpPrevious)[index]) :
            charFromHere(index);
    }

    constexpr std::size_t hash () const
    {
        return (size() != 0) ?
            hashRecursive(size() - 1, fnvOffset) :
            fnvOffset * fnvPrime;
    }

protected:
    template <std::size_t Size>
    constexpr StringLiteralBase (const CharType (&string) [Size], const StringLiteralBase<CharType> * previous = nullptr)
    : mpString(string), mSize(Size - 1), mpPrevious(previous)
    { }

    constexpr StringLiteralBase (const StringLiteralBase<CharType> & src, const StringLiteralBase<CharType> * previous = nullptr)
    : mpString(src.mpString), mSize(src.mSize), mpPrevious(previous)
    { }

    constexpr CharType charFromHere (std::size_t index) const
    {
        return (index < mSize) ? mpString[index] : '\0';
    }

    constexpr std::size_t hashRecursive (std::size_t index, std::size_t currentHash) const
    {
        return (mpPrevious != nullptr) ?
            ((index >= mpPrevious->size()) ?
                (index != 0) ?
                    hashRecursive(index - 1, (currentHash ^ mpString[index - mpPrevious->size()]) * fnvPrime) :
                    (currentHash ^ mpString[index]) * fnvPrime :
                mpPrevious->hashRecursive(index, currentHash)) :
            (index != 0) ?
                hashRecursive(index - 1, (currentHash ^ mpString[index]) * fnvPrime) :
                (currentHash ^ mpString[index]) * fnvPrime;
    }

    const CharType * const mpString;
    const std::size_t mSize;
    const StringLiteralBase<CharType> * const mpPrevious;
};

class StringLiteral : public StringLiteralBase<char>
{
public:
    template <std::size_t Size>
    constexpr StringLiteral (const char (&string) [Size], const StringLiteral * previous = nullptr)
    : StringLiteralBase<char>::StringLiteralBase(string, previous)
    { }

    constexpr StringLiteral (const StringLiteral & src, const StringLiteral * previous = nullptr)
    : StringLiteralBase<char>::StringLiteralBase(src, previous)
    { }

    template <std::size_t Size>
    constexpr StringLiteral operator + (const char (&string) [Size]) const
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
    template <std::size_t Size>
    constexpr WStringLiteral (const wchar_t (&string) [Size], const WStringLiteral * previous = nullptr)
    : StringLiteralBase<wchar_t>::StringLiteralBase(string, previous)
    { }

    constexpr WStringLiteral (const WStringLiteral & src, const WStringLiteral * previous = nullptr)
    : StringLiteralBase<wchar_t>::StringLiteralBase(src, previous)
    { }

    template <std::size_t Size>
    constexpr WStringLiteral operator + (const wchar_t (&string) [Size]) const
    {
        return WStringLiteral(string, this);
    }

    constexpr WStringLiteral operator + (const WStringLiteral & rhs) const
    {
        return WStringLiteral(rhs, this);
    }
};

} // namespace Text
} // namespace TUCUT

#endif // TUCUT_Text_StringLiteral_h
