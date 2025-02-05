#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    class iterator;
    
    Solution(istream &inp) {
        string line;
        while (getline(inp, line)) {
            string trimmed;
            size_t start = 0, end = line.size();
            
            while (start < end && isspace(line[start])) ++start;
            while (end > start && isspace(line[end - 1])) --end;
            
            trimmed = line.substr(start, end - start);
            
            if (isValidInteger(trimmed)) {
                numbers.push_back(stoi(trimmed));
            }
        }
    }
    
    iterator begin() { return iterator(numbers.begin()); }
    iterator end() { return iterator(numbers.end()); }
    
private:
    vector<int> numbers;
    
    bool isValidInteger(const string &s) {
        if (s.empty()) return false;
        size_t i = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == s.size() || (s[i] == '0' && s.size() > i + 1)) return false;
        while (i < s.size()) {
            if (!isdigit(s[i])) return false;
            ++i;
        }
        try {
            int num = stoi(s);
            (void)num; 
        } catch (...) {
            return false;
        }
        return true;
    }
    
public:
    class iterator {
    public:
        using iter_type = vector<int>::iterator;
        
        iterator(iter_type it) : current(it) {}
        iterator &operator++() { ++current; return *this; }
        int operator*() const { return *current; }
        bool operator!=(const iterator &other) const { return current != other.current; }
        
    private:
        iter_type current;
    };
};

int main() {
    istringstream input("  42  \n+23\n-17\n 1000000000 \ninvalid\n 001 \n+0001\n2000000000\n");
    Solution solution(input);
    
    for (Solution::iterator it = solution.begin(); it != solution.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}

