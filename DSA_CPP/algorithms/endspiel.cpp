#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>

using std::vector;

////////// Cell /////////

struct Cell {
    int x, y;

    Cell( int a, int b ) : x( a ), y( b ) {}

    explicit Cell( const std::string a ) {
        x = a[0] - 'a' + 1;
        y = a[1] - '0';
    }

    bool operator==( const Cell& other ) const {
        return x == other.x && y == other.y;
    }

    bool operator!=( const Cell& other ) {
        return not(*this == other);
    }

    bool operator<( const Cell& other ) const;

    bool can_step( int stepX, int stepY );

    int get_hash() const {
        return x * 10 + y;
    }

    Cell step( int stepX, int stepY );
};

bool Cell::operator<( const Cell& other ) const {
    if (x < other.x) {
        return true;
    } else if (x > other.x) {
        return false;
    } else if (y < other.y) {
        return true;
    } else {
        return false;
    }
}

bool Cell::can_step( int stepX, int stepY ) {
    return (x + stepX) >= 1 and (x + stepX) <= 8 and (y + stepY) >= 1 and (y + stepY) <= 8;
}

Cell Cell::step( int stepX, int stepY ) {
    return Cell( x + stepX, y + stepY );
}

const Cell WhiteKing = Cell( "c3" );

////////// Board /////////

struct Board {
    Cell WhiteQueen;
    Cell BlackKing;
    bool turn_color; // 1 - white, 0 - black

    Board( Cell a, Cell b, bool d ) : WhiteQueen( a ), BlackKing( b ), turn_color( d ) {}

    bool operator<( const Board& a ) const {
        return get_hash() < a.get_hash();
    }

    int get_hash() const {
        return (WhiteQueen.get_hash() * 100 + BlackKing.get_hash()) * (turn_color ? -1 : 1);
    }
};

////////// EndspielSolver /////////

// King C 3

class EndspielSolver {
public:
    EndspielSolver() : XStep{1, 1, 1, -1, -1, -1, 0, 0}, YStep{1, -1, 0, 1, -1, 0, 1, -1} {}

    int solve( const Cell& WQ, const Cell& BK );

private:
    std::map<Board, int> results;

    void white_turn( Cell& king, Cell& queen, std::queue<Board>& queueSituation );

    void black_turn( Cell& king, Cell& queen, std::queue<Board>& queueSituation );

    void check();

    void add_white_queens( const Cell& queen, const Cell& BK, std::queue<Board>& queueSituations,
                           int maxStep );

    void add_black_kings( const Cell& queen, const Cell& Bking, std::queue<Board>& queueSituations,
                          int minStep );

    bool is_check( const Cell& King, const Cell& Queen );

    bool step_without_interceptions_with_WK( Cell BK, Cell WK, Cell WQ );

    const int XStep[8];
    const int YStep[8];
};

bool EndspielSolver::step_without_interceptions_with_WK( Cell BK, Cell WK, Cell WQ ) {
    for (int i = 0; i < 8; ++i) {
        if (BK.step( XStep[i], YStep[i] ) == WK) {
            return false;
        }
    }
    return true;
}

bool EndspielSolver::is_check( const Cell& King, const Cell& Queen ) {
    for (int i = 0; i < 8; ++i) {
        Cell tempQueen = Queen;

        while (tempQueen.can_step( XStep[i], YStep[i] )) {
            tempQueen = tempQueen.step( XStep[i], YStep[i] );

            if (tempQueen != WhiteKing) {
                if (tempQueen == King) {
                    return true;
                }
            } else {
                break;
            }
        }
    }
    return false;
}

void EndspielSolver::add_black_kings( const Cell& queen, const Cell& Bking,
                                      std::queue<Board>& queueSituations, int minStep ) {

    for (int i = 0; i < 8; i++) {
        Cell tempKing = Bking;
        if (tempKing.can_step( XStep[i], YStep[i] )) {
            tempKing = tempKing.step( XStep[i], YStep[i] );
            if (tempKing != WhiteKing && tempKing != queen &&
                step_without_interceptions_with_WK( tempKing, WhiteKing, queen )) {
                if (results.find( Board{queen, tempKing, false} ) != results.end()) {
                    if (results[Board{queen, tempKing, false}] >= minStep + 1) {
                        continue;
                    }
                }
                queueSituations.push( Board{queen, tempKing, false} );
            } else {
                continue;
            }
        }
    }
}

void EndspielSolver::add_white_queens( const Cell& queen, const Cell& BK,
                                       std::queue<Board>& queueSituations, int maxStep ) {

    for (int i = 0; i < 8; i++) {
        Cell tempQueen( queen );
        while (tempQueen.can_step( XStep[i], YStep[i] )) {
            tempQueen = tempQueen.step( XStep[i], YStep[i] );
            if (tempQueen != WhiteKing && tempQueen != BK) {
                if (is_check( tempQueen, BK )) {
                    continue;
                }
                if (results.find( Board{tempQueen, BK, true} ) != results.end()) {
                    if (results[Board{tempQueen, BK, true}] <= maxStep + 1) {
                        continue;
                    }
                }
                queueSituations.push( Board{tempQueen, BK, true} );
            } else {
                break;
            }
        }
    }
}


