// 22i-1552_Lab13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<string>

using namespace std;

class Student
{
public:
    string name;
    int magical_abilities;
    int bravery;
    int cunning;
    int intelligence;
    int loyalty;

    Student()
    {

    }

    Student(string n, int m_a, int b, int c, int i, int l)
    {
        name = n;
        magical_abilities = m_a;
        bravery = b;
        cunning = c;
        intelligence = i;
        loyalty = l;
    }
};


class Node
{
public:
    Student student;
    //int data;
    Node* next; // points to the next vakue 

    Node(Student s)
    {
        student = s;
        //cout << "Default of node" << endl;
        next = NULL;
        //~Node() { };
    }
};

class AdjList
{
public:
    Node* head;
    Node* last;
    AdjList(/**/)
    {
        head = NULL;
        last = NULL;
    }

    void insert(Student student)
    {
        Node* newnode = new Node(student);

       

        if (head == NULL)
        {
            head = newnode;
            last = newnode;
        }
        else
        {
            Node* temp = head;
           

            last->next = newnode;
            last = newnode;
            
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->student.name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};


class Graph
{
public:
    AdjList* arr;
    Student* students;
    int vertex;
    int count;

    Graph(int size)
    {
        vertex = size;
        arr = new AdjList[vertex];
        students = new Student[vertex];
        count = 0;
        /*for (int i = 0; i < size; i++)
        {
            arr[i].insertEdge(i + 1);
        }*/
    }

    
    void insertEdge(Student obj)
    {
        arr[count].insert(obj);
        arr[count].insert(obj);
        count++;
    }

    void showGraphStructure()
    {
        for (int i = 0; i < vertex; i++)
        {
            arr[i].display();
        }
    }

    ~Graph()
    {
        delete[] arr;
        arr = NULL;
    }
};

int main()
{
    Graph g(5);

    Student s1("Azan", 7, 8, 5, 8, 9);
    Student s2("Muhammad", 9, 7, 5, 10, 8);
    Student s3("Moosa", 6, 7, 6, 6, 10);
    Student s4("Taha", 7, 5, 8, 7, 5);
    Student s5("Arham", 8, 8, 6, 9, 9);
    

  

    int choice = 999999;

    while (choice != 0)
    {
        cout << "1. INSERT" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "0. END" << endl;
        cin >> choice;

        if (choice == 1)
        {
           
           
        }
        else if (choice == 2)
        {
            g.showGraphStructure();
        }
        else if (choice == 0)
        {
            cout << "GOOD BYE............." << endl;
        }
    }
    return 0;
}
