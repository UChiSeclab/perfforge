#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string rep[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                "1101011", "1101111", "1010010", "1111111", "1111011"};
string dig[2005];
bitset<N> val[2005];

// Checker function to detect high number of digits
void check_digit_count_invariant(int n) {
    if (n > 1500) { // Threshold chosen based on maximum n value being 2000
        cerr << "Warning: Performance bottleneck condition triggered - high number of digits!" << endl;
        abort();
    }
}

// Checker function to detect complex segment configurations
void check_complex_segment_invariant(int k, int n) {
    if (k > n * 4) { // Assuming each digit may need an average of 4 segments changed
        cerr << "Warning: Performance bottleneck condition triggered - complex segment transformations needed!" << endl;
        abort();
    }
}

// Checker function to detect iteration over large configurations
void check_iteration_invariant(int k, int n) {
    if (k > n * 5) { // This condition marks a potentially large search space
        cerr << "Warning: Performance bottleneck condition triggered - large iteration over configurations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k;
    cin >> k;

    // Place checkers early before the main computation
    check_digit_count_invariant(n); // Checks for too many scoreboard digits
    check_complex_segment_invariant(k, n); // Checks for complexity in segment configuration
    check_iteration_invariant(k, n); // Checks for potential large iteration requirements

    for (int i = 1; i <= n; ++i) cin >> dig[i];
    reverse(dig + 1, dig + 1 + n);
    val[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int c = 0; c < 10; ++c) {
            int w = 0;
            for (int j = 0; j < 7; ++j) {
                if (dig[i][j] > rep[c][j]) {
                    w = k + 1;
                    break;
                }
                w += rep[c][j] - dig[i][j];
            }
            val[i] |= (val[i - 1] << w);
        }
    if (!val[n][k]) {
        cout << "-1";
        return 0;
    }
    for (int i = n; i >= 1; --i)
        for (int c = 9; c >= 0; --c) {
            int w = 0;
            for (int j = 0; j < 7; ++j) {
                if (dig[i][j] > rep[c][j]) {
                    w = k + 1;
                    break;
                }
                w += rep[c][j] - dig[i][j];
            }
            if (w > k) continue;
            if (val[i - 1][k - w]) {
                k -= w;
                cout << c;
                break;
            }
        }
}