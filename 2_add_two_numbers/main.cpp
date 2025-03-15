#include <algorithm>
#include <iostream>
#include <string>
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

    std::vector<int> values_A;
    std::vector<int> values_B;

    ListNode *current_A = l1;
    ListNode *current_B = l2;

    unsigned long long result_A = 0;
    unsigned long long result_B = 0;
    int counter_A = 0;

    while (current_A != nullptr) {
      values_A.push_back(current_A->val);
      current_A = current_A->next;
      counter_A += 1;
    }

    while (current_B != nullptr) {
      values_B.push_back(current_B->val);
      current_B = current_B->next;
    }

    std::reverse(values_A.begin(), values_A.end());
    std::reverse(values_B.begin(), values_B.end());

    for (int num : values_A) {
      result_A = result_A * 10 + num;
    }
    std::cout << result_A;

    for (int num : values_B) {
      result_B = result_B * 10 + num;
    }
    std::cout << "\n" << result_B << std::endl;

    long result = result_A + result_B;

    std::string result_str = std::to_string(result);
    std::cout << "The ans is " << result_str << std::endl;
    std::reverse(result_str.begin(),result_str.end());

    ListNode *base = new ListNode(result_str[0] - '0');

    ListNode *current = base;

    for (int i = 1; i < result_str.length(); i++) {
      ListNode *newNode = new ListNode(result_str[i] - '0');

      current->next = newNode;

      current = newNode;
    }

    ListNode *temp = base;
    while (temp != nullptr) {
      std::cout << temp->val << " ";
      temp = temp->next;
    }

    temp = base;
    while (temp != nullptr) {
      ListNode *next = temp->next;
      delete temp;
      temp = next;
    }

    return base;
  }
};

int main(int argc, char *argv[]) {

  ListNode *baseNode_A = new ListNode(0);
  ListNode *node_A1 = new ListNode(7);
  ListNode *node_A2 = new ListNode(5);
  ListNode *node_A3 = new ListNode(1);

  ListNode *baseNode_B = new ListNode(0);
  ListNode *node_B1 = new ListNode(3);

  baseNode_A->next = node_A1;
  node_A1->next = node_A2;
  node_A2->next = node_A3;
  baseNode_B->next = node_B1;

  Solution solution;

  solution.addTwoNumbers(baseNode_A, baseNode_B);

  return 0;
}
