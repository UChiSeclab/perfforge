#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
using namespace std;

const bool DEBUG = false;

// Checker functions
void check_recursion_depth_and_branching(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth or branching factor!" << endl;
        abort();
    }
}

void check_string_pattern_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex string patterns!" << endl;
        abort();
    }
}

void check_trie_interactions(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent trie interactions!" << endl;
        abort();
    }
}

struct TupleHasher {
    std::size_t operator()(
        const std::tuple<long long int, long long int, long long int, long long int>& k) const {
        return std::get<0>(k) ^ (std::get<1>(k) << 8) ^ (std::get<2>(k) << 16) ^ (std::get<3>(k) << 30);
    }
};

std::unordered_map<
    std::tuple<long long int, long long int, long long int, long long int>,
    long long int, TupleHasher> dyna;

struct TrieNode {
    TrieNode() : word_score(-1), children('z' - 'a' + 1, -1) {}
    long long int word_score;
    std::vector<long long int> children;
};

struct Trie {
    Trie() : nodes_(1) {}

    void Add(const std::string& word, long long int score) {
        assert(score >= 0);
        long long int trie_pos = 0;
        if (DEBUG) {
            std::cout << "Adding: '" << word << "': " << score << std::endl;
        }
        TrieNode* cur = &nodes_[0];
        for (long long int i = 0; i < word.size(); ++i) {
            long long int c = word[i] - '0';
            long long int& next_index = cur->children.at(c);
            if (next_index < 0) {
                next_index = nodes_.size();
                nodes_.push_back(TrieNode());
            }
            cur = &nodes_[next_index];
        }
        cur->word_score = std::max(cur->word_score, score);
    }

    long long int GetScore(long long int trie_pos) const {
        if (trie_pos < 0) {
            return -1;
        }
        return nodes_.at(trie_pos).word_score;
    }

    long long int Next(long long int trie_pos, char c) const {
        if (trie_pos < 0) {
            return trie_pos;
        }
        return nodes_.at(trie_pos).children.at(c - '0');
    }

    std::vector<TrieNode> nodes_;
};

long long int solve(const std::string& s, const Trie& trie, long long int i, long long int j, long long int trie_pos, bool require_match, long long int debug_word_start) {
    if (DEBUG) {
        std::cout << "COMPUTE: i=" << i << " j = " << j << " trie_pos: " << trie_pos << " debug_word_start: " << debug_word_start << std::endl;
    }
    if (i == j) {
        long long int score = trie.GetScore(trie_pos);
        if (DEBUG) {
            std::cout << "SCORE: i=" << i << " trie_pos: " << trie_pos << " score: " << score << std::endl;
        }
        if (!require_match && score < 0) return 0;
        return score;
    }
    assert(i < j);
    assert(j <= s.size());
    auto t = std::make_tuple(i, j, trie_pos, require_match);
    auto it = dyna.find(t);
    if (it != dyna.end()) return it->second;
    long long int& res = dyna[t];
    res = require_match ? -1 : 0;
    const long long int next_trie_pos = trie.Next(trie_pos, s[i]);
    if (next_trie_pos >= 0) {
        long long int res_next = solve(s, trie, i + 1, j, next_trie_pos, require_match, debug_word_start);
        if (DEBUG) {
            std::cout << "continue: i=" << i << " j=" << j << " trie_pos=" << trie_pos << " debug_word_start=" << debug_word_start << " res= " << res_next << std::endl;
        }
        if (res_next >= 0) {
            res = res_next;
        }
    }
    for (long long int k = i + 1; k <= j; ++k) {
        if (k == j && trie_pos == 0) continue;
        long long int left = solve(s, trie, i, k, 0, trie_pos != 0, i);
        long long int right = solve(s, trie, k, j, trie_pos, require_match, debug_word_start);
        if (DEBUG) {
            std::cout << "skip: i=" << i << " j=" << j << " trie_pos=" << trie_pos << " k1=" << i + 1 << " k=" << k << " debug_word_start=" << debug_word_start << " left=" << left << " right=" << right << std::endl;
        }
        if (left >= 0 && right >= 0) {
            res = std::max(res, left + right);
        }
    }

    // Check for recursion depth and branching
    const int maxDepthThreshold = 50;  // Arbitrary threshold
    const int maxBranchFactor = 10;    // Arbitrary threshold
    check_recursion_depth_and_branching((j - i > maxDepthThreshold) && (j - i > maxBranchFactor));

    return res;
}

int main() {
    Trie trie;
    int n;
    scanf("%d", &n);
    std::string s;
    std::cin >> s;
    std::string word, word2;
    for (int i = 0; i < n; ++i) {
        word += '1';
        word2 += '0';
        long long int score;
        std::cin >> score;
        trie.Add(word, score);
        trie.Add(word2, score);
    }

    // Check for complex string patterns
    check_string_pattern_complexity(s.find("000") != std::string::npos || s.find("111") != std::string::npos);

    // Check for frequent trie interactions
    check_trie_interactions(trie.nodes_.size() > 100);  // Arbitrary threshold

    long long int res = solve(s, trie, 0, s.size(), 0, false, 0);
    std::cout << res << std::endl;
}