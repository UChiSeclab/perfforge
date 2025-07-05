#include <bits/stdc++.h>
using namespace std;
vector<int> nextn[64];
vector<int> cost[64];
vector<int> candies;
string colors;
bool visited[64];
int n, k;
char dp[2048][51][2001];

void check_state_space_invariant(int n, const vector<int>& candies, const string& colors) {
    int sameColorSequence = 0;
    int minDifferenceCount = 0;
    for (int i = 1; i < n; ++i) {
        if (colors[i] == colors[i - 1]) {
            sameColorSequence++;
        }
        if (candies[i] > candies[i - 1] && candies[i] - candies[i - 1] <= 2) {
            minDifferenceCount++;
        }
    }
    if (sameColorSequence > n / 2 && minDifferenceCount > n / 2) {
        cerr << "Warning: state_space_invariant triggered - minimal differences in candy counts with long same-color sequences" << endl;
        abort();
    }
}

void check_caching_invariant(int n, int k, const vector<vector<int>>& nextn) {
    int potentialStates = nextn.size() * n * k;
    if (potentialStates > 100000) {  // Arbitrary large threshold for potential states
        cerr << "Warning: caching_invariant triggered - large number of potential states" << endl;
        abort();
    }
}

void check_recursion_invariant(int maxDepthEstimate, int branchFactorEstimate) {
    if (maxDepthEstimate > 10 && branchFactorEstimate > 10) {  // Thresholds for depth and branching
        cerr << "Warning: recursion_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

bool solve(int time, int currNode, int toEat) {
    if (time < 0) {
        return false;
    }
    toEat -= candies[currNode];
    if (toEat <= 0) {
        return true;
    }
    if (time < 2048 && dp[time][currNode][toEat] != -1) {
        return dp[time][currNode][toEat];
    }
    visited[currNode] = true;
    bool res = false;
    for (int i = 0; i < nextn[currNode].size() && !res; ++i) {
        int nextNode = nextn[currNode][i];
        if (visited[nextNode]) {
            continue;
        }
        res = solve(time - cost[currNode][i], nextNode, toEat);
    }
    visited[currNode] = false;
    if (time < 2048) {
        dp[time][currNode][toEat] = int(res);
    }
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int s;
    cin >> n >> s >> k;
    s--;
    candies.resize(n + 1);
    candies[n] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> candies[i];
    }
    cin >> colors;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (colors[i] == colors[j]) {
                continue;
            }
            if (candies[i] >= candies[j]) {
                continue;
            }
            nextn[i].push_back(j);
            cost[i].push_back(abs(i - j));
        }
    }
    for (int i = 0; i < n; ++i) {
        nextn[n].push_back(i);
        cost[n].push_back(abs(i - s));
    }

    // Insert invariant checks
    check_state_space_invariant(n, candies, colors);
    check_caching_invariant(n, k, nextn);
    check_recursion_invariant(n, nextn[0].size()); // Rough estimate for branching factor

    int l = -1, r = ((n + 1) * n) / 2;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (solve(mid, n, k)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (!solve(r, n, k)) {
        cout << -1 << endl;
    } else {
        cout << r << endl;
    }
    return 0;
}