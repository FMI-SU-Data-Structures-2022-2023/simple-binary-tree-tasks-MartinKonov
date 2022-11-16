#include "solution.h"

int countElements(Node* tree) {
    if (!tree) return 0;
    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
    if (!tree) return 0;
    if (!tree->left && !tree->right) return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    if (!tree) return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node* tree) {
    if (!tree) return 0;
    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if (!tree) return 0;
    if (!level) return tree->key;
    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}

bool helper(Node* lft, Node* rght) {

    if (!lft && !rght) return true;
    if (!lft || !rght) return false;
    if (lft->key == rght->key) {
        return helper(lft->left, rght->right) && helper(lft->right, rght->left);
    }
    return false;
}

bool isSymmetric(Node* tree) {
    if (!tree) return true;
    if (!tree->left && !tree->right) return true;
    return helper(tree->left, tree->right);
}

void inorderInVec(Node* tree, std::vector<int>* vecTree) {

    if (!tree) return;

    inorderInVec(tree->left, vecTree);
    vecTree->push_back(tree->key);
    inorderInVec(tree->right, vecTree);
}

void preorderInVec(Node* tree, std::vector<int>* vecTree) {

    if (!tree) return;
    
    vecTree->push_back(tree->key);
    preorderInVec(tree->left, vecTree);
    preorderInVec(tree->right, vecTree);

}

void postorderInVec(Node* tree, std::vector<int>* vecTree) {

    if (!tree) return;

    preorderInVec(tree->left, vecTree);
    preorderInVec(tree->right, vecTree);
    vecTree->push_back(tree->key);

}

bool isSorted(const std::vector<int> vecTree) {

    for (size_t i = 0; i < vecTree.size() - 1 ; i++)
    {
        if (vecTree[i] > vecTree[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isBST(Node* tree) {
    std::vector<int> vecTree;
    inorderInVec(tree, &vecTree);
    return isSorted(vecTree);
}