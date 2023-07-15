#include <iostream>
#include <string>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* str2tree(std::string s) {
    if (s.empty()) {
        return nullptr;
    }

    std::stack<TreeNode*> stk;

    for (int i = 0; i < s.size(); ++i) {
        if (std::isdigit(s[i]) || s[i] == '-') {
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                ++i;
            }
            int num = 0;
            while (i < s.size() && std::isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            stk.push(new TreeNode(sign * num));
            --i;  // Compensate for the increment in the outer loop
        } else if (s[i] == ')') {
            TreeNode* curr = stk.top();
            stk.pop();
            if (!stk.empty()) {
                TreeNode* parent = stk.top();
                if (parent->left == nullptr) {
                    parent->left = curr;
                } else {
                    parent->right = curr;
                }
            }
        }
    }

    return stk.top();
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::string s = "4(2(3)(1))(6(5))";
    TreeNode* root = str2tree(s);
    std::cout << "Output: ";
    inorderTraversal(root);
    std::cout << std::endl;
    return 0;
}
