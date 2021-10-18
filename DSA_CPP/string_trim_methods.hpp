#include <vector>
#include <numeric>
#include <string_view>
#include <algorithm>

// trim from start (in place)
inline void ltrim( std::string &s )
{
    s.erase( s.begin(), std::find_if( s.begin(), s.end(), []( int ch ) {
        return !std::isspace( ch );
    } ));
}

// trim from end (in place)
inline void rtrim( std::string &s )
{
    s.erase( std::find_if( s.rbegin(), s.rend(), []( int ch ) {
        return !std::isspace( ch );
    } ).base(), s.end());
}

// trim from start (in place)
inline void ltrim( std::string &s, const std::string &trimmed )
{
    s.erase( s.begin(), std::find_if( s.begin(), s.end(), [trimmed]( int ch ) {
        return trimmed.find( ch ) == std::string::npos;
    } ));
}

// trim from end (in place)
inline void rtrim( std::string &s, const std::string &trimmed )
{
    s.erase( std::find_if( s.rbegin(), s.rend(), [trimmed]( int ch ) {
        return trimmed.find( ch ) == std::string::npos;
    } ).base(), s.end());
}

// trim from both ends (in place)
inline void trim( std::string &s )
{
    ltrim( s );
    rtrim( s );
}

// trim from start (copying)
inline std::string ltrim_copy( std::string s )
{
    ltrim( s );
    return s;
}

// trim from end (copying)
inline std::string rtrim_copy( std::string s )
{
    rtrim( s );
    return s;
}

// trim from both ends (copying)
inline std::string trim_copy( std::string s )
{
    trim( s );
    return s;
}

// trim from both ends (in place)
inline void trim( std::string &s, const std::string &trimmed )
{
    ltrim( s, trimmed );
    rtrim( s, trimmed );
}

// trim from start (copying)
inline std::string ltrim_copy( std::string s, const std::string &trimmed )
{
    ltrim( s, trimmed );
    return s;
}

// trim from end (copying)
inline std::string rtrim_copy( std::string s, const std::string &trimmed )
{
    rtrim( s, trimmed );
    return s;
}

// trim from both ends (copying)
inline std::string trim_copy( std::string s, const std::string &trimmed )
{
    trim( s, trimmed );
    return s;
}