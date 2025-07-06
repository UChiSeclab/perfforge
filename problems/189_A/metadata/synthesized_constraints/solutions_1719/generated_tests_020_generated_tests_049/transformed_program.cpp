#include <bits/stdc++.h>
using namespace std;

// Function to check performance invariants
void check_high_iteration_invariant(int n) {
    if (n > 3500) { // Assuming 3500 as a threshold for high n value
        cerr << "Warning: High iteration invariant triggered - n is very large" << endl;
        abort();
    }
}

void check_small_piece_lengths_invariant(int a, int b, int c) {
    if (a < 5 && b < 5 && c < 5) { // Assuming values less than 5 are 'small'
        cerr << "Warning: Small piece lengths invariant triggered - all piece lengths are small" << endl;
        abort();
    }
}

void check_close_piece_lengths_invariant(int a, int b, int c) {
    if (abs(a - b) <= 1 && abs(b - c) <= 1 && abs(a - c) <= 1) { // Assuming closeness within 1 unit
        cerr << "Warning: Close piece lengths invariant triggered - piece lengths are similar" << endl;
        abort();
    }
}

int n, a, b, c;

void input() { 
    cin >> n >> a >> b >> c;
    
    // Check performance invariants after reading input
    check_high_iteration_invariant(n);
    check_small_piece_lengths_invariant(a, b, c);
    check_close_piece_lengths_invariant(a, b, c);
}

int mx = -1;
int k = 0;

void solve() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            k = n - (i * a + j * b);
            if (k % c == 0 && k >= 0) {
                mx = max(mx, i + j + (k / c));
            }
        }
    }
}

void output() { 
    cout << mx; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    output();
    return 0;
}