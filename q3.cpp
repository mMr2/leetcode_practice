//running time: 1616ms
//memory occupation: 439MB
//need to be improved
#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s){
    if (s == "") return 0;

    string temp = "";
    string s_substr = "";
    string longest_str = "";

    for(int i = 0; i < s.length(); i++){
        for(int j = i; j < s.length(); j++){
            if(j != i && temp.find(s.at(j)) != string::npos){
                s_substr = temp;
                break;
            } else if(j == s.length() - 1 && s_substr == ""){
                temp = temp + s.at(j);
                s_substr = temp;
                break;
            }

            temp = temp + s.at(j);
        }
        if (longest_str.length() <= s_substr.length()) longest_str = s_substr;

        s_substr.clear();
        temp.clear();
    }

    if (longest_str.length() == 0) return s.length();
    else return longest_str.length();
}