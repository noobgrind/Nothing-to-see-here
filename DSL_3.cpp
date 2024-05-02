/*
	Name - Atharv R Sonawane
	Roll no - 25
	Problem Statement -
		Beginning with an empty binary search tree, Construct binary search tree by inserting the
		values in the order given. After constructing a binary tree - 
		a) Insert new Node.
		b) Find number of Nodes in longest path from root,
		c) Minimum data value found in the tree.
		d) Change a tree so that the roles of the left and right pointers are swapped at every node,
		e) Serach a value.

*/
#include<iostream>
using namespace std;

class Tnode
{
	Tnode* left;
	Tnode* right;
	int data;

	Tnode(int d)
	{
		left = right = NULL;
		data = d;
	}
	friend class BST;
};

class BST
{
		Tnode* root;
	public:
		BST()
		{
			root = NULL;
		}
		void insert(Tnode* root , int e)
		{
			Tnode* p = new Tnode(e);
			if(this -> root == NULL)
			{
				this -> root = p;
				return;
			}	
			if(root -> data >= e)
			{
				if(root -> left == NULL)
					root -> left = p;
				else
				{
					insert(root -> left, e);
				}
			}
			else
			{
				if(root -> right == NULL)
					root -> right = p;
				else
				{
					insert(root -> right, e);
				}

			}

		}
		bool search(int e)
		{
			Tnode* temp = root;
			while(true)
			{
				if(temp -> data == e)
					return true;
				else if(temp -> data > e)
				{
					if(temp -> left)
					{
						temp = temp -> left;						
					}
					else
					{
						return 0;
					}
				}
				else if(temp -> data < e)
				{
					if(temp -> right)
					{
						temp = temp -> right;						
					}
					else
					{
						return 0;
					}
				}			
			}
		}

		void inorder(Tnode* root)
		{
			if(root)
			{
				inorder(root -> left);
				cout<<root -> data<<" ";
				inorder(root -> right);
			}
		}
		void preorder(Tnode* root)
		{
			if(root)
			{
				cout<<root -> data<<" ";
				preorder(root -> left);
				preorder(root -> right);
			}
		}
		void postorder(Tnode* root)
		{
			if(root)
			{
				postorder(root -> left);
				postorder(root -> right);
				cout<<root -> data<<" ";

			}
		}
		void mirror(Tnode* root)
		{
			if(root)
			{
				Tnode* temp = root -> left;
				root -> left = root -> right;
				root -> right = temp;
				mirror(root -> left);
				mirror(root -> right);
			}
		}
		int height(Tnode* root)
		{
			if(root == NULL)
				return 0;
			int ldepth = height(root -> left);
			int rdepth = height(root -> right);

			if(ldepth > rdepth)
				return ldepth + 1;
			return rdepth + 1;
		}
		Tnode* getRoot()
		{
			return root;
		}
		int min(Tnode* root)
		{
			
			if(root -> left == NULL)
				return root -> data;
			min(root -> left);
		}
		int max(Tnode* root)
		{
			
			if(root -> right == NULL)
				return root -> data;
			max(root -> right);
		}
};

int main()
{
	BST bt;

	
	int ch,flag,key;
	do
	{
		cout<<"\n------MENU-------"<<endl;
		cout<<"1.Insert an element"<<endl;
		cout<<"2.Search an element"<<endl;
		cout<<"3.Inorder Traversal"<<endl;
		cout<<"4.Pre-Order Traversal"<<endl;
		cout<<"5.Post-Order Traversal"<<endl;
		cout<<"6.Mirror Current Tree"<<endl;
		cout<<"7.Height of the Current Tree"<<endl;
		cout<<"8.Maximum of the Tree"<<endl;
		cout<<"9.Minimum of the Tree"<<endl;
		cout<<"10.Exit"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter The Element To be Inserted : ";
				cin>>key;
				bt.insert(bt.getRoot(),key);
				break;
			case 2:
				cout<<"Enter The Element To be Searched : ";
				cin>>key;
				flag = bt.search(key);
				if(flag)
				{
					cout<<"\nElement Found\n"<<endl;
				}
				else
				{
					cout<<"\nElement Not Found\n"<<endl;
				}
				break;
			case 3:
				cout<<endl;
				cout<<"In-Order : ";
				bt.inorder(bt.getRoot());
				cout<<endl;
				break;
			case 4:
				cout<<"Pre-Order : ";
				cout<<endl;
				bt.preorder(bt.getRoot());
				cout<<endl;
				break;
			case 5:
				cout<<"Post-Order : ";
				cout<<endl;
				bt.postorder(bt.getRoot());
				cout<<endl;
				break;
			case 6:
				cout<<endl;
				cout<<"In-Order Before Mirroring : ";
				bt.inorder(bt.getRoot());
				cout<<endl;
				cout<<"In-Order After Mirroring : ";
				bt.mirror(bt.getRoot());
				bt.inorder(bt.getRoot());
				cout<<endl;
				break;
			case 7:
				cout<<"Height : "<<bt.height(bt.getRoot());;
				cout<<endl;
				break;
			case 8:
				cout<<"Maximum : "<<bt.max(bt.getRoot());;
				cout<<endl;
				break;
			case 9:
				cout<<"Minimum : "<<bt.min(bt.getRoot());;
				cout<<endl;
				break;
		}


	}while(ch != 10);
	
	return 0;
}
/* 
------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 10

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 5

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 15

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 3

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 6

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 12

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 1
Enter The Element To be Inserted : 18

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 2
Enter The Element To be Searched : 15

Element Found


------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 3 

In-Order : 3 5 6 10 12 15 18 

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 4
Pre-Order : 
10 5 3 6 15 12 18 

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 5
Post-Order : 
3 6 5 12 18 15 10 

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 6

In-Order Before Mirroring : 3 5 6 10 12 15 18 
In-Order After Mirroring : 18 15 12 10 6 5 3 

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 7
Height : 3

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 6

In-Order Before Mirroring : 18 15 12 10 6 5 3 
In-Order After Mirroring : 3 5 6 10 12 15 18 

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 8
Maximum : 18

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 9
Minimum : 3

------MENU-------
1.Insert an element
2.Search an element
3.Inorder Traversal
4.Pre-Order Traversal
5.Post-Order Traversal
6.Mirror Current Tree
7.Height of the Current Tree
8.Maximum of the Tree
9.Minimum of the Tree
10.Exit
Enter Your Choice : 10


	
*/