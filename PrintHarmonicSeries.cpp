#include <iostream>

using namespace std;

int main() {
  int n;
  float sum = 0.0f;
  cout << "Enter the number of terms: ";
  cin >> n;

  cout << "Harmonic series up to " << n << " terms: ";

  for (int i = 1; i <= n; ++i) {
 
    if (i == 1) {
      cout << "1 + ";
      sum = 1;
    } else {
      sum += 1.0f / i;
      cout << "1/" << i << " + ";
    }
  }

  cout << " = " << sum << endl;

  return 0;
}
