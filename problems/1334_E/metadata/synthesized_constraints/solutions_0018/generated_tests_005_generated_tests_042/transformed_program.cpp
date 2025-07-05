#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 2e5 + 7;
long long mod = 998244353;

void check_gcd_recursion_depth(int depth) {
    if (depth > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - High recursion depth in `gcd` function!" << endl;
        abort();
    }
}

void check_divisor_loop(long long iterations, long long n) {
    if (iterations > sqrt(n) * 10) {
        cerr << "Warning: Performance bottleneck condition triggered - High number of iterations in divisor loop!" << endl;
        abort();
    }
}

void check_repeated_division(int division_count) {
    if (division_count > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - Excessive repeated division!" << endl;
        abort();
    }
}

void check_factorial_computation(long long sum) {
    if (sum > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - Large factorial computation range!" << endl;
        abort();
    }
}

long long gcd(long long a, long long b, long long &x, long long &y, int depth = 0) {
    check_gcd_recursion_depth(depth);
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b % a, a, x1, y1, depth + 1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long calc(long long a, long long b, vector<long long> &div) {
    vector<pair<long long, long long> > d_a, d_b;
    long long sum = 0;
    vector<long long> x;
    int division_count_a = 0, division_count_b = 0;
    
    for (long long d : div) {
        d_a.push_back({d, 0});
        d_b.push_back({d, 0});
        
        while (a % d == 0) {
            d_a[d_a.size() - 1].second++;
            a /= d;
            division_count_a++;
        }
        
        while (b % d == 0) {
            d_b[d_b.size() - 1].second++;
            b /= d;
            division_count_b++;
        }
        
        long long c = d_a[d_a.size() - 1].second - d_b[d_b.size() - 1].second;
        sum += d_a[d_a.size() - 1].second - d_b[d_b.size() - 1].second;
        if (c != 0) x.push_back(c);
    }
    
    check_repeated_division(division_count_a);
    check_repeated_division(division_count_b);
    
    sort(x.begin(), x.end());
    long long zn = 1;
    long long fact = 1;
    long long pos = 0;
    
    check_factorial_computation(sum);
    
    for (long long i = 1; i <= sum; ++i) {
        fact *= i;
        fact %= mod;
        while (pos < x.size() && x[pos] == i) {
            zn *= fact;
            zn %= mod;
            pos++;
        }
    }
    long long x1, y1;
    gcd(zn, mod, x1, y1);
    x1 %= mod;
    x1 += mod;
    x1 %= mod;
    return (x1 * fact) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin >> n >> q;
    vector<long long> div;
    long long r = n;
    long long divisor_iterations = 0;
    
    for (long long i = 2; i <= sqrt(n); ++i) {
        divisor_iterations++;
        if (r % i == 0) {
            div.push_back(i);
            while (r % i == 0) r /= i;
        }
    }
    
    check_divisor_loop(divisor_iterations, n);
    
    if (r != 1) div.push_back(r);
    while (q--) {
        long long a, b;
        cin >> a >> b;
        long long x1, y1;
        long long d = gcd(a, b, x1, y1);
        cout << (calc(a, d, div) * calc(b, d, div)) % mod << endl;
    }
}