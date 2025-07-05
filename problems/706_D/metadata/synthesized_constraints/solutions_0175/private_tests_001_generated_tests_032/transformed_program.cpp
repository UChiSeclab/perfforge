#include <bits/stdc++.h>
using namespace std;

int TRIE[200005 * 32 * 2][2];
int isword[200005 * 32 * 2];
int nxt;

// Performance checkers
void check_alternating_insert_delete(int insertCount, int deleteCount) {
    if (insertCount > 1000 && deleteCount > 1000) {
        cerr << "Warning: Performance bottleneck due to high alternating insertions and deletions!" << endl;
        abort();
    }
}

void check_string_operations(int conversionCount) {
    if (conversionCount > 2000) {
        cerr << "Warning: Performance bottleneck due to excessive binary string conversions!" << endl;
        abort();
    }
}

void check_query_load(int queryCount, int trieSize) {
    if (queryCount > 1000 && trieSize > 1024) {
        cerr << "Warning: Performance bottleneck due to high query load on large TRIE!" << endl;
        abort();
    }
}

void ins(string &s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        if (TRIE[v][s[i] - '0'] == -1) TRIE[v][s[i] - '0'] = nxt++;
        isword[v]++;
        v = TRIE[v][s[i] - '0'];
    }
    isword[v]++;
}

void del(string &s) {
    int v = 0;
    int u;
    for (int i = 0; i < s.size(); i++) {
        if (isword[v] > 0) isword[v]--;
        if (isword[v] == 0 && i > 0) TRIE[u][s[i - 1] - '0'] = -1;
        u = v;
        v = TRIE[v][s[i] - '0'];
    }
    if (isword[v] > 0) isword[v]--;
    if (isword[v] == 0) TRIE[u][s[31] - '0'] = -1;
}

string bin(int a) {
    string k = "";
    while (a) {
        k += to_string(a % 2);
        a /= 2;
    }
    int u = k.length();
    for (int i = 0; i < 32 - u; i++) k += "0";
    reverse(k.begin(), k.end());
    return k;
}

long long int query(string &s) {
    int v = 0;
    string k = "";
    for (int i = 0; i < s.size(); i++) {
        if (TRIE[v][1 - (s[i] - '0')] != -1) {
            v = TRIE[v][1 - (s[i] - '0')];
            if (s[i] == '0')
                k += "1";
            else
                k += "0";
        } else {
            v = TRIE[v][s[i] - '0'];
            k += s[i];
        }
    }
    long long int val = 0, bit;
    for (int i = 0; i <= 31; i++) {
        bit = (s[i] == k[i]) ? 0 : 1;
        val <<= 1;
        val += bit;
    }
    return val;
}

int main() {
    memset(isword, 0, sizeof(isword));
    memset(TRIE, -1, sizeof(TRIE));
    isword[0] = 1;
    nxt = 1;
    int q, a;
    int insertCount = 0, deleteCount = 0, conversionCount = 0, queryCount = 0;
    string s;
    cin >> q;
    string k = bin(0);
    ins(k);
    for (int i = 0; i < q; i++) {
        cin >> s >> a;
        conversionCount++;
        string k = bin(a);
        if (s == "+") {
            ins(k);
            insertCount++;
        } else if (s == "-") {
            del(k);
            deleteCount++;
        } else {
            cout << query(k) << endl;
            queryCount++;
        }

        // Performance checks
        check_alternating_insert_delete(insertCount, deleteCount);
        check_string_operations(conversionCount);
        check_query_load(queryCount, nxt);
    }
    return 0;
}