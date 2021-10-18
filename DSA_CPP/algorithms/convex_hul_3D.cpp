#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Vector {
    int x = 0;
    int y = 0;
    int z = 0;

    Vector() = default;

    Vector( int x_, int y_, int z_ ) : x( x_ ), y( y_ ), z( z_ ) {}
};

Vector cross_product( const Vector& u, const Vector& v ) {
    int i = u.y * v.z - u.z * v.y;
    int j = u.z * v.x - u.x * v.z;
    int k = u.x * v.y - u.y * v.x;
    return {i, j, k};
}

int scalar_product( const Vector& v, const Vector& u ) {
    return ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z);

}

Vector operator+( const Vector& u, const Vector& v ) {
    return {u.x + v.x, u.y + v.y, u.z + v.z};
}

Vector operator*( const Vector& u, const int s ) {
    return {u.x * s, u.y * s, u.z * s};
}

struct Plane {
    Vector norm;
    short points[3] = {0, 0, 0};

    Plane() = default;

    Plane( int p1, int p2, int p3 ) {
        int t_1 = std::min( p1, std::min( p2, p3 ));
        int t_3 = std::max( p1, std::max( p2, p3 ));
        int t_2 = p1 + p2 + p3 - t_1 - t_3;
        points[0] = static_cast<short>(t_1);
        points[1] = static_cast<short>(t_2);
        points[2] = static_cast<short>(t_3);
    }
};

static bool comparator( const Plane& fst, const Plane& snd ) {
    if (fst.points[0] < snd.points[0]) {
        return true;
    } else if (fst.points[0] == snd.points[0] and fst.points[1] < snd.points[1]) {
        return true;
    } else if (fst.points[0] == snd.points[0] and fst.points[1] == snd.points[1] and fst.points[2] <= snd.points[2]) {
        return true;
    }
    return false;
}

class Hull {
private:
    int facesCount;
    vector<Plane> faces;
    vector<Vector> vertices;
    vector<vector<char>> count_edges_usage; // 0/1/2 - нигде не используется/исп. в 1 грани/исп. в 2 гранях

public:
    int get_faces_count() { return facesCount; }

    vector<Plane> get_faces() { return faces; }

    Hull( size_t n, vector<Vector> points ) : facesCount( 0 ), vertices( std::move( points )) {
        count_edges_usage.resize( n );
        for (size_t i = 0; i < n; i++) {
            count_edges_usage[i] = vector<char>( n - i, 0 );
        }
    }

    void add_face( int p1, int p2, int p3, int p4 );

    void add_faces();

    void add_found_faces(const int i, const vector<pair<short, short>>& upt_eu);

    void build();
};

void Hull::add_face( int p1, int p2, int p3, int p4 ) {
    Plane face( p1, p2, p3 );
    Vector foo = vertices[face.points[1]] + vertices[face.points[0]] * (-1);
    Vector bar = vertices[face.points[2]] + vertices[face.points[0]] * (-1);
    Vector baz = vertices[p4] + vertices[face.points[0]] * (-1);
    face.norm = cross_product( foo, bar );
    if (scalar_product( baz, face.norm ) > 0) {
        face.norm = face.norm * (-1);
        short tmp = face.points[2];
        face.points[2] = face.points[1];
        face.points[1] = tmp;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (i == j)continue;
            if (face.points[i] <= face.points[j]) {
                count_edges_usage[face.points[i]][face.points[j] - face.points[i]]++;
            } else {
                count_edges_usage[face.points[j]][face.points[i] - face.points[j]]++;
            }
        }
    }
    faces.push_back( face );
    ++facesCount;
}

void Hull::add_faces() {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                add_face( i, j, k, 6 - i - j - k );
            }
        }
    }
}

void Hull::add_found_faces(const int i, const vector<pair<short, short>>& upt_eu){
    for (auto edge : upt_eu) {
        short first = edge.first, second = edge.second;
        if (first > second) {
            swap( first, second );
        }
        if (count_edges_usage[first][second - first] == 1) {
            int k = 0;
            while (k == i or k == edge.first or k == edge.second) {
                ++k;
            }
            add_face( edge.first, edge.second, i, k );
        }
    }
}

void Hull::build() {
    add_faces();

    for (int i = 4; i < vertices.size(); i++) {
        vector<pair<short, short>> upt_eu; // Ребра для обновления
        for (int j = 0; j < faces.size(); j++) {
            Plane face = faces[j];
            Vector l = vertices[i] + vertices[face.points[0]] * (-1);
            if (scalar_product( face.norm, l ) > 0) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < i + 1; ++j) {
                        if (i == j)continue;
                        if (face.points[i] <= face.points[j]) {
                            count_edges_usage[face.points[i]][face.points[j] - face.points[i]]--;
                        } else {
                            count_edges_usage[face.points[j]][face.points[i] - face.points[j]]--;
                        }
                    }
                }
                upt_eu.emplace_back( make_pair( face.points[0], face.points[1] ));
                upt_eu.emplace_back( make_pair( face.points[1], face.points[2] ));
                upt_eu.emplace_back( make_pair( face.points[2], face.points[0] ));
                faces[j--] = faces.back();
                faces.resize( faces.size() - 1 );
                --facesCount;
            }
        }

        add_found_faces(i, upt_eu);
    }
    sort( faces.begin(), faces.end(), comparator );
}


int main() {
    size_t m = 0, n = 0;
    cin >> m;
    for (size_t i = 0; i < m; i++) {
        cin >> n;
        int x = 0, y = 0, z = 0;
        vector<Vector> points( n );
        for (size_t k = 0; k < n; k++) {
            cin >> x >> y >> z;
            points[k] = Vector( x, y, z );
        }
        Hull hull( n, points );
        hull.build();
        cout << hull.get_faces_count() << '\n';
        for (auto face : hull.get_faces()) {
            cout << "3 ";
            cout << face.points[0] << ' ';
            cout << face.points[1] << ' ';
            cout << face.points[2] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
