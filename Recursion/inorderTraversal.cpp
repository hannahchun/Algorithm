#include <iostream>

using namespace std;

struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};

Node* newNode (int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} 

void inOrder(Node* ptr) {
    if (ptr == NULL)
        return;

    if (ptr->left != NULL)
        inOrder(ptr->left);

    cout << ptr->data << " ";

    if (ptr->right != NULL)
        inOrder(ptr->right);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 

    cout << "Inorder traversal of binary tree is \n";
    inOrder(root);
    cout << endl;

    return 0;
}