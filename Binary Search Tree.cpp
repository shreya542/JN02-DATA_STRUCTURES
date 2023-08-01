#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            // Node with only one child or no child
            if (current->left == nullptr) {
                TreeNode* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                TreeNode* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMin(current->right);

            // Copy the inorder successor's data to this node
            current->data = temp->data;

            // Delete the inorder successor
            current->right = deleteRecursive(current->right, temp->data);
        }
        return current;
    }

    void inOrderRecursive(TreeNode* current) {
        if (current == nullptr) {
            return;
        }

        inOrderRecursive(current->left);
        std::cout << current->data << " ";
        inOrderRecursive(current->right);
    }

    void preOrderRecursive(TreeNode* current) {
        if (current == nullptr) {
            return;
        }

        std::cout << current->data << " ";
        preOrderRecursive(current->left);
        preOrderRecursive(current->right);
    }

    void postOrderRecursive(TreeNode* current) {
        if (current == nullptr) {
            return;
        }

        postOrderRecursive(current->left);
        postOrderRecursive(current->right);
        std::cout << current->data << " ";
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    bool search(int value) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    void inOrderTraversal() {
        std::cout << "In-order Traversal: ";
        inOrderRecursive(root);
        std::cout << std::endl;
    }

    void preOrderTraversal() {
        std::cout << "Pre-order Traversal: ";
        preOrderRecursive(root);
        std::cout << std::endl;
    }

    void postOrderTraversal() {
        std::cout << "Post-order Traversal: ";
        postOrderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the binary search tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform tree traversals
    bst.inOrderTraversal();   // Output: In-order Traversal: 20 30 40 50 60 70 80
    bst.preOrderTraversal();  // Output: Pre-order Traversal: 50 30 20 40 70 60 80
    bst.postOrderTraversal(); // Output: Post-order Traversal: 20 40 30 60 80 70 50

    // Search for elements in the tree
    std::cout << "Search 30: " << (bst.search(30) ? "Found" : "Not Found") << std::endl; // Output: Found
    std::cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << std::endl; // Output: Not Found

    // Remove elements from the tree
    
    bst.remove(30);
    bst.inOrderTraversal(); // Output: In-order Traversal: 20 40 50 60 70 80

    return 0;
}
