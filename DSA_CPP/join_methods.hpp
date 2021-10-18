#include <vector>
#include <numeric>
#include <string_view>

template<typename SeqIt>
inline std::string join( SeqIt first, SeqIt last, const std::string &sep )
{
    auto binaryJoinString = [sep]( std::string &a, std::string_view b ) -> std::string & {
        return a.append((a.empty()) ? "" : sep ).append( b );
    };
    return std::accumulate( first, last,
                            std::string(), binaryJoinString );
}

template<typename Container = std::vector<std::string >>
inline std::string join( const Container &container,
                         const std::string &sep )
{
    return join( container.cbegin(), container.cend(), sep );
}
