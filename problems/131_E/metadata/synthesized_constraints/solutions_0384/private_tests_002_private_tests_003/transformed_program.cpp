#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> m1, m2, m3, m4;
vector<int>::iterator it, k;
int n, m, x[100010], y[100010], ans[77] = {0};
map<pair<int, int>, bool> ss;

// Function implementations for the performance checks
void check_repeated_sorting_invariant(int m, const map<int, vector<int>>& m1, const map<int, vector<int>>& m2, const map<int, vector<int>>& m3, const map<int, vector<int>>& m4) {
    for (const auto& pair : {m1, m2, m3, m4}) {
        for (const auto& entry : pair) {
            if (entry.second.size() > m / 4) {
                cerr << "Warning: sort_invariant triggered - repeatedly sorting large data sets" << endl;
                abort();
            }
        }
    }
}

void check_frequent_search_invariant(int m, int n) {
    if (m > n * n / 10) {
        cerr << "Warning: search_invariant triggered - frequent searching due to high queen density" << endl;
        abort();
    }
}

void check_high_frequency_trigger_invariant(int m, const map<pair<int, int>, bool>& ss) {
    if (ss.size() > m / 2) {
        cerr << "Warning: high_frequency_invariant triggered - high frequency of repeated data access" << endl;
        abort();
    }
}

void check_threshold_complexity_invariant(int n, int m) {
    if (m > n * n / 4) {
        cerr << "Warning: threshold_invariant triggered - dense queen distribution" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x[i], &y[i]);
        m1[x[i]].push_back(y[i]);
        m2[y[i]].push_back(x[i]);
        m3[x[i] + y[i] - 1].push_back(x[i]);
        m4[y[i] - x[i]].push_back(x[i]);
    }

    // Insert checks after initial data structure setup
    check_threshold_complexity_invariant(n, m);

    for (int i = 0; i < m; i++) {
        if (!ss[make_pair(1, x[i])]) {
            sort(m1[x[i]].begin(), m1[x[i]].end());
            ss[make_pair(1, x[i])] = true;
        }
        if (!ss[make_pair(2, y[i])]) {
            sort(m2[y[i]].begin(), m2[y[i]].end());
            ss[make_pair(2, y[i])] = true;
        }
        if (!ss[make_pair(3, x[i] + y[i] - 1)]) {
            sort(m3[x[i] + y[i] - 1].begin(), m3[x[i] + y[i] - 1].end());
            ss[make_pair(3, x[i] + y[i] - 1)] = true;
        }
        if (!ss[make_pair(4, y[i] - x[i])]) {
            sort(m4[y[i] - x[i]].begin(), m4[y[i] - x[i]].end());
            ss[make_pair(4, y[i] - x[i])] = true;
        }
    }

    // Insert checks after potential sorting
    check_repeated_sorting_invariant(m, m1, m2, m3, m4);
    check_high_frequency_trigger_invariant(m, ss);

    for (int i = 0; i < m; i++) {
        int cnt = 0;
        it = lower_bound(m1[x[i]].begin(), m1[x[i]].end(), y[i]);
        k = --m1[x[i]].end();
        if (it != k && k != m1[x[i]].begin()) cnt++;
        if (it != m1[x[i]].begin()) cnt++;
        it = lower_bound(m2[y[i]].begin(), m2[y[i]].end(), x[i]);
        k = --m2[y[i]].end();
        if (it != k && k != m2[y[i]].begin()) cnt++;
        if (it != m2[y[i]].begin()) cnt++;
        it = lower_bound(m3[x[i] + y[i] - 1].begin(), m3[x[i] + y[i] - 1].end(), x[i]);
        k = --m3[x[i] + y[i] - 1].end();
        if (it != k && k != m3[x[i] + y[i] - 1].begin()) cnt++;
        if (it != m3[x[i] + y[i] - 1].begin()) cnt++;
        it = lower_bound(m4[y[i] - x[i]].begin(), m4[y[i] - x[i]].end(), x[i]);
        k = --m4[y[i] - x[i]].end();
        if (it != k && k != m4[y[i] - x[i]].begin()) cnt++;
        if (it != m4[y[i] - x[i]].begin()) cnt++;
        ans[cnt]++;
    }

    // Insert check for frequent searches
    check_frequent_search_invariant(m, n);
    
    for (int i = 0; i < 9; i++) 
        printf("%d ", ans[i]);
    cout << endl;
    return 0;
}