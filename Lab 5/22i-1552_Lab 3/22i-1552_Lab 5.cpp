#include <iostream>
#include<string>

using namespace std;

class Student
{
public:
    string student_id;
    string student_name;
    //string nic;
    double gpa;
    int age;

    Student()
    {
        //cout << "Employee default called " << endl;
    }

    Student(string id, string name /*string n*/, double sal, double bo)
    {
        student_id = id;
        student_name = name;
        //nic = n;
        gpa = sal;
        age = bo;
    }

    void display()
    {
        
        
        cout << "Student id     = " << student_id << endl;
        cout << "Student name = " << student_name << endl;
        //cout << "Student NIC    = " << nic << endl;
        cout << "Student GPA = " << gpa << endl;
        cout << "Student Age  = " << age << endl;
        cout << endl;
        
        
    }
};

class Node
{
public:
    Student s;
    Node* next; // points to the next vakue 
    Node* prev;

    Node()
    {
        //cout << "Default of node" << endl;
        next = NULL;
        prev = NULL;
        //~Node() { };
    }
};

class LinkedList
{
private:
    Node* head;
    Node* last;

public:
    LinkedList(/**/)
    {
        head = NULL;
        last = NULL;
    }

    void insert(const Student& data)
    {
        Node* newnode = new Node();

        newnode->s.student_id = data.student_id;
        newnode->s.age = data.age;
        newnode->s.student_name = data.student_name;
        //newnode->s.nic = data.nic;
        newnode->s.gpa = data.gpa;

        if (head == NULL)
        {
            head = newnode;
            last = newnode;
        }
        else
        {
            /*Node* temp = head;
            Node* prev = new Node();
            last->next = newnode;
            newnode->prev = last;
            last = newnode;*/
         
            last->next = newnode;
            newnode->prev = last;
            last = newnode;
        
            /*****************************************************************************************/
        }
    }

    void display()
    {
        Node* temp = head;
        if (temp != NULL)
        {
            while (temp->next != NULL)
            {
                temp->s.display();
                temp = temp->next;
            }
            temp->s.display();
        }
        else
        {
            cout << "List is empty" << endl;
        }
        
    }

    void remove(string id)
    {
        Node* temp = head;

        if (temp->s.student_id == id)
        {
            /*temp = head->next;
            head = temp;*/
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            return;
        }
        while ( temp->s.student_id != id)
        {
            temp = temp->next;
        }
        if (temp->next != NULL)
        {
           
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
        }
        else 
        {
            temp->prev->next = NULL;
            delete temp;
        }
            
        
    }

    void updateGPA(double g,string id)
    {
        Node* temp = head;

        if (temp->s.student_id == id)
        {
            /*temp = head->next;
            head = temp;*/
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            return;
        }
        while (temp != NULL && temp->s.student_id != id)
        {
            temp = temp->next;
        }

        temp->s.gpa = g;
    }

    void clear()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        head = NULL;
    }

    bool is_empty()
    {
        return head == NULL;
    }
    
    /*void sort()
    {
        if (head == NULL || head->next == NULL)
        {
            return; 
        }

        Node* i;
        Node* j;
        for (i = head; i->next != NULL; i = i->next)
        {
            for (j = head; j->next != NULL; j = j->next)
            {
                if (j->s.gpa < j->next->s.gpa)
                {
                    Student temp = j->s;
                    j->s = j->next->s;
                    j->next->s = temp;
                }
            }
        }
    }*/

};


int main()
{
    //cout << "Hello World!\n";

    Student e1("1552","Arham",4.0,18);
    Student e2("1668", "Azan ", 3.19, 19);
    Student e3("1345", "MK ", 2.19, 20);
    Student e4("1456", "Hussain", 1.19, 19);
    Student e5("1674", "Ali", 0.19, 19);
    Student e6("1999", "James Bond", 4.0, 19);

    LinkedList l1;
    //cout << "Before removing " << endl;
    cout << endl;
    
    //l1.insert(e3);
   
    
    
    
    cout << "Press 1 to insert values" << endl;
    cout << "Press 2 to display list" << endl;
    cout << "Press 3 to check if list is empty" << endl;
    cout << "Press 4 to empty the list" << endl;
    cout << "Press 5 to update gpa " << endl;
    cout << "Press 6 to remove node " << endl;
    //cout << "Press 7 to sort list " << endl;
    cout << "Press 0 to end the program" << endl;
    int choice;
    cin >> choice;
    while (choice != 0)
    {
        if (choice == 1)
        {
            l1.insert(e1);
            l1.insert(e2);
            l1.insert(e3);
            l1.insert(e4);
            l1.insert(e5);
            l1.insert(e6);
        }
        else if (choice == 2)
        {
            l1.display();
        }
        else if (choice == 3)
        {
            if (l1.is_empty())
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << "List is not empty" << endl;
            }
        }
        else if (choice == 4)
        {
            l1.clear();
            cout << "CLEARED" << endl;
        }
        else if (choice == 5)
        {
            l1.updateGPA(2.0, "1345");
            cout << "GPA Updated" << endl;
        }
        else if (choice == 6)
        {
            l1.remove("1999");
            cout << "Removed Node" << endl;
        }
        /*else if (choice == 7)
        {
            l1.sort();
        }*/
        cin >> choice;
    }
    

    /*cout << "cleared" << endl;
    cout << "CLESS" << endl;*/
    /*l1.display();
    
    l1.display();*/
    /*cout << "After removing " << endl;
    cout << endl;
    l1.remove(1668);
    l1.display();*/


    return 0;
}