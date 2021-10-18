#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define _USE_MATH_DEFINES // for pi constant
using std::vector;
using std::cin;
using std::cout;
using std::copy;
using std::atan2;
using std::rotate;
#define pi M_PI

struct Point {
    double _x = 0, _y = 0;

    Point( double x, double y ) : _x( x ), _y( y ) {}

    Point() = default;

    bool operator<( const Point& other ) const {
        // Самая нижняя самая левая
        if (this->_y < other._y) {
            return true;
        } else if (this->_y == other._y and this->_x < other._x) {
            return true;
        } else {
            return false;
        }
    }

    Point operator+( const Point& other ) const {
        return {this->_x + other._x, this->_y + other._y};
    }
};

void read_polygon( vector<Point>& Pol, size_t len, int koef ) {
    for (int i = 0; i < len; ++i) {
        double x = 0, y = 0;
        cin >> x >> y;
        Pol.emplace_back( Point( x * koef, y * koef ));
    }
    reverse( Pol.begin(), Pol.end());
}

// Считает полярный угол
double angle( const Point& a, const Point& b ) {
    double temp = atan2((b._y - a._y), (b._x - a._x));
    return temp >= 0 ? temp : temp + 2 * pi;
}

void
find_min_points( const vector<Point>& V, const vector<Point>& W, const size_t n, const size_t m, size_t& V_min_index,
                 size_t& W_min_index ) {
    // Находим самую левую самую правую точку в каждом многоугольнике
    Point V_min = V[0];
    for (size_t k = 1; k < n; ++k) {
        if (V[k] < V_min) {
            V_min = V[k];
            V_min_index = k;
        }
    }

    Point W_min = W[0];
    for (size_t k = 1; k < m; ++k) {
        if (W[k] < W_min) {
            W_min = W[k];
            W_min_index = k;
        }
    }
}

vector<Point>
find_Minkowski_addition( const vector<Point>& V, const vector<Point>& W, const size_t n, const size_t m ) {
    size_t V_min_index = 0;
    size_t W_min_index = 0;

    find_min_points( V, W, n, m, V_min_index, W_min_index );

    vector<Point> local_V( V );
    rotate( local_V.begin(), local_V.begin() + V_min_index, local_V.end());

    vector<Point> local_W( W );
    rotate( local_W.begin(), local_W.begin() + W_min_index, local_W.end());

    int i = 0, j = 0;
    vector<Point> res;
    local_V.push_back( local_V[0] );
    local_V.push_back( local_V[1] );
    local_W.push_back( local_W[0] );
    local_W.push_back( local_W[1] );
    while (i <= n and j <= m) {
        Point temp_point = local_V[i] + local_W[j];
        res.push_back( temp_point );
        if (angle( local_V[i], local_V[i + 1] ) < angle( local_W[j], local_W[j + 1] )) {
            ++i;
        } else if (angle( local_V[i], local_V[i + 1] ) > angle( local_W[j], local_W[j + 1] )) {
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
    return res;
}

bool isCenterInside( const vector<Point>& Minkowski_add_get ) {
    vector<Point> Minkowski_add( Minkowski_add_get );
    Minkowski_add.push_back( Minkowski_add[0] );
    Minkowski_add.push_back( Minkowski_add[1] );
    for (int i = 0; i < Minkowski_add.size() - 2; ++i) {
        double product = Minkowski_add[i]._x * Minkowski_add[i + 1]._y - Minkowski_add[i + 1]._x * Minkowski_add[i]._y;
        if (product < 0) {
            return false;
        } else if (product == 0) {

            if (Minkowski_add[i]._x == Minkowski_add[i + 1]._x and
                Minkowski_add[i]._y == Minkowski_add[i + 1]._y) {
                continue;
            }
            return (Minkowski_add[i]._y * Minkowski_add[i + 1]._y < 0) or
                   ((Minkowski_add[i]._y == 0) and
                    (Minkowski_add[i + 1]._y == 0) and
                    (Minkowski_add[i]._x * Minkowski_add[i + 1]._x <= 0));
        }
    }
    return true;
}

int main() {
    size_t n = 0;
    cin >> n;
    vector<Point> V;
    read_polygon( V, n, -1 ); // Отражаем многоугольник относительно y=-x

    size_t m = 0;
    cin >> m;
    vector<Point> W;
    read_polygon( W, m, 1 );

    vector<Point> Minkowski_add = find_Minkowski_addition( V, W, n, m );

    cout << (isCenterInside( Minkowski_add ) ? "YES" : "NO");

    return 0;
}
