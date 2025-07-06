#include <bits/stdc++.h>
using namespace std;

// Define the node structure for the trie
struct node {
    int isend = 0;
    int cnt = 0;
    struct node* left;
    struct node* right;
};

// Global root node for the trie
node* root = new node();

// Function to create a new node
struct node* getnode() {
    struct node* cur = new node();
    cur->left = NULL;
    cur->right = NULL;
    return cur;
}

// Insert a binary string representation into the trie
void insert(struct node* root, string s) {
    struct node* cur = root;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (cur->left == NULL) {
                cur->left = getnode();
            }
            cur->left->cnt++;
            cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = getnode();
            }
            cur->right->cnt++;
            cur = cur->right;
        }
    }
    cur->isend++;
}

// Delete a binary string representation from the trie
void deleteit(struct node* root, string s) {
    struct node* cur = root;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            cur->left->cnt--;
            if (cur->left->cnt == 0) {
                cur->left = NULL;
                break;
            } else
                cur = cur->left;
        } else {
            cur->right->cnt--;
            if (cur->right->cnt == 0) {
                cur->right = NULL;
                break;
            } else
                cur = cur->right;
        }
    }
}

// Find the maximum XOR of a given binary string with the trie
long long find(struct node* root, string s) {
    struct node* cur = root;
    long long ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (cur->right != NULL) {
                ans += (1ll << (31 - i));
                cur = cur->right;
            } else if (cur->left != NULL) {
                cur = cur->left;
                continue;
            }
        } else {
            if (cur->left != NULL) {
                ans += (1ll << (31 - i));
                cur = cur->left;
            } else if (cur->right != NULL)
                cur = cur->right;
            continue;
        }
    }
    return ans;
}

// Convert an integer to a binary string representation
string get(int x) {
    string s = "";
    int sz = 0;
    while (x) {
        s = (char)(x % 2 + 48) + s;
        x /= 2;
        sz++;
    }
    while (sz <= 31) {
        s = '0' + s;
        sz++;
    }
    return s;
}

// Main function
int main() {
    int q;
    cin >> q;
    insert(root, get(0));

    int queryCounter = 0;

    while (q--) {
        char ch;
        cin >> ch;
        if (ch == '+') {
            long long x;
            cin >> x;
            elementFrequency[x]++;  // Track frequency of element
            check_repeated_element_operations(x);  // Check for repeated operations
            insert(root, get(x));
        }
        if (ch == '-') {
            long long x;
            cin >> x;
            elementFrequency[x]--;  // Track frequency of element
            check_repeated_element_operations(x);  // Check for repeated operations
            deleteit(root, get(x));
        } else if (ch == '?') {
            long long x;
            cin >> x;
            queryCounter++;
            check_frequent_queries(queryCounter);  // Check for frequent queries
            long long ans = find(root, get(x));
            if (ans == 0) ans = x;
            cout << ans << "\n";
        }
    }
    return 0;
}