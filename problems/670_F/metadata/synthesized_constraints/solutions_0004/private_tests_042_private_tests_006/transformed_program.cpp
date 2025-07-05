#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 3, C = 8 + 3;
string s, a, m1, m2, m3;
int k[C], d;

void check_conversion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to excessive integer to string conversion!" << endl;
        abort();
    }
}

void check_search_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to exhaustive search over a large range!" << endl;
        abort();
    }
}

void input() {
    cin >> s >> a;
    d = s.size();
    for (int i = 0; i < s.size(); i++) k[s[i] - '0']++;
    for (int i = 0; i < a.size(); i++) k[a[i] - '0']--;
}

string chg(int n) {
    string res;
    while (n) {
        res += (n % 10) + '0';
        n /= 10;
    }
    for (int i = 0; i < res.size() / 2; i++)
        swap(res[i], res[res.size() - i - 1]);
    return res;
}

bool check(int n) {
    string x = chg(n);
    if (s.size() - x.size() != n) return false;
    int y[10 + 3];
    for (int i = 0; i < 10; i++) y[i] = k[i];
    for (int i = 0; i < x.size(); i++)
        if (y[x[i] - '0'] < 1)
            return false;
        else
            y[x[i] - '0']--;
    if ((a[0] - '0') > 0) return true;
    for (int i = 1; i < 10; i++)
        if (y[i]) return true;
    return false;
}

void solve() {
    if (s.size() == 2) cout << a << endl, exit(0);
    int x;
    
    // Checking for the exhaustive search invariant before the loop
    check_search_invariant(N > 100000); // Arbitrary threshold to demonstrate the check

    for (int i = N; i > 0; i--) {
        // Check conversion invariant for high conversion count
        check_conversion_invariant(i > 500000); // Arbitrary threshold to demonstrate the check
        if (check(i) == true) {
            x = i;
            break;
        }
    }
    
    while (x) d--, k[x % 10]--, x /= 10;
}

char f() {
    for (int i = 1; i < 10; i++)
        if (k[i]) return i + '0';
    return '0';
}

void make() {
    m1 += a;
    for (int i = 0; i < 10; i++) {
        int x = k[i];
        while (x--) m1 += i + '0';
    }
    if (d == a.size()) cout << a << endl, exit(0);
    int x = a[0] - '0';
    char c = f();
    m2 += c, k[c - '0']--;
    for (int i = 0; i < x; i++) {
        int y = k[i];
        while (y--) m2 += i + '0';
    }
    m2 += a;
    for (int i = x; i < 10; i++) {
        int y = k[i];
        while (y--) m2 += i + '0';
    }
    m3 += c;
    for (int i = 0; i <= x; i++) {
        int y = k[i];
        while (y--) m3 += i + '0';
    }
    m3 += a;
    for (int i = x + 1; i < 10; i++) {
        int y = k[i];
        while (y--) m3 += i + '0';
    }
    if (c == '0')
        cout << m1;
    else if (a[0] == '0')
        cout << min(m2, m3);
    else
        cout << min(m1, min(m2, m3));
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input(), solve(), make();
    return 0;
}