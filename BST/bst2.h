#pragma once
#include <iostream>

typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
}
Node;

Node* Add_Node(Node* root, int data);
void display(Node* root, int nivel);
Node* FindMin(Node* root);
Node* stergere_nod(Node* root, int data);
void order(Node* root);
void deep(Node* root, int data);
