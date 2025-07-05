#include <bits/stdc++.h>
using namespace std;

// Check if high iteration count invariant is triggered
void check_high_iteration_count(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count!" << endl;
        abort();
    }
}

// Check if lack of multiplicity invariant is triggered
void check_lack_of_multiplicity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - lack of multiplicity!" << endl;
        abort();
    }
}

// Check if input configuration invariant is triggered
void check_input_configuration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient input configuration!" << endl;
        abort();
    }
}

void solve() {
    long long int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    
    // Check inefficient input configuration
    check_input_configuration(k != 1 && l != 1 && m != 1 && d > 10000);

    if (k == 1 || l == 1 || m == 1) {
        cout << d;
        return;
    }
    
    long long int i, cnt = d;
    
    // Check high iteration count
    check_high_iteration_count(d > 90000);

    for (i = 1; i < d + 1; i++) {
        if ((i % k != 0) && (i % l != 0) && (i % m != 0) && (i % n != 0)) {
            cnt--;
        }
    }
    cout << cnt;
    return;
}

int main() {
    long long int t = 1, temp;
    for (temp = 0; temp < t; temp++) {
        solve();
    }
}