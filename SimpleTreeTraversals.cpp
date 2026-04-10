#include <iostream>

class Node {
    public:
    int data;

    Node* left;
    Node* right;

    Node (int value) {
        data = value;
        left = right = nullptr;
    }
};

void inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    std::cout <<node->data<<" ";
    inorder(node->right);
}

void preorder (Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout <<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void postorder (Node* node) {
    if (node == nullptr) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    std::cout <<node->data<<" ";
}

int main () {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    int choice;

    do {
        std::cout <<"\n--- Tree Traversals ---\n";
        std::cout <<"1.In-Order\n";
        std::cout <<"2.Pre-Order\n";
        std::cout <<"3.Post-Order\n";
        std::cout <<"4.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        if (choice == 1) {
            std::cout <<"\nIn-Order Traversal : ";
            inorder(root);
        }
        else if (choice == 2) {
            std::cout <<"\nPre-Order Traversal : ";
            preorder(root);
        }
        else if (choice == 3) {
            std::cout <<"\nPost-Order Traversal : ";
            postorder(root);
        }
        else if (choice == 4) {
            std::cout <<"\n\033[32mProgram Exited!\033[0m";
        }
        else {
            std::cout <<"\n\033[31mInvalid Choice!\033[0m";
        }

    } while (choice != 4);

    

    return 0;
}
