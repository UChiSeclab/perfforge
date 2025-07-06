#include <bits/stdc++.h>

struct Box {
    size_t pos;
    char color;
    size_t candies;
};

struct CacheEntry {
    size_t curPath;
    size_t curCandies;
};

// Function to check cache size
void check_cache_size_invariant(size_t cacheSize, size_t threshold) {
    if (cacheSize > threshold) {
        std::cerr << "Warning: Performance bottleneck condition triggered - cache size too large!" << std::endl;
        abort();
    }
}

// Function to check recursion depth
void check_recursion_depth_invariant(size_t curDepth, size_t maxDepth) {
    if (curDepth > maxDepth) {
        std::cerr << "Warning: Performance bottleneck condition triggered - recursion depth too high!" << std::endl;
        abort();
    }
}

// Function to check candy and color pattern issues
void check_candy_color_invariant(size_t candyCount, char currentColor) {
    if (candyCount < 5 && currentColor == 'R') {  // This condition is arbitrary; refine based on real patterns
        std::cerr << "Warning: Performance bottleneck condition triggered - unfavorable candy count or color pattern!" << std::endl;
        abort();
    }
}

int eat(const std::vector<Box> &boxes, std::vector<std::list<CacheEntry>> &cache,
        std::vector<Box>::iterator it, size_t curPath, size_t prevPos,
        size_t curCandies, size_t threshold, size_t curDepth) {
    size_t newPos = it->pos;
    curCandies += it->candies;
    curPath += std::max(prevPos, newPos) - std::min(prevPos, newPos);
    auto &cacheList = cache.at(newPos);

    // Check cache size invariant
    check_cache_size_invariant(cacheList.size(), 100); // Arbitrary threshold

    for (auto it = cacheList.begin(); it != cacheList.end();) {
        if (curCandies <= it->curCandies && curPath >= it->curPath)
            return -1;
        else if (curCandies >= it->curCandies && curPath < it->curPath ||
                 curCandies > it->curCandies && curPath <= it->curPath)
            cacheList.erase(it++);
        else
            ++it;
    }
    cacheList.push_back(CacheEntry{curPath, curCandies});
    if (curCandies >= threshold) return curPath;

    char color = it->color;
    size_t candies = it->candies;
    int res = -1;

    // Check recursion depth invariant
    check_recursion_depth_invariant(curDepth, 10); // Arbitrary threshold

    for (++it; it != boxes.end(); ++it) {
        if (it->color == color || it->candies == candies) continue;

        // Check candy color invariant
        check_candy_color_invariant(it->candies, it->color);

        int newRes = eat(boxes, cache, it, curPath, newPos, curCandies, threshold, curDepth + 1);
        if (res == -1)
            res = newRes;
        else if (newRes != -1)
            res = std::min(res, newRes);
    }
    return res;
}

int main(int argc, char *argv[]) {
    size_t n, s, k;
    std::cin >> n >> s >> k;
    std::vector<Box> boxes(n);
    for (size_t i = 0; i < n; ++i) {
        boxes.at(i).pos = i;
        std::cin >> boxes.at(i).candies;
    }
    std::string colors;
    std::cin >> colors;
    for (size_t i = 0; i < n; ++i) boxes.at(i).color = colors.at(i);
    std::sort(boxes.begin(), boxes.end(), [](const Box &lhs, const Box &rhs) {
        return lhs.candies < rhs.candies;
    });
    std::vector<std::list<CacheEntry>> cache(n);
    int res = -1;
    for (auto it = boxes.begin(); it != boxes.end(); ++it) {
        int newRes = eat(boxes, cache, it, 0, s - 1, 0, k, 0); // Start recursion depth from 0
        if (res == -1)
            res = newRes;
        else if (newRes != -1)
            res = std::min(res, newRes);
    }
    std::cout << res << std::endl;
    return 0;
}