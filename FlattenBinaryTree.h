#pragma once
#include<stddef.h> // for NULL definition
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : left(NULL), right(NULL) {}
};
class FlattenBinaryTree
{
    public:
    void flatten(TreeNode *root) ;

};