#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const int mod = 1e9 + 7;
const long long N = 1e4 + 5, K = 105;
const long long oo = 1e18 + 5;
const int si = (1 << 20);
const int INF = (1 << 30);
const long long M = 1e3 + 5;
const double INFdb = 1e10;
vector<string> nums = {"1110111", "0010010", "1011101", "1011011", "0111010",
                       "1101011", "1101111", "1010010", "1111111", "1111011"};
bool exist[2005][2005];

int num_stick(string s, int num) {
    int ans = 0;
    for (int i = 0; i < 7; ++i) {
        if (nums[num][i] == '0' && s[i] == '1') return INF;
        if (nums[num][i] != s[i]) ++ans;
    }
    return ans;
}

void check_high_k_relative_to_n(int n, int k) {
    if (k > n * 5) {
        cerr << "Warning: Performance bottleneck condition triggered due to high k relative to n!" << endl;
        abort();
    }
}

void check_inefficient_exploration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient exploration!" << endl;
        abort();
    }
}

void check_extensive_possible_combinations(int n, int k) {
    if (k > n * 3 && k < n * 5) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive possible combinations!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<string> s(n + 1);
    
    for (int i = 1; i <= n; ++i) cin >> s[i];

    // Check for high 'k' relative to 'n'
    check_high_k_relative_to_n(n, k);

    exist[n + 1][0] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= k; ++j) {
            for (int num = 0; num < 10; ++num) {
                int cost = num_stick(s[i], num);
                if (cost <= j) {
                    exist[i][j] |= exist[i + 1][j - cost];
                }
            }
        }
    }

    // Check for inefficient exploration before solution exploration
    check_inefficient_exploration(!exist[1][k]);

    if (!exist[1][k]) return cout << -1, 0;

    // Check for extensive possible combinations
    check_extensive_possible_combinations(n, k);

    string ans = "";
    int remain = k;
    for (int i = 1; i <= n; ++i) {
        for (int num = 9; num >= 0; --num) {
            int cost = num_stick(s[i], num);
            if (cost <= remain && exist[i + 1][remain - cost]) {
                ans += (char)(num + '0');
                remain -= cost;
                break;
            }
        }
    }
    
    cout << ans;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}