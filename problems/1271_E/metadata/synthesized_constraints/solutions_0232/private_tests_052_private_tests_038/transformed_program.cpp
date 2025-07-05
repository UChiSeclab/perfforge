#include <bits/stdc++.h>
using namespace std;
long long n, k, m, dp[100][2];
string s, ans1;

long long check(string s, string lim) {
    int len = s.length();
    long long ans = 0;
    if (s[len - 1] == '0') {
        for (int i = len; i < m; i++) {
            ans += 2 * (1LL << (i - len));
        }
        s = s.substr(0, len - 1);
        len--;
    } else {
        for (int i = len; i < m; i++) {
            ans += (1LL << (i - len));
        }
    }
    int kt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != lim[i]) {
            if (s[i] < lim[i]) {
                kt = 1;
            } else {
                kt = 2;
            }
            break;
        }
    }
    if (kt == 0) {
        memset(dp, 0, sizeof dp);
        dp[len][1] = 1;
        for (int i = len + 1; i <= m; i++) {
            for (int cs = 0; cs <= 1; cs++) {
                if (cs == lim[i - 1] - 48) {
                    dp[i][1] += dp[i - 1][1];
                }
                if (cs < lim[i - 1] - 48) {
                    dp[i][0] += dp[i - 1][1];
                }
                dp[i][0] += dp[i - 1][0];
            }
        }
        ans += dp[m][0] + dp[m][1];
    } else {
        if (kt == 1) {
            ans += (1LL << (m - len));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    long long tmp1 = n, ans = 0;
    int binaryLength = 0;
    while (tmp1 > 0) {
        s = (char)(tmp1 % 2 + 48) + s;
        tmp1 /= 2;
        binaryLength++;
    }

    m = s.length();

    // Check for binary representation length
    check_binary_representation_invariant(binaryLength);

    int numberOfCallsToCheck = 0;
    for (int len = 1; len <= m; len++) {
        string tmp;
        while (tmp.length() < len) tmp += "0";

        // Check for binary string length within the loop
        check_binary_length_invariant(len, 60);

        for (int i = 0; i < len; i++) {
            tmp[i] = '1';
            if (check(tmp, s) < k) {
                tmp[i] = '0';
            }
            numberOfCallsToCheck++;
        }

        if (check(tmp, s) >= k) {
            long long tmp1 = 0;
            for (int i = 0; i < len; i++) {
                tmp1 = 2 * tmp1 + tmp[i] - 48;
            }
            ans = max(ans, tmp1);
        }
    }

    // Check number of calls made to check function
    check_number_of_calls_invariant(numberOfCallsToCheck);

    cout << ans;
}