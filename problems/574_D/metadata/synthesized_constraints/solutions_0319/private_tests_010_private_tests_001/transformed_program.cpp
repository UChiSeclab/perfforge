#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = 3.14159265359;
vector<long long> primes;
void GeneratingPrimes(int top) {
    vector<bool> p(top + 1, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i <= sqrt(top); i++) {
        if (p[i]) {
            for (int j = i * i; j <= top; j += i) {
                p[j] = 0;
            }
        }
    }
    for (int i = 0; i < top + 1; i++)
        if (p[i]) primes.push_back(i);
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
void EXTgcd(long long a, long long b, int& x0, int& y0) {
    if (b == 0) {
        x0 = 1, y0 = 0;
        return;
    }
    EXTgcd(b, a % b, x0, y0);
    long long x1 = y0;
    long long y1 = x0 - (a / b) * y0;
    x0 = x1;
    y0 = y1;
}
long long power(long long n, long long p, long long mod) {
    if (!p) return 1;
    long long ans = 1;
    while (p > 1) {
        if (p & 1) ans = (ans * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return (ans * n) % mod;
}
double dist(double a, double b, double x, double y) {
    return sqrt(pow(a - x, 2) + pow(b - y, 2));
}
double dist3(double a, double b, double c, double x, double y, double z) {
    return sqrt(pow(a - x, 2) + pow(b - y, 2) + pow(c - z, 2));
}
int xadd[9] = {1, -1, 0, 1, -1, 0, 1, -1, 0};
int yadd[9] = {1, -1, 0, -1, 0, 1, 0, 1, -1};
int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};
long long const N = 1e5 + 10;
long long const mod = 1e9 + 7;
long long const INF = 1e9;
int n, a[N];

// Function to check set operation invariant
void check_set_operation_invariant(int n, int setOperations) {
    if (setOperations > 2 * n) { // Arbitrary threshold based on expensive set operations
        cerr << "Warning: Performance bottleneck condition triggered due to excessive set operations!" << endl;
        abort();
    }
}

// Function to check recursion depth invariant
void check_recursion_depth_invariant(int recursionDepth, int uniformHeightCount) {
    if (recursionDepth > 20 && uniformHeightCount > 0.8 * recursionDepth) { // Thresholds based on recursion and uniformity
        cerr << "Warning: Performance bottleneck condition triggered due to excessive recursion depth!" << endl;
        abort();
    }
}

// Function to check loop complexity invariant
void check_loop_complexity_invariant(int n, int loopIterations) {
    if (loopIterations > 3 * n) { // Arbitrary threshold based on loop iterations
        cerr << "Warning: Performance bottleneck condition triggered due to high loop complexity!" << endl;
        abort();
    }
}

// Function to check boundary check invariant
void check_boundary_check_invariant(int n, int similarHeightTowers) {
    if (similarHeightTowers > 0.5 * n) { // Threshold for similar height leading to boundary checks
        cerr << "Warning: Performance bottleneck condition triggered due to excessive boundary checks!" << endl;
        abort();
    }
}

bool chk(int mid) {
    set<int> s, ns;
    for (int i = 0; i < n; i++) s.insert(i), ns.insert(-i);
    
    // Initialize operation counters
    int setOperations = 0;
    int loopIterations = 0;
    int similarHeightTowers = 0;
    int recursionDepth = 0;

    for (int i = 0; i < n; i++) {
        loopIterations++;
        if (mid >= a[i]) {
            int r = mid - a[i];
            auto it = s.lower_bound(i);
            while (it != s.end()) {
                int z = *it;
                if (z - i <= r) {
                    auto x = it++;
                    s.erase(x);
                    if (ns.count(-z)) ns.erase(-z);
                    setOperations++;
                } else
                    break;
            }
            it = ns.lower_bound(-i);
            while (it != ns.end()) {
                int z = *it;
                if (i + z <= r) {
                    auto x = it++;
                    ns.erase(x);
                    if (s.count(-z)) s.erase(-z);
                    setOperations++;
                } else
                    break;
            }
        }
        if (i > 0 && a[i] == a[i - 1]) {
            similarHeightTowers++;
        }
        recursionDepth++;
    }
    
    // Apply the checks
    check_set_operation_invariant(n, setOperations);
    check_recursion_depth_invariant(recursionDepth, similarHeightTowers);
    check_loop_complexity_invariant(n, loopIterations);
    check_boundary_check_invariant(n, similarHeightTowers);
    
    for (int x : s) {
        x++;
        if (x > mid && x <= n - mid) return 0;
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (chk(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << hi + 1;
    return 0;
}