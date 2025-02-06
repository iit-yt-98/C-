#include <bits/stdc++.h>

using namespace std;


class Solution{
public:
    class iterator{
    private:
        vector<int>::iterator current;
    public:
        iterator(vector<int>::iterator it){
            current = it;
        }

        iterator &operator++(){ ++current; return *this; } // why this?
        bool operator!=(const iterator &other)const{ return current != other.current; }
        int operator*(){return *current;}

    };

    iterator begin(){
        return iterator(nums.begin());
    }
    iterator end(){
        return iterator(nums.end());
    }

    Solution(istream &s){
        string line;
        while(getline(s, line)){
            line = trimString(line);
            auto [condition, val] = isValidNum(line);
            if(condition){
                nums.push_back(val);
            }
        }
    }

private:
    string trimString(string input){
        int n = input.size();
        int startIdx = 0, endIdx = n-1;
        for(int i=0;i<n;i++){
            startIdx = i;
            if(!isspace(input[i])){
                break;
            }
        }

        for(int i = n-1;i>=startIdx;i--){
            endIdx = i;
            if(!isspace(input[i])){
                break;
            }
        }

        return input.substr(startIdx, endIdx-startIdx);
    }


    pair<bool, int> isValidNum(string input){
        int n = input.length();
        bool negative = false;
        if(input[0] == '+' || input[0] == '-'){
            if(input[0] == '-')
                negative = true;
            
            input = input.substr(1);
        }
        try{
            int val = stoi(input);
            if(negative)
            val = val *(-1);
            return {true, val};
        }catch(...){
            return {false, -1};
        }
    }


    vector<int> nums;
};


int main(){
    istringstream input("  42  \n+23\n-17\n 1000000000 \ninvalid\n 001 \n+0001\n2000000000\n");

    Solution soln(input);

    for(auto it = soln.begin(); it!=soln.end(); ++it){
        cout<<*it<<endl;
    }

    return 0;

}


