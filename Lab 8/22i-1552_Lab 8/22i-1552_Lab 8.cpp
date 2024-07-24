// 22i-1552_Lab 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* right_child;
    Node* left_child;

    Node() { right_child = NULL; left_child = NULL; }
    Node(int x)
    {
        data = x;
    }
};

class Tree
{
private:
    Node* root;

public:

    Tree() { root = NULL; }

    Node* getroot()
    {
        return root;
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int num)
    {
        Node* newnode = new Node();

        newnode->data = num;
        newnode->left_child = NULL;
        newnode->right_child = NULL;

        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            Node* current = root;
            while (true)
            {
                if (num < current->data)
                {
                    if (current->left_child == NULL)
                    {
                        current->left_child = newnode;
                        break;
                    }
                    current = current->left_child;
                }
                else if (num > current->data)
                {
                    if (current->right_child == NULL)
                    {
                        current->right_child = newnode;
                        break;
                    }
                    current = current->right_child;
                }
            }
        }
    }

    void inorder(Node* root) 
    {
        if (root == nullptr) 
        {
            //cout << "Tree is empty" << endl;
            return;  
        }

        inorder(root->left_child);
        cout << root->data << " ";
        inorder(root->right_child);
        //cout << endl;
    }

    int Minimum(Node* root)
    {
        int left_min, right_min;
        if (root == nullptr)
        {
            return 3413213; 
        }

        left_min = Minimum(root->left_child);
        right_min = Minimum(root->right_child);

        int minimumvalue = root->data;

        if (left_min < minimumvalue)
        {
            minimumvalue = left_min;
        }
            

        if (right_min < minimumvalue)
        {
            minimumvalue = right_min;
        }
            

        return  minimumvalue;
    }

    bool search(Node* root, int target)
    {
        
        while (root) 
        {
            if (root->data == target)
            {
                cout << "FOUND" << endl;
                return true; 
            }
            else if (target < root->data) 
            {
                root = root->left_child; 
            }
            else 
            {
                root = root->right_child;
            }
        }
        cout << "NOT FOUND " << endl;
        return false;
    }
};

int main()
{
    Tree t1;

    int data;
   

    int choice = 3456; 

    while (choice != 0)
    {
        cout << "1. Enter Data" << endl;
        cout << "2. IsEmpty" << endl;
        cout << "3. InOrder" << endl;
        cout << "4. Minimum" << endl;
        cout << "5. Search" << endl;
        cout << "0. Exit" << endl;
        cin >> choice; 

        if (choice == 1)
        {
            cout << "enter data = ";
            cin >> data;
            t1.insert(data);
            cout << "----------------------data entered------------------------" << endl;
        }
        else if (choice == 2)
        {
            cout << "tree is " << (t1.isEmpty() ? "empty" : "not empty") << endl;
        }
        else if (choice == 3)
        {
            cout << "***************************************************" << endl;
            t1.inorder(t1.getroot());
            cout << endl;
            cout << "***************************************************" << endl;
        }
        else if (choice == 4)
        {
            cout << "The minimum value is " << t1.Minimum(t1.getroot()) << endl;
        }
        else if (choice == 5)
        {
            cout << "Enter number u wish to search = ";
            int number;
            cin >> number;
            t1.search(t1.getroot(), number);
            cout << endl;
        }
       
    }
    

    return 0;
}

