#include <sstream>
#include <vector>

inline auto split( const std::string &s, char delim )
{
    std::stringstream ss( s );
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline( ss, token, delim ))
        tokens.push_back( token );
    return tokens;
}

inline auto split( const std::string &s )
{
    std::stringstream ss( s );
    std::vector<std::string> tokens;
    while (!ss.eof())
    {
        std::string i;
        ss >> i;
        tokens.emplace_back( i );
    }
    return tokens;
}

inline auto split( const std::string &s,
                   std::string delim )
{
    std::vector<std::string> tokens;
    size_t last = 0;
    size_t next = 0;
    while ((next = s.find( delim, last )) != std::string::npos)
    {
        tokens.push_back( s.substr( last, next - last ));
        last = next + 1;
    }
    last += delim.length() - 1;
    if ( last < s.length())
        tokens.push_back( s.substr( last, std::string::npos ));
    return tokens;
}