class Solution {
public:
    Node* construct(vector<vector<int>>& g, int l = 0, int t = 0, int r = -1, int b = -1) {
        r = r == -1 ? g.size() - 1 : r;
        b = b == -1 ? g[r].size() - 1 : b;
        if (l == r)
            return new Node(g[t][l], true);
        auto tl = construct(g, l, t, (l + r) / 2, (t + b) / 2);
        auto tr = construct(g, (l + r) / 2 + 1, t, r, (t + b) / 2);
        auto bl = construct(g, l, (t + b) / 2 + 1, (l + r) / 2, b);
        auto br = construct(g, (l + r) / 2 + 1, (t + b) / 2 + 1, r, b);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf
                && tl->val == tr->val && bl->val == br->val && tl->val == br->val)
            return new Node(tl->val, true);
        return new Node(false, false, tl, tr, bl, br);
    }

};