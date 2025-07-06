#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_dense_graph(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to dense graph of character overlaps!" << endl;
        abort();
    }
}

void check_cyclic_dependencies(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to complex cyclic dependencies!" << endl;
        abort();
    }
}

void check_character_set_size(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to large character set utilization!" << endl;
        abort();
    }
}

template <class X, class Y>
void minimize(X &x, const Y &y) {
    if (x > y) x = y;
}

template <class X, class Y>
void maximize(X &x, const Y &y) {
    if (x < y) x = y;
}

template <class T>
T Abs(const T &x) {
    return (x < 0 ? -x : x);
}

const string NO = "NO";

void answerNO(void) {
    cout << NO << endl;
    exit(EXIT_SUCCESS);
}

bool havePath[226][226], need[226][226];
int countIn[226], countOut[226];

bool compare(const string &s, const string &t) { return s + t < t + s; }

void process(void) {
    int needChar = 0;
    int n;
    cin >> n;
    for (int love = 0, _n = (n); love < _n; love = love + 1) {
        string s;
        cin >> s;
        int mask = 0;
        for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++) {
            if ((((mask) >> (*it - 'a')) & 1)) answerNO();
            mask |= (1LL << (*it - 'a'));
        }
        for (int i = 0, _n = ((int)s.size() - 1); i < _n; i = i + 1) {
            int x = s[i] - 'a';
            int y = s[i + 1] - 'a';
            need[x][y] = true;
        }
        needChar |= mask;
    }

    // Check for large character set utilization
    check_character_set_size(__builtin_popcount(needChar) > 20); // Example threshold

    for (int i = 0, _n = (26); i < _n; i = i + 1) havePath[i][i] = true;
    for (int i = 0, _n = (26); i < _n; i = i + 1)
        for (int j = 0, _n = (26); j < _n; j = j + 1) havePath[i][j] |= need[i][j];
    
    for (int k = 0, _n = (26); k < _n; k = k + 1)
        for (int i = 0, _n = (26); i < _n; i = i + 1)
            for (int j = 0, _n = (26); j < _n; j = j + 1)
                havePath[i][j] |= havePath[i][k] && havePath[k][j];
    
    // Check for complex cyclic dependencies
    for (int i = 0, _n = (26); i < _n; i = i + 1)
        for (int j = 0, _n = (26); j < _n; j = j + 1)
            if (i != j && havePath[i][j] && havePath[j][i])
                check_cyclic_dependencies(true);
    
    for (int i = 0, _n = (26); i < _n; i = i + 1)
        for (int j = 0, _n = (26); j < _n; j = j + 1)
            if (need[i][j]) {
                countIn[j]++;
                countOut[i]++;
            }

    // Check for dense graph of character overlaps
    check_dense_graph(std::accumulate(&countIn[0], &countIn[26], 0) > 13); // Example threshold

    for (int i = 0, _n = (26); i < _n; i = i + 1)
        if (countIn[i] > 1 || countOut[i] > 1) answerNO();
    
    vector<string> str;
    for (int i = 0, _n = (26); i < _n; i = i + 1)
        if (countOut[i] > 0 && countIn[i] == 0) {
            int tmp = i;
            string s;
            while (countOut[tmp] > 0) {
                s.push_back(tmp + 'a');
                for (int j = 0, _n = (26); j < _n; j = j + 1)
                    if (need[tmp][j]) {
                        tmp = j;
                        break;
                    }
            }
            s.push_back(tmp + 'a');
            str.push_back(s);
        }
    
    for (int i = 0, _n = (26); i < _n; i = i + 1)
        if ((((needChar) >> (i)) & 1) && countIn[i] == 0 && countOut[i] == 0)
            str.push_back(string(1, i + 'a'));
    
    sort((str).begin(), (str).end(), compare);
    for (__typeof((str).begin()) it = (str).begin(); it != (str).end(); it++)
        cout << *it;
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    process();
    return 0;
}