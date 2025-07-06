#include <bits/stdc++.h>
using namespace std;

vector<string> rotate(vector<string> a) {
    int n = (int((a.size())));
    int m = (int((a[0].size())));
    vector<string> b(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[i] += "@";
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][n - i - 1] = a[i][j];
        }
    }
    return b;
}

vector<string> flipV(vector<string> a) {
    int n = (int((a.size())));
    int m = (int((a[0].size())));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            swap(a[i][j], a[i][m - j - 1]);
        }
    }
    return a;
}

vector<string> flipH(vector<string> a) {
    int n = (int((a.size())));
    int m = (int((a[0].size())));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            swap(a[i][j], a[n - i - 1][j]);
        }
    }
    return a;
}

bool same(vector<string>& a, vector<string>& b) {
    for (int i = 0; i < (int((a.size()))); i++) {
        for (int j = 0; j < (int((a.size()))); j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

// Checker functions
void check_rotation_invariant(int rotationCount) {
    if (rotationCount > 90) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive rotations!" << endl;
        abort();
    }
}

void check_permutation_invariant(int permutationCount) {
    if (permutationCount > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive permutations!" << endl;
        abort();
    }
}

void check_flip_invariant(int flipCount) {
    if (flipCount > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive flips!" << endl;
        abort();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> a;
    vector<string> c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c.push_back(s);
    }
    int cm[] = {0, 1, 2, 3, 4};
    int rotationCount = 0, permutationCount = 0, flipCount = 0;  // Counters for invariants

    do {
        permutationCount++;
        check_permutation_invariant(permutationCount);  // Check for excessive permutations

        vector<string> b = a;
        for (int i = 0; i < 5; i++) {
            if (cm[i] == 0) {
                b = flipH(b);
                flipCount++;
                check_flip_invariant(flipCount);  // Check for excessive flips
            } else if (cm[i] == 4) {
                b = flipV(b);
                flipCount++;
                check_flip_invariant(flipCount);  // Check for excessive flips
            } else {
                for (int j = 0; j < cm[i]; j++) {
                    b = rotate(b);
                    rotationCount++;
                    check_rotation_invariant(rotationCount);  // Check for excessive rotations
                }
            }
            if (same(b, c)) {
                cout << "Yes";
                return;
            }
        }
    } while (next_permutation(cm, cm + 5));
    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}