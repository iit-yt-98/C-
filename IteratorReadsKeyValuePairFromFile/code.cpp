#include <bits/stdc++.h>

using namespace std;


class Solution{
private:
    unordered_map<string, string> mp;
public:
    class CIterator; // just a pre-declaration
    // constructor for Solution
    Solution(ifstream &file){
        string line;
        while(getline(file, line)){
            removeExtraSpaces(line);
            auto [key, value] = extractKeyValue(line);
            if(value.size() > 0){
                mp[key] = value;
            }
        }
    }

    // we need to define begin and end for the CIterator
    CIterator begin(){
        return CIterator(mp.begin());
    };
    CIterator end(){
        return CIterator(mp.end());
    };
    void removeExtraSpaces(string &line){
        int n = line.size();
        int startIdx = 0, endIdx = n-1;
        while(startIdx < n and isspace(line[startIdx])){
            startIdx++;
        }

        while(endIdx >=0 and isspace(line[endIdx])){
            endIdx--;
        }
        line = line.substr(startIdx, endIdx - startIdx + 1);
    }

    pair<string ,string> extractKeyValue(string line){
        int n = line.length();
        int startIdx = 0;

        while(startIdx < n and line[startIdx] != '='){
            startIdx++;
        }
        
        if (startIdx == n) return {"", ""};

        string key = (startIdx > 0) ? line.substr(0, startIdx) : "";
        removeExtraSpaces(key);
        string value;

        if(startIdx+1 < n){
            value = line.substr(startIdx+1);
        }
        removeExtraSpaces(value);


        return {key, value};
    }

    class CIterator{
    private:
        using mapItr = unordered_map<string , string>::iterator;
        mapItr current;
    public:
        // constructor
        CIterator(mapItr temp){
            current = temp;
        }

        // define the operator actions that can be performed on this custom CIterator/CustomIterator
        bool operator!=(const CIterator &other) const{
            return current != other.current;
        }
        // another useful operator used in loops
        CIterator &operator++(){
            current++;
            return *this;
        }
        // de-ref operator
        pair<string,string> operator*(){
            // below creates a new pair so its not a good choice
            // return {(current)->first, (current)->second};
            return *current;
        }

    };
};



int main(){
    ifstream file("inputFile.txt");
    Solution solution(file);

    for(Solution::CIterator itr = solution.begin(); itr != solution.end(); ++itr){
        auto [key , value] = *itr;
        cout<<"Key is "<<key<<" and value is "<<value<<endl;
    }

    return 0;
}