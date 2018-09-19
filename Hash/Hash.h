//
//  Hash.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/3/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Hash_Hash_h
#define TUCUT_Hash_Hash_h

#include <cstdint>
#include <type_traits>

namespace TUCUT {
namespace Hash {

template<int BitCount>
struct HashSize
{ };

template<>
struct HashSize<32>
{
    using HashValue = uint32_t;
};

template<>
struct HashSize<64>
{
    using HashValue = uint64_t;
};
    
template <int BitCount>
class HashGenerator
{
public:
    using HashValue = typename HashSize<BitCount>::HashValue;
    
    virtual ~HashGenerator () = default;
    
    virtual HashValue generate (const char * str, HashValue seed) const = 0;
    
    virtual HashValue generate (const char * data, std::size_t byteCount, HashValue seed) const = 0;

protected:
    HashGenerator () = default;
};

// The following comment applies to FNVHashGenerator32 and FNVHashGenerator64. The original
// code has been modified slightly but still follows the basic structure.
/*
 * Fowler/Noll/Vo hash
 *
 * The basis of this hash algorithm was taken from an idea sent
 * as reviewer comments to the IEEE POSIX P1003.2 committee by:
 *
 *      Phong Vo (http://www.research.att.com/info/kpv/)
 *      Glenn Fowler (http://www.research.att.com/~gsf/)
 *
 * In a subsequent ballot round:
 *
 *      Landon Curt Noll (http://www.isthe.com/chongo/)
 *
 * improved on their algorithm.  Some people tried this hash
 * and found that it worked rather well.  In an EMail message
 * to Landon, they named it the ``Fowler/Noll/Vo'' or FNV hash.
 *
 * FNV hashes are designed to be fast while maintaining a low
 * collision rate. The FNV speed allows one to quickly hash lots
 * of data while maintaining a reasonable collision rate.  See:
 *
 *      http://www.isthe.com/chongo/tech/comp/fnv/index.html
 *
 * for more details as well as other forms of the FNV hash.
 ***
 *
 * Please do not copyright this code.  This code is in the public domain.
 *
 * LANDON CURT NOLL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO
 * EVENT SHALL LANDON CURT NOLL BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
 * USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 * By:
 *    chongo <Landon Curt Noll> /\oo/\
 *      http://www.isthe.com/chongo/
 *
 * Share and Enjoy!    :-)
 */
    
class FNVHashGenerator32 : public HashGenerator<32>
{
public:
    using HashValue = typename HashGenerator<32>::HashValue;
    
    static constexpr HashValue prime = 16777619u;
    static constexpr HashValue offset = 2166136261u;

    FNVHashGenerator32 ()
    : HashGenerator()
    { }
    
    HashValue generate (const char * str, HashValue seed) const override
    {
        const unsigned char *bp = reinterpret_cast<const unsigned char *>(str);
        
        // The original code expected the offset to be passed in as the seed. This modification
        // allows the caller to specify a true seed that's independent from the offset.
        seed ^= offset;
        seed *= prime;

        // FNV-1a hash each octet in the buffer
        while (*bp)
        {
            // xor the bottom with the current octet
            seed ^= static_cast<HashValue>(*bp++);
            
            // multiply by the 32 bit FNV magic prime mod 2^32
            seed *= prime;
        }
        
        return seed;
    }
    
    HashValue generate (const char * data, std::size_t byteCount, HashValue seed) const override
    {
        const unsigned char *bp = reinterpret_cast<const unsigned char *>(data);
        const unsigned char *be = bp + byteCount;
        
        // The original code expected the offset to be passed in as the seed. This modification
        // allows the caller to specify a true seed that's independent from the offset.
        seed ^= offset;
        seed *= prime;
        
        // FNV-1a hash each octet in the buffer
        while (bp < be)
        {
            // xor the bottom with the current octet
            seed ^= static_cast<HashValue>(*bp++);
            
            // multiply by the 32 bit FNV magic prime mod 2^32
            seed *= prime;
        }
        
        return seed;
    }
};

class FNVHashGenerator64 : public HashGenerator<64>
{
public:
    using HashValue = typename HashGenerator<64>::HashValue;
    
    static constexpr HashValue prime = 1099511628211u;
    static constexpr HashValue offset = 14695981039346656037u;

    FNVHashGenerator64 ()
    : HashGenerator()
    { }
    
    HashValue generate (const char * str, HashValue seed) const override
    {
        const unsigned char *bp = reinterpret_cast<const unsigned char *>(str);

        // The original code expected the offset to be passed in as the seed. This modification
        // allows the caller to specify a true seed that's independent from the offset.
        seed ^= offset;
        seed *= prime;
        
        // FNV-1a hash each octet in the buffer
        while (*bp)
        {
            // xor the bottom with the current octet
            seed ^= static_cast<HashValue>(*bp++);
            
            // multiply by the 64 bit FNV magic prime mod 2^64
            seed *= prime;
        }
        
        return seed;
    }
    
    HashValue generate (const char * data, std::size_t byteCount, HashValue seed) const override
    {
        const unsigned char *bp = reinterpret_cast<const unsigned char *>(data);
        const unsigned char *be = bp + byteCount;
        
        // The original code expected the offset to be passed in as the seed. This modification
        // allows the caller to specify a true seed that's independent from the offset.
        seed ^= offset;
        seed *= prime;
        
        // FNV-1a hash each octet in the buffer
        while (bp < be)
        {
            // xor the bottom with the current octet
            seed ^= static_cast<HashValue>(*bp++);
            
            // multiply by the 64 bit FNV magic prime mod 2^64
            seed *= prime;
        }
        
        return seed;
    }
};

enum class HashAdapterStrategies
{
    XorFoldTiny,
    XorFold32,
    Native32,
    XorFold64,
    Native64
};

template<int BitCount, int Begin, int End, class Enable = void>
struct HashRange
{
};

template<int BitCount, int Begin, int End>
struct HashRange<BitCount, Begin, End, std::enable_if_t<BitCount >= Begin && BitCount < End>>
{
    using ValidRange = void;
};

template <int BitCount, class Enable = void>
struct HashAdapterStrategy
{ };

template <int BitCount>
struct HashAdapterStrategy<BitCount, typename HashRange<BitCount, 8, 16>::ValidRange>
{
    static constexpr int nativeSize = 32;
    static constexpr HashAdapterStrategies strategy = HashAdapterStrategies::XorFoldTiny;
};

template <int BitCount>
struct HashAdapterStrategy<BitCount, typename HashRange<BitCount, 16, 32>::ValidRange>
{
    static constexpr int nativeSize = 32;
    static constexpr HashAdapterStrategies strategy = HashAdapterStrategies::XorFold32;
};

template <int BitCount>
struct HashAdapterStrategy<BitCount, typename HashRange<BitCount, 32, 33>::ValidRange>
{
    static constexpr int nativeSize = 32;
    static constexpr HashAdapterStrategies strategy = HashAdapterStrategies::Native32;
};

template <int BitCount>
struct HashAdapterStrategy<BitCount, typename HashRange<BitCount, 33, 64>::ValidRange>
{
    static constexpr int nativeSize = 64;
    static constexpr HashAdapterStrategies strategy = HashAdapterStrategies::XorFold64;
};

template <int BitCount>
struct HashAdapterStrategy<BitCount, typename HashRange<BitCount, 64, 65>::ValidRange>
{
    static constexpr int nativeSize = 64;
    static constexpr HashAdapterStrategies strategy = HashAdapterStrategies::Native64;
};

template <int BitCount>
class HashAdapter
{
public:
    static constexpr int nativeSize = HashAdapterStrategy<BitCount>::nativeSize;
    static constexpr HashAdapterStrategies strategy = HashAdapterStrategy<BitCount>::strategy;
    using HashValue = typename HashSize<nativeSize>::HashValue;
    static constexpr HashValue mask = (static_cast<HashValue>(1) << BitCount) - 1;

    HashAdapter (const HashGenerator<nativeSize> & generator)
    : mGenerator(generator)
    { }
    
    virtual ~HashAdapter () = default;
    
    HashValue getHash (const char * str, HashValue seed) const
    {
        HashValue hash = mGenerator.generate(str, seed);
        
        fold(hash);
        
        return hash;
    }
    
    HashValue getHash (const std::string & str, HashValue seed) const
    {
        HashValue hash = mGenerator.generate(str.c_str(), str.length(), seed);
        
        fold(hash);
        
        return hash;
    }

    template <typename T>
    HashValue getHash (T value, HashValue seed) const
    {
        HashValue hash = mGenerator.generate(reinterpret_cast<const char *>(&value), sizeof(T), seed);
        
        fold(hash);
        
        return hash;
    }

    HashValue getHash (const char * data, std::size_t byteCount, HashValue seed) const
    {
        HashValue hash = mGenerator.generate(data, byteCount, seed);
        
        fold(hash);
        
        return hash;
    }

protected:
    void fold (HashValue & hash) const
    {
        switch (strategy)
        {
            case HashAdapterStrategies::XorFoldTiny:
                hash = ((hash >> BitCount) ^ hash) & mask;
                break;
                
            case HashAdapterStrategies::XorFold32:
            case HashAdapterStrategies::XorFold64:
                hash = (hash >> BitCount) ^ (hash & mask);
                break;
        }
    }
    
    const HashGenerator<nativeSize> & mGenerator;
};

} // namespace Hash
} // namespace TUCUT

#endif // TUCUT_Hash_Hash_h
