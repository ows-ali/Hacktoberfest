#include <iostream>
#include <random>
#include <set>

/**
 * @brief random_element
 * credits: http://stackoverflow.com/a/6943003
 * @param begin
 * @param end
 * @return
 */
template<typename I>
inline I randomElement( I begin, I end )
{
    using UInt = unsigned long;
    const UInt n = std::distance( begin, end );
    const UInt divisor = (UInt( RAND_MAX ) + 1) / n;

    unsigned long k;
    do
    { k = std::rand() / divisor; }
    while (k >= n);

    std::advance( begin, k );
    return begin;
}

template<typename I>
inline auto randomElementSampler( I begin, I end )
{
    static std::mt19937 rng( std::random_device{}());
    auto n = std::distance( begin, end );
    return [n, begin]() -> I {
        std::uniform_int_distribution<decltype( n )> dist{0, n - 1};
        return std::next( begin, dist( rng ));
    };
}

template<typename I>
inline auto randomIndexSampler( I begin, I end )
{
    static std::mt19937 rng( std::random_device{}());
    auto n = std::distance( begin, end );
    return [n, begin]() -> size_t {
        std::uniform_int_distribution<decltype( n )> dist{0, n - 1};
        return dist( rng );
    };
}

template<typename ContainerT>
inline std::pair<ContainerT, ContainerT>
subsetRandomSeparation( const ContainerT &items, float percentage )
{
    ContainerT subset;
    ContainerT rest;
    std::set<size_t> subsetIndices;

    size_t subsetSize = 0;
    auto sampler = randomIndexSampler( std::begin( items ), std::end( items ));
    while (static_cast< float >( subsetSize ) / items.size() < percentage)
    {
        auto p = subsetIndices.insert( sampler());
        subsetSize += p.second;
    }


    auto indicesIt = subsetIndices.cbegin();
    for (auto i = 0; i < items.size(); ++i)
    {
        if ( indicesIt != subsetIndices.cend() && i == *indicesIt )
        {
            subset.push_back( items.at( i ));
            ++indicesIt;
        } else
            rest.push_back( items.at( i ));
    }
    return std::make_pair( subset, rest );
}
