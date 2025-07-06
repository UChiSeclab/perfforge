#include <bits/stdc++.h>

#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> a3;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 2 * 1e5 + 5;

// Check the condition for a high maximum element
void check_high_max_element(int maxElement, int threshold) {
    if (maxElement > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high maximum element!" << endl;
        abort();
    }
}

// Check the condition for dense multiples
void check_dense_multiples(const vector<int>& frequency, int threshold) {
    int count = 0;
    for (int f : frequency) {
        if (f > 1) {
            count++;
        }
    }
    if (count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - dense multiples!" << endl;
        abort();
    }
}

// Check the condition for frequent updates in loops
void check_frequent_updates(int totalUpdates, int threshold) {
    if (totalUpdates > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent updates in nested loops!" << endl;
        abort();
    }
}

void solve() {
    int n;
    cin >> n;

    vi f(N, 0);
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
        m = max(m, x);
    }

    // Performance checker for the maximum element
    check_high_max_element(m, 1.5 * 1e5);  // Threshold set to 150,000

    int maxlen = 0;
    int totalUpdates = 0; // Counter for updates in the loop
    for (int i = m; i; i--) {
        int x = f[i];
        for (int j = 2; i * j <= m; j++) {
            f[i] = max(f[i], f[i * j] + x);
            totalUpdates++;
        }
        maxlen = max(maxlen, f[i]);
    }

    // Performance checker for frequent updates
    check_frequent_updates(totalUpdates, 1e6);  // Threshold set to 1,000,000

    cout << n - maxlen << "\n";
}

int main() {
//  freopen(".inp","r",stdin);
//  freopen(".out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}