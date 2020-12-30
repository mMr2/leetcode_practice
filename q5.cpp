#include <iostream>
#include <string>

string longestPalindrome(string s) {
    string temp;
    string longest_str;

    if (s.length() == 1) return s;
    else{
        for(unsigned int i = 0; i < s.length(); ++i){
            if(i = 0 && (s.at(i) == s.at(i+1))) temp = s.substr(i,2);
            else if(s.at(i) == s.at(i+1) || s.at(i-1) == s.at(i+1)) 
        }
    }
}