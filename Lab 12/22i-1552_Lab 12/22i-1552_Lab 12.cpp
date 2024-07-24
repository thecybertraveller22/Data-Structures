#include <iostream>
#include<string>

using namespace std;


class Node
{
public:
    
    int data;
    Node* next; // points to the next vakue 

    Node()
    {
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

    void insertEdge(int num)
    {
        Node* newnode = new Node();

        newnode->data = num;
        
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

        while (temp->next != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
        cout << endl;
    }

    
};


class Graph
{
public:
    AdjList* arr;
    int vertex;
    int size;
    
    Graph(int size)
    {
        vertex = size;
        arr = new AdjList[vertex];
        for (int i = 0; i < size; i++)
        {
            arr[i].insertEdge(i + 1);
        }
    }

    void insertEdge(int src, int dest)
    {
        if (src > vertex || dest > vertex)
        {
            cout << "Error!" << endl;
        }
        else
        {
            arr[src - 1].insertEdge(dest);
            arr[dest - 1].insertEdge(src); // comment this to cehk for loop
        }
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
        for (int i = 0; i < vertex; i++)
        {
            Node* current = arr[i].head;
            Node* next;
            while (current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] arr;
        arr = NULL;
    }
    /*-------------------------------------------------------------------------*/
    bool isCyclicUtil(int v, bool visited[], int parent)
    {
        visited[v - 1] = true;  // subtract 1 here
        Node* node = arr[v - 1].head;  // subtract 1 here

        while (node != NULL)
        {
            int u = node->data;

            if (!visited[u - 1])  // subtract 1 here
            {
                if (isCyclicUtil(u, visited, v))
                    return true;
            }
            else if (u != parent)
                return true;

            node = node->next;
        }
        return false;
    }

    bool isCyclic()
    {
        bool* visited = new bool[vertex];
        for (int i = 0; i < vertex; i++)
            visited[i] = false;

        for (int u = 1; u <= vertex; u++)  // change 0 to 1 here
        {
            if (!visited[u - 1])  // subtract 1 here
                if (isCyclicUtil(u, visited, -1))
                    return true;
        }
        return false;
    }

};
int main()
{
    AdjList l1;
    Graph g(3);
    int choice = 999999;
    while (choice!=0)
    {
        cout << "1. INSERT" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. Cyclic" << endl;
        cout << "0. END" << endl;
        if (choice == 1)
        {
            g.insertEdge(1, 2);
            g.insertEdge(2, 3);
            //g.insertEdge(1, 3);
          /*  g.insertEdge(5, 4);
            g.insertEdge(1, 2);
            g.insertEdge(2, 3);
            g.insertEdge(5, 2);
            g.insertEdge(3, 4);
            g.insertEdge(2, 1);*/
        }
        else if (choice == 2)
        {
            g.showGraphStructure();
        }
        else if (choice == 3)
        {
            if (g.isCyclic())
                cout << "Graph contains cycle";
            else
                cout << "Graph doesn't contain cycle";
        }
        else if (choice == 0)
        {
            cout << "GOOD BYE............." << endl;
        }
        cin >> choice;
    }
    return 0;
}