#include <bits/stdc++.h>
using namespace std;

// Function to check excessive iteration condition
void check_excessive_iteration(long long i, long long m) {
    if (i > 1000000 && m > 0) {
        cerr << "Warning: Performance bottleneck due to excessive iteration!" << endl;
        abort();
    }
}

// Function to check excessive bit-checking condition
void check_excessive_bit_checking(long long value, long long i, long long m) {
    if (value > i || i > m) {
        cerr << "Warning: Performance bottleneck due to excessive bit-checking!" << endl;
        abort();
    }
}

void solve() {
    long long n, p;
    cin >> n >> p;
    for (int i = 1; i <= 2000000; i++) {
        long long m = n - p * i;
        long long value = 0;
        for (int j = 0; j < 40; j++) {
            if ((m >> j) & 1) value += 1;
        }
        check_excessive_bit_checking(value, i, m); // Check for excessive bit-checking
        
        if (value <= i && i <= m) {
            cout << i;
            return;
        }
        check_excessive_iteration(i, m); // Check for excessive iteration
    }
    cout << -1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}