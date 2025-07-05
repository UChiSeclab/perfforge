#include <bits/stdc++.h>
using namespace std;

// Function to calculate gcd
int gcd(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

// Checker function for increment alignment
void check_increment_alignment(int a, int b, int c, int d) {
    if ((a == c) && ((b - d) % a != 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - increments do not align quickly!" << endl;
        abort();
    }
}

// Checker function for initial value alignment
void check_initial_value_alignment(int b, int d, int gcd_ac) {
    if ((b - d) % gcd_ac != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - initial values never align under increments!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Calculate gcd of a and c
    int gcd_ac = gcd(a, c);
    
    // Insert performance checks
    check_increment_alignment(a, b, c, d);
    check_initial_value_alignment(b, d, gcd_ac);
    
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            if (b + a * i == d + c * j) {
                cout << b + a * i << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}