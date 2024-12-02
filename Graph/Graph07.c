*DSA ASSIGNMENT *
->CUT THE TREE

#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

const int MAXN = 1e5+5;
vector<int> tree[MAXN];
int values[MAXN];
int subtree_sum[MAXN];
bool visited[MAXN];
int total_sum = 0;
int min_diff = INT_MAX;

void dfs(int node) {
    visited[node] = true;
    subtree_sum[node] = values[node];

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);
            subtree_sum[node] += subtree_sum[child];
        }
    }

    if (node != 1) { // Assuming 1 is the root node
        int diff = abs(total_sum - 2 * subtree_sum[node]);
        min_diff = min(min_diff, diff);
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> values[i];
        total_sum += values[i];
    }

    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1); // Start DFS from the root node

    cout << min_diff << endl;

    return 0;
}

->LEVEL ORDER

void levelOrder(Node * root) {
        if(!root)return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*node=q.front();
            cout<<node->data<<" ";
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

    }

->TOP VIEW

void topView(Node* root) {
    if (root == nullptr)
        return;

    map<int, int> hlp;
    queue<pair<Node*, int>> qpr;

    qpr.push({root, 0});

    while (!qpr.empty()) {
        Node* temp = qpr.front().first;
        int x = qpr.front().second;
        qpr.pop();

        if (hlp.find(x) == hlp.end()) {
            hlp[x] = temp->data;
        }

        if (temp->left)
            qpr.push({temp->left, x - 1});

        if (temp->right)
            qpr.push({temp->right, x + 1});
    }

    
    for (auto it = hlp.begin(); it != hlp.end(); ++it) {
        std::cout << it->second << " ";
    }
}

->SWAP NODES

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    inorderTraversal(node->left, result);
    result.push_back(node->data);
    inorderTraversal(node->right, result);
}

void swapAtDepth(Node* node, int level, int k) {
    if (node == nullptr) return;
    if (level % k == 0) swap(node->left, node->right);
    swapAtDepth(node->left, level + 1, k);
    swapAtDepth(node->right, level + 1, k);
}

int main() {
    int N;
    cin >> N;
    vector<Node*> nodes(N + 1);
    for (int i = 1; i <= N; ++i) {
        nodes[i] = new Node(i);
    }
    
    for (int i = 1; i <= N; ++i) {
        int left, right;
        cin >> left >> right;
        if (left != -1) nodes[i]->left = nodes[left];
        if (right != -1) nodes[i]->right = nodes[right];
    }
    
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        swapAtDepth(nodes[1], 1, k);
        vector<int> result;
        inorderTraversal(nodes[1], result);
        for (int value : result) {
            cout << value << " ";
        }
        cout << endl;
    }
    
    return 0;
}

->BST:LOWEST ORDER COMMON ANCESTOR

Node *lca(Node *root, int n1,int n2) {
        if(root==NULL)
            return NULL;
        if(root->data > n1 && root->data > n2)
            return lca (root->left , n1,n2);
        if(root->data < n1 && root->data < n2)
            return lca (root->right , n1,n2);
        
        return root;
    }