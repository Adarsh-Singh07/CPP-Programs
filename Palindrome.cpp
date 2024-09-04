#include <iostream>

using namespace std;

int main() {
  int number, originalNumber, reversedNumber = 0;

  cout << "Enter a number: ";
  cin >> number;

  originalNumber = number;

  while (number > 0) {
    int digit = number % 10;
    reversedNumber = reversedNumber * 10 + digit;
    number /= 10;
  }
  if (originalNumber == reversedNumber) {
    cout << originalNumber << " is a palindrome." << endl;
  } else {
    cout << originalNumber << " is not a palindrome." << endl;
  }

  return 0;
}
