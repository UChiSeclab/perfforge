#include <bits/stdc++.h>
const int md = 1e9 + 7;
const long long hs = 199;
const long double eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a, b, mn = 1e9;

void check_recursion_invariant(int depth, int maxBranchingFactor, int thresholdDepth = 100, int thresholdBranching = 20) {
    if (depth > thresholdDepth || maxBranchingFactor > thresholdBranching) {
        cerr << "Warning: Recursion depth or branching factor too high!" << endl;
        abort();
    }
}

void check_length_invariant(int n, int a, int b, int lengthRatioThreshold = 4) {
    if (n / a >= lengthRatioThreshold || n / b >= lengthRatioThreshold) {
        cerr << "Warning: Bar length to side length ratio too high!" << endl;
        abort();
    }
}

void check_similarity_invariant(int n, int a, int b, int similarityThreshold = 2) {
    if ((abs(a - b) < similarityThreshold) && (a < n / 2 && b < n / 2)) {
        cerr << "Warning: Side lengths are too similar and small!" << endl;
        abort();
    }
}

void check(vector<int>& x, vector<bool>& took, int left = 0, int dis = 0, int depth = 0) {
    int cnt = 0;
    int maxBranchingFactor = 6;  // Maximum at any point due to loop
    check_recursion_invariant(depth, maxBranchingFactor);
  
    for (int i = 0; i < 6; i++) {
        if (!took[i]) {
            cnt++, took[i] = true;
            if (x[i] <= left) check(x, took, left - x[i], dis, depth + 1);
            check(x, took, n - x[i], dis + 1, depth + 1);
            took[i] = false;
        }
    }
    if (!cnt) mn = min(mn, dis);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
  
    // Check length and similarity invariants before processing
    check_length_invariant(n, a, b);
    check_similarity_invariant(n, a, b);
  
    vector<int> tot = {a, a, a, a, b, b};
    vector<bool> took(6, false);
    check(tot, took);
    cout << mn << '\n';
}