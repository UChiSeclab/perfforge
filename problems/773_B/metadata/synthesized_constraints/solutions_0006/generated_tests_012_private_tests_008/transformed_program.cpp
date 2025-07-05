#include <bits/stdc++.h>
using namespace std;

int n, a[125][125];
int c[125];

bool can(int p1, int p2, int p3, int p4, int p5, int smurfs) {
    int total = n + smurfs;
    int lower[7];
    int upper[7];
    upper[1] = total;
    upper[2] = total >> 1;
    upper[3] = total >> 2;
    upper[4] = total >> 3;
    upper[5] = total >> 4;
    upper[6] = total >> 5;
    lower[1] = upper[2] + 1;
    lower[2] = upper[3] + 1;
    lower[3] = upper[4] + 1;
    lower[4] = upper[5] + 1;
    lower[5] = upper[6] + 1;
    lower[6] = 0;
    int p[] = {0, p1, p2, p3, p4, p5};
    for (int i = 1; i <= 5; i++) {
        if (lower[p[i]] > upper[p[i]]) return false;
        if (c[i] > upper[p[i]]) return false;
        if (c[i] < lower[p[i]]) {
            if (a[1][i] == -1) return false;
        }
        if (c[i] + smurfs < lower[p[i]]) return false;
    }
    return true;
}

int required(int p1, int p2, int p3, int p4, int p5) {
    for (int i = 0; i < 10000; i++) {
        check_high_iteration_invariant(i);  // Check for high iteration count
        if (can(p1, p2, p3, p4, p5, i)) return i;
    }
    return INT_MAX;
}

int score(int p, int t) {
    if (t == -1) return 0;
    return p * 500 - (p * 2) * t;
}

bool solves(int p1, int p2, int p3, int p4, int p5) {
    int vasya = 0, petya = 0;
    vasya += score(p1, a[1][1]);
    vasya += score(p2, a[1][2]);
    vasya += score(p3, a[1][3]);
    vasya += score(p4, a[1][4]);
    vasya += score(p5, a[1][5]);
    petya += score(p1, a[2][1]);
    petya += score(p2, a[2][2]);
    petya += score(p3, a[2][3]);
    petya += score(p4, a[2][4]);
    petya += score(p5, a[2][5]);
    return vasya > petya;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int p = 1; p <= 5; p++) {
            cin >> a[i][p];
            if (a[i][p] != -1) c[p] += 1;
        }
    }
    int answer = INT_MAX;
    int combinations = 0;
    for (int p1 = 1; p1 <= 6; p1++) {
        for (int p2 = 1; p2 <= 6; p2++) {
            for (int p3 = 1; p3 <= 6; p3++) {
                for (int p4 = 1; p4 <= 6; p4++) {
                    for (int p5 = 1; p5 <= 6; p5++) {
                        combinations++;
                        check_scoring_permutation_invariant(combinations);  // Check scoring permutations
                        if (solves(p1, p2, p3, p4, p5)) {
                            answer = min(answer, required(p1, p2, p3, p4, p5));
                        }
                    }
                }
            }
        }
    }
    if (answer == INT_MAX) answer = -1;
    cout << answer << endl;
}