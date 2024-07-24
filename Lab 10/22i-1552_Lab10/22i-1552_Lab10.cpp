#include<iostream> 

using namespace std;

class Node
{
public:
	int data;
	Node* left_child;
	Node* right_child;
	int height;

	Node(int d)
	{
		data = d;
		left_child = right_child = NULL;
		height = 1;
	}
};

class AVLTree
{
public:
	Node* root;

	AVLTree()
	{
		root = NULL;
	}

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

	int height(Node* root)
	{
		Node* newnode = root;

		if (newnode == NULL)
		{
			return 0;
		}
		else
		{
			int leftheight = height(newnode->left_child);
			int rightheight = height(newnode->right_child);

			if (rightheight > leftheight)
			{
				return (rightheight + 1);
			}
			else
			{
				return (leftheight + 1);
			}
		}
	}

	void printtheLevel(Node* root, int level)
	{
		if (root == NULL)
		{
			return;
		}

		if (level == 1)
		{
			cout << root->data << " ";
		}

		else if (level > 1)
		{
			printtheLevel(root->left_child, level - 1);
			printtheLevel(root->right_child, level - 1);
		}
	}

	void breadthFirstTraversal(Node* root)
	{
		int h = height(root);
		for (int i = 1; i <= h; i++)
		{
			printtheLevel(root, i);
			cout << endl;
		}

	}

	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	Node* rightRotate(Node* y)
	{
		Node* x = y->left_child;
		Node* T2 = x->right_child;

		x->right_child = y;
		y->left_child = T2;

		y->height = max(height(y->left_child), height(y->right_child)) + 1;
		x->height = max(height(x->left_child), height(x->right_child)) + 1;

		return x;
	}

	Node* leftRotate(Node* x)
	{
		Node* y = x->right_child;
		Node* T2 = y->left_child;

		y->left_child = x;
		x->right_child = T2;

		x->height = max(height(x->left_child), height(y->right_child)) + 1;
		y->height = max(height(y->left_child), height(y->right_child)) + 1;

		return y;
	}

	int getBalance(Node* N)
	{
		if (N == NULL)
		{
			return 0;
		}
		return height(N->left_child) - height(N->right_child);
	}

	Node* insert(Node* node, int number)
	{
		if (node == NULL)
		{
			return(new Node(number));
		}

		if (number < node->data)
		{
			node->left_child = insert(node->left_child, number);
		}
		else if (number > node->data)
		{
			node->right_child = insert(node->right_child, number);
		}
		else
		{
			return node;
		}

		node->height = 1 + max(height(node->left_child), height(node->right_child));

		int balance = getBalance(node);

		if (balance > 1 && number < node->left_child->data)
		{
			return rightRotate(node);
		}

		if (balance < -1 && number > node->right_child->data)
		{
			return leftRotate(node);
		}

		if (balance > 1 && number > node->left_child->data)
		{
			node->left_child = leftRotate(node->left_child);
			return rightRotate(node);
		}

		if (balance < -1 && number < node->right_child->data)
		{
			node->right_child = rightRotate(node->right_child);
			return leftRotate(node);
		}

		return node;
	}

	/*void preOrder(Node* root)
	{
		if (root != NULL)
		{
			cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}*/

	void inorder(Node* root)
	{
		//int counter = 0;

		if (root == nullptr)
		{
			//cout << "Tree is empty" << endl;
			return;
		}
		//counter++;
		inorder(root->left_child);
		cout << root->data << " ";
		inorder(root->right_child);
		//cout << endl;
		//return counter;
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

	void delete_node(int num)
	{
		if (root == nullptr)
		{
			cout << "Tree is empty. Cannot delete." << endl;
			return;
		}

		Node* parent = nullptr;
		Node* current = root;

		while (current != nullptr && current->data != num)
		{
			parent = current;
			if (num < current->data)
			{
				current = current->left_child;
			}
			else
			{
				current = current->right_child;
			}
		}

		if (current == nullptr)
		{
			cout << "Node not found. Cannot delete." << endl;
			return;
		}

		// Node with only one child or no child
		if (current->left_child == nullptr || current->right_child == nullptr)
		{
			Node* temp = nullptr;
			if (current != root)
			{
				if (current->left_child)
				{
					temp = current->left_child;
				}
				else
				{
					temp = current->right_child;
				}

				if (current == parent->left_child)
				{
					parent->left_child = temp;
				}

				else
				{
					parent->right_child = temp;
				}

			}
			else
			{
				root = temp;
			}
			delete current;
		}
		else // Node with two children
		{
			Node* smallest_right = smallest_right_value(current);
			int value = smallest_right->data;
			delete_node(smallest_right->data);
			current->data = value;
		}
	}

	Node* smallest_right_value(Node* n)
	{
		Node* temp = n;

		temp = temp->right_child;

		while (temp->left_child != nullptr)
		{
			temp = temp->left_child;
		}

		return temp;
	}

	int node_count(Node* root)
	{
		Node* newnode = root;
		if (newnode == NULL)
		{
			//cout << "0 nodes as the tree is empty" << endl;
			return 0;
		}
		else
		{
			return 1 + node_count(newnode->left_child) + node_count(newnode->right_child);
		}
	}

	bool fullbinarytree(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}

		if (root->left_child == NULL && root->right_child == NULL)
		{
			return true;
		}

		if (root->right_child && root->left_child)
		{
			return (fullbinarytree(root->left_child) && fullbinarytree(root->right_child));
		}
		return false;
	}

