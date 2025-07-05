#include <bits/stdc++.h>
using namespace std;

// Checkers
void check_small_intervals(int a, int c) {
    if (a <= 5 && c <= 5) {  // Threshold chosen based on typical small values
        cerr << "Warning: Performance bottleneck condition triggered due to small intervals!" << endl;
        abort();
    }
}

void check_equal_intervals(int a, int c) {
    if (a == c) {
        cerr << "Warning: Performance bottleneck condition triggered due to equal intervals!" << endl;
        abort();
    }
}

void check_small_initial_offset(int b, int d, int a, int c) {
    if (abs(b - d) <= 5 && a != c) {  // Small offset threshold with intervals not aligned
        cerr << "Warning: Performance bottleneck condition triggered due to small initial offset!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Place performance checks here after input is read
    check_small_intervals(a, c);
    check_equal_intervals(a, c);
    check_small_initial_offset(b, d, a, c);

    int x = 0, y = 0, p = 0;
    for (int i = 0; i < 10e7; i++) {
        if (b + a * x == d + c * y) {
            p = 1;
            break;
        } else if (b + a * x > d + c * y)
            y++;
        else if (b + a * x < d + c * y)
            x++;
    }
    if (p == 1)
        cout << b + a * x << endl;
    else
        cout << -1 << endl;
}