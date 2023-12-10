#include <iostream>

using namespace std;

int main() {
  int n, i, divisor;

  cout << "Enter the upper limit: ";
  cin >> n;

  cout << "Prime numbers under " << n << ": ";

  for (i = 2; i <= n; ++i) {
    int isPrime = 1;

    for (divisor = 2; divisor * divisor <= i; ++divisor) {
      if (i % divisor == 0) {
        // If any divisor divides the number, it's not prime
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      cout << i << " ";
    }
  }

  cout << endl;

  return 0;
}
