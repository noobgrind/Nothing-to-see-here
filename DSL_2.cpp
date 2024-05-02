/*
	Name - Atharv R Sonawane
	Roll no - 25
	Problem Statement -
		Consider telephone book of N clients. Make use of a Hash table implementation to quickly look up
		clients phone telephone number. Make use of two collision handling techniques and compare them 
		using number of comparisons required to find a set of telephone numbers.

*/

#include<iostream>
using namespace std;

class HashTable
{
	int key;
	long tel_no;
	friend class Hashing;
};
int num_of_digits(long num)
{
	long copy = num;
	int order = 0;
	while(copy)
	{
		order++;
		copy/=10;
	}
	return order;
}
class Hashing
{
		HashTable h[10];
	public:
		Hashing()
		{
			for(int i = 0 ; i < 10 ; i++)
			{
				h[i].key = i;
				h[i].tel_no = -1;
			}
		}

		void LinearProbe(long ,int);
		void QuadraticProbe(long,int);

		void display()
		{
			cout<<"Key\t"<<"Mobile Number"<<endl;
			for(int i = 0 ; i < 10 ; i++)
			{
				cout<<" "<<h[i].key<<"\t "<<h[i].tel_no<<endl;
			}
		}
		void insert(int probe_choice)
		{
			long num;
			cout<<"Enter Mobile No. : ";
			cin>>num;
			// if(num_of_digits(num) != 10)
			// {
			// 	cout<<"\nInvalid Number"<<endl;
			// 	return;
			// }
			if(probe_choice == 1)
			{
				int key = num%10;
				if(h[key].tel_no == -1)
					h[key].tel_no = num;
				else
				{
					LinearProbe(num,key);					
				}
			}
			else
			{
				int key = num%10;
				if(h[key].tel_no == -1)
					h[key].tel_no = num;
				else
				{	
					QuadraticProbe(num,key);
				}
			}
		}
		void search(long num)
		{
			for(int i = 0; i < 10 ; i++)
			{
				if(h[i].tel_no == num)
				{
					cout<<"\nKey\t"<<"Mobile Number"<<endl;
					cout<<h[i].key<<"\t"<<h[i].tel_no<<endl;
					return;
				}
				
			}

			cout<<"\nNumber Not Found\n";
		}
};

void Hashing::LinearProbe(long num,int coll_pos)
{
			
	if(coll_pos >= 9)
	{
		coll_pos = 0;
		while(h[coll_pos].tel_no != -1)
			coll_pos++;
	}
	else
	{
		while(h[coll_pos].tel_no != -1)
			coll_pos++;
	}
	h[coll_pos].tel_no = num;
		
}
void Hashing::QuadraticProbe(long num,int key)
{
	int j = 1;
	while(j < 10)
	{
		key = (h[key].tel_no + j*j)%10;
		if(key > 10)
		{
			cout<<"Hash Table Overflow\n"<<endl;
			break;
		}
		if(h[key].tel_no == -1)
		{
			h[key].tel_no = num;
			break;
		}
		j++;
	}

}
int main()
{
	Hashing h1;
	int key,ch,probe_choice;
	do
	{
		cout<<"\n-----MENU-----"<<endl;
		cout<<"1.Insert an element in the Hashtable"<<endl;
		cout<<"2.Display the Hashtable"<<endl; 
		cout<<"3.Search a Number"<<endl; 
		cout<<"4.Exit"<<endl;
		cout<<"Enter Your Choice : "; 
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n1.Linear Probing"<<endl;
				cout<<"2.Quadratic Probing"<<endl;
				cout<<"Enter Your Choice : ";
				cin>>probe_choice;
				h1.insert(probe_choice);
				break;
			case 2:
				h1.display();
				break;
			case 3:
				cout<<"Enter the Number to be searched : ";
				cin>>key;
				h1.search(key);
				break;
		}

	}while(ch != 4);

	return 0;
}
/* OUTPUT:
-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 1

1.Linear Probing
2.Quadratic Probing
Enter Your Choice : 1
Enter Mobile No. : 1234567892

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 2
Key	Mobile Number
 0	 -1
 1	 -1
 2	 1234567892
 3	 -1
 4	 -1
 5	 -1
 6	 -1
 7	 -1
 8	 -1
 9	 -1

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 1

1.Linear Probing
2.Quadratic Probing
Enter Your Choice : 1
Enter Mobile No. : 9730002762

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 2
Key	Mobile Number
 0	 -1
 1	 -1
 2	 1234567892
 3	 9730002762
 4	 -1
 5	 -1
 6	 -1
 7	 -1
 8	 -1
 9	 -1

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 1

1.Linear Probing
2.Quadratic Probing
Enter Your Choice : 1
Enter Mobile No. : 8379992762

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 2
Key	Mobile Number
 0	 -1
 1	 -1
 2	 1234567892
 3	 9730002762
 4	 8379992762
 5	 -1
 6	 -1
 7	 -1
 8	 -1
 9	 -1

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 1

1.Linear Probing
2.Quadratic Probing
Enter Your Choice : 2
Enter Mobile No. : 9503155452

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 2
Key	Mobile Number
 0	 -1
 1	 -1
 2	 1234567892
 3	 9730002762
 4	 8379992762
 5	 -1
 6	 9503155452
 7	 -1
 8	 -1
 9	 -1

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 3
Enter the Number to be searched : 1234567892

Key	Mobile Number
2	1234567892

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 2
Key	Mobile Number
 0	 -1
 1	 -1
 2	 1234567892
 3	 9730002762
 4	 8379992762
 5	 -1
 6	 9503155452
 7	 -1
 8	 -1
 9	 -1

-----MENU-----
1.Insert an element in the Hashtable
2.Display the Hashtable
3.Search a Number
4.Exit
Enter Your Choice : 4


*/
