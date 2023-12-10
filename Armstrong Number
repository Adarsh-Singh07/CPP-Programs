#include <iostream>

using namespace std;

int main() {
  int num, originalNum, sum = 0, digit;

  cout << "Enter a number: ";
  cin >> num;

  originalNum = num;

  while (num > 0) {
    digit = num % 10;
    sum += digit * digit * digit;
    num /= 10;
  }

  if (sum == originalNum) {
    cout << originalNum << " is an Armstrong number." << endl;
  } else {
    cout << originalNum << " is not an Armstrong number." << endl;
  }

  return 0;
}
