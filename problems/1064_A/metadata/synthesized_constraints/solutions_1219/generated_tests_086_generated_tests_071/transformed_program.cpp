#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

double calcArea(int a, int b, int c) {
    const double p = static_cast<double>(a + b + c) / 2.0;
    try {
        return sqrt(p * (p - a) * (p - b) * (p - c));
    } catch (exception& e) {
        return 0;
    }
}

void check_length_difference_invariant(int a, int b, int c) {
    int lengths[] = {a, b, c};
    sort(lengths, lengths + 3);

    if ((lengths[2] >= lengths[0] + lengths[1]) && (lengths[2] - lengths[0] > 50)) {
        cerr << "Warning: Significant length difference causing potential slowdown." << endl;
        abort();
    }
}

void check_minimal_lengths_invariant(int a, int b, int c) {
    int lengths[] = {a, b, c};
    sort(lengths, lengths + 3);

    if (lengths[0] <= 5 && lengths[1] <= 5 && lengths[2] >= 90) {
        cerr << "Warning: Two minimal and one maximal stick configuration detected." << endl;
        abort();
    }
}

void check_balancing_needed_invariant(int a, int b, int c) {
    int lengths[] = {a, b, c};
    sort(lengths, lengths + 3);

    if (lengths[2] >= lengths[0] + lengths[1] && lengths[2] - lengths[1] > 20) {
        cerr << "Warning: Significant balancing needed for stick lengths." << endl;
        abort();
    }
}

void check_max_diff_invariant(int a, int b, int c) {
    int lengths[] = {a, b, c};
    sort(lengths, lengths + 3);

    if (lengths[2] - lengths[0] > 90) {
        cerr << "Warning: Maximum stick length difference detected." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, inc = 0;
    cin >> a >> b >> c;

    // Add checks after input is read
    check_length_difference_invariant(a, b, c);
    check_minimal_lengths_invariant(a, b, c);
    check_balancing_needed_invariant(a, b, c);
    check_max_diff_invariant(a, b, c);

    if (calcArea(a, b, c) == 0) {
        inc = 100 * 3;
        for (int ai = a; ai <= 100; ai++) {
            for (int bi = b; bi <= 100; bi++) {
                for (int ci = c; ci <= 100; ci++) {
                    if (calcArea(ai, bi, ci) > 0)
                        inc = min(inc, (ai - a) + (bi - b) + (ci - c));
                }
            }
        }
    }
    cout << inc;
}