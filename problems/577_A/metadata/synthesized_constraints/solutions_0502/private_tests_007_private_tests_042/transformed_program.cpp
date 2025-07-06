#include <bits/stdc++.h>
using namespace std;

void check_large_table_small_x(int n, int x) {
    if (n > 1000 && x == 1) {
        cerr << "Warning: Performance bottleneck triggered - large table with small x (x = 1)" << endl;
        abort();
    }
}

void check_input_size_disparity(int n, int x) {
    if (n > 1000 && n > sqrt(x)) {
        cerr << "Warning: Performance bottleneck triggered - large n with respect to sqrt(x)" << endl;
        abort();
    }
}

void check_perfect_square_impact(int x, int limit) {
    int sqrt_x = static_cast<int>(sqrt(x));
    if (sqrt_x * sqrt_x != x && limit > 1000) {
        cerr << "Warning: Performance bottleneck triggered - x is not a perfect square with large limit" << endl;
        abort();
    }
}

void check_divisibility_check_frequency(int n, int x) {
    if (n > 1000 && x % n != 0) {
        cerr << "Warning: Performance bottleneck triggered - frequent divisibility checks with large n" << endl;
        abort();
    }
}

int main() {
    int n, i, x, ans = 0;
    cin >> n >> x;
    
    // Insert checkers after reading inputs
    check_large_table_small_x(n, x);
    check_input_size_disparity(n, x);
    check_perfect_square_impact(x, n);
    check_divisibility_check_frequency(n, x);

    // Original loop
    for (i = ceil(sqrt((double)x)); i <= n; i++) {
        if (i * i == x)
            ans++;
        else if (!(x % i))
            ans += 2;
    }
    
    cout << ans;
    return 0;
}