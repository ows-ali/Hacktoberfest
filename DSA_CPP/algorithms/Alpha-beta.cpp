#include <vector>
#include <iostream>
#include <algorithm>

// Minimax algorithm with Alpha-beta pruning

using namespace std;

//Define the data structure
class Tree {
public:
    Tree () {val = -1;}
    Tree(int value) {val = value;}
    int get_value() { return val;}
    void set_value(int value) {val = value;}
    Tree& get_child(int i) { return *(children[i]);}
    Tree& add_child(Tree& tree) {children.push_back(&tree);}
    int num_children() {return children.size();}

private:
    vector<Tree*> children;
    int val;
};

//Minimax algorithm with alpha-beta pruning. We assume that each node can have value >= 0
int minimax(Tree& t, bool is_max, int alpha, int beta){
    // Base case: A leaf node return its value
    if (t.get_value() > -1) {
        return t.get_value();
    }

    vector<int> children_values;
    //Repeat the algorithm recursively and find max(min) value for the node
    for (auto i = 0; i < t.num_children(); ++i){
        auto new_val = minimax(t.get_child(i), !is_max, alpha, beta);
        children_values.push_back(new_val);
        if (is_max)
            alpha = max(alpha, new_val);
        else
            beta = min(beta, new_val);
        if (alpha >= beta)
            break;
    }

    //Set value for backtracking
    auto beg = children_values.begin();
    auto fin = children_values.end();
    t.set_value(is_max ? *max_element(beg, fin) : *min_element(beg, fin));

    return t.get_value();
}

// Minimax with alpha-beta pruning for the following tree: (((3, 5), (6, 9)), ((1, 2), (1, 4)))
int main() {
    Tree base;
    Tree lc, rc;
    Tree llc, lrc, rlc, rrc;
    Tree node1(3), node2(5), node3(6), node4(9);
    Tree node5(1), node6(2), node7(1), node8(4);
    base.add_child(lc); base.add_child(rc);
    lc.add_child(llc); lc.add_child(lrc);
    rc.add_child(rlc); rc.add_child(rrc);
    llc.add_child(node1); llc.add_child(node2);
    lrc.add_child(node3); lrc.add_child(node4);
    rlc.add_child(node5); rlc.add_child(node6);
    rrc.add_child(node7); rrc.add_child(node8);
    cout << minimax(base, true, INT_MIN, INT_MAX) << endl;
}