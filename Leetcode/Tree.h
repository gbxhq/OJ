#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 创建二叉树 传入数组 和数组大小即可 
// 注意： 只能建完全二叉树！ 建普通二叉树的 方法需要重写！
TreeNode* initBTree(int elements[], int size)
{
    if (size < 1)
    {
        return NULL;
    }
    //动态申请size大小的指针数组
    TreeNode **nodes = new TreeNode*[size];
    //将int数据转换为TreeNode节点
    for (int i = 0; i < size; i++)
    {
        if (elements[i] == 0)
        {
            nodes[i] = NULL;
        }
        else
        {
            nodes[i] = new TreeNode(elements[i]);
        }
    }
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(nodes[0]);

    TreeNode *node;
    int index = 1;
    while (index < size)
    {
        node = nodeQueue.front();
        nodeQueue.pop();
        nodeQueue.push(nodes[index++]);
        node->left = nodeQueue.back();
        nodeQueue.push(nodes[index++]);
        node->right = nodeQueue.back();
    }
    cout <<"建树完成\n" ;
    return nodes[0];
}
// 前序遍历
void preOrder(TreeNode *root, vector<int> &result)
{
    if (root)
    {
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}
// 中序遍历
void inOrder(TreeNode *root, vector<int> &result)
{
    if (root)
    {
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
}
// 后序遍历
void postOrder(TreeNode *root, vector<int> &result)
{
    if (root)
    {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
}


// 根据二叉树的前序和中序遍历，构建二叉树
TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) return NULL;
    int i = 0;
    for (i = iLeft; i <= iRight; ++i) {
        if (preorder[pLeft] == inorder[i]) break;
    }
    TreeNode *cur = new TreeNode(preorder[pLeft]);
    cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
    cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
    return cur;
}// 递归执行上个函数
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, 0, (int)preorder.size()-1, inorder, 0, (int)inorder.size()-1);
}

// // 层次遍历
// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> resultVec; // 保存所有层的节点
//     vector<int> nodeVec; // 保存每层的节点
//     queue<TreeNode*> nodeQue; // 保存当前层节点
//     int curCount = 0;
//     int leftCount = 1;
//     if (root) {
//         nodeQue.push(root);
//     }
//     while (!nodeQue.empty()) {
//         TreeNode* currentNode = nodeQue.front();
//         nodeVec.push_back(currentNode->val);
//         nodeQue.pop();
//         leftCount --;
//         if (currentNode -> left) {
//             nodeQue.push(currentNode->left);
//             curCount ++;
//         }
//         if (currentNode -> right) {
//             nodeQue.push(currentNode->right);
//             curCount ++;
//         }
//         if (leftCount == 0) {
//             resultVec.push_back(nodeVec);
//             leftCount = curCount;
//             curCount = 0;
//             nodeVec.clear();
//         }
//     }
//     return resultVec;
// }

// 遍历输出
void traverse(vector<int> nums)
{
    int size = (int)nums.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

// 计算二叉树的深度
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftDepth = maxDepth(root->left) + 1;
    int rightDepth = maxDepth(root->right) + 1;
    return leftDepth > rightDepth ? leftDepth : rightDepth;
}

// TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
//     if (left > right) {
//         return NULL;
//     }
//     int midIndex = (left+right)/2;
//     TreeNode* root = new TreeNode(nums[midIndex]);
//     root->left = sortedArrayToBST(nums, left, midIndex-1);
//     root->right = sortedArrayToBST(nums, midIndex+1, right);
//     return root;
// }
// // 将有序数组转化为二叉搜索树
// TreeNode* sortedArrayToBST(vector<int>& nums) {
//     return sortedArrayToBST(nums, 0, (int)nums.size()-1);
// }