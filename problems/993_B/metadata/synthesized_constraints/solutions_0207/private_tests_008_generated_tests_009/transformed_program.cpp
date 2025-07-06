#include <bits/stdc++.h>
using namespace std;

int Gcd(int a, int b) {
    if (b == 0) return a;
    return Gcd(b, a % b);
}

int Lcm(int a, int b) { return a / Gcd(a, b) * b; }

inline long long read() {
    long long f = 1, x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int maxn = 1e6 + 10;
pair<int, int> a[maxn], b[maxn];
int cnt[maxn];

// Function to check high density of matching pairs
void check_matching_pairs_density(int sharedElementsCount, int threshold) {
    if (sharedElementsCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high density of matching pairs!" << endl;
        abort();
    }
}

// Function to check nested loop overhead
void check_nested_loop_overhead(int n, int m, int threshold) {
    if ((n * m) > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive nested loop iterations!" << endl;
        abort();
    }
}

// Function to check redundant checking
void check_redundant_checking(int uniqueCommonNumbers, int threshold) {
    if (uniqueCommonNumbers > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to redundant checking!" << endl;
        abort();
    }
}

int check(pair<int, int> a, pair<int, int> b) {
    if (a == b) return -1;
    if (a.second == b.first && a.first == b.second) return -1;
    if (a.first == b.first || a.first == b.second) {
        return a.first;
    } else if (a.second == b.first || a.second == b.second) {
        return a.second;
    } else {
        return -1;
    }
}

int main() {
    int n = read(), m = read();

    // Check nested loop overhead before main processing
    check_nested_loop_overhead(n, m, 100);

    for (int i = 1; i <= n; i++) {
        a[i].first = read();
        a[i].second = read();
    }
    for (int i = 1; i <= m; i++) {
        b[i].first = read();
        b[i].second = read();
    }

    int tag = 1, cur = 0, val = -1;
    for (int i = 1; i <= n; i++) {
        vector<int> tmp;
        tmp.clear();
        for (int j = 1; j <= m; j++) {
            int pos = check(a[i], b[j]);
            if (pos != -1) {
                tmp.push_back(pos);
            }
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        // Check for redundant checking within this loop
        check_redundant_checking(tmp.size(), 2);

        if (tmp.size() >= 2) {
            puts("-1");
            return 0;
        } else if (tmp.size() > 0) {
            int num = tmp[0];
            cnt[num]++;
            if (cnt[num] == 1) {
                cur++;
                val = num;
                if (cur >= 2) {
                    tag = 0;
                }
            }
        }
    }

    swap(b, a);
    for (int i = 1; i <= m; i++) {
        vector<int> tmp;
        tmp.clear();
        for (int j = 1; j <= n; j++) {
            int pos = check(a[i], b[j]);
            if (pos != -1) {
                tmp.push_back(pos);
            }
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        // Check for redundant checking within this loop
        check_redundant_checking(tmp.size(), 2);

        if (tmp.size() >= 2) {
            puts("-1");
            return 0;
        }
    }

    if (tag) {
        printf("%d\n", val);
    } else {
        printf("0\n");
    }
    return 0;
}