#include <bits/stdc++.h>
using namespace std;

string s, w;
int ans;

bool sub(string t) {
    int i = 0, j = 0;
    while (i < w.size() && j < t.size()) {
        if (w[i] == t[j]) i++;
        j++;
    }
    return (i == w.size());
}

// Invariant Check Functions
void check_length_disparity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to length disparity!" << endl;
        abort();
    }
}

void check_character_disparity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to character disparity!" << endl;
        abort();
    }
}

void check_substring_explosion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to substring explosion!" << endl;
        abort();
    }
}

void Suhaib_Sawalha() {
    cin >> s >> w;

    // Length disparity check: s is long, while w is short
    check_length_disparity_invariant(s.size() > 150 && w.size() < 10);

    // Character disparity check: many characters in s not in w
    set<char> s_chars(s.begin(), s.end());
    set<char> w_chars(w.begin(), w.end());
    check_character_disparity_invariant(s_chars.size() > (w_chars.size() + 10));

    string t, f;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            t = s.substr(0, i);
            f = s.substr(j, n);
            if (sub(t + f)) ans = max(ans, j - i);
            if (sub(t)) ans = max(ans, n - i);
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Suhaib_Sawalha();
    return 0;
}