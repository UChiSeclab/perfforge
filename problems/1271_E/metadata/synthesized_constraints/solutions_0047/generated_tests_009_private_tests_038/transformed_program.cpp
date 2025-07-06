#include <bits/stdc++.h>
using namespace std;
const int MAXN = 64 + 20;
long long n, k;
long long d[MAXN][3];
vector<pair<long long, long long>> vec;
map<long long, long long> ma;

void check_logarithmic_depth_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Logarithmic depth invariant triggered - costly repeated division operations!" << endl;
        abort();
    }
}

void check_nested_logic_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Nested logic invariant triggered - extensive use of nested conditionals and iterations!" << endl;
        abort();
    }
}

void check_data_structure_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Data structure invariant triggered - managing large data structures!" << endl;
        abort();
    }
}

void check_function_call_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Function call invariant triggered - repeated calls with large values!" << endl;
        abort();
    }
}

long long ln(long long a) {
    long long l = 0;
    while (a) {
        a /= 2;
        l++;
    }
    return l;
}

long long getnum(long long l) {
    long long alen = ln(l), blen = ln(n);
    memset(d, 0, sizeof(d));
    if ((n >> (blen - alen)) > (l))
        d[alen][0] = 1;
    else if ((n >> (blen - alen)) == (l))
        d[alen][1] = 1;
    else if ((n >> (blen - alen)) < (l))
        d[alen][2] = 1;
    if ((l & 1) == 0 && (l + 1) <= n) {
        if ((n >> (blen - alen)) > (l + 1))
            d[alen][0] += 1;
        else if ((n >> (blen - alen)) == (l + 1))
            d[alen][1] += 1;
        else if ((n >> (blen - alen)) < (l + 1))
            d[alen][2] += 1;
    }
    long long ans = d[alen][0] + d[alen][1] + d[alen][2];

    // Check for nested logic invariant
    check_nested_logic_invariant(blen > 60); // Example condition based on depth

    for (long long i = alen; i < blen; ++i) {
        if ((n >> (blen - i - 1)) & 1) {
            d[i + 1][0] = d[i][0] * 2 + d[i][1];
            d[i + 1][2] = d[i][2] * 2;
            d[i + 1][1] = d[i][1];
        } else {
            d[i + 1][0] = d[i][0] * 2;
            d[i + 1][2] = d[i][2] * 2 + d[i][1];
            d[i + 1][1] = d[i][1];
        }
        if (i != blen - 1) {
            for (long long j = 0; j < 3; ++j) {
                ans += d[i + 1][j];
            }
        } else {
            for (long long j = 0; j < 2; ++j) {
                ans += d[i + 1][j];
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> k;
    ma[1] = n;

    // Check for data structure invariant
    check_data_structure_invariant(n > 1e12); // Example threshold

    long long maxn = 1;
    for (long long m = n; m > 1;) {
        vec.clear();
        for (auto i : ma) {
            vec.emplace_back(i.first, i.second);
        }
        for (auto i : vec) {
            if ((i.second & 1) && getnum(i.second - 1) > maxn) {
                ma[getnum(i.second - 1)] = i.second - 1;
                maxn = getnum(i.second - 1);
            }
            if (!(i.second & 1) && i.second > 2 && getnum(i.second - 2) > maxn) {
                ma[getnum(i.second - 2)] = i.second - 2;
                maxn = getnum(i.second - 2);
            }
            if (maxn < getnum(i.second / 2)) {
                ma[getnum(i.second / 2)] = i.second / 2;
                maxn = getnum(i.second / 2);
            }

            // Check for function call invariant
            check_function_call_invariant(i.second > 1e12); // Example threshold
        }
        for (auto i : ma) {
            m = min(m, i.second);
        }
    }
    vec.clear();
    for (auto i : ma) {
        vec.emplace_back(i.first, i.second);
    }
    int idx =
        lower_bound(vec.begin(), vec.end(), pair<long long, long long>(k, 0)) -
        vec.begin();
    cout << vec[idx].second << endl;
}