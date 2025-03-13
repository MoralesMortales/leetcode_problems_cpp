#include <vector>
#include <iostream>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    int counter = 0;

    bool possibility = true;
    bool checked = false;
    std::vector<int> res(2, 0);

    while (possibility) {
      for (int i = 0; i < nums.size(); i++) {
        if (nums[counter] == nums[i] && checked == false) {
          checked = true;
        }

        else if (nums[counter] + nums[i] == target) {
          std::cout << "FOUND! " << nums[counter] << " + " << nums[i]
                    << std::endl;
          res[0] = counter;
          res[1] = i;
          possibility = false;
          return res;
        }
      }
      counter = counter + 1;
      checked = false;

      if (nums.size() == counter - 1) {
        std::cout << "NOT FOUND" << std::endl;
        possibility = false;
        return res;
      }
    }
    return res;
  }
};


int main (int argc, char *argv[]) {
  Solution solution;

  std::vector<int> nros = {2, 0, 4};
  solution.twoSum(nros, 6);

  return 0;
}
