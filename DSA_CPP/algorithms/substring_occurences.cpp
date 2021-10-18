/*Найдите все вхождения шаблона в строку. Длина шаблона – p, длина строки ­– n. Время O(n + p), доп. память – O(p).
-> Вариант 1. С помощью префикс-функции;
   Вариант 2. С помощью z-функции.
Формат входного файла
Шаблон, символ перевода строки, строка.
Формат выходного файла
Позиции вхождения шаблона в строке.
Время: 100мс, память 3Mb.*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

// Ищет префикс-функцию
vector<int> find_prefix_func( const string& str )
{
	size_t len = str.length();
	vector<int> prefix_func( len );
	for (size_t i = 1; i < len; i++) {
		size_t j = prefix_func[i - 1];
		while (j > 0 && str[i] != str[j]) {
			j = prefix_func[j - 1];
		}
		if (str[i] == str[j]) ++j;
		prefix_func[i] = j;
	}

	return prefix_func; 
}

inline int move_temp_str( const string& pattern, const vector<int>& prefix_func, const char symb, int pref ) {
	// pref - Предыдущее значение префикс-функции
	while (pref > 0 && symb != pattern[pref]) {
		pref = prefix_func[pref - 1];
	}
	if (symb == pattern[pref]) ++pref;
	int prefix_func_val = pref;

	return prefix_func_val;
}

int main() {
	std::ios::sync_with_stdio( false );
	string pattern;
	string str;
	cin >> pattern >> str;
	size_t p = pattern.length();
	size_t s = str.length();
	pattern = pattern + '#';
	vector<int> prefix_func = find_prefix_func( pattern );

	int prefix_func_val = 0; // значение от # равно 0
	int pos = 0;
	for (size_t pos = 0; pos < s; pos++) {
		char symb = str[pos];
		prefix_func_val = move_temp_str( pattern, prefix_func, symb, prefix_func_val );
		if (prefix_func_val == p) {
			cout << pos - p + 1 << '\n';
		}
	}

	return 0;
}
