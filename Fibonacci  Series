#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    int a = 0, b = 1;

    cout << "Fibonacci Series up to " << n << " terms: ";

    for (int i = 0; i < n; ++i) {
        cout << a << " ";

        int nextTerm = a + b;
        a = b;
        b = nextTerm;
    }

    cout << endl;

    return 0;
}
