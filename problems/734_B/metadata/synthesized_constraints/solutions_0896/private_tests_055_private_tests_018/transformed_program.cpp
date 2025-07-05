#include <bits/stdc++.h>
using namespace std;

int k2, k3, k5, k6, s;

// Functions to check performance invariants
void check_large_256_invariant(int k2, int k5, int k6) {
    if (k2 > 4500000 && k5 > 4500000 && k6 > 4500000) {
        cerr << "Warning: Performance bottleneck due to high counts of digits 2, 5, and 6!" << endl;
        abort();
    }
}

void check_large_32_invariant(int k2, int k3, int k5, int k6) {
    if ((k5 == 0 || k6 == 0) && k2 > 4500000 && k3 > 4500000) {
        cerr << "Warning: Performance bottleneck due to high counts of digits 2 and 3!" << endl;
        abort();
    }
}

int f256(int suma) {
    k2--;
    k5--;
    k6--;
    return suma + 256;
}

int f32(int suma) {
    k2--;
    k3--;
    return suma + 32;
}

int main() {
    cin >> k2 >> k3 >> k5 >> k6;

    // Check performance bottleneck conditions based on the initial input values
    check_large_256_invariant(k2, k5, k6);
    check_large_32_invariant(k2, k3, k5, k6);

    while (true) {
        if (k2 > 0 && k5 > 0 && k6 > 0) s = f256(s);
        if ((k5 == 0 || k6 == 0) && k2 > 0 && k3 > 0) s = f32(s);
        if (((k5 == 0 || k6 == 0) && k3 == 0) || k2 == 0) {
            cout << s;
            break;
        }
    }
    return 0;
}