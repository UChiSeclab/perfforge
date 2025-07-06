#include <iostream>
using namespace std;

// Checkers for performance bottleneck conditions
void check_large_y_invariant(int y) {
    if (y > 1e8) { // Threshold chosen to detect large y values
        cerr << "Warning: Performance bottleneck condition triggered due to large y!" << endl;
        abort();
    }
}

void check_large_difference_invariant(int x, int y) {
    if ((y - 1) > 1e8) { // Large difference from the initial original toy count.
        cerr << "Warning: Performance bottleneck condition triggered due to large y difference!" << endl;
        abort();
    }
}

void check_large_x_and_y_invariant(int x, int y) {
    if (x > 1e8 && y > 1e8) { // Both x and y being large can cause inefficiencies
        cerr << "Warning: Performance bottleneck condition triggered due to large x and y!" << endl;
        abort();
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    // Insert performance checkers here
    check_large_y_invariant(y);
    check_large_difference_invariant(x, y);
    check_large_x_and_y_invariant(x, y);

    int sum = 1, sum1 = 0;
    for (;;) {
        if (sum == y) break;
        if (sum > y) {
            cout << "No";
            return 0;
        }
        sum++;
        sum1++;
    }
    for (;;) {
        if (sum1 == x && sum == y) {
            cout << "Yes";
            return 0;
        }
        if (sum1 > x) {
            cout << "No";
            return 0;
        }
        if (sum1 > 0) sum1 += 2;
        if (sum1 == 0) {
            cout << "No";
            return 0;
        }
    }
    return 0;
}