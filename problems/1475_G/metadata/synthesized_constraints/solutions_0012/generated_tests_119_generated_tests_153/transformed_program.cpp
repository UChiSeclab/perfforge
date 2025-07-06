#include <bits/stdc++.h>
using namespace std;
#define joker ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define z 1000000007
#define sh 200000
#define pb push_back
#define fi first
#define se second
#define pr(x) printf("%d ", x)
#define sc(x) scanf("%d",&x)
#define mxf INT_MAX
#define mnf INT_MIN
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpi;
typedef map<int, pi> mpii;

void why_so_serious() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void check_small_elements_invariant(int smallestElement) {
    if (smallestElement < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of small elements!" << endl;
        abort();
    }
}

void check_diverse_range_invariant(int uniqueElementCount) {
    if (uniqueElementCount > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - diverse range of array elements!" << endl;
        abort();
    }
}

void check_large_array_invariant(int n) {
    if (n > 190000) {
        cerr << "Warning: Performance bottleneck condition triggered - large arrays near constraint!" << endl;
        abort();
    }
}

void check_high_multiples_invariant(int number) {
    if (number < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent high multiples calculation!" << endl;
        abort();
    }
}

int main() {
    why_so_serious();
    joker
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        // Add check for large arrays near the upper constraint.
        check_large_array_invariant(n);

        int ar[n];
        int dp[sh + 2];
        memset(dp, 0, sizeof(dp));
        map<int, int> mp;

        for (i = 0; i < n; i++) {
            cin >> ar[i];
            dp[ar[i]]++;
            mp[ar[i]]++;
        }

        // Sort the array and check for small elements.
        sort(ar, ar + n);
        check_small_elements_invariant(ar[0]);

        // Check for diverse range of elements.
        check_diverse_range_invariant(mp.size());

        int ans = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            int val = it->first;
            int num = val;

            // Check for frequent high multiples calculation.
            check_high_multiples_invariant(val);

            while (num <= sh) {
                num += val;
                if (num <= sh)
                    dp[val] = max(dp[val], dp[num] + mp[val]);
            }
        }
        for (i = 1; i <= sh; i++)
            ans = max(ans, dp[i]);

        cout << n - ans << endl;
    }
}