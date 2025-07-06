#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return x *= f, void();
}

template <typename T>
void ckmax(T &a, T b) {
    a = b > a ? b : a;
}

template <typename T>
void ckmin(T &a, T b) {
    a = b < a ? b : a;
}

const int N = 200 + 5;
int n, k, f[N][N][N], ans;
char s[N], t[N];

// Check functions to detect performance bottlenecks
void check_high_replacement_capacity(int n, int k) {
    if (k >= n - 1) {
        cerr << "Warning: Performance bottleneck condition triggered - high replacement capacity!" << endl;
        abort();
    }
}

void check_repetitive_character_scenario(const string& s, int n, int k) {
    int max_char_count = 0;
    vector<int> char_count(26, 0);
    for (char c : s) {
        char_count[c - 'a']++;
        max_char_count = max(max_char_count, char_count[c - 'a']);
    }
    if (max_char_count / static_cast<double>(n) > 0.8 && k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - repetitive character scenario!" << endl;
        abort();
    }
}

void check_nested_loop_complexity(int n, int k) {
    if (n == 200 && k == 200) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum constraints reached!" << endl;
        abort();
    }
}

int main() {
    read(n), read(k);
    scanf("%s%s", s + 1, t + 1);

    // Convert char array to string for checker use
    string s_str(s + 1);

    // Check for potential performance bottlenecks
    check_high_replacement_capacity(n, k);
    check_repetitive_character_scenario(s_str, n, k);
    check_nested_loop_complexity(n, k);

    memset(f, 0xcf, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int l = 0; l <= min(k, i); l++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (l + (c != s[i + 1]) <= min(k, i + 1)) {
                        ckmax(f[i + 1][j + (c == t[1])][l + (c != s[i + 1])],
                              f[i][j][l] + (c == t[2]) * j);
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(n, k); j++) {
            ckmax(ans, f[n][i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}