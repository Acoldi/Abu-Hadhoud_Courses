#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;
using namespace Project1;


void mySol()
{
#pragma region MySol

	MySol::clsDblLinkedList<int> myDoubleLinkedList;

	myDoubleLinkedList.InsertAtBeginning(5);
	myDoubleLinkedList.InsertAtBeginning(4);
	myDoubleLinkedList.InsertAtBeginning(3);
	myDoubleLinkedList.InsertAtBeginning(2);
	myDoubleLinkedList.InsertAtBeginning(1);

	cout << "Linked List content:\n";
	myDoubleLinkedList.PrintList();

	MySol::clsDblLinkedList<int>* n1 = myDoubleLinkedList.Find(2);
	if (n1 == NULL)
		cout << "Node with value 2 is not found\n";
	else
		cout << "Node with value 2 is found\n";

	myDoubleLinkedList.InsertAfter(n1, 500);
	myDoubleLinkedList.PrintList();

	myDoubleLinkedList.InsertAtEnd(700);
	cout << "\nAfter inserting 700 at the end\n";
	myDoubleLinkedList.PrintList();

	MySol::clsDblLinkedList<int>* n2 = myDoubleLinkedList.Find(4);
	myDoubleLinkedList.DeleteNode(n2);
	cout << "\nAfter deleting 4\n";
	myDoubleLinkedList.PrintList();

	myDoubleLinkedList.DeleteFirstNode();
	cout << "After deleting first node:\n";
	myDoubleLinkedList.PrintList();

	myDoubleLinkedList.DeleteLastNode();
	cout << "After deleting last node:\n";
	myDoubleLinkedList.PrintList();
#pragma endregion
}

void abuHadSol()
{
#pragma region AbuHadhoudSOl
	AbuHadhoudSOl::clsDblLinkedList<int> myDoubleLinkedList;

	myDoubleLinkedList.InsertAtBeginning(5);
	myDoubleLinkedList.InsertAtBeginning(4);
	myDoubleLinkedList.InsertAtBeginning(3);
	myDoubleLinkedList.InsertAtBeginning(2);
	myDoubleLinkedList.InsertAtBeginning(1);

	cout << "Linked List content:\n";
	myDoubleLinkedList.PrintList();

	AbuHadhoudSOl::clsDblLinkedList<int>::Node* n1 = myDoubleLinkedList.Find(2);
	if (n1 == NULL)
		cout << "Node with value 2 is not found\n";
	else
		cout << "Node with value 2 is found\n";

	myDoubleLinkedList.InsertAfter(n1, 500);
	myDoubleLinkedList.PrintList();

	myDoubleLinkedList.InsertAtEnd(700);
	cout << "\nAfter inserting 700 at the end\n";
	myDoubleLinkedList.PrintList();

	AbuHadhoudSOl::clsDblLinkedList<int>::Node* n2 = myDoubleLinkedList.Find(4);
	myDoubleLinkedList.DeleteNode(n2);
	cout << "\nAfter deleting 4\n";
	myDoubleLinkedList.PrintList();

	myDoubleLinkedList.DeleteFirstNode();
	cout << "After deleting first node:\n";
	myDoubleLinkedList.PrintList();

	myDoubleLinkedList.DeleteLastNode();
	cout << "After deleting last node:\n";
	myDoubleLinkedList.PrintList();
#pragma endregion
}

void project1()
{
	//mySol();
	abuHadSol();
}