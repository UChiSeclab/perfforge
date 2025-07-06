#include <bits/stdc++.h>
#include <cstdlib> // for abort()
using namespace std;

// Checker for high iteration in the inner loop
void check_high_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iterations in loop." << endl;
        abort();
    }
}

// Checker for complexity in determining uniqueness
void check_uniqueness_determination_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complexity in determining uniqueness." << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    int segms[1001];
    int h0 = 0;
    for (int i = 0; i < n; i++) {
        int h1;
        cin >> h1;
        segms[i] = h1 - h0;
        h0 = h1;
    }
    double x = 1;
    double y = 0;
    double maxa = 100000000;
    double mina = 10;
    for (int i = 0; i < n; i++) {
        double nmaxa = (10 * (segms[i] + 1) - y) / x;
        double nmina = (10 * segms[i] - y) / x;
        if (nmaxa < maxa) maxa = nmaxa;
        if (nmina > mina) mina = nmina;
        x = x + 1;
        y = y - segms[i] * 10;
    }

    int vozm = -1;
    int mx = 1000001;

    // Place checks before the heavy loop to detect potential slowdowns
    check_high_iteration_invariant((maxa - mina) > mx / 10); // Example threshold for a wide range
    check_uniqueness_determination_invariant(n > 10); // Example threshold where uniqueness becomes costly

    for (int i = 1; i < mx; i++) {
        double nmaxa = (10 * (i + 1) - y) / x;
        double nmina = (10 * (i)-y) / x;
        if (nmaxa > mina && maxa > nmina)
            if (vozm == -1) {
                vozm = h0 + i;
                continue;
            } else {
                cout << "not unique";
                return 0;
            }
    }
    cout << "unique" << endl << vozm;
}