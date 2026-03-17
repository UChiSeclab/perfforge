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
int eat(const std::vector<Box> &boxes,
        std::vector<std::list<CacheEntry>> &cache,
        std::vector<Box>::iterator it, size_t curPath, size_t prevPos,
        size_t curCandies, size_t threshold) {
  size_t newPos = it->pos;
  curCandies += it->candies;
  curPath += std::max(prevPos, newPos) - std::min(prevPos, newPos);
  auto &cacheList = cache.at(newPos);
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
  for (++it; it != boxes.end(); ++it) {
    if (it->color == color || it->candies == candies) continue;
    int newRes = eat(boxes, cache, it, curPath, newPos, curCandies, threshold);
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
    int newRes = eat(boxes, cache, it, 0, s - 1, 0, k);
    if (res == -1)
      res = newRes;
    else if (newRes != -1)
      res = std::min(res, newRes);
  }
  std::cout << res << std::endl;
  return 0;
}
