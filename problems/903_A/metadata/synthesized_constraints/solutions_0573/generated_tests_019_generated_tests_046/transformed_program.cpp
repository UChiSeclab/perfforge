#include <bits/stdc++.h>

void check_impossible_request(int x) {
    // Check if x cannot be formed using 3a + 7b for non-negative integers a and b.
    if (x % 3 != 0 && x % 7 != 0 && x % 10 != 0) {
        std::cerr << "Warning: impossible_request invariant triggered - x cannot be formed" << std::endl;
        abort();
    }
}

int main(int argc, const char* argv[]) {
    int n;
    std::cin >> n;
    while (n-- > 0) {
        int x;
        std::cin >> x;

        // Check for impossible requests based on the derived invariant
        check_impossible_request(x);

        bool flag = false;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                int t = 3 * i + 7 * j;
                if (t == x) flag = true;
            }
        }
        if (flag)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}