#include <bits/stdc++.h>
using namespace std;

// Function to check the performance bottleneck condition based on probabilities
void check_probability_invariant(long double s) {
    if (s > 0.999) {  // Check if the product is close to 1
        cerr << "Warning: Performance bottleneck condition triggered! Probability product is too close to 1." << endl;
        abort();
    }
}

int main() {
    long double e = 1, a, b, c, d, p, s;
    cin >> a >> b >> c >> d;
    s = (1 - a / b) * (1 - c / d);
    
    // Check for the probability product invariant
    check_probability_invariant(s);
    
    p = s;
    while (e > 0.000000000001) {
        long double h = p;
        p = p * s + s;
        e = p - h;
    }
    cout << (p + 1) * (a / b) << endl;
    return 0;
}