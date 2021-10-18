#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

#define alphabet_cardinality 150 // Мощность алфавита

class DiffStrCounter {
public:
    DiffStrCounter() {
        s;
        cin >> s;
        s += '#';
    }

    int find_count() {
        size_t len = s.length() - 1;
        auto sum = static_cast<int>(len * (len + 1));
        for (size_t i = 0; i <= len; ++i) {
            sum -= suffix_array[i];
        }
        for (size_t i = 0; i < len; ++i) {
            sum -= lcp[i];
        }
        return sum;
    }

    void build_suffix_array() {
        size_t len = s.length();
        vector<size_t> counter( alphabet_cardinality ); // Для стабильной сортировки подсчетом
        vector<int> perm( len ); // Массив перестановок в отсортированном виде
        vector<int> classes( len ); // Массив классов эквивалентности равных символов

        // База индукции - нулевая итерация алгоритма
        int count_classes = pocket_sort( len, counter, perm, classes, s );

        // Переход - от (k-1)й итерации к (k)й
        induction_transition( len, perm, count_classes, classes );

        this->suffix_array = perm;
    }

    // the_algorithm_of_Kasai_Arimura_Arikawa_Lee_Park
    void calc_LCP() {
        lcp.resize( s.length() );
        vector<int> inverted_suff_arr = invert_arr( suffix_array );
        int k = 0;

        for (int i = 0; i < s.length(); ++i) {
            // В последнем значение -1
            if (inverted_suff_arr[i] == s.length() - 1) {
                lcp[s.length() - 1] = -1;
                k = 0;
                continue;
            }

            if (k > 0) {
                --k;
            }

            int j = suffix_array[inverted_suff_arr[i] + 1];
            while (i + k < s.length() and j + k < s.length() and s[i + k] == s[j + k]) {
                ++k;
            }

            lcp[inverted_suff_arr[i]] = k;
        }
    }

private:
    string s;
    vector<int> suffix_array;
    vector<int> lcp;

    int
    pocket_sort( size_t len, vector<size_t>& counter, vector<int>& perm, vector<int>& classes, const string& s );


    void induction_transition( size_t len, vector<int>& perm,
                               int count_classes, vector<int>& classes );

    vector<int> invert_arr( const vector<int>& arr ) const {
        vector<int> inverted_arr( arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            inverted_arr[arr[i]] = i;
        }
        return inverted_arr;
    }
};

int DiffStrCounter::pocket_sort(
        const size_t len, vector<size_t>& counter, vector<int>& perm, vector<int>& classes, const string& s ) {
    int count_classes = 1;

    // Считаем количество одинаковых символов
    for (int i = 0; i < len; ++i) {
        ++counter[s[i]];
    }

    // Считаем границы классов эквивалентности одинаковых символов
    for (int i = 1; i < alphabet_cardinality; ++i) {
        counter[i] += counter[i - 1];
    }

    // В соответствии с классами заполняем массив
    for (int i = 0; i < len; ++i) {
        perm[--counter[s[i]]] = i;
    }

    classes[perm[0]] = 0;
    for (int i = 1; i < len; ++i) {
        if (s[perm[i]] != s[perm[i - 1]]) {
            ++count_classes;
        }
        classes[perm[i]] = count_classes - 1;
    }

    return count_classes;
}

void DiffStrCounter::induction_transition( const size_t len, vector<int>& perm,
                                           int count_classes, vector<int>& classes ) {
    vector<int> perm_new( len ); // Массив перестановок в отсортированном виде
    vector<int> classes_new( len ); // Массив классов эквивалентности равных символов
    // Переход - от (k-1)й итерации к (k)й
    int h = 0;// Итерация
    while ((1 << h) < len) {
        for (int i = 0; i < len; ++i) {
            perm_new[i] = perm[i] - (1 << h);
            if (perm_new[i] < 0) {
                perm_new[i] += len;
            }
        }

        vector<size_t> counter( count_classes );

        // Считаем количество одинаковых символов
        for (int i = 0; i < len; ++i) {
            ++counter[classes[perm_new[i]]];
        }

        // Считаем границы классов эквивалентности одинаковых символов
        for (int i = 1; i < count_classes; ++i) {
            counter[i] += counter[i - 1];
        }

        // В соответствии с классами заполняем массив
        for (auto i = (int) (len - 1); i >= 0; --i) {
            perm[--counter[classes[perm_new[i]]]] = perm_new[i];
        }

        classes_new[perm[0]] = 0;
        count_classes = 1;
        for (int i = 1; i < len; ++i) {
            if (classes[perm[i]] != classes[perm[i - 1]] or
                classes[(perm[i] + (1 << h)) % len] != classes[(perm[i - 1] + (1 << h)) % len]) {
                ++count_classes;
            }
            classes_new[perm[i]] = count_classes - 1;
        }
        ++h;
        perm_new = perm;
        classes = classes_new;
    }
}


int main() {
    DiffStrCounter counter;

    counter.build_suffix_array();

    counter.calc_LCP();

    cout << counter.find_count();

    return 0;
}
