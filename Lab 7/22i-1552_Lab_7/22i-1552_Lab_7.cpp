//// 22i-1552_Lab7_Task1 & Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//-----------------------------------STACK-----------------------------------
#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node* next;

    Node(char d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
private:
    Node* top;
    int numItems;
    int max;

public:
    Stack()
    {
        top = NULL;
        numItems = 0;
        max = 5;
    }

    void push(char d)
    {
        if (isFull())
        {
            cout << "Stack is full, cannot add the element anymore" << endl;
            return;
        }
        else if (!isFull())
        {
            Node* newNode = new Node(d);

            if (top == NULL)
            {
                top = newNode;
            }
            else
            {
                newNode->next = top;
                top = newNode;
            }
            numItems++;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        else
        {
            Node* temp = top;
            top = top->next;
            delete temp;
            numItems--;
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;
        cout << "Stack elements = ";
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isFull()
    {
        return numItems > max;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
        cout << "Stack cleared." << endl;
    }

    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return 0;
        }
        else
        {
            //cout << "Data on top is = " << top->data << endl;
        }
        
        return top->data;
    }

    bool areBracketsBalanced(string e) // TASK#2
    {
        Stack sb1;

        for (int i = 0; i < e.length(); i++) 
        {
            char ch = e[i];

            if (ch == '(' || ch == '[' || ch == '{') 
            {
                sb1.push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') 
            {
                if (sb1.isEmpty()) 
                {
                    return false; 
                }

                char top = sb1.peek();
                sb1.pop();

                if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) 
                {
                    return false; 
                }
            }
        }

        return sb1.isEmpty(); 
    }
};

int main()
{
    Stack s1;


    char data;
    int c;

    int choice = -1;

    while (choice != 0)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Expression" << endl;// TASK#2
        cout << "0. Exit" << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Press 1 to Enter data into the stack" << endl;
            cout << "Press 0 to stop pushing" << endl;
            cin >> c;
            while (c != 0)
            {
                cout << "Enter data = ";
                cin >> data;
                s1.push(data);
                cout << "Do you want to add more?" << endl;
                cout << "Press 1 to continue" << endl;
                cout << "Press 0 to stop" << endl;

                cin >> c;
            }
        }
        else if (choice == 2)
        {
            s1.pop();
        }
        else if (choice == 3)
        {
            s1.display();
        }
        else if (choice == 4)
        {
            s1.clear();
        }
        else if (choice == 5)
        {
            cout<<"Data on top is "<<s1.peek()<<endl;
        }
        else if (choice == 6)// TASK#2
        {
            string e1 = "1 + 2 * (3 / 4)";
            string e2 = "1 + 2 * [3 * 3 + {4 � 5 (6 (7/8/9) + 10) � 11 + (12*8)] + 14";
            string e3 = "1 + 2 * [3 * 3 + {4 � 5 (6 (7 / 8 / 9) + 10)} � 11 + (12 * 8) / {13 + 13}] + 14";
            

            if (s1.areBracketsBalanced(e1))
            {
                cout << "Expression 1 is correct" << endl;
            }
            else
            {
                cout << "Expression 1 is NOT correct" << endl;
            }
            if (s1.areBracketsBalanced(e2))
            {
                cout << "Expression 2 is correct" << endl;
            }
            else
            {
                cout << "Expression 2 is NOT correct" << endl;
            }
            if (s1.areBracketsBalanced(e3))
            {
                cout << "Expression 3 is correct" << endl;
            }
            else
            {
                cout << "Expression 3 is NOT correct" << endl;
            }

        }
        else if (choice == 0)
        {
            cout << "Exiting the program.............................." << endl;
        }
        else
        {
            cout << "Invalid choice, Please try again" << endl;
        }
    }
    return 0;
}
