// 22i-1552_Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
///////////////////////////Queue-----------------------------
#include <iostream>
#include<string>

using namespace std;

class Student
{
public:
    int student_id;
    string student_name;
    double gpa;
    double age;

    Student()
    {
        //cout << "Employee default called " << endl;
    }

    Student(int id, string name, double sal, double bo)
    {
        student_id = id;
        student_name = name;
        
        gpa = sal;
        age = bo;
    }

    void display()
    {
        cout << "Student id     = " << student_id << endl;
        cout << "Student name   = " << student_name << endl;
        //cout << "Employee NIC    = " << nic << endl;
        cout << "Student gpa = " << gpa << endl;
        cout << "Student age  = " << age << endl;
        cout << endl;
    }
};

class Node
{
public:
    Student data;
    Node* next; 
    int priority;

    Node()
    {
        //cout << "Default of node" << endl;
        next = NULL;
        //~Node() { };
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;
    int numitems;

public:
    Queue(/**/)
    {
        front = NULL;
        rear = NULL;
        numitems = 0;
    }

    void Enqueue(Student& std, int priority)
    {
        Node* newnode = new Node();
        newnode->data = std;
        newnode->priority = priority;

        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        numitems++;
    }


    void Dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void PriorityBasedDequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            Node* temp = front;
            Node* prev = NULL;
            Node* maxNode = front;
            Node* maxPrev = NULL;
            
            while (temp != NULL)
            {
                if (temp->priority < maxNode->priority)
                {
                    maxNode = temp;
                    maxPrev = prev;
                }
                prev = temp;
                temp = temp->next;
            }

            if (maxNode == front)
            {
                front = front->next;
                if (maxNode == rear) 
                {
                    rear = maxPrev; 
                }
                delete maxNode;
            }
            else
            {
                maxPrev->next = maxNode->next;
                if (maxNode == rear) 
                {
                    rear = maxPrev; 
                }
                delete maxNode;
            }
        }
    }


    void FRONT()
    {
        Node* temp = front;

        if (temp != NULL)
        {
            temp->data.display();
            //temp = temp->next;
        }
        //temp->data.display();
    }

    void REAR()
    {
        Node* temp = rear;

        if (temp != NULL)
        {
            temp->data.display();
            //temp = temp->next;
        }
        //temp->data.display();
    }

    void clear()
    {
        while (front != NULL)
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        cout << "CLEARED QUEUE" << endl;
    }

    void display()
    {
        Node* temp = front;
        if (temp == NULL)
        {
            cout << "QUEUE is empty" << endl;
        }
        while (temp->next != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
        temp->data.display();
    }

    bool isEmpty()
    {
        Node* temp = front;

        if (temp == NULL)
        {
            cout << "QUEUE is empty" << endl;
            return true;
        }
        else
        {
            cout << "QUEUE is not empty" << endl;
            return false;
        }
    }
};


int main()
{
    Student e1(1552, "ARHAM", 4.0, 18);
    Student e2(1668, "AZAN", 3.0, 19);
    Student e3(1612, "MK", 2.0, 20);
    Student e4(1575, "Umar Zeb", 2.8, 15);
    Queue l1;

    int choice;
    cout << "Press 1 to add elements to the queue" << endl;
    cout << "Press 2 to display" << endl;
    cout << "Press 3 to remove from queue based on priority" << endl;
    cout << "Press 4 to remove from front " << endl;
    cout << "Press 5 to return rear " << endl;
    cout << "Press 6 to return front" << endl;
    cout << "Press 7 to check if queue is empty ot not " << endl;
    cout << "Press 8 to clear queue" << endl;
    cout << "Press 0 to exit" << endl;
    cin >> choice;

    while (choice != 0)
    {
        if (choice == 1)
        {
            l1.Enqueue(e1, 2);
            l1.Enqueue(e2, 4);
            l1.Enqueue(e3, 3);
            l1.Enqueue(e4, 1);
        }
        else if (choice == 2)
        {
            l1.display();
        }
        else if (choice == 3)
        {
            l1.PriorityBasedDequeue();
        }
        else if (choice == 4)
        {
            l1.Dequeue();
        }
        else if (choice == 5)
        {
            l1.FRONT();
        }
        else if (choice == 6)
        {
            l1.REAR();
        }
        else if (choice == 7)
        {
            l1.isEmpty();
        }
        else if (choice == 8)
        {
            l1.clear();
        }
        cin >> choice;
    }

    
    

    return 0;
}