	int calculateDepth(Node* node)
	{
		int depth = 0;
		while (node != NULL)
		{
			depth++;
			node = node->left_child;
		}
		return depth;
	}

	bool perfectbinarytree(Node* root, int depth = -1, int level = 0)
	{
		if (root == NULL)
		{
			return true;
		}

		if (depth == -1)
		{
			depth = calculateDepth(root);
		}

		if (root->left_child == NULL && root->right_child == NULL)
		{
			return (depth == level + 1);
		}

		if (root->left_child == NULL || root->right_child == NULL)
		{
			return false;
		}

		return perfectbinarytree(root->left_child, depth, level + 1) && perfectbinarytree(root->right_child, depth, level + 1);
	}

	bool balancedbinarytree(Node* root)
	{
		int leftheight, rightheight;

		if (root == NULL)
		{
			return true;
		}

		leftheight = height(root->left_child);
		rightheight = height(root->right_child);

		if ((leftheight - rightheight) >= -1 && (leftheight - rightheight <= 1) && (balancedbinarytree(root->left_child)) && (balancedbinarytree(root->right_child)))
		{
			return true;
		}


		return false;
	}

	bool degeneratebinarytree(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}
		if (root->left_child != NULL && root->right_child != NULL)
		{
			return false;
		}
		return degeneratebinarytree(root->left_child) && degeneratebinarytree(root->right_child);
	}


};

int main()
{
	AVLTree t1;


	int choice = 9999;

	while (choice != 0)
	{
		cout << "1. Insert numbers" << endl;
		cout << "2. Print In-Order traversal" << endl;
		cout << "3. Print Breadth-First traversal" << endl;
		cout << "4. Minimum" << endl;
		cout << "5. Search" << endl;
		cout << "6. Delete" << endl;
		cout << "7. Number of Nodes" << endl;
		cout << "8. Height" << endl;
		cout << "9. Check Type of Tree" << endl;
		cout << "10. IsEmpty" << endl;
		cout << "0. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "***************************************************" << endl;

			t1.root = t1.insert(t1.root, 1);
			t1.root = t1.insert(t1.root, 2);
			t1.root = t1.insert(t1.root, 3);
			t1.root = t1.insert(t1.root, 4);
			t1.root = t1.insert(t1.root, 5);
			t1.root = t1.insert(t1.root, 6);
			t1.root = t1.insert(t1.root, 7);
			t1.root = t1.insert(t1.root, 8);
			t1.root = t1.insert(t1.root, 9);
			cout << "***************************************************" << endl;
		}
		
		else if (choice == 2)
		{
			cout << "***************************************************" << endl;
			cout << "In-Order traversal of the constructed AVL tree is " << endl;
			t1.inorder(t1.root);
			cout << endl;
			cout << "***************************************************" << endl;
		}
		else if (choice == 3)
		{
			cout << "***************************************************" << endl;
			cout << "Breadth first traversal" << endl;
			t1.breadthFirstTraversal(t1.root);
			cout << "***************************************************" << endl;
		}
		else if (choice == 4)
		{
			cout << "The minimum value is " << t1.Minimum(t1.getroot()) << endl;
			cout << "***************************************************" << endl;
		}
		else if (choice == 5)
		{
			cout << "Enter number u wish to search = ";
			int number;
			cin >> number;
			t1.search(t1.getroot(), number);
			cout << endl;
			cout << "***************************************************" << endl;
		}
		else if (choice == 6)
		{
			cout << "Enter the number u wish to delete = ";
			int nim;
			cin >> nim;
			t1.delete_node(nim);
			cout << "***************************************************" << endl;
		}

		else if (choice == 7)
		{
			cout << "***************************************************" << endl;
			cout << "Nodes = " << t1.node_count(t1.getroot()) << endl;
			cout << "***************************************************" << endl;
		}
		else if (choice == 8)
		{
			cout << "***************************************************" << endl;
			cout << "Height = " << t1.height(t1.getroot()) << endl;
			cout << "***************************************************" << endl;
		}
		else if (choice == 9)
		{
			cout << "**************Checking what type of tree this is*************************" << endl;
			//cout << t1.fullbinarytree(t1.getroot()) << endl;
			bool type = 0, type1 = 0, type2 = 0, type3 = 0;
			type = t1.fullbinarytree(t1.getroot());
			type1 = t1.perfectbinarytree(t1.getroot());
			type2 = t1.balancedbinarytree(t1.getroot());
			type3 = t1.degeneratebinarytree(t1.getroot());

			if (type == 1)
			{
				cout << "***************************************************" << endl;
				cout << "Full Binary Tree" << endl;
				cout << "***************************************************" << endl;
			}
			if (type1 == 1)
			{
				cout << "***************************************************" << endl;
				cout << "Perfect Binary Tree" << endl;
				cout << "***************************************************" << endl;
			}
			if (type2 == 1)
			{
				cout << "***************************************************" << endl;
				cout << "Balanced Binary Tree" << endl;
				cout << "***************************************************" << endl;
			}
			if (type3 == 1)
			{
				cout << "***************************************************" << endl;
				cout << "Degenerate Binary Tree" << endl;
				cout << "***************************************************" << endl;
			}
			cout << endl;
		}
		else if (choice == 10)
		{
			cout << "***************************************************" << endl;
			cout << "tree is " << (t1.isEmpty() ? "empty" : "not empty") << endl;
			cout << "***************************************************" << endl;
		}
		else if (choice == 0)
		{
			cout << "Goodbye................................................" << endl;
		}
	}
	return 0;
}
