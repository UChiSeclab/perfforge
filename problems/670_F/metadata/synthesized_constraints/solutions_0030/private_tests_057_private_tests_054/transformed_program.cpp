#include <bits/stdc++.h>
using namespace std;

inline string get() {
    char ch[1000010];
    scanf("%s", ch);
    return ch;
}

inline int getlen(int x) {
    int ret = 0;
    while (x) ret++, x /= 10;
    return ret;
}

// Checker for excessive iterations in the length calculation loop
void check_thelength_invariant(int s_size, int i) {
    if (s_size >= 999000 && i >= 999000) {
        cerr << "Warning: thelength_invariant triggered - excessive iterations searching for length" << endl;
        abort();
    }
}

// Checker for constructing an excessively large string `ans`
void check_ans_string_invariant(const string& t, int ans_size) {
    if (t[0] == '0' && ans_size > 1000000) {
        cerr << "Warning: ans_string_invariant triggered - constructing excessively large string" << endl;
        abort();
    }
}

int has[20], cnt2[20], cnt[20], theln;
string res, ans, check, mini;

int32_t main() {
    string s = get(), t = get();
    
    // Early return for trivial cases
    if (s == "0" || s == "00") {
        cout << 0 << "\n";
        return 0;
    }

    // Loop to determine theln
    for (int i = 1; i <= 1000000; i++) {
        int ln = getlen(i);
        check_thelength_invariant(s.size(), i);  // Check for excessive iterations
        if (i + ln == s.size()) {
            theln = i;
            break;
        }
    }

    for (int i = 0; i < s.size(); i++) cnt[s[i] - '0']++;
    while (theln) {
        cnt[theln % 10]--;
        theln /= 10;
    }
    for (int i = 0; i < t.size(); i++) cnt[t[i] - '0']--;
    for (int i = 0; i <= 10; i++) cnt2[i] = cnt[i];
    for (int i = 0; i <= 9; i++)
        while (cnt2[i]) cnt2[i]--, mini += char(i + '0');
    
    int lim = -1;
    if (!cnt[0]) {
        for (int i = 1; i <= 9; i++) {
            while (cnt[i]) {
                res += char('1' + i - 1);
                cnt[i]--;
            }
        }
    } else {
        int mrk = -1;
        for (int i = 1; i <= 9; i++) {
            if (cnt[i]) {
                mrk = i;
                cnt[i]--;
                break;
            }
        }
        if (mrk != -1) res += char('1' + mrk - 1);
        for (int i = 0; i <= 9; i++) {
            while (cnt[i]) {
                res += char('1' + i - 1);
                cnt[i]--;
            }
        }
    }
    
    if (res.size() >= 2 && res[1] == '0')
        for (int j = 1; j < res.size() && res[j] == '0'; j++) lim = j;

    if (!res.size()) {
        cout << t << "\n";
        return 0;
    }

    for (int i = 0; i < res.size(); i++) has[res[i] - '0']++;
    
    if (res[0] == '0') {
        cout << t << res << "\n";
        return 0;
    }
    
    // Constructing ans based on t and mini
    if (t[0] != '0') {
        ans = t + mini;
    } else {
        for (int i = 0; i <= 1e6; i++) ans += '9';
        check_ans_string_invariant(t, ans.size());  // Check for large `ans` construction
    }

    int yk = -1;
    if (t.size() > 1)
        for (int i = 1; i < t.size(); i++) {
            if (yk == -1 && t[i] != t[0]) {
                yk = t[i] - '0';
            }
        }

    if (!has[t[0] - '0']) {
        bool fl = false;
        for (int i = lim + 1; i < s.size(); i++) {
            if (s[i] > t[0]) {
                lim = max(lim, i - 1);
                break;
            }
        }
        for (int i = 0; i < res.size(); i++) {
            if (i > lim && (t[i] != '0' || i) && !fl) {
                check += t;
                fl = true;
            }
            check += res[i];
        }
        if (!fl) check += t;
    } else if (yk == -1 || yk > (t[0] - '0')) {
        bool fl = false;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] > t[0]) break;
            if (res[i] == t[0]) lim = i;
        }
        for (int i = 0; i < res.size(); i++) {
            if (i > lim && !fl) {
                check += t;
                fl = true;
            }
            check += res[i];
        }
        if (!fl) check += t;
    } else {
        bool fl = false;
        for (int i = lim + 1; i < res.size(); i++) {
            if (res[i] == t[0]) {
                lim = max(lim, i - 1);
                break;
            }
        }
        for (int i = 0; i < res.size(); i++) {
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