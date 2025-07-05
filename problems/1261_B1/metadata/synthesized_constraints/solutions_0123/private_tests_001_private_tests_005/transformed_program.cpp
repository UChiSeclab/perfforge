#include <bits/stdc++.h>
using namespace std;

// Function to check for excessive subsequence searches
void check_subsequence_invariant(long long n, long long m) {
    if (n > 80 && m > 80) {
        cerr << "Warning: subsequence_invariant triggered - excessive subsequence searches" << endl;
        abort();
    }
}

// Function to check for high data structure overhead
void check_map_invariant(const unordered_map<long long, long long>& mymap) {
    if (mymap.size() > 50) {
        cerr << "Warning: map_invariant triggered - high data structure overhead" << endl;
        abort();
    }
}

// Function to check for high repetition checks
void check_repeated_elements_invariant(long long n) {
    if (n > 90) {
        cerr << "Warning: repeated_elements_invariant triggered - high repetition checks" << endl;
        abort();
    }
}

long long MOD = 1e9 + 7;
const long long maxn = 2e5 + 5;
long long a[maxn];
long long n, m, t;
vector<long long> v;
vector<long long> temp;
unordered_map<long long, long long> mymap;
unordered_map<long long, long long> current;

long long help(long long id, long long x) {
    current.clear();
    long long index = -1;
    for (long long i = id; i <= t - 1; i++) {
        if (temp[i] == x) {
            index = i;
            break;
        }
    }
    for (long long i = index; i <= t - 1; i++) {
        current[temp[i]]++;
    }
    for (auto it : mymap) {
        if (current[it.first] < it.second) return -1;
    }
    return index;
}

long long f(long long k, long long pos) {
    set<long long> s;
    temp.clear();
    mymap.clear();
    for (long long i = 0; i < k; ++i) {
        mymap[v[i]]++;
        s.insert(v[i]);
    }
    vector<long long> flag;
    for (auto it : s) flag.emplace_back(it);
    for (long long i = 1; i <= n; ++i) {
        if (mymap[a[i]]) temp.emplace_back(a[i]);
    }
    vector<long long> ans;
    long long prev = 0;
    t = temp.size();
    while (ans.size() != k) {
        for (auto it : flag) {
            if (mymap[it] == 0) continue;
            long long id = help(prev, it);
            if (id != -1) {
                ans.emplace_back(it);
                prev = id + 1;
                mymap[it]--;
                break;
            }
        }
        if (ans.size() == pos) return ans.back();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin >> n;

    // Checking for high repetition checks
    check_repeated_elements_invariant(n);

    for (long long i = 1; i <= n; i++) cin >> a[i], v.emplace_back(a[i]);
    cin >> m;

    // Checking for excessive subsequence searches
    check_subsequence_invariant(n, m);

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    while (m--) {
        long long k, pos;
        cin >> k >> pos;
        cout << f(k, pos) << endl;
        // Check for map size within function
        check_map_invariant(mymap);
    }
    return 0;
}