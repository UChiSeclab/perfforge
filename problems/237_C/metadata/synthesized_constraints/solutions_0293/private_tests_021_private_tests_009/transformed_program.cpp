#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool isPrime(int x) {
    if (x == 1) return false;
    for (int j = 2; j * j <= x; j++) {
        if (x % j == 0) return false;
    }
    return true;
}

// Performance checkers
void check_prime_call_invariant(int a, int b) {
    if (b - a > 100000) {  // Assume large ranges are problematic
        cerr << "Warning: Performance bottleneck - large range causing excessive prime checks!" << endl;
        abort();
    }
}

void check_large_range_vs_k_invariant(int a, int b, int k) {
    if ((b - a) > 100000 && k < 10) {  // Example threshold
        cerr << "Warning: Performance bottleneck - large range with small k!" << endl;
        abort();
    }
}

void check_large_input_range_invariant(int a, int b) {
    if (b > 1000000) {
        cerr << "Warning: Performance bottleneck - large input range!" << endl;
        abort();
    }
}

void check_large_k_invariant(int a, int b, int k) {
    if (k >= (b - a + 1)) {
        cerr << "Warning: Performance bottleneck - k larger than the range!" << endl;
        abort();
    }
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    
    // Integrate performance checkers
    check_prime_call_invariant(a, b);
    check_large_range_vs_k_invariant(a, b, k);
    check_large_input_range_invariant(a, b);
    check_large_k_invariant(a, b, k);

    v.push_back(a - 1);
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) v.push_back(i);
    }
    int ans = 0;
    v.push_back(b + 1);
    if (k > v.size() - 2) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i + k < v.size(); i++) {
        ans = max(ans, v[i + k] - v[i]);
    }
    cout << ans;
    return 0;
}