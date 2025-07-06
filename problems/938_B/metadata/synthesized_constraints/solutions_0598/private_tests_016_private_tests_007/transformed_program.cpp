#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];

void check_spread_invariant(int first_prize_pos, int last_prize_pos) {
    if (first_prize_pos > 106 || last_prize_pos < 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to widely spread prizes!" << endl;
        abort();
    }
}

void check_edge_distribution_invariant(int first_prize_pos, int last_prize_pos) {
    int middle_range = (last_prize_pos - first_prize_pos) / 2;
    if (first_prize_pos + middle_range > 106 && last_prize_pos - middle_range < 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to edge distribution of prizes!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    int first_prize_pos = INT_MAX;
    int last_prize_pos = INT_MIN;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        a[l] = 1;
        first_prize_pos = min(first_prize_pos, l);
        last_prize_pos = max(last_prize_pos, l);
    }

    // Check for performance bottlenecks based on prize distribution
    check_spread_invariant(first_prize_pos, last_prize_pos);
    check_edge_distribution_invariant(first_prize_pos, last_prize_pos);

    int l = 0, r = 0;
    if (a[1] == 1) l++;
    if (a[(int)1e6] == 1) l++;
    for (int i = 2, j = 1e6 - 1; i < j && l < n; i++, j--, r++) {
        if (a[i] == 1) l++;
        if (a[j] == 1) l++;
    }
    cout << r << "\n";
    return 0;
}