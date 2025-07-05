#include <bits/stdc++.h>
using namespace std;

int k;
string s;
vector<int> len;

// Invariant Check Functions
void check_large_segments_invariant(size_t segmentCount) {
    if (segmentCount > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - Too many segments!" << endl;
        abort();
    }
}

void check_high_length_invariant(int totalLength) {
    if (totalLength > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - High total segment length!" << endl;
        abort();
    }
}

void check_hyphen_usage_invariant(int hyphenCount) {
    if (hyphenCount > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - Excessive hyphens!" << endl;
        abort();
    }
}

void check_k_value_invariant(int k, size_t segmentCount) {
    if (k > 90000 && segmentCount > 30) {
        cerr << "Warning: Performance bottleneck condition triggered - Large k with complex input!" << endl;
        abort();
    }
}

bool check(int x) {
    int pos = 0, ans = 0;
    while (pos < len.size()) {
        int tmp = x;
        while (pos < len.size() && tmp >= len[pos]) tmp -= len[pos++];
        ++ans;
        if (ans > k) return false;
    }
    return true;
}

int main() {
    cin >> k;
    getline(cin, s); // Read the entire line including spaces
    getline(cin, s); // Read the actual ad text
    
    int tmp = 0, hyphenCount = 0, totalLength = 0;
    for (int i = 0; i < s.size(); i++) {
        ++tmp;
        if (s[i] == '-') {
            ++hyphenCount;
        }
        if (s[i] == ' ' || s[i] == '-') {
            len.push_back(tmp);
            tmp = 0;
        }
    }
    len.push_back(tmp);

    totalLength = s.size();
    size_t segmentCount = len.size();

    // Check performance-characterizing invariants
    check_large_segments_invariant(segmentCount);
    check_high_length_invariant(totalLength);
    check_hyphen_usage_invariant(hyphenCount);
    check_k_value_invariant(k, segmentCount);

    int lbound = 0, ubound = 1000000;
    for (int i = 0; i < 1500; i++) {
        int mid = (lbound + ubound) / 2;
        if (check(mid))
            ubound = mid;
        else
            lbound = mid + 1;
    }
    cout << lbound << endl;
    return 0;
}