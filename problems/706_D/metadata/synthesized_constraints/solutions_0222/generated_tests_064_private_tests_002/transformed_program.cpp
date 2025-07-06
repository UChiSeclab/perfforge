#include <bits/stdc++.h>
using namespace std;

struct trieNode {
    trieNode *children[2];
    int counter;
    trieNode() {
        counter = 0;
        for (int i = 0; i < 2; i++) children[i] = NULL;
    }
} *root = new trieNode();

// Checkers for performance bottlenecks
void check_addition_invariant(int additionCount) {
    if (additionCount > 100) {
        cerr << "Warning: Performance bottleneck condition triggered due to frequent additions of the same value!" << endl;
        abort();
    }
}

void check_query_invariant(int queryCount) {
    if (queryCount > 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to repetitive similar queries!" << endl;
        abort();
    }
}

void check_conversion_invariant(int conversionCount) {
    if (conversionCount > 200) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive binary conversions!" << endl;
        abort();
    }
}

void check_trie_saturation_invariant(int trieDepth) {
    if (trieDepth > 30) {
        cerr << "Warning: Performance bottleneck condition triggered due to trie saturation!" << endl;
        abort();
    }
}

void add(string s, int delta) {
    trieNode *cur = root;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        int idx = s[i] - '0';
        if (cur->children[idx] == NULL) cur->children[idx] = new trieNode();
        cur = cur->children[idx];
        cur->counter += delta;
    }
}

int query(string s) {
    int n = s.length();
    int ret = 0;
    trieNode *cur = root;
    for (int i = 0; i < n; i++) {
        int idx = s[i] - '0';
        idx = 1 - idx;
        if (cur->children[idx] != NULL && cur->children[idx]->counter != 0) {
            ret += (1 << (n - i - 1));
            cur = cur->children[idx];
        } else {
            cur = cur->children[1 - idx];
        }
    }
    return ret;
}

string toBinary(int x) {
    string ret = "";
    while (x) {
        if (x % 2 == 0)
            ret = "0" + ret;
        else
            ret = "1" + ret;
        x /= 2;
    }
    while (ret.length() != 30) ret = "0" + ret;
    return ret;
}

int main() {
    int q;
    cin >> q;
    add(toBinary(0), 1);

    int additionCount = 0;  // Track addition operations
    int queryCount = 0;     // Track query operations
    int conversionCount = 0;  // Track conversions

    while (q--) {
        char type;
        int x;
        cin >> type >> x;
        string bin = toBinary(x);

        conversionCount++;
        check_conversion_invariant(conversionCount);  // Check conversion overhead

        if (type == '+') {
            add(bin, 1);
            additionCount++;
            check_addition_invariant(additionCount);  // Check frequent additions
        }
        if (type == '-') {
            add(bin, -1);
        }
        if (type == '?') {
            cout << query(bin) << '\n';
            queryCount++;
            check_query_invariant(queryCount);  // Check repetitive similar queries
        }
    }
}