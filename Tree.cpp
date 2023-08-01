#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

    void insertRecursive(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
        } else {
            if (value < node->data) {
                insertRecursive(node->left, value);
            } else {
                insertRecursive(node->right, value);
            }
        }
    }

    bool searchRecursive(TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteRecursive(TreeNode*& node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursive(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            } else {
                TreeNode* minRight = findMin(node->right);
                node->data = minRight->data;
                node->right = deleteRecursive(node->right, minRight->data);
            }
        }
        return node;
    }

    void inorderTraversal(TreeNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    Tree() : root(nullptr) {}

    void insert(int value) {
        insertRecursive(root, value);
    }

    bool search(int value) const {
        return searchRecursive(root, value);
    }

    void remove(int value) {
        deleteRecursive(root, value);
    }

    void display() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Tree elements: ";
    tree.display();

    int searchValue = 6;
    if (tree.search(searchValue)) {
        std::cout << searchValue << " is present in the tree." << std::endl;
    } else {
        std::cout << searchValue << " is not present in the tree." << std::endl;
    }

    int removeValue = 3;
    tree.remove(removeValue);
    std::cout << "After removing " << removeValue << ": ";
    tree.display();

    return 0;
}
