#include <bits/stdc++.h>
using namespace std;

inline string get() {
    char ch[1000010];
    scanf("%s", ch);
    return ch;
}

inline long long getlen(long long x) {
    long long ret = 0;
    while (x) ret++, x /= 10;
    return ret;
}

void check_string_length_invariant(size_t length) {
    if (length > 900000) {  // Threshold chosen considering the upper limit
        cerr << "Warning: Performance bottleneck condition triggered - excessively long input string!" << endl;
        abort();
    }
}

void check_digit_manipulation_invariant(const array<long long, 20>& cnt) {
    long long manipulations = 0;
    for (int i = 0; i <= 9; i++) {
        manipulations += cnt[i];
    }
    if (manipulations > 1000000) { // Threshold for excessive digit operations
        cerr << "Warning: Performance bottleneck condition triggered - too many digit operations!" << endl;
        abort();
    }
}

void check_loop_iterations_invariant(long long theln) {
    if (theln > 900000) { // Checking if theln is approaching upper range
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

void check_leading_zeros_invariant(const string& res) {
    if (!res.empty() && res[0] == '0') {
        cerr << "Warning: Performance bottleneck condition triggered - leading zeros in result!" << endl;
        abort();
    }
}

int32_t main() {
    string s = get(), t = get();

    // Check the length of the input string
    check_string_length_invariant(s.size());

    if (s == "0" || s == "00") {
        cout << 0 << "\n";
        return 0;
    }

    long long has[20] = {0}, cnt2[20] = {0}, cnt[20] = {0}, theln = 0;
    string res, ans, check, mini;
    
    for (long long i = 1; i <= 1000000; i++) {
        long long ln = getlen(i);
        if (i + ln == s.size()) {
            theln = i;
            break;
        }
    }

    // Check the loop iterations
    check_loop_iterations_invariant(theln);

    for (long long i = 0; i < s.size(); i++) cnt[s[i] - '0']++;
    while (theln) {
        cnt[theln % 10]--;
        theln /= 10;
    }
    for (long long i = 0; i < t.size(); i++) cnt[t[i] - '0']--;
    for (long long i = 0; i <= 10; i++) cnt2[i] = cnt[i];
    for (long long i = 0; i <= 9; i++)
        while (cnt2[i]) cnt2[i]--, mini += char(i + '0');

    // Check digit manipulation frequency
    check_digit_manipulation_invariant(cnt);

    long long lim = -1;
    if (!cnt[0]) {
        for (long long i = 1; i <= 9; i++) {
            while (cnt[i]) {
                res += char('1' + i - 1);
                cnt[i]--;
            }
        }
    } else {
        long long mrk = -1;
        for (long long i = 1; i <= 9; i++) {
            if (cnt[i]) {
                mrk = i;
                cnt[i]--;
                break;
            }
        }
        if (mrk != -1) res += char('1' + mrk - 1);
        for (long long i = 0; i <= 9; i++) {
            while (cnt[i]) {
                res += char('1' + i - 1);
                cnt[i]--;
            }
        }
    }

    if (res.size() >= 2 && res[1] == '0')
        for (long long j = 1; j < res.size() && res[j] == '0'; j++) lim = j;
    if (!res.size()) {
        cout << t << "\n";
        return 0;
    }

    for (long long i = 0; i < res.size(); i++) has[res[i] - '0']++;
    
    // Check for leading zeros in the result
    check_leading_zeros_invariant(res);

    if (res[0] == '0') {
        cout << t << res << "\n";
        return 0;
    }
    if (t[0] != '0') {
        ans = t + mini;
    } else {
        for (long long i = 0; i <= 1e6; i++) ans += '9';
    }
    long long yk = -1;
    if (t.size() > 1)
        for (long long i = 1; i < t.size(); i++) {
            if (yk == -1 && t[i] != t[0]) {
                yk = t[i] - '0';
            }
        }
    if (!has[t[0] - '0']) {
        bool fl = false;
        for (long long i = lim + 1; i < s.size(); i++) {
            if (s[i] > t[0]) {
                lim = max(lim, i - 1);
                break;
            }
        }
        for (long long i = 0; i < res.size(); i++) {
            if (i > lim && (t[i] != '0' || i) && !fl) {
                check += t;
                fl = true;
            }
            check += res[i];
        }
        if (!fl) check += t;
    } else if (yk == -1 || yk > (t[0] - '0')) {
        bool fl = false;
        for (long long i = 0; i < res.size(); i++) {
            if (res[i] > t[0]) break;
            if (res[i] == t[0]) lim = i;
        }
        for (long long i = 0; i < res.size(); i++) {
            if (i > lim && !fl) {
                check += t;
                fl = true;
            }
            check += res[i];
        }
        if (!fl) check += t;
    } else {
        bool fl = false;
        for (long long i = lim + 1; i < res.size(); i++) {
            if (res[i] == t[0]) {
                lim = max(lim, i - 1);
                break;
            }
        }
        for (long long i = 0; i < res.size(); i++) {
            if (i > lim && !fl) {
                check += t;
                fl = true;
            }
            check += res[i];
        }
        if (!fl) check += t;
    }
    ans = min(ans, check);
    cout << ans << "\n";
}