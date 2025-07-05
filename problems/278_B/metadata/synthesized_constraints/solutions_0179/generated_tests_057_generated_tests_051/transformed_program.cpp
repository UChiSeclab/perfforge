#include <bits/stdc++.h>
using namespace std;

// Function to check excessive substring generation
void check_substring_invariant(size_t substringCount, size_t threshold) {
    if (substringCount > threshold) {
        cerr << "Warning: substring_invariant triggered - too many substrings generated!" << endl;
        abort();
    }
}

// Function to check excessive sorting operations
void check_sort_invariant(size_t elementCount, size_t threshold) {
    if (elementCount > threshold) {
        cerr << "Warning: sort_invariant triggered - too many elements being sorted!" << endl;
        abort();
    }
}

// Function to check excessive calls to getNext
void check_getnext_call_invariant(int callCount, int threshold) {
    if (callCount > threshold) {
        cerr << "Warning: getNext_call_invariant triggered - excessive calls to getNext!" << endl;
        abort();
    }
}

string getNext(string s) {
    static int getNextCallCount = 0;
    getNextCallCount++;
    check_getnext_call_invariant(getNextCallCount, 500); // Threshold is arbitrary but should be reasonable

    int n = s.size();
    string res = s;
    for (int i = n - 1; i >= 0; i--) {
        if (res[i] != 'z') {
            res[i] = res[i] + 1;
            break;
        }
    }
    if (res == s) {
        res = "";
        for (int i = 0; i < n + 1; i++) res += "a";
    }
    return res;
}

bool sortStr(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    set<string> S;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= a[i].size(); len++) {
            string s = "";
            int j;
            for (j = 0; j < len; j++) s += a[i][j];
            S.insert(s);
            for (; j < a[i].size(); j++) {
                s.erase(0, 1);
                s += a[i][j];
                S.insert(s);
            }
        }
    }

    check_substring_invariant(S.size(), 5000); // Adjust threshold as appropriate to catch potential slow cases

    string arr[S.size()];
    set<string>::iterator itr;
    int i = 0;
    for (itr = S.begin(); itr != S.end(); ++itr) {
        arr[i++] = *itr;
    }

    check_sort_invariant(S.size(), 5000); // Again, adjust threshold appropriately

    sort(arr, arr + S.size(), sortStr);
    string ans;
    if (arr[0] != "a") {
        ans = "a";
    } else {
        string arr1[S.size()];
        int k = 0;
        for (int i = 0; i < S.size(); i++) {
            string next = getNext(arr[i]);
            if (i != S.size() - 1 && !S.count(next)) {
                arr1[k++] = next;
            }
            if (i == S.size() - 1) arr1[k++] = next;
        }
        sort(arr1, arr1 + k, sortStr);
        ans = arr1[0];
    }

    cout << ans << endl;
    return 0;
}