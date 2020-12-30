//running time: 28ms
//memory usage: 14.2MB
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int cover = 0;
    int column = 0;
    int max = 0;

    //get max value
    for(int i=0; i<height.size(); i++){
        if(max <= height.at(i)) max = height.at(i);
    }

    for(int j=1; j<=max; j++){
        int k = 0;
        int l = height.size() - 1;

        while(height.at(k) < j && k <= height.size() - 1){
            k++;
        }

        while(height.at(l) < j && l >= 0){
            l--;
        }

        if(k == height.size() && l == -1) break;
        else cover += (l - k + 1);
    }

    for (int p=0; p<height.size(); p++) column += height.at(p);

    return cover - column;
}

//example solution: double pointer
// int trap(vector<int>& height)
// {
//     int left = 0, right = height.size() - 1;
//     int ans = 0;
//     int left_max = 0, right_max = 0;
//     while (left < right) {
//         if (height[left] < height[right]) {
//             height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
//             ++left;
//         }
//         else {
//             height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
//             --right;
//         }
//     }
//     return ans;
// }

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。