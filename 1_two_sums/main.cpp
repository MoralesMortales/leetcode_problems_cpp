#include <iostream>
#include <ostream>
#include <vector>

void getArray(std::vector<int> &numbers);
void showNumbers(std::vector<int> numbers);

int main(int argc, char *argv[]) {
  std::vector<int> numbers;
  int target, counter = 0;
  bool possibility = true;
  bool checked = false;

  getArray(numbers);

  showNumbers(numbers);
  std::cout << "\nWitch number is your target?: ";
  std::cin >> target;

  while (possibility) {
    for (int i = 0; i < numbers.size(); i++) {
      if (numbers[counter] == numbers[i] && checked == false) {
        checked = true;
      }

      else if (numbers[counter] + numbers[i] == target) {
        std::cout << "FOUND! " << numbers[counter] << " + " << numbers[i]
                  << std::endl;
        possibility = false;
        break;
      }
    }
      counter = counter + 1;
      checked = false;


    if (numbers.size() == counter - 1) {
      std::cout << "NOT FOUND" << std::endl;
      possibility = false;
    }
  }

  return 0;
}

void showNumbers(std::vector<int> numbers) {
  std::cout << "Your numbers are: \n";
  for (int i = 0; i < numbers.size(); i++) {
    if (i == numbers.size() - 1) {
      std::cout << numbers[i] << ".";
    } else {

      std::cout << numbers[i] << ", ";
    }
  }
}

void getArray(std::vector<int> &numbers) {
  int quantity, curVal = 0;
  std::cout << "Insert the quantity of numbers: ";
  std::cin >> quantity;

  for (int i = 0; i < quantity; i++) {
    std::cout << "Which is the elements for the item " << i + 1 << "?: ";
    std::cin >> curVal;
    numbers.push_back(curVal);
  }
}
