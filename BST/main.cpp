#include <iostream>
#include"bst2.h"
using namespace std;


int main()
{
    int n, caz, nr, val;
    Node* root = NULL;
    cout << "Introduceti numarul de noduri: ";
    cin >> nr;
    for (int i = 0; i < nr; i++)
    {
        cin >> n;
        root = Add_Node(root, n);
    }
    do {
        cout << "Alegeti obtiunea dorita:" << endl;
        cout << "1.Display." << endl;
        cout << "2.Delete." << endl;
        cout << "3.Order. " << endl;
        cout << "4.Adaugare nod." << endl;
        cout << "5.Adancimea nodului." << endl;
        cin >> caz;
        switch (caz)
        {
        case 1:
            display(root, 0);
            break;
        case 2:
            cout << "Alegeti nodul pe care doriti sa il stergeti: ";
            cin >> val;
            stergere_nod(root, val);
            break;
        case 3:
            order(root);
            break;
        case 4:
            cout << "Adaugati un nod: ";
            cin >> n;
            root = Add_Node(root, n);
            break;
        case 5:
            cout << "Introduceti nodul caruiva vreti sa ii aflati adancimea.";
            cin >> n;
            deep(root, n);
        }
    } while (nr != 0);


    delete root;
    return 0;

}
