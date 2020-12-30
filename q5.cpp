//running time: 68ms
//memory usage: 66.8MB
#include <iostream>
#include <string>

using namespace std;

string computeLongestStr(string s, int back, int front);

string longestPalindrome(string s) {
    string temp;
    string longest_str = "";

    if (s.length() == 0) return "";
    else if(s.length() == 1) return s;
    else{
        longest_str = s.substr(0,1);
        for(unsigned int i = 0; i < s.length() - 1; ++i){
            if(s.at(i) == s.at(i+1)){
                temp = computeLongestStr(s, i, i+1);
                if(longest_str.length() <= temp.length()) longest_str = temp;
            }
            if(i > 0){
                if(s.at(i-1) == s.at(i+1)){
                    temp = computeLongestStr(s, i-1, i+1);
                    if(longest_str.length() <= temp.length()) longest_str = temp;
                } 
            }
        }
        return longest_str;
    }
}

string computeLongestStr(string s, int back, int front){
    while(back != 0 && front != s.length() - 1){
        if(s.at(back-1) == s.at(front+1)){
            back--;
            front++;
        }
        else break;
    }

    return s.substr(back, front-back+1);
}