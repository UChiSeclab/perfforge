#include <bits/stdc++.h>
using namespace std;

void swapstick(int &a, int &b, int &c) {
    int s;
    if (a > b) {
        s = b;
        b = a;
        a = s;
    }
    if (a > c) {
        s = c;
        c = a;
        a = s;
    }
    if (b > c) {
        s = c;
        c = b;
        b = s;
    }
}

bool succeed(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a && a - b < c && a - c < b && b - c < a) {
        return true;
    }
    return false;
}

void check_large_stick_invariant(int a, int b, int c) {
    if (c > a + b) { // Check if the largest stick is significantly longer than the sum of others
        cerr << "Warning: Performance bottleneck condition triggered - largest stick significantly longer than the sum of others." << endl;
        abort();
    }
}

void check_diff_invariant(int a, int b, int c) {
    if ((c - a > 50) || (c - b > 50)) { // Check for large difference between smallest and largest stick
        cerr << "Warning: Performance bottleneck condition triggered - large difference between smallest and largest stick." << endl;
        abort();
    }
}

void check_repeated_checks_invariant(int i, int j, int c) {
    if (i + j <= c + 5) { // Check if repeated validity checks are close to the critical sum
        cerr << "Warning: Performance bottleneck condition triggered - repeated validity checks close to the critical sum." << endl;
        abort();
    }
}

int main(int argc, char **argv) {
    int a, b, c;
    int min = 500;
    cin >> a >> b >> c;
    swapstick(a, b, c);

    // Place checks after sorting the sticks
    check_large_stick_invariant(a, b, c);
    check_diff_invariant(a, b, c);

    for (int i = a; i <= c; i++) {
        for (int j = b; j <= c; j++) {
            check_repeated_checks_invariant(i, j, c); // Inside loop but before the heavy operations
            if (succeed(i, j, c)) {
                if (i - a + j - b < min) {
                    min = i - a + j - b;
                }
            }
        }
    }
    cout << min << endl;
    return 0;
}