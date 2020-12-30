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

// example answer
// class Solution {
// public:
//     pair<int, int> expandAroundCenter(const string& s, int left, int right) {
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             --left;
//             ++right;
//         }
//         return {left + 1, right - 1};
//     }

//     string longestPalindrome(string s) {
//         int start = 0, end = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             auto [left1, right1] = expandAroundCenter(s, i, i);
//             auto [left2, right2] = expandAroundCenter(s, i, i + 1);
//             if (right1 - left1 > end - start) {
//                 start = left1;
//                 end = right1;
//             }
//             if (right2 - left2 > end - start) {
//                 start = left2;
//                 end = right2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
// };

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
