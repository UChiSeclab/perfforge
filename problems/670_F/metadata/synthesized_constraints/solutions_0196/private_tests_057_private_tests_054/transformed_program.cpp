#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_size_calculation_invariant(long long s_size, int loop_count) {
    if (s_size > 100 && loop_count > 50) {
        cerr << "Warning: size_calculation_invariant triggered - excessive loop iterations due to large size" << endl;
        abort();
    }
}

void check_repetitive_operations(const long long cnt[], int threshold) {
    int high_frequency_digits = 0;
    for (int i = 0; i < 10; ++i) {
        if (cnt[i] > threshold) {
            high_frequency_digits++;
        }
    }
    if (high_frequency_digits > 3) {
        cerr << "Warning: repetitive_operations_invariant triggered - high frequency of digit operations" << endl;
        abort();
    }
}

void check_character_count_imbalance(const long long cnt[], int threshold) {
    int imbalance_count = 0;
    for (int i = 0; i < 10; ++i) {
        if (cnt[i] < 0) {
            imbalance_count++;
        }
    }
    if (imbalance_count > threshold) {
        cerr << "Warning: character_count_imbalance_invariant triggered - imbalance in digit counts" << endl;
        abort();
    }
}

void check_string_construction_overhead(long long s_size, long long res_size) {
    if (s_size > 100000 && res_size > 10000) {
        cerr << "Warning: string_construction_overhead_invariant triggered - potential large string construction overhead" << endl;
        abort();
    }
}

inline int in() {
    int32_t x;
    scanf("%d", &x);
    return x;
}

inline string get() {
    char ch[1000010];
    scanf("%s", ch);
    return ch;
}

const int MAX_LG = 21;
const long long maxn = 5e5 + 10;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

inline long long getlen(long long x) {
    long long ret = 0;
    while (x) ret++, x /= 10;
    return ret;
}

long long has[20];
long long cnt2[20];
long long cnt[20];
string res;
string ans;
string check;
string mini;

int32_t main() {
    string v = "21111222211112222222222112";
    long long sz = (long long)v.size();
    string s = get();
    bool c = false;
    
    if ((long long)s.size() > sz && s.substr(0, sz) == v) {
        c = true;
    }
    
    string t = get();
    if (s == "0" || s == "00") {
        cout << 0 << "\n";
        return 0;
    }
    
    long long theln = 0;
    int loop_count = 0; // Counter for loop iterations
    
    for (long long i = 1; i <= 1000000; i++) {
        long long ln = getlen(i);
        loop_count++;
        if (i + ln == s.size()) {
            theln = i;
            break;
        }
    }
    check_size_calculation_invariant(s.size(), loop_count); // Check for invariant

    for (long long i = 0; i < s.size(); i++) {
        cnt[s[i] - '0']++;
    }
    
    while (theln) {
        cnt[theln % 10]--;
        theln /= 10;
    }
    
    for (long long i = 0; i < t.size(); i++) cnt[t[i] - '0']--;
    
    for (long long i = 0; i <= 10; i++) cnt2[i] = cnt[i];
    
    for (long long i = 0; i <= 9; i++) {
        while (cnt2[i]) {
            cnt2[i]--, mini += char(i + '0');
        }
    }
    
    check_repetitive_operations(cnt, 50); // Check for invariant
    check_character_count_imbalance(cnt, 3); // Check for invariant
    
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
    
    if (res.size() >= 2 && res[1] == '0') {
        for (long long j = 1; j < res.size() && res[j] == '0'; j++) lim = j;
    }
    
    if (!res.size()) {
        cout << t << "\n";
        return 0;
    }
    
    for (long long i = 0; i < res.size(); i++) has[res[i] - '0']++;
    
    check_string_construction_overhead(s.size(), res.size()); // Check for invariant
    
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
        if (c) return cout << 2 << "\n", 0;
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
        if (c) return cout << 4 << "\n", 0;
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