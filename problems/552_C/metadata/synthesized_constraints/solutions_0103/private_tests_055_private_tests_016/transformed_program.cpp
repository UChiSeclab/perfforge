#include <bits/stdc++.h>
using namespace std;

// Function to check potential high branching factor and deep recursion
void check_branching_factor_and_depth(long long int w) {
    if (w <= 10) {
        cerr << "Warning: Potential high branching factor and deep recursion due to small base w!" << endl;
        abort();
    }
}

// Function to check potential exponential growth of search space
void check_exponential_growth(long long int w, long long int m) {
    if (w <= 10 && m > 100000000) {
        cerr << "Warning: Potential exponential growth of search space!" << endl;
        abort();
    }
}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long int infLL = 90000000000000000;
int MOD1 = 1000000007;
int MOD2 = 1000000009;

inline bool checkBit(long long int n, long long int i) {
    return n & (1LL << i);
}

inline long long int setBit(long long int n, long long int i) {
    return n | (1LL << i);
}

inline long long int resetBit(long long int n, long long int i) {
    return n & (~(1LL << i));
}

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

inline bool isLeapYear(long long int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

inline void normal(long long int &a) {
    a %= 1000000000007LL;
    (a < 0) && (a += 1000000000007LL);
}

inline long long int modMul(long long int a, long long int b) {
    a %= 1000000000007LL, b %= 1000000000007LL;
    normal(a), normal(b);
    return (a * b) % 1000000000007LL;
}

inline long long int modAdd(long long int a, long long int b) {
    a %= 1000000000007LL, b %= 1000000000007LL;
    normal(a), normal(b);
    return (a + b) % 1000000000007LL;
}

inline long long int modSub(long long int a, long long int b) {
    a %= 1000000000007LL, b %= 1000000000007LL;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}

inline long long int modPow(long long int b, long long int p) {
    long long int r = 1LL;
    while (p) {
        if (p & 1) r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}

inline long long int modDiv(long long int a, long long int b) {
    return modMul(a, modPow(b, 1000000000007LL - 2));
}

bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

long long int converter(string a) {
    long long int i, mul = 1, r, t, ans = 0LL;
    if (a.length() == 0) return 0;
    for (i = a.length() - 1; i >= 0; i--) {
        t = a[i] - '0';
        r = t % 10;
        ans += (mul * r);
        mul = mul * 10;
    }
    return ans;
}

vector<long long int> w;
long long int n, m;
bool flag;

void recur(long long int scale, long long int mass, long long int idx) {
    if (scale > 3000000000 || mass > 3000000000 || idx == w.size()) return;
    if (scale == mass) {
        flag = true;
        return;
    }
    recur(scale + w[idx], mass, idx + 1);
    recur(scale, mass + w[idx], idx + 1);
    recur(scale, mass, idx + 1);
}

int main() {
    scanf("%lld %lld", &n, &m);

    // Check potential performance bottlenecks
    check_branching_factor_and_depth(n);
    check_exponential_growth(n, m);

    if (n == 2 || n == 3) {
        cout << "YES";
        return 0;
    }
    w.push_back(1);
    long long int i = 1LL;
    while (i <= 3000000000) {
        i = i * n;
        w.push_back(i);
    }
    flag = false;
    recur(0, m, 0);
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}