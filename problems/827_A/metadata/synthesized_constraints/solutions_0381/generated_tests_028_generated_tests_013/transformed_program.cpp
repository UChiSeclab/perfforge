#include <bits/stdc++.h>
using namespace std;
const long long inf = 9.2e18;
const int maxn = 2007;
const int INF = 2.1e9;
const int MOD = 1e9 + 7;
const double dif = 1e-5;
const double PI = 3.14159265358979323846;
int n, m, k;
map<int, int> M;
vector<string> V;

void check_overlap_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: overlap_invariant triggered - frequent switching due to overlapping substrings" << endl;
        abort();
    }
}

void check_length_invariant(int r) {
    if (r > 1000000) {  // Arbitrary large threshold chosen for demonstration
        cerr << "Warning: length_invariant triggered - large maximum position to fill in the result string" << endl;
        abort();
    }
}

void check_nested_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: nested_loop_invariant triggered - high frequency of substring placement in result string" << endl;
        abort();
    }
}

int main(void) {
    while (cin >> n) {
        V.clear();
        M.clear();
        int r = 0;
        string s;
        for (int i = 0; i < n; i++) {
            int x, p, idx;
            cin >> s;
            scanf("%d", &x);
            V.push_back(s);
            idx = V.size() - 1;
            while (x--) {
                scanf("%d", &p);
                r = max(r, p);
                if (!M.count(p))
                    M[p] = idx;
                else if (s.length() > V[M[p]].length())
                    M[p] = idx;
            }
        }

        // Check for large maximum position
        check_length_invariant(r);

        int l = 1;
        while (l <= r) {
            if (M.count(l)) {
                int i = 0, idx = M[l];
                while (i < V[idx].length()) {
                    l++;
                    printf("%c", V[idx][i]);

                    // Check for frequent switching
                    check_overlap_invariant(M.count(l) && V[M[l]].length() > V[idx].length() - i - 1);

                    if (M.count(l) && V[M[l]].length() > V[idx].length() - i - 1) {
                        idx = M[l];
                        i = 0;
                    } else
                        i++;
                }
            } else {
                printf("a");
                l++;
            }
        }
        cout << endl;
    }
    return 0;
}