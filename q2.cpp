//failed 
//I should add that node by node
//example code on https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode-solution/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    string l1_str = "";
    string l2_str = "";
    string result_str = "";

    ListNode *trav_l1 = l1;
    ListNode *trav_l2 = l2;    

    do{
        l1_str.push_back(trav_l1->val);
        trav_l1 = trav_l1->next;
    } while (trav_l1->next != nullptr);
    do{
        l2_str.push_back(trav_l2->val);
        trav_l2 = trav_l2->next;
    } while (trav_l2->next != nullptr);

    int result = atoi(l1_str.c_str()) + atoi(l2_str.c_str());

    stringstream ss;
    ss << result;
    result_str = ss.str();

    ListNode *result_list = new ListNode;
    ListNode *trav_result = result_list;

    for(int i = 0; i < result_str.length(); i++){
        result_list->val = int(result_str[i]);

        if(i == result_str.length() - 1) break;

        result_list->next = new ListNode;
        result_list = result_list->next;
    }

    return trav_result;
}