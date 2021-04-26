#include"bst2.h"
#include<iostream>
using namespace std;

Node* Add_Node(Node* root, int data)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = Add_Node(root->left, data);
    }
    else
    {
        root->right = Add_Node(root->right, data);
    }
    return root;
}

void display(Node* root, int nivel)
{
    if (root != 0)
    {
        display(root->right, nivel + 1);
        for (int i = 0; i <= nivel; i++)
        {
            cout << "      ";
        }
        cout << root->data << endl;
        display(root->left, nivel + 1);
    }
}
Node* FindMin(Node* root)
{
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* stergere_nod(Node* root, int data)
{
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = stergere_nod(root->left, data);
    }
    else if (data > root->data) {
        root->right = stergere_nod(root->right, data);
    }
    else {
        // CAZUL 1 CAND NU AVEM COPII
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //CAZUL 2 CAND AVEM UN SINGUR COPIL
        else if (root->left == NULL) {
            //Node* temp = root;
            root = root->right;
            //delete temp;
        }
        else if (root->right == NULL) {
            // Node* temp = root;
            root = root->left;
            //delete temp;
        }
        //CAZUL 3
        else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = stergere_nod(root->right, temp->data);
        }

    }
    return root;
}
void order(Node* root)   //Inorder = LPR   Preorder = PLR   Postorder = LRP
{                        // P = print;
    if (root != NULL)
    {
        order(root->left);                      //L
        cout << root->data << " " << endl;      //P
        order(root->right);                     //R
    }
}

void deep(Node* root, int data)
{


}