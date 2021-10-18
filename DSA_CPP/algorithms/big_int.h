#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::cerr;

#define base 10
#define uint unsigned int

class BigInteger {
public:
    BigInteger() = default;

    ~BigInteger() = default;

    explicit BigInteger( const std::string& value );

    BigInteger( const int value ) : BigInteger( std::to_string( value )) {
    }

    BigInteger( const BigInteger& other );

    BigInteger& operator=( const BigInteger& value );

    BigInteger& operator=( BigInteger&& value ) = default;

    std::string toString() const;

    // Логика и порядок.
    bool operator==( const BigInteger& other ) const {
        return not(*this < other) and not(other < *this);
    }

    bool operator!=( const BigInteger& other ) const {
        return not(*this == other);
    }

    bool operator<( const BigInteger& other ) const;

    bool operator<=( const BigInteger& other ) const {
        return (*this < other) or (*this == other);
    }

    bool operator>( const BigInteger& other ) const {
        return not(*this < other) and not(*this == other);
    }

    bool operator>=( const BigInteger& other ) const {
        return (*this > other) or (*this == other);
    }

    // Унарный оператор
    BigInteger operator-() const;

    // pre/post increment/decrement
    BigInteger& operator++();

    BigInteger& operator--();

    BigInteger operator++( int );

    BigInteger operator--( int );

    // Бинарные операторы
    friend BigInteger operator+( const BigInteger& left, const BigInteger& right );

    friend BigInteger operator*( const BigInteger& left, const BigInteger& right );

    friend BigInteger operator-( const BigInteger& left, const BigInteger& right );

    friend BigInteger operator/( const BigInteger& left, const int& right );

    friend BigInteger operator/( const BigInteger& left, const BigInteger& right );

    friend BigInteger operator%( const BigInteger& left, const BigInteger& right );

    // Составные операторы
    BigInteger& operator+=( const BigInteger& other ) {
        *this = *this + other;
        return *this;
    }

    BigInteger& operator-=( const BigInteger& other ) {
        *this = *this - other;
        return *this;
    }

    BigInteger& operator*=( const BigInteger& other ) {
        *this = *this * other;
        return *this;
    }

    BigInteger& operator/=( const BigInteger& other ) {
        *this = *this / other;
        return *this;
    }

    BigInteger& operator%=( const BigInteger& other ) {
        *this = *this % other;
        return *this;
    }

    // Преобразование типов
    explicit operator bool() const {
        return !number.empty() && number.back() != 0;
    }

    // Ввод/вывод
    friend std::ostream& operator<<( std::ostream& stream, const BigInteger& value );

    friend std::istream& operator>>( std::istream& stream, BigInteger& value );

private:
    bool isNegative = false;
    vector<uint> number;
};

BigInteger::BigInteger( const string& value ) {

    isNegative = value[0] == '-';
    for (int i = value.size() - 1; i >= isNegative; --i) {
        number.emplace_back( value[i] - '0' );
    }
}

BigInteger::BigInteger( const BigInteger& other ) {
    number = other.number;
    isNegative = other.isNegative;
}

BigInteger& BigInteger::operator=( const BigInteger& value ) {
    this->number = value.number;
    this->isNegative = value.isNegative;
    return *this;
}

std::string BigInteger::toString() const {
    std::ostringstream stream;
    stream << *this;
    std::string str = stream.str();
    return str;
}

bool BigInteger::operator<( const BigInteger& other ) const {
    // Проверяем, что не -0
    if (this->isNegative and (this->number.empty() or (this->number.size() == 1 and this->number.back() == 0))) {
        if ((other.number.empty()) or (other.number.size() == 1 and other.number.back() == 0)) {
            return false;
        }
        if (other.isNegative) {
            return false;
        }
        if (not other.isNegative) {
            return true;
        }
    }
    if (this->isNegative and not other.isNegative) {
        return true;
    }
    if (this->number.size() < other.number.size()) {
        return true;
    } else if (this->number.size() > other.number.size()) {
        return false;
    }
    for (auto i = static_cast<int>(this->number.size()) - 1; i >= 0; --i) {
        if (this->number[i] < other.number[i]) {
            return true;
        } else if (this->number[i] > other.number[i]) {
            return false;
        }
    }
    return false;
}

BigInteger BigInteger::operator-() const {
    BigInteger res( *this );
    res.isNegative = not res.isNegative;
    return res;
}

BigInteger& BigInteger::operator++() {
    *this += 1;
    return *this;
}

BigInteger& BigInteger::operator--() {
    *this -= 1;
    return *this;
}

BigInteger BigInteger::operator++( int ) {
    BigInteger temp_object( *this );
    *this += 1;
    return temp_object;
}

BigInteger BigInteger::operator--( int ) {
    BigInteger temp_object( *this );
    *this -= 1;
    return temp_object;
}

BigInteger BigInteger::operator+( const BigInteger& left, const BigInteger& right ) {
    BigInteger local_left( left );
    BigInteger local_right( right );
    BigInteger zero( 0 );
    bool is_inverted = false;
    if (local_left < zero and local_right < zero) {
        local_left = -local_left;
        local_right = -local_right;
        is_inverted = true;
    } else if (local_right < zero) {
        return local_left - (-local_right);
    } else if (local_left < zero) {
        return local_right - (-local_left);
    }
    // Складывает два неотрицательных числа
    int carry = 0;
    size_t max_size = std::max( local_left.number.size(), local_right.number.size());
    for (size_t i = 0; i < max_size || carry; ++i) {
        if (i == local_left.number.size()) {
            local_left.number.push_back( 0 );
        }
        local_left.number[i] += carry;
        if (i < local_right.number.size()) {
            local_left.number[i] += local_right.number[i];
        }
        carry = local_left.number[i] >= base;
        if (carry) {
            local_left.number[i] -= base;
        }
    }
    if (is_inverted) {
        return -local_left;
    } else {
        return local_left;
    }
}

BigInteger BigInteger::operator*( const BigInteger& left, const BigInteger& right ) {
    BigInteger res;
    res.number.resize( left.number.size() + right.number.size());
    for (size_t i = 0; i < left.number.size(); ++i) {
        //int
        for (int j = 0, carry = 0; j < (int) right.number.size() || carry; ++j) {
            long long cur = res.number[i + j] + carry;
            if (j < (int) right.number.size()) {
                cur += left.number[i] * 1ll * right.number[j];
            }
            res.number[i + j] = int( cur % base );
            carry = static_cast<int>( cur / base );
        }
    }
    while (res.number.size() > 1 && res.number.back() == 0) {
        res.number.pop_back();
    }
    return ((left.isNegative xor right.isNegative) ? -res : res);
}

BigInteger BigInteger::operator-( const BigInteger& left, const BigInteger& right ) {
    BigInteger local_left( left );
    BigInteger local_right( right );
    BigInteger zero( 0 );
    bool is_inverted = false;
    if (local_left < zero and local_right < zero) {
        local_left = -local_left;
        local_right = -local_right;
        is_inverted = true;
    } else if (local_right < zero) {
        return local_left + (-local_right);
    } else if (local_left < zero) {
        return -(-local_left + local_right);
    }
    if (local_left < local_right) {
        BigInteger temp = local_left;
        local_left = local_right;
        local_right = temp;
        is_inverted = true;
    }

    // Вычитает два неотрицательных числа, left >= right
    int carry = 0;
    for (size_t i = 0; i < local_right.number.size() || carry; ++i) {
        int temp_number_i = local_left.number[i];
        temp_number_i -= carry;
        if (i < local_right.number.size()) {
            temp_number_i -= local_right.number[i];
        }
        carry = temp_number_i < 0;
        if (carry) {
            temp_number_i += base;
        }
        local_left.number[i] = static_cast<uint>(temp_number_i);
    }
    // Удаляем лишние 0
    while (local_left.number.size() > 1 && local_left.number.back() == 0) {
        local_left.number.pop_back();
    }

    if (is_inverted) {
        return -local_left;
    } else {
        return local_left;
    }
}

BigInteger BigInteger::operator/( const BigInteger& left, const int& right ) {
    BigInteger local_left( left );
    uint carry = 0;
    auto size = static_cast<int>(local_left.number.size());
    for (int i = size - 1; i >= 0; --i) {
        uint cur = local_left.number[i] + carry * base;
        local_left.number[i] = cur / right;
        carry = cur % right;
    }
    while (local_left.number.size() > 1 && local_left.number.back() == 0) {
        local_left.number.pop_back();
    }
    return local_left * (right < 0 ? -1 : 1);
}

BigInteger BigInteger::operator/( const BigInteger& left, const BigInteger& right ) {
    if(right==2){
        return left/2;
    }
    bool sign_is_negative = (left.isNegative) ^(right.isNegative);
    BigInteger local_left( left );
    local_left.isNegative = false;
    BigInteger local_right( right );
    local_right.isNegative = false;
    if (local_left < local_right) {
        return BigInteger( 0 );
    }
    if (local_left == local_right) {
        return BigInteger( 1 )*(sign_is_negative ? -1 : 1);
    }
    BigInteger top = local_left / 2;
    BigInteger bottom( 0 );
    while (top > bottom) {
        BigInteger middle = (top + bottom) / 2;
        BigInteger multiply = middle * local_right;
        if (multiply < local_left) {
            if ((middle + 1) * local_right > local_left) {
                while (middle.number.size() > 1 && middle.number.back() == 0) {
                    middle.number.pop_back();
                }
                return middle * (sign_is_negative ? -1 : 1);
            }
            bottom = middle;
        } else if (multiply > local_left) {
            top = middle;
        } else {
            while (middle.number.size() > 1 && middle.number.back() == 0) {
                middle.number.pop_back();
            }
            return middle * (sign_is_negative ? -1 : 1);
        }
    }
    while (bottom.number.size() > 1 && bottom.number.back() == 0) {
        bottom.number.pop_back();
    }
    return bottom * (sign_is_negative ? -1 : 1);
}

BigInteger BigInteger::operator%( const BigInteger& left, const BigInteger& right ) {
    BigInteger division_res = left / right;
    return left - (division_res * right);
}

std::ostream& BigInteger::operator<<( std::ostream& stream, const BigInteger& value ) {
    if (value.isNegative) {
        if (not(value.number.empty() or (value.number.size() == 1 and value.number.back() == 0))) {
            stream << "-";
        }
    }
    stream << (value.number.empty() ? 0 : value.number.back());
    for (int i = static_cast<int>(value.number.size()) - 2; i >= 0; --i) {
        if (value.number[i] == 0) {
            stream << "0";
        } else {
            stream << value.number[i];
        }
    }
    return stream;
}

std::istream& BigInteger::operator>>( std::istream& stream, BigInteger& value ) {
    string temp_str;
    stream >> temp_str;
    value = BigInteger( temp_str );
    return stream;
}
