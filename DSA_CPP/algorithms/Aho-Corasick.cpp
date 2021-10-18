#include <iostream>
#include <queue>

using namespace std;

struct Pattern{
    const string text;   
    const int size;       
    const int num;        
    const int pos;        
    Pattern(string t_text,const int& t_size, const int& t_num, const int& t_pos):  
            text(std::move(t_text)),size(t_size), num(t_num), pos(t_pos) {}
};

const int alphabet_size = 27;
struct Node{
    vector<Node*> sons; 
    vector<Node*> go;   

    Node* father;     
    Node* suff;         
    Node* up;           

    char letter;        
    bool is_terminal;   
    vector<int> numbers_of_patters; 
    Node(){
        sons.resize(alphabet_size);
        for(int i = 0; i < alphabet_size; i++){
            sons[i] = nullptr;
        }
        go.resize(alphabet_size);
        for(int i = 0; i < alphabet_size; i++){
            go[i] = nullptr;
        }

        father = nullptr;
        suff = nullptr;
        up = nullptr;

        letter = '@';
        is_terminal = false;
    }
};

// Бор(Автомат)
class Bor{
public:
    explicit Bor(const vector<Pattern>& p);  
    ~Bor(); 
    void Transform();  
    vector<int> Find(const string& text,const vector<Pattern>& p); 
private:
    Node* root; 

    void addLetter(const string& word, int pattern_number);  

    Node* getSuffLink(Node* vertex); 
    Node* getLink(Node* vertex,const char c);     
    Node* up(Node* vertex);   

    void del(Node* v);  
};
Bor::Bor(const vector<Pattern>& p){  
    root = new Node;   

    for(auto i = p.begin(); i != p.end(); ++i){  
        addLetter(i->text, i->num);     
    }
}
Bor::~Bor() {
    del(root); 
}
void Bor::Transform(){
    queue<Node*> q;
    q.push(root);
    if(root == nullptr){
        return;
    }
    root->suff = root;
    while(!q.empty()) {  
        Node *tmp = q.front();q.pop();
        if (tmp != nullptr) {
            for (int i = 0; i < tmp->sons.size(); i++) {
                if (tmp->sons[i] != nullptr) {
                    q.push(tmp->sons[i]);
                }
            }
            if (tmp->suff == nullptr) {
                tmp->suff = getSuffLink(tmp);
            }
        }
    }
}
vector<int> Bor::Find(const string& text,const vector<Pattern>& p) {
    Node* current = root;
    vector<int> tmp;
    if(root != nullptr){
        tmp.assign(text.size(),0);
    }
    else{
        return tmp;
    }
    for(int pos = 0; pos < text.size(); pos++){
        current = getLink(current,text[pos]);
        for(auto j = 0; j < current->numbers_of_patters.size(); j++){
            int pattern_num = current->numbers_of_patters[j];
            int w = pos-p[pattern_num].size+1-p[pattern_num].pos;
            if(w>=0){
                tmp[w]+=1;
            }
        }
        Node* k = up(current);
        while(k != root){
            for(auto j = 0; j < k->numbers_of_patters.size(); j++){
                int pattern_num = k->numbers_of_patters[j];
                int w = pos-p[pattern_num].size+1-p[pattern_num].pos;
                if(w>=0){
                    tmp[w]+=1;
                }
            }
            k = up(k);
        }
    }
    return tmp;
}
void Bor::addLetter(const string& word, int pattern_number){
    Node* cur = root;
    for(auto i = 0 ; i < word.size(); i++){
        char c = word[i]-'a';
        if(cur->sons[c] == nullptr){
            Node* tmp = new Node();
            tmp->father = cur;
            tmp->letter = word[i];
            cur->sons[c] = tmp;
        }
        cur = cur->sons[c];
    }
    cur->is_terminal = true;
    cur->numbers_of_patters.push_back(pattern_number);
    return;
}
void Bor::del(Node* v){
    if(v == nullptr){
        return;
    }
    for(int i = 0; i < alphabet_size; ++i){
        if(v->sons[i] != nullptr){
            del(v->sons[i]);
        }
    }
    delete v;
}
Node* Bor::getSuffLink(Node* vertex){
    if(vertex == nullptr){
        return nullptr;
    }
    if(vertex->suff == nullptr){
        if((vertex == root) or (vertex->father == root)){
            vertex->suff = root;
        }
        else{
            vertex->suff = getLink(getSuffLink(vertex->father), vertex->letter);
        }
    }
    return vertex->suff;
}
Node* Bor::getLink(Node* vertex,const char c){
    if(vertex == nullptr){
        return nullptr;
    }
    if(vertex->go[c-'a'] == nullptr){
        if(vertex->sons[c-'a'] != nullptr){
            vertex->go[c-'a'] = vertex->sons[c-97];
        }
        else if(vertex == root){
            vertex->go[c-'a'] = root;
        }
        else{
            vertex->go[c-'a'] = getLink(getSuffLink(vertex), c);
        }
    }
    return vertex->go[c-'a'];
}
Node* Bor::up(Node* vertex){
    if(vertex == nullptr){
        return nullptr;
    }
    if(vertex->up == nullptr){
        if(getSuffLink(vertex)->is_terminal){
            vertex->up = getSuffLink(vertex);
        }
        else if(getSuffLink(vertex) == root){
            vertex->up = root;
        }
        else{
            vertex->up = up(getSuffLink(vertex));
        }
    }
    return vertex->up;
}

vector<Pattern> SplitForPattern(const string& sample){
    vector<Pattern> patterns;
    int pattern_num = 0;
    for(int i = 0; i < sample.size(); i++){
        if(sample[i] != '?'){
            string s;
            s = sample[i];
            int j = i+1;
            while(sample[j] != '?' && j < sample.size()){
                s += sample[j];
                j++;
            }
            Pattern tmp(s, s.size(), pattern_num,i);
            patterns.push_back(tmp);
            i = j-1;
            pattern_num++;
        }
    }
    return  patterns;
}

int main(){
    string sample;
    string text;   

    cin >> sample;
    cin >> text;

    if(sample.size() > text.size()){ 
        return 0;
    }

    vector<Pattern> patterns = SplitForPattern(sample);

    class Bor Tree(patterns);

    Tree.Transform();
    vector<int> patterns_positions = Tree.Find(text, patterns);

    size_t num_of_patterns = patterns.size();
    size_t size = text.size()-sample.size()+1;
    for(int i = 0; i < size; i++){
        if(patterns_positions[i] == num_of_patterns) {
            if (patterns.size() > 0) {
                cout << i + patterns[0].pos << " ";
            }
            else{   // Если паттернов нет, только ??
                cout << i << " ";
            }
        }
    }
    return 0;
}
