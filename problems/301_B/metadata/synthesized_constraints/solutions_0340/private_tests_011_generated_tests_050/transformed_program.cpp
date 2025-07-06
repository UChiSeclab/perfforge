#include <bits/stdc++.h>
using namespace std;

void check_recursion_invariant(int recursionDepth, int stationCount) {
    if (recursionDepth > 50 && stationCount > 80) { 
        cerr << "Warning: Recursion invariant triggered - High recursion depth or station count" << endl;
        abort();
    }
}

void check_favorable_conditions_invariant(long long currentTime, long long distance) {
    if (currentTime > 5000 && distance < 10) {
        cerr << "Warning: Favorable conditions invariant triggered - Excessive exploration due to favorable conditions" << endl;
        abort();
    }
}

void check_path_exploration_invariant(int exploredPathsCount) {
    if (exploredPathsCount > 1000) { 
        cerr << "Warning: Path exploration invariant triggered - Too many paths explored" << endl;
        abort();
    }
}

int n, m, d;
int s1[2];
vector<pair<int, int>> st;
vector<long long> mark;
vector<long long> w;
int recursionDepth = 0;
int exploredPathsCount = 0;

bool dfs(int v, long long a) {
    recursionDepth++;
    exploredPathsCount++;
    
    check_recursion_invariant(recursionDepth, n);
    check_path_exploration_invariant(exploredPathsCount);
    
    if (v == n - 1) {
        recursionDepth--;
        return true;
    }
    
    mark[v] = a;
    bool ans = false;
    
    for (int i = 0; i < st.size(); i++) {
        long long dist = abs(st[v].first - st[i].first);
        dist += abs(st[v].second - st[i].second);
        dist *= d;
        
        check_favorable_conditions_invariant(a, dist);
        
        if (a >= dist) {
            if (i != v && (mark[i] == 0 || mark[i] < a + w[i] - dist)) {
                if (dfs(i, a + w[i] - dist)) ans = true;
            }
        }
    }
    
    recursionDepth--;
    return ans;
}

bool can(int a) {
    mark.assign(st.size(), 0);
    recursionDepth = 0;
    exploredPathsCount = 0;
    return dfs(0, a);
}

int main() {
    int i;
    cin >> n >> d;
    w.push_back(0);
    int a;
    
    for (i = 0; i < (n - 2); ++i) {
        cin >> a;
        w.push_back(a);
    }
    
    w.push_back(0);
    int b;
    
    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        st.push_back(make_pair(a, b));
    }
    
    int ans = 0;
    long long l = 0;
    long long r = 1e12;
    
    while (l <= r) {
        int m = (l + r) / 2;
        if (can(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    cout << ans;
    return 0;
}