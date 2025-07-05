#include <bits/stdc++.h>
using namespace std;

int n, T;
int a[101], cnt[401];
vector<int> seq;
int dp[301][10001];
int cache[301][10001];

// Checker functions
void check_large_sequence_invariant(int seqSize, int T) {
    if (seqSize > 1000 && T > 1000) { // arbitrary threshold for large sequence
        cerr << "Warning: Performance bottleneck condition triggered - large sequence due to high T value!" << endl;
        abort();
    }
}

void check_recursive_calls_invariant(int lisCalls, int lis2Calls, int T) {
    if (lisCalls > 100 && lis2Calls > 100 && T > 1000) { // arbitrary thresholds
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls!" << endl;
        abort();
    }
}

int solve(int maxi) {
    int ret = 0;
    for (int i = seq.size() - 1; i >= 0; i--) {
        if (seq[i] > maxi) continue;
        for (int j = i + 1; j < seq.size(); j++) {
            if (seq[j] >= seq[i]) dp[maxi][i] = max(dp[maxi][i], dp[maxi][j] + 1);
        }
        ret = max(ret, dp[maxi][i]);
    }
    return ret;
}

int binary(const vector<int>& in, int ind, int val, const int maxK) {
    if (in[ind - 1] <= val && val < in[ind]) return ind;
    if (val < in[ind])
        return binary(in, (ind + 1) / 2, val, ind);
    else
        return binary(in, (ind + maxK) / 2, val, maxK);
}

int lis(int maxi) {
    int len = seq.size();
    vector<int> c = vector<int>(len + 2, 303);
    int firstMin = -1;
    c[0] = -1;
    for (int i = 0; i < len; i++) {
        if (seq[i] <= maxi) {
            c[1] = seq[i];
            cache[maxi][i] = 1;
            firstMin = i;
            break;
        }
    }
    if (firstMin == -1) return 0;
    int sz = 1;
    for (int i = firstMin + 1; i < seq.size(); i++) {
        if (seq[i] > maxi) continue;
        if (seq[i] < c[1]) {
            c[1] = seq[i];
            cache[maxi][i] = 1;
        } else if (seq[i] >= c[sz]) {
            sz++;
            c[sz] = seq[i];
            cache[maxi][i] = sz;
        } else {
            int k = binary(c, sz, seq[i], sz);
            c[k] = seq[i];
            cache[maxi][i] = k;
        }
    }
    c.clear();
    return sz;
}

int lis2(int mini) {
    int len = seq.size();
    vector<int> c = vector<int>(len + 2, 303);
    int firstMin = -1;
    c[0] = -1;
    for (int i = 0; i < len; i++) {
        if (seq[i] >= mini) {
            c[1] = seq[i];
            firstMin = i;
            break;
        }
    }
    if (firstMin == -1) return 0;
    int sz = 1;
    for (int i = firstMin + 1; i < seq.size(); i++) {
        if (seq[i] < mini) continue;
        if (seq[i] < c[1]) {
            c[1] = seq[i];
        } else if (seq[i] >= c[sz]) {
            sz++;
            c[sz] = seq[i];
        } else {
            int k = binary(c, sz, seq[i], sz);
            c[k] = seq[i];
        }
    }
    c.clear();
    return sz;
}

int main() {
    cin >> n >> T;
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 301; i++)
        for (int j = 0; j < 10001; j++) cache[i][j] = 0;
    seq.clear();
    for (int i = 0; i < n; i++) cin >> a[i];
    int ret = 0;
    
    check_large_sequence_invariant(n * n, T); // Check for large sequence due to high T

    if (T <= 2 * n) {
        for (int i = 0; i < T; i++)
            for (int j = 0; j < n; j++) seq.push_back(a[j]);
        ret = lis(300);
        cout << ret << endl;
        return 0;
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) seq.push_back(a[j]);
        for (int j = 0; j < n; j++) cnt[a[j]]++;

        int lisCalls = 0, lis2Calls = 0;
        
        for (int i = 1; i < 301; i++) lisCalls += lis(i);
        for (int i = 1; i < 301; i++) {
            int pre = 0;
            pre = lis(i);
            int suf = 0;
            suf = lis2(i);
            lis2Calls++;
            ret = max(ret, cnt[i] * (T - (2 * n)) + pre + suf);
        }

        check_recursive_calls_invariant(lisCalls, lis2Calls, T); // Check for excessive recursive calls

        cout << ret << endl;
    }
    return 0;
}