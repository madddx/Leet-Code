class FindElements {
private:
    unordered_set<int> seen;
public:
    FindElements(TreeNode* root) {
        if (root) { // root 不為空時才執行 BFS
            root->val = 0; // 根節點固定為 0
            bfs(root);
        }
    }

    bool find(int target) {
        return seen.count(target);
    }

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            int val = node->val; // 取得當前節點值
            seen.insert(val);    // 存入已恢復的數值集合

            if (node->left) {
                node->left->val = 2 * val + 1; // 設置左子節點值
                q.push(node->left);
            }
            if (node->right) {
                node->right->val = 2 * val + 2; // 設置右子節點值
                q.push(node->right);
            }
        }
    }
};