int EndspielSolver::solve( const Cell& WQ, const Cell& BK ) {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            Cell BlackKing( i, j );
            if (not(BlackKing == WhiteKing || not step_without_interceptions_with_WK( BlackKing, WhiteKing,
                                                                                      Cell( 0, 0 )))) {
                for (int k = 1; k <= 8; ++k) {
                    for (int l = 1; l <= 8; ++l) {
                        Cell queen( k, l );
                        if (not(queen == BlackKing || queen == WhiteKing)) {
                            if (is_check( BlackKing, queen )) {

                                bool flag = false;
                                for (int t = 0; t < 8; t++) {
                                    if (BlackKing.can_step( XStep[t], YStep[t] )) {
                                        Cell tempKing = BlackKing.step( XStep[t], YStep[t] );
                                        if (tempKing != WhiteKing) {
                                            if (step_without_interceptions_with_WK( tempKing, WhiteKing, queen )) {
                                                if (!is_check( tempKing, queen )) {
                                                    flag = true;
                                                }
                                            }
                                        }
                                    }
                                }

                                if (!flag) {
                                    results[Board( queen, BlackKing, false )] = 0;
                                }
                            }
                        }

                    }
                }
            }
        }
    }

    check();

    if (results.find( Board( WQ, BK, true )) != results.end()) {
        return results[Board( WQ, BK, true )];
    }
}

void EndspielSolver::white_turn( Cell& king, Cell& queen, std::queue<Board>& queueSituation ) {
    if (not is_check( king, queen )) {
        bool isSure = false;
        int minStep = 0;
        for (int i = 0; i < 8; i++) {
            Cell tempQueen = queen;
            while (tempQueen.can_step( XStep[i], YStep[i] )) {
                tempQueen = tempQueen.step( XStep[i], YStep[i] );
                if (tempQueen != WhiteKing && tempQueen != king) {
                    if (results.find( Board{tempQueen, king, false} ) != results.end()) {
                        if (!isSure) {
                            minStep = results[Board{tempQueen, king, false}];
                        }
                        isSure = true;
                        minStep = std::min( minStep, results[Board{tempQueen, king, false}] );
                    }
                } else {
                    break;
                }
            }
        }

        if (isSure) {
            if (results.find( Board{queen, king, true} ) == results.end() ||
                results[Board{queen, king, true}] > minStep + 1) {
                results[Board( queen, king, true )] = minStep + 1;
                if (!is_check( king, queen )) {
                    add_black_kings( queen, king, queueSituation, minStep + 1 );
                }
            }
        }
    }
}

void EndspielSolver::black_turn( Cell& king, Cell& queen, std::queue<Board>& queueSituation ) {
    bool isNotSure = false;
    int maxCountStep = -3;
    for (int i = 0; i < 8; i++) {
        if (king.can_step( XStep[i], YStep[i] )) {
            Cell tempKing = king.step( XStep[i], YStep[i] );
            if (tempKing != WhiteKing) {
                if (step_without_interceptions_with_WK( tempKing, WhiteKing, queen ) && !is_check( tempKing, queen )) {
                    if (results.find( Board{queen, tempKing, true} ) == results.end()) {
                        isNotSure = true;
                    } else {
                        maxCountStep = std::max( maxCountStep, results[Board{queen, tempKing, true}] );
                    }
                }
            }
        }
    }

    if (!isNotSure) {
        if (results.find( Board{queen, king, false} ) == results.end() ||
            results[Board{queen, king, false}] < maxCountStep + 1) {
            results[Board( queen, king, false )] = maxCountStep + 1;
            add_white_queens( queen, king, queueSituation, maxCountStep + 1 );
        }
    }
}

void EndspielSolver::check() {

    std::queue<Board> queueSituation;

    for (const auto& situation: results) {
        add_white_queens( situation.first.WhiteQueen, situation.first.BlackKing, queueSituation, -3 );
    }

    while (!queueSituation.empty()) {
        Board situation = queueSituation.front();
        queueSituation.pop();
        Cell king = situation.BlackKing;
        Cell queen = situation.WhiteQueen;
        if (situation.turn_color) {
            white_turn( king, queen, queueSituation );
        } else {
            black_turn( king, queen, queueSituation );

        }
    }
}


int main() {
    std::string WhiteQueen_string, BlackKing_string;
    EndspielSolver solver;
    std::cin >> WhiteQueen_string >> BlackKing_string;

    Cell WhiteQueen( WhiteQueen_string );
    Cell BlackKing( BlackKing_string );

    int res = solver.solve( WhiteQueen, BlackKing );
    if (res > 0) {
        std::cout << res;
    } else {
        std::cout << "IMPOSSIBLE";
    }

}
