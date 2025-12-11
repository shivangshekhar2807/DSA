#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == k)
    {
        return true;
    }

    bool left;

    bool right;

    if (root->data > k)
    {
        left = searchInBST(root->left, k);
    }
    if (root->data < k)
    {
        right = searchInBST(root->right, k);
    }

    if (left || right)
    {
        return true;
    }

    return false;
}