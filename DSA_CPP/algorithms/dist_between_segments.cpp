/*
 * Даны два отрезка в пространстве (x1, y1, z1) - (x2, y2, z2) и (x3, y3, z3) - (x4, y4, z4).
 * Найдите расстояние между отрезками.
*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <assert.h>

using std::cin;
using std::cout;
using std::setprecision;


#define eps (double)1e-11

struct Point {
    double x = 0, y = 0, z = 0;

    Point( double _x, double _y, double _z ) : x( _x ), y( _y ), z( _z ) {}

    Point() = default;
};

struct Vector {
    double x = 0;
    double y = 0;
    double z = 0;

    Vector( double _x, double _y, double _z ) : x( _x ), y( _y ), z( _z ) {}

    Vector( const Point& start, const Point& finish ) : x( finish.x - start.x ), y( finish.y - start.y ),
                                                        z( finish.z - start.z ) {}

    Vector operator+( const Vector& other ) {
        return {this->x + other.x, this->y + other.y, this->z + other.z};
    }

    Vector operator*( double c ) {
        return {this->x * c, this->y * c, this->z * c};
    }

    double scalar_product( const Vector& u ) const {
        const Vector v = *this;
        return ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z);

    }

    double vector_product( const Vector& v ) const {
        const Vector u = *this;
        return u.norm() * v.norm() - u.scalar_product( v ) * u.scalar_product( v );
    }

    double norm() const {
        return this->scalar_product( *this );
    }
};

void dist_between_lines( const Vector& u, const Vector& v, const Vector& w, double& s_closest, double& t_closest ) {
    // Если прямые параллельны
    if (u.vector_product( v ) < eps) {
        s_closest = 0.0;
        t_closest = v.scalar_product( w ) / v.norm();
    } else {
        s_closest = (u.scalar_product( v ) * v.scalar_product( w ) - v.norm() * u.scalar_product( w )) /
                    (u.vector_product( v ));
        t_closest = (u.norm() * v.scalar_product( w ) - u.scalar_product( v ) * u.scalar_product( w )) /
                    (u.vector_product( v ));
    }
}

double dist_between_segments( const Point& P0, const Point& P1, const Point& R0, const Point& R1 ) {
    Vector u( P1, P0 );
    Vector v( R1, R0 );
    Vector w( P0, R0 );

    // Сначала считаем расстояние между бесконечными прямыми, вычисляя s_closest и t_closest
    double s_closest = 0.0;
    double t_closest = 0.0;
    dist_between_lines( u, v, w, s_closest, t_closest );

    if (s_closest <= 0.0 + eps) {
        s_closest = 0.0;
        t_closest = v.scalar_product( w ) / v.norm();
    } else if (s_closest >= 1.0 - eps) {
        s_closest = 1.0;
        t_closest = (v.scalar_product( w ) + u.scalar_product( v )) / v.norm();
    }

    if (t_closest <= 0.0 + eps) {
        t_closest = 0.0;

        if (-u.scalar_product( w ) <= 0.0 + eps) {
            s_closest = 0.0;
        } else if (-u.scalar_product( w ) >= u.norm() - eps) {
            s_closest = 1.0;
        } else {
            s_closest = -u.scalar_product( w ) / u.norm();
        }
    } else if (t_closest >= 1.0 - eps) {
        t_closest = 1.0;

        if ((-u.scalar_product( w ) + u.scalar_product( v )) <= 0.0 + eps) {
            s_closest = 0.0;
        } else if ((-u.scalar_product( w ) + u.scalar_product( v )) >= u.norm() - eps) {
            s_closest = 1.0;
        } else {
            s_closest = (-u.scalar_product( w ) + u.scalar_product( v )) / u.norm();
        }
    }
    
    s_closest = (std::abs( s_closest ) <= eps ? 0.0 : s_closest);
    t_closest = (std::abs( t_closest ) <= eps ? 0.0 : t_closest);

    Vector dP = w + (u * s_closest) + (v * t_closest * (-1));

    return std::sqrt( dP.norm());
}

int main() {
    Point p1, p2, r1, r2;
    cin >> p1.x >> p1.y >> p1.z
        >> p2.x >> p2.y >> p2.z
        >> r1.x >> r1.y >> r1.z
        >> r2.x >> r2.y >> r2.z;

    cout << std::fixed;
    cout << setprecision( 8 );

    cout << dist_between_segments( p1, p2, r1, r2 );

    return 0;
}
