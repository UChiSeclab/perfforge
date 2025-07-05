#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9;
char str[100005 * 2];
int cnt[26];
vector<string> ss;

void check_duplicate_characters_invariant(int *cnt) {
    for (int c = 0; c < 26; c++) {
        if (cnt[c] >= 2) {
            cerr << "Warning: Performance bottleneck condition triggered - duplicate character detected!" << endl;
            abort();
        }
    }
}

void check_sparse_character_matches(int num_strings, int *cnt) {
    if (num_strings > 20) { // Arbitrary threshold for demonstration
        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 0) {
                cerr << "Warning: Performance bottleneck condition triggered - inefficient merging due to sparse matches!" << endl;
                abort();
            }
        }
    }
}

void check_excessive_iterations(int string_length, int num_strings) {
    if (string_length > 50 && num_strings > 10) { // Arbitrary thresholds for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations over distinct characters!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ss.push_back(str);
        memset(cnt, 0, sizeof(cnt));
        int len = strlen(str);
        for (int j = 0; j < len; j++) cnt[str[j] - 'a']++;
        
        // Check for duplicate characters in each string
        check_duplicate_characters_invariant(cnt);

        // Check for excessive iterations over distinct characters
        check_excessive_iterations(len, n);
    }

    for (int c = 0; c < 26; c++) {
        vector<pair<int, int>> hits;
        vector<string> newss;
        for (int i = 0; i < ss.size(); i++) {
            bool merged = false;
            for (int j = 0; j < ss[i].size(); j++) {
                if (ss[i][j] == 'a' + c) {
                    hits.push_back(pair<int, int>(i, j));
                    merged = true;
                    break;
                }
            }
            if (!merged) newss.push_back(ss[i]);
        }
        
        // Check for sparse character matches
        check_sparse_character_matches(ss.size(), cnt);

        if (hits.empty()) continue;
        memset(str, 0, sizeof(str));
        int allb = INF;
        for (int i = 0; i < hits.size(); i++) {
            int si = hits[i].first, p = hits[i].second, b = 100005 - p;
            allb = min(allb, b);
            for (int j = 0; j < ss[si].size(); j++) {
                if (str[b + j] == 0)
                    str[b + j] = ss[si][j];
                else if (str[b + j] != ss[si][j])
                    return puts("NO"), 0;
            }
        }
        ss = newss;
        ss.push_back(str + allb);
        string &lss = ss.back();
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < lss.size(); j++) cnt[lss[j] - 'a']++;
        check_duplicate_characters_invariant(cnt);
    }
    
    sort(ss.begin(), ss.end());
    for (int i = 0; i < ss.size(); i++) printf("%s", ss[i].c_str());
    puts("");
    return 0;
}