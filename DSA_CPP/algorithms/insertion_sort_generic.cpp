#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<class Iter, class Pred = std::less<> >
void insertionSort(Iter first, Iter last, Pred pred = Pred())
{
    for (auto i = first; i != last; i = std::next(i)) {
        std::rotate(std::upper_bound(first, i, *i, pred), i, std::next(i));
    }
}

template<class Container, class Pred = std::less<>>
Container& insertionSort(Container&& cont, Pred pred = Pred())
{
    insertionSort(std::begin(cont), std::end(cont), std::forward<Pred>(pred));
    return cont;
}

template<class T, class A>
struct vector_printer
{
    std::ostream& operator()(std::ostream& os) const {
        const char* sep = "";
        const char* pre_brace = "";
        os << "[";
        for (auto&& e : vec_) {
            os << sep << e;
            sep = ", ";
            pre_brace = " ";
        }
        return os << pre_brace << "]";
    }

    const std::vector<T, A>& vec_;
};
template<class T, class A>
decltype(auto) operator<<(std::ostream& os, vector_printer<T, A> const& p)
{
    return p(os);
}

template<class T, class A>
auto print(std::vector<T, A> const& v)
{
    return vector_printer<T, A> { v };
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::vector<int> v {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // Print the vector before sorting.
    std::cout << print(v) << std::endl;
    // Sort

    // Print the vector after sorting.
    std::cout << print(insertionSort(v)) << std::endl;

    // ascending order
    std::cout << print(insertionSort(v, std::greater<>())) << std::endl;

    // sort now works on any container:

    std::cout << insertionSort(std::string("ZXCVBNMASDFGHJKLQWERTYUIOP")) << std::endl;
    return 0;
}
