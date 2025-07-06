#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}
long long powmod(long long x, long long y, long long m) {
    if (y == 0) return 1;
    long long p = powmod(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}
long long modif(long long x, long long m) { return (powmod(x, m - 2, m)); }
bool fa(vector<long long> &x, vector<long long> &y) { return x[0] < y[0]; }
bool fa1(vector<long long> &x, vector<long long> &y) { return x[1] < y[1]; }
bool f1(pair<long long, long long> &x, pair<long long, long long> &y) {
    return x.second > y.second;
}
bool f2(pair<long long, long long> &x, pair<long long, long long> &y) {
    return x.first < y.first;
}
bool f3(long long &x, long long &y) { return abs(x) > abs(y); }
long long mxn = 1e6;
vector<long long> b;
vector<long long> ch(mxn, 0ll);
long long tr;
long long m, n, k;

void check_large_initialization(long long mxn, long long n) {
    if (mxn > 10 * n) { // Condition: if mxn is significantly larger than n
        cerr << "Warning: Performance bottleneck condition triggered - large initialization size!" << endl;
        abort();
    }
}

void check_high_trap_processing(long long k, const vector<array<long long, 3>>& c, long long max_agility) {
    int count_restrictive_traps = 0;
    for (const auto& trap : c) {
        if (trap[2] > max_agility) { // Condition: count traps that are restrictive for maximum agility
            count_restrictive_traps++;
        }
    }
    if (count_restrictive_traps > k / 2) { // If more than half of the traps are restrictive
        cerr << "Warning: Performance bottleneck condition triggered - high trap processing complexity!" << endl;
        abort();
    }
}

void check_high_path_complexity(const vector<array<long long, 3>>& c) {
    int active_traps_count = 0;
    for (const auto& trap : c) {
        if (trap[0] != trap[1]) { // If the trap spans multiple positions, count as active
            active_traps_count++;
        }
    }
    if (active_traps_count > c.size() / 2) { // If more than half of the traps are active
        cerr << "Warning: Performance bottleneck condition triggered - high path complexity!" << endl;
        abort();
    }
}

bool meow(long long x, vector<array<long long, 3> > &c) {
    if (x == 0) return true;
    long long yo = 0;
    for (int i = 0; i < mxn; i++) ch[i] = 0;
    long long y = b[b.size() - x];
    for (int i = 0; i < k; i++) {
        if (c[i][2] > y) {
            ch[c[i][0]]++;
            ch[c[i][1] + 1]--;
        }
    }
    long long l = 0;
    for (int i = 0; i < n + 1; i++) {
        l += ch[i];
        yo += 1;
        if (l > 0) yo += 2;
    }
    return yo <= tr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k >> tr;
    check_large_initialization(mxn, n); // Check for large initialization overhead

    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    vector<array<long long, 3> > c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }
    check_high_trap_processing(k, c, b.back()); // Check for high trap processing complexity
    check_high_path_complexity(c); // Check for high path complexity with active traps

    long long l = 0, r = m;
    long long it = 0;
    while (l < r) {
        if (it > 100) {
            cout << "meow";
            break;
        }
        long long mid = (l + r + 1) / 2;
        if (meow(mid, c))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}