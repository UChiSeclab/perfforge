#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0;
    bool t = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') t = true, ch = getchar();
    while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
    return t ? -x : x;
}

void check_large_station_network(int n, int m) {
    if (n > 4000 && m > 15000) {  // Adjusted thresholds based on constraints
        cerr << "Warning: Performance bottleneck condition triggered - Large station network." << endl;
        abort();
    }
}

void check_suboptimal_distribution(int n, vector<int>& start, vector<int>& end) {
    int long_distance_candies = 0;
    for (int i = 0; i < start.size(); ++i) {
        if (abs(end[i] - start[i]) > n / 2) {
            long_distance_candies++;
        }
    }
    if (long_distance_candies > 0.7 * start.size()) {  // Example threshold of 70% of candies
        cerr << "Warning: Performance bottleneck condition triggered - Sub-optimal candy distribution." << endl;
        abort();
    }
}

void check_uneven_distribution(int n, vector<int>& cnt) {
    int max_candies = *max_element(cnt.begin(), cnt.end());
    if (max_candies > 0.4 * cnt.size()) {  // Example threshold of 40% of candies at one station
        cerr << "Warning: Performance bottleneck condition triggered - Uneven candy distribution." << endl;
        abort();
    }
}

int main() {
    int n = read();
    int m = read();
    
    vector<int> start(m), end(m);
    for (int i = 0; i < m; ++i) {
        start[i] = read();
        end[i] = read();
    }
    
    // Check for large station network
    check_large_station_network(n, m);
    
    // Check for suboptimal candy distribution
    check_suboptimal_distribution(n, start, end);
    
    int cnt[5050] = {0}, d[5050];
    for (int i = 1; i <= n; ++i) d[i] = n + 1;
    for (int i = 1; i <= m; ++i) {
        int l = start[i - 1], r = end[i - 1];
        if (r < l) r += n;
        cnt[l] += 1;
        d[l] = min(d[l], r - l);
    }
    
    // Check for uneven candy distribution
    vector<int> cnt_vector(cnt, cnt + n + 1);
    check_uneven_distribution(n, cnt_vector);
    
    int mx = 0;
    for (int i = 1; i <= n; ++i) mx = max(mx, cnt[i]);
    for (int i = 1; i <= n; ++i)
        if (cnt[i] < max(1, mx - 1)) d[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int ans = (mx - 1) * n, mxx = 0;
        for (int j = 1; j <= n; ++j)
            if (cnt[j] == mx) {
                int dis = i <= j ? j - i : j - i + n;
                dis += d[j];
                mxx = max(mxx, dis);
            } else if (cnt[j] == mx - 1) {
                int dis = j < i ? i - j : i - j + n;
                mxx = max(mxx, d[j] - dis);
            }
        printf("%d ", ans + mxx);
    }
    puts("");
    return 0;
}