#include <bits/stdc++.h>
using namespace std;

void check_large_input_size(int n) {
    if (n > 90) {  // Checking if n is close to the upper limit
        cerr << "Warning: Performance bottleneck condition triggered - large input size!" << endl;
        abort();
    }
}

void check_large_values(int n, int* a) {
    bool largeValuesPresent = false;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 900) {  // Check if any value is large
            largeValuesPresent = true;
            break;
        }
    }
    if (largeValuesPresent && n > 50) {  // Combined condition for large n and large values
        cerr << "Warning: Performance bottleneck condition triggered - large values in input!" << endl;
        abort();
    }
}

int a[200];

int main() {
    int n;
    cin >> n;

    // Check for large input size
    check_large_input_size(n);

    int i;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Check for large values after reading input
    check_large_values(n, a);

    unsigned long long ans;
    ans = 0;
    for (i = 1; i <= n; i++) {
        ans += a[i] * i;
    }
    cout << ans << endl;
    return 0;
}