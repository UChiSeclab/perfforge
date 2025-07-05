#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
string s;
map<string, bool> m;

// Function to check substring generation overhead
void check_substring_generation_invariant(size_t totalSubstrings) {
    if (totalSubstrings > 1000) {  // Arbitrary threshold for demonstration
        cerr << "Warning: Substring generation overhead detected - too many substrings being processed!" << endl;
        abort();
    }
}

// Function to check sorting overhead
void check_sorting_invariant(size_t vectorSize) {
    if (vectorSize > 300) {  // Threshold based on constraints and potential complexity
        cerr << "Warning: Sorting overhead detected - too many unique substrings!" << endl;
        abort();
    }
}

// Function to check comparator invocation overhead
void check_comparator_invocation_invariant(size_t invocationCount) {
    if (invocationCount > 1000) {  // Arbitrary threshold for excessive comparator calls
        cerr << "Warning: Comparator invocation overhead detected - too many comparisons!" << endl;
        abort();
    }
}

bool comp(string a, string b) {
    static size_t invocationCount = 0;
    invocationCount++;
    check_comparator_invocation_invariant(invocationCount);

    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

string sig(string mini) {
    string r = "";
    if (mini[mini.length() - 1] == 'z') {
        bool ok = 0;
        for (int i = mini.length() - 1; i >= 0; i--) {
            if (mini[i] != 'z') {
                mini[i]++;
                ok = 1;
                int u = mini.length() - 1;
                while (u >= 0 && mini[u] == 'z') {
                    mini[u] = 'a';
                    u--;
                }
                return mini;
            }
        }
        if (!ok) {
            for (int i = 0; i <= mini.length(); i++) {
                r += "a";
            }
        }
        return r;
    } else {
        mini[mini.length() - 1]++;
        return mini;
    }
}

int main() {
    scanf("%d", &n);
    string mini = "a";
    
    size_t totalSubstrings = 0;  // Counter for substrings generated

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            for (int r = 0; r <= s.length(); r++) {
                if (j + r > s.length()) continue;
                string aux = s.substr(j, r);
                totalSubstrings++;
                if (!m[aux] && aux.length() > 0) v.push_back(aux);
                m[aux] = 1;
            }
        }
    }

    check_substring_generation_invariant(totalSubstrings);
    check_sorting_invariant(v.size());

    sort(v.begin(), v.end(), comp);
    string res = "";
    if (v[0] != "a") {
        cout << "a" << endl;
        return 0;
    }
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i + 1] != sig(v[i]) && v[i + 1] != v[i]) {
            res = v[i];
            break;
        }
    }
    if (res != "") {
        cout << sig(res) << endl;
    } else {
        cout << sig(v[v.size() - 1]) << endl;
    }
}