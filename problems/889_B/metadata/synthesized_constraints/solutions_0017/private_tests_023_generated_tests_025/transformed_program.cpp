#include <bits/stdc++.h>
using namespace std;

void ri(int &a) {
    a = 0;
    register int x = getchar_unlocked();
    bool neg = false;
    while (x < '0' || x > '9') {
        if (x == '-') neg = true;
        x = getchar_unlocked();
    }
    while (x >= '0' && x <= '9') {
        a = (a << 3) + (a << 1) + (x - '0');
        x = getchar_unlocked();
    }
    if (neg) a = -a;
}

const int maxn = 100100, INF = (1 << 30) - 1, alpha = 28;
int n;
map<string, vector<int>> pref, suff;
string str[maxn];
bool used[alpha];
int par[alpha], rnk[alpha];
bool check[alpha];

// Performance checkers
void check_union_find_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive union-find operations!" << endl;
        abort();
    }
}

void check_substring_concatenation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive substring concatenation and checking!" << endl;
        abort();
    }
}

void check_substring_existence_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - quadratic substring existence checks!" << endl;
        abort();
    }
}

void check_preprocessing_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - preprocessing large number of substrings!" << endl;
        abort();
    }
}

void no() {
    printf("NO\n");
    exit(0);
}

int getpar(int a) {
    return a == par[a] ? a : par[a] = getpar(par[a]);
}

void mrg(int a, int b) {
    int A = getpar(a), B = getpar(b);
    if (A == B) return;
    if (rnk[A] > rnk[B]) {
        par[B] = A;
    } else if (rnk[B] > rnk[A]) {
        par[A] = B;
    } else {
        par[A] = B;
        rnk[A]++;
    }
}

string addTo(int flag, string ans) {
    string tempStr;
    bool found = false;
    for (char c = 'a'; !found && c <= 'z'; c++) {
        if (used[c - 'a']) continue;
        if (flag == 0) {
            tempStr = c + ans;
            string prefIt = "";
            prefIt += tempStr[0];
            for (int i = 1; i < tempStr.size(); i++) {
                prefIt += tempStr[i];
                if (suff[prefIt].size() > 0) {
                    found = true;
                    used[c - 'a'] = true;
                    break;
                }
            }
        } else {
            tempStr = ans + c;
            string suffIt = "";
            suffIt += tempStr[tempStr.size() - 1];
            for (int i = tempStr.size() - 2; i >= 0; i--) {
                suffIt = tempStr[i] + suffIt;
                if (pref[suffIt].size() > 0) {
                    found = true;
                    used[c - 'a'] = true;
                    break;
                }
            }
        }
    }
    if (found) {
        return addTo(flag, tempStr);
    }
    return ans;
}

int main() {
    ri(n);
    int unionFindOperationCount = 0; // Track union-find operations
    int concatenationCheckCount = 0; // Track concatenation and check operations
    int substringExistenceCheckCount = 0; // Track substring existence checks
    int substringPreprocessingCount = 0; // Track preprocessing operations

    for (int i = 0; i < n; i++) {
        cin >> str[i];
        if (str[i].size() > 26) {
            no();
        }

        int cnt[alpha];
        memset(cnt, 0, sizeof(cnt));
        string prefIt = "", suffIt = "";

        for (int j = 0; j < str[i].size(); j++) {
            prefIt += str[i][j];
            cnt[str[i][j] - 'a']++;
            if (cnt[str[i][j] - 'a'] > 1) {
                no();
            }
            pref[prefIt].push_back(i);
        }

        for (int j = str[i].size() - 1; j >= 0; j--) {
            suffIt = str[i][j] + suffIt;
            suff[suffIt].push_back(i);
        }
    }

    // Checking preprocessing invariant
    check_preprocessing_invariant(substringPreprocessingCount > n * 20); // Simplified threshold

    for (int i = 0; i < alpha; i++) {
        par[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (char c : str[i]) {
            mrg(c - 'a', str[i][0] - 'a');
            unionFindOperationCount++;
        }
    }

    // Checking union-find invariant
    check_union_find_invariant(unionFindOperationCount > n * 20); // Simplified threshold

    vector<string> ans;
    for (int i = 0; i < n; i++) {
        int num = getpar(str[i][0] - 'a');
        if (!check[num]) {
            for (char c : str[i]) {
                used[c - 'a'] = true;
            }
            ans.push_back(addTo(1, addTo(0, str[i])));
            check[num] = true;
        }
    }

    sort(ans.begin(), ans.end());
    string prnt = "";
    for (string add : ans) {
        prnt += add;
    }

    map<string, bool> occ;
    for (int i = 0; i < prnt.size(); i++) {
        string ss = "";
        ss += prnt[i];
        occ[ss] = true;
        for (int j = i + 1; j < prnt.size(); j++) {
            ss += prnt[j];
            occ[ss] = true;
            substringExistenceCheckCount++;
        }
    }

    // Checking substring existence invariant
    check_substring_existence_invariant(substringExistenceCheckCount > prnt.size() * prnt.size());

    for (int i = 0; i < n; i++) {
        if (!occ[str[i]]) {
            no();
        }
    }
    cout << prnt << '\n';
    return 0;
}