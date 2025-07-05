#include <bits/stdc++.h>
using namespace std;

// Function to check if the range is too large, indicating a potential performance bottleneck
void check_large_range_invariant(int smallest, int largest, int n) {
    if ((largest - smallest) > (10 * n)) { // Arbitrary factor to detect a large range
        cerr << "Warning: Performance bottleneck condition triggered due to large range between indices!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // Check for potentially large range causing slow performance
    check_large_range_invariant(a[0], a[n-1], n);

    int count = a[0];
    int counter = 0, i = 0;
    while (i < n) {
        if (count == a[i]) {
            count++;
            i++;
        } else {
            count++;
            counter++;
        }
    }
    cout << counter;
}