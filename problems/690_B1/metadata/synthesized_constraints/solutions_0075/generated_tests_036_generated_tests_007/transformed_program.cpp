#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;

mt19937 ggen;
int n;
int f[500][500];
int nf[500][500];
int u[500][500];
int timer;
vector<pair<int, int> > ones;
vector<pair<int, int> > cand;
int sm = 0;

// Function to check candidate size invariant
void check_candidate_size_invariant(size_t candidateSize) {
    if (candidateSize > 1000) {
        cerr << "Warning: Candidate size invariant triggered - too many candidate points!" << endl;
        abort();
    }
}

// Function to check nested loop invariant
void check_nested_loop_invariant(int x1, int x2, int yy1, int y2) {
    int area = (x2 - x1 + 1) * (y2 - yy1 + 1);
    if (area > 400) {
        cerr << "Warning: Nested loop invariant triggered - large area checked!" << endl;
        abort();
    }
}

// Function to check contamination level invariant
void check_contamination_level_invariant(size_t levelOneCount) {
    if (levelOneCount > 100) {
        cerr << "Warning: Contamination level invariant triggered - excessive level 1 points!" << endl;
        abort();
    }
}

void inc(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    if (u[x][y] != timer) {
        cand.push_back(pair<int, int>(x, y));
        nf[x][y] = 0;
        u[x][y] = timer;
    }
    nf[x][y]++;
}

bool check(int x1, int yy1, int x2, int y2) {
    if (x1 < 0 || x1 > n || x2 < 0 || x2 > n || yy1 < 0 || yy1 > n || y2 < 0 || y2 > n)
        return false;
    if (x1 >= x2 || yy1 >= y2) return false;

    // Check the nested loop invariant
    check_nested_loop_invariant(x1, x2, yy1, y2);

    memset(nf, 0, sizeof nf);
    cand.clear();
    timer++;
    for (int i = x1; i <= x2; i++) {
        for (int j = yy1; j <= y2; j++) {
            inc(i, j);
            inc(i, j - 1);
            inc(i - 1, j);
            inc(i - 1, j - 1);
        }
    }
    int ssm = 0;
    timer++;
    for (int i = 0; i < (int)cand.size(); i++) {
        int x = cand[i].first;
        int y = cand[i].second;
        if (u[x][y] == timer) continue;
        u[x][y] = timer;
        if (f[x][y] != nf[x][y]) return false;
        ssm += nf[x][y];
    }
    // Check the candidate size invariant
    check_candidate_size_invariant(cand.size());
    return (sm == ssm);
}

void solve() {
    cin >> n;
    int levelOneCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            f[i][j] = c - '0';
            sm += f[i][j];
            if (f[i][j]) ones.push_back(pair<int, int>(i, j));
            if (f[i][j] == 1) levelOneCount++;
        }
    }

    // Check the contamination level invariant
    check_contamination_level_invariant(levelOneCount);

    sort(ones.begin(), ones.end());
    if (ones.size() == 0) {
        cout << "No";
        return;
    }
    int vars = 0;
    int x1 = ((int)(1e9) + 1337), x2 = -((int)(1e9) + 1337),
        yy1 = ((int)(1e9) + 1337), y2 = -((int)(1e9) + 1337);

    for (int i = 0; i < (int)ones.size(); i++) {
        x1 = min(x1, ones[i].first);
        x2 = max(x2, ones[i].first);
        yy1 = min(yy1, ones[i].second);
        y2 = max(y2, ones[i].second);
    }
    if (x1 - x2 == 0 || yy1 - y2 == 0) {
        cout << "No";
        return;
    }
    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            for (int ii = -3; ii <= 3; ii++) {
                for (int jj = -3; jj <= 3; jj++) {
                    if (check(x1 + i, yy1 + j, x2 + ii, y2 + jj)) {
                        vars++;
                    }
                }
            }
        }
    }
    if (vars > 0)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(1313);
    ggen = mt19937(13);
    solve();
    return 0;
}