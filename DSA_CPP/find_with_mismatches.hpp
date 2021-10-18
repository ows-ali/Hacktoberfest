
#include <string>
#include <cassert>

inline auto
findWithMismatches( const std::string &str,
                    const std::string &substr,
                    unsigned int d )
{
    assert( substr.size() <= str.size() && substr.size() > d );
    auto cStr = str.data();
    auto cSubstr = substr.data();
    auto k = substr.size();

    auto occurance = [k, d, &cStr, &cSubstr]( std::string::size_type index ) {
        decltype( d ) mismatches = 0;
        decltype( index ) i = 0;
        while (mismatches <= d && i < k)
            mismatches += cStr[index + i] != cSubstr[i++];
        return mismatches <= d;
    };

    for (std::string::size_type i = 0, until = str.size() - substr.size() + 1;
         i < until; i++)
        if ( occurance( i ))
            return i;

    return std::string::npos;
}