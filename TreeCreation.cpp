#include <iostream>

class Node {
    public:
    int data;

    Node* left; 
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert (Node* root , int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left , value);
    }
    else if (value > root->data) {
        root->right = insert(root->right , value);
    }
    return root;
}

void inorder (Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    std::cout <<root->data<<" ";
    inorder(root->right);
}

bool search (Node* root , int key) {
    if (root == nullptr) {
        return false;
    }

    if (key == root->data) {
        return true;
    }

    if (key < root->data) {
        return search (root->left , key);
    } else {
        return search (root->right , key);
    }
}

int main () {
    Node* root = nullptr;
    int n , value , key;

    std::cout <<"Enter the number of data : ";
    std::cin >>n;

    for (int i = 0; i < n; i++) {
        std::cout <<"Enter data "<<i + 1<<" : ";
        std::cin >>value;

        root = insert(root, value);
    }

    std::cout <<"\nIn-Order traversal (Sorted) : ";
    inorder(root);

    std::cout <<"\nEnter an element to search : ";
    std::cin >>key;

    if (search(root , key)) {
        std::cout <<"Element found!";
    } else {
        std::cout <<"Element not found!";
    }

    std::cout <<"\n";
}
