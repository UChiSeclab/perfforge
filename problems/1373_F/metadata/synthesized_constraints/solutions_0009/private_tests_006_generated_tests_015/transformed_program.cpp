#include <bits/stdc++.h>
using namespace std;

int T, N, a[1000001], b[1000001];
bool chk[1000001];

// Checker function implementations
void check_high_need_invariant(int total_need, int total_capacity) {
    if (total_need > total_capacity) {
        cerr << "Warning: high_need_invariant triggered - unmet household needs exceed total network capacity" << endl;
        abort();
    }
}

void check_iteration_invariant(int iteration_count, int threshold) {
    if (iteration_count > threshold) {
        cerr << "Warning: iteration_invariant triggered - excessive loop iterations" << endl;
        abort();
    }
}

void check_circular_dependency_invariant(int redistribution_attempts, int threshold) {
    if (redistribution_attempts > threshold) {
        cerr << "Warning: circular_dependency_invariant triggered - excessive redistribution attempts" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            chk[i] = 0;
        }
        for (int i = 0; i < N; i++) cin >> b[i];
        
        int s, prev = -1, cnt = 0;

        // Calculate total need and capacity before starting main logic
        int total_need = accumulate(a, a + N, 0);
        int total_capacity = accumulate(b, b + N, 0); 
        
        // Check if initial needs exceed capacities
        check_high_need_invariant(total_need, total_capacity);
        
        while (1) {
            int f = 0;
            for (s = 0; s < N; s++) {
                if (a[s] > b[s] && f == 0)
                    f = 1;
                else if (f == 1 && b[s] >= a[s])
                    break;
            }
            if (f == 0) {
                cout << "YES\n";
                break;
            } else if (s == N && a[0] > b[0]) {
                cout << "NO\n";
                break;
            }
            if (f == 1 && s == N) {
                s = 0;
            }
            chk[s] = 1;
            for (int i = 0; i < N; i++) {
                int now = (s + i) % N;
                int nxt = (now + 1) % N;
                if (b[now] < a[now]) continue;
                chk[nxt] = 0;
                int x = min(a[nxt], b[now] - a[now]);
                a[nxt] -= x;
                b[now] -= x;
            }
            cnt++;
            // Check iteration invariant after each complete redistribution attempt
            check_iteration_invariant(cnt, 100); // hypothetical threshold value
            if (cnt == 71) {
                cout << "NO\n";
                break;
            }
        }
    }
}