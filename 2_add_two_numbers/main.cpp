#include <algorithm>
#include <iostream>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    std::vector<int> values;

    ListNode *current_A = l1;
    ListNode *current_B = l2;

    while (current_B != nullptr) {
      values.push_back(current_B->val);
      current_B = current_B->next;
    }

    std::reverse(values.begin(), values.end());

  }
};

int main(int argc, char *argv[]) {

  ListNode *baseNode_A = new ListNode(1);
  ListNode *node_A1 = new ListNode(7);

  ListNode *baseNode_B = new ListNode(3);
  ListNode *node_B1 = new ListNode(3);

  baseNode_A->next = node_A1;
  baseNode_B->next = node_B1;

  return 0;
}
