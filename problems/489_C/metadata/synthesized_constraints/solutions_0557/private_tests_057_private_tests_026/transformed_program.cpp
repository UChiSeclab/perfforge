#include <bits/stdc++.h>
using namespace std;

// Function prototypes for invariant checks
void check_large_m_small_s_invariant(int m, int s) {
    if (m > 90 && s < 10) {
        cerr << "Warning: Large m and small s invariant triggered - potential recursion depth issue!" << endl;
        abort();
    }
}

void check_recursive_exploration_invariant(int m, int s) {
    if (m > 80 && s < 10) {
        cerr << "Warning: Recursive exploration invariant triggered - high branching factor possible!" << endl;
        abort();
    }
}

void check_memoization_efficiency_invariant(int m, int s) {
    if (m > 70 && s < 5) {
        cerr << "Warning: Memoization efficiency invariant triggered - repeated evaluations possible!" << endl;
        abort();
    }
}

bool learnt[102][901];
bool learntmin[102][901];
bool mem[102][901];
bool memmin[102][901];
int maxnum[102];
int minnum[102];
int sum;
int n;

bool dp(int pos, int need) {
    if (pos > n) {
        if (need != 0)
            return false;
        else
            return true;
    }
    if (learnt[pos][need]) return mem[pos][need];
    int mx = -1;
    bool able = false;
    bool can0, can1, can2, can3, can4, can5, can6, can7, can8, can9;
    if (pos != 1) {
        bool can = dp(pos + 1, need);
        if (can) {
            learnt[pos][need] = true;
            mem[pos][need] = true;
            mx = 0;
            maxnum[pos] = mx;
            return true;
        }
    }
    for (int i = 1; i <= 9; i++) {
        bool can = dp(pos + 1, need - i);
        if (can) {
            learnt[pos][need] = true;
            mem[pos][need] = true;
            mx = i;
            maxnum[pos] = mx;
            return true;
        }
    }
    learnt[pos][need] = true;
    mem[pos][need] = false;
    return false;
}

bool dpmin(int pos, int need) {
    if (pos > n) {
        if (need == 0)
            return true;
        else
            return false;
    }
    if (learntmin[pos][need]) return memmin[pos][need];
    int mx = -1;
    bool able = false;
    bool can0, can1, can2, can3, can4, can5, can6, can7, can8, can9;
    for (int i = 9; i >= 1; i--) {
        bool can = dpmin(pos + 1, need - i);
        if (can) {
            learntmin[pos][need] = true;
            memmin[pos][need] = true;
            mx = i;
            minnum[pos] = mx;
            return true;
        }
    }
    if (pos != 1) {
        bool can = dpmin(pos + 1, need);
        if (can) {
            learntmin[pos][need] = true;
            memmin[pos][need] = true;
            mx = 0;
            minnum[pos] = mx;
            return true;
        }
    }
    learntmin[pos][need] = true;
    memmin[pos][need] = false;
    return false;
}

int main() {
    cin >> n >> sum;

    // Perform invariant checks after input reading
    check_large_m_small_s_invariant(n, sum);
    check_recursive_exploration_invariant(n, sum);
    check_memoization_efficiency_invariant(n, sum);

    memset(mem, false, sizeof(mem));
    memset(learnt, false, sizeof(learnt));
    memset(learntmin, false, sizeof(learntmin));
    memset(memmin, false, sizeof(memmin));
    memset(maxnum, -1, sizeof(maxnum));
    memset(minnum, -1, sizeof(minnum));

    if (n == 1 && sum == 0) {
        cout << "0 0";
        return 0;
    }
    bool posmin = dp(1, sum);
    bool posmax = dpmin(1, sum);
    if (posmax && posmin) {
        for (int i = 1; i <= n; i++) {
            cout << maxnum[i];
        }
        cout << " ";
        for (int i = 1; i <= n; i++) {
            cout << minnum[i];
        }
    } else
        cout << "-1 -1";
    return 0;
}