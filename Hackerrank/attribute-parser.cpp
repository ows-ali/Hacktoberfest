#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

string parseTag(map<string, map<string, string>*>& tags) {
    string line;
    string tag;
    string word;
    getline(cin, line);
    stringstream ss(line);
    if(line[1] == '/') {
        return "";
    }
    ss >> word;
    if(word.back() != '>') {
        tag = (word.substr(1));
        tags.emplace(tag, new map<string, string>());
    }
    else {
        tag = (word.substr(1, word.size()-2));
        tags.emplace(tag, new map<string, string>());
        return tag;
    }
    
    
    while((word.back() != '>')) {
        string value;
        ss >> word;
        string attribute = word;
        ss >> word;
        ss >> word;
        if(word.back() == '>')
            value = word.substr(1, word.size()-3);
        else {
            value = word.substr(1, word.size()-2);
        }
        tags.at(tag)->emplace(attribute, value);
    }
    return tag;
}

string getAttributeValue(string attr, map<string, string> attrValuePair) {
    string value;
    try {
        return attrValuePair.at(attr);
    } catch(const out_of_range& ex) {
        return "Not Found!";
    }
}

string parseOutput(vector<string>& input, string line) {
    stringstream ln(line);
    string word;
    getline(ln, word, '.');
    while(word.find("~") == string::npos) {
        input.push_back(word);
        getline(ln, word, '.');
    }
    size_t pos = word.find("~");
    input.push_back(word.substr(0, pos));
    return word.substr(pos+1);
}

bool checkValidity(vector<string> tagChain, map<string, vector<string>> tagMapper, map<string, int> tagLevels) {
    string tag, prevTag;
    for(int i = 1; i < tagChain.size(); i++) {
        prevTag = tagChain.at(i-1);
        tag = tagChain.at(i);
        try {
            vector<string> vec = tagMapper.at(prevTag);
            if(find(vec.begin(), vec.end(), tag) == vec.end()) {
                return false;
            }
        } catch(const out_of_range& ex) {
            return false;
        }
    }
    try {
            if(tagChain.size() - 1 != tagLevels.at(tagChain.back()))
                return false;
        } catch(const out_of_range& ex) {
            return false;
        }
    
    return true;
}

int main() {
    // Write C++ code here
    
    map<string, map<string, string>*> tags; // tag and its attributes
    map<string, vector<string>> tagMapper; // tag and its children tags
    map<string, int> tagLevels; // tag and their hierarchical level
    stack<string> tagTrace;
    string line;
    int n, q;
    getline(cin, line);
    stringstream input(line);
    input >> n >> q;

    for(int i = 0; i < n; i++) {
        string tag = parseTag(tags);
        if(tag.empty()) {
            tagTrace.pop();
            continue;
        }
        tagLevels.emplace(tag, tagTrace.size());
        if(tagTrace.size() > 0) {
            tagMapper.at(tagTrace.top()).push_back(tag);
        }
        tagTrace.push(tag);
        tagMapper.emplace(tag, vector<string>());
    }
    
    for(int i = 0; i < q; i++) {
        string currentTag;
        string attribute;
        vector<string> tagChain;
        getline(cin, line);
        attribute = parseOutput(tagChain, line);
        //cout << "Attribute: " << attribute << endl;
        if(checkValidity(tagChain, tagMapper, tagLevels)) {
            try {
                map<string, string>* attrValuePair = tags.at(tagChain.back());
                cout << getAttributeValue(attribute, *attrValuePair) << endl;
            } catch(const out_of_range& ex) {
                cout << "Not Found!" << endl;
            }
        } else {
            cout << "Not Found!" << endl;
        }
        
            
    }

    return 0;
}