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
    int kindness;
    int creativity;
    int ambition;
    string house;

    Student()
    {

    }

    Student(string n, int m_a, int b, int c, int i, int l,int k ,int cr,int am,string h)
    {
        name = n;
        magical_abilities = m_a;
        bravery = b;
        cunning = c;
        intelligence = i;
        loyalty = l;
        kindness = k;
        creativity = cr;
        ambition = am;
        house = h;
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
            cout << temp->student.name << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

   /* void display_new()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->student.name << " -- " << temp->student.house;
            temp = temp->next;
        }
        cout << endl;
    }*/

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

    void insertEdge(string src, string dest)
    {
        Student obj;
        Student obj2;

        obj.name = src;
        obj2.name = dest;
        //int count = vertex;
        for (int i = 0; i < count; i++)
        {
            if (arr[i].head->student.name == obj.name)
            {
                arr[i].insert(obj2);
            }
        }

        for (int i = 0; i < count; i++)
        {
            if (arr[i].head->student.name == obj2.name)
            {
                arr[i].insert(obj);
            }
        }
    }

    void insertvertex(Student obj)
    {
        arr[count].insert(obj);
        //arr[count].insert(obj2);
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

    void assign_house(Student& obj)
    {
        // high above 7
        // low is any number below 7
        //cout << "addhvashd" << endl;
        if (obj.bravery > 7 && obj.loyalty > 7)
        {
            obj.house = "Gryffindor";
            //cout << obj.house << " hehe" << endl;
        }
        else if (obj.loyalty > 7 && obj.kindness>7)
        {
            obj.house = "Hufflepuff";
        }
        else if (obj.intelligence > 7 && obj.creativity > 7)
        {
            obj.house = "Ravenclaw";
        }
        else if (obj.cunning > 7 && obj.ambition > 7)
        {
            obj.house = "Slytherin";
        }

        cout << obj.name << " is in " << obj.house << endl;
    }

    /*void display_houses()
    {
        for (int i = 0; i < vertex; i++)
        {
            arr[i].display_new();
        }
    }*/
};

int main()
{
    Graph g(5);
    /*magical_abilities = m_a;
        bravery = b;
        cunning = c;
        intelligence = i;
        loyalty = l;
        kindness = k;
        creativity = cr;
        ambition = am;
        house = h;
    }*/

    // i ddint pass correct valkues below so only one condition is satisfied for obj s1 
    // need to change the numbers passed below 

    Student s1("Azan", 1, 10, 1, 1, 8, 1, 1,1, "House not assigned");
    Student s2("Muhammad", 9, 7, 5, 10, 8,  8, 8,9, "House not assigned");
    Student s3("Moosa", 6, 7, 6, 6, 10, 8, 8,8, "House not assigned");
    Student s4("Taha", 7, 5, 8, 7, 5, 1, 1,7, "House not assigned");
    Student s5("Arham", 8, 8, 6, 9, 9, 1, 1,7, "House not assigned");

    int choice = 999999;

    while (choice != 0)
    {
        cout << "1. INSERT" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "0. END" << endl;
        cin >> choice;

        if (choice == 1)
        {

            g.insertvertex(s1);
            g.insertvertex(s2);
            g.insertvertex(s3);
            g.insertvertex(s4);
            g.insertvertex(s5);
            

            g.insertEdge("Azan", "Arham");
           // g.insertEdge("Arham", "Azan");
            g.insertEdge("Muhammad", "Azan");
            //g.insertEdge("Azan", "Muhammad");
            g.insertEdge("Taha", "Arham");
            g.insertEdge("Moosa", "Arham");
            // calll all 
            g.assign_house(s1);
            g.assign_house(s2);
            g.assign_house(s3);
            g.assign_house(s4);
            g.assign_house(s5);
            
        }
        else if (choice == 2)
        {
            g.showGraphStructure();
            //g.display_houses();
        }
        else if (choice == 0)
        {
            cout << "GOOD BYE............." << endl;
        }
    }
    return 0;
}
