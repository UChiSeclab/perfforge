#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int finish[5005] = {0}, freq[5005][5005] = {0}, total[5005] = {0};

// Checker functions for performance invariants
void check_sparse_distribution(int totalCandies, int stations) {
    if (totalCandies < stations / 10) { // Assuming sparse if less than 10% of the stations have candies
        cerr << "Warning: Sparse candy distribution detected - potential slowdown!" << endl;
        abort();
    }
}

void check_high_station_count(int stations) {
    if (stations > 1000) { // Arbitrary threshold for high station count causing potential slowdown
        cerr << "Warning: High station count - potential slowdown!" << endl;
        abort();
    }
}

void check_sequential_dependency(const long long int freq[][5005], int stations) {
    for (int i = 0; i < stations; ++i) {
        int count = 0;
        for (int j = 0; j < stations; ++j) {
            if (freq[i][j] > 0) {
                count++;
            }
        }
        if (count > stations / 2) { // Arbitrary threshold, if more than half destinations from a station
            cerr << "Warning: High sequential dependency - potential slowdown!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long int n, m;
    cin >> n >> m;
    
    // Insert checks after reading inputs
    check_sparse_distribution(m, n);
    check_high_station_count(n);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        total[a]++;
        freq[a][b]++;
    }
    
    // Check for sequential dependency after processing all candies
    check_sequential_dependency(freq, n);

    for (int i = 0; i < n; ++i) {
        long long int tmp = max(0LL, (total[i] - 1) * n);
        int j = (i + 1 + n) % n;
        while (j != i) {
            if (freq[i][j] != 0) {
                if (j > i)
                    tmp += j - i;
                else
                    tmp += n - i + j;
                break;
            }
            j++;
            j %= n;
        }
        finish[i] = tmp;
    }
    for (int i = 0; i < n; ++i) {
        long long int ans = finish[i];
        int j = (i + 1) % n;
        while (j != i) {
            int tmp;
            if (j > i)
                tmp = j - i;
            else
                tmp = n - i + j;
            if (finish[j] != 0) ans = max(ans, finish[j] + tmp);
            ++j;
            j %= n;
        }
        cout << ans << " ";
    }
    return 0;
}