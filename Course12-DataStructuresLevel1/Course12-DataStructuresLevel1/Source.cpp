#include <iostream>
using namespace std;
class Node
{
public:
	Node() : Value(0), Next(NULL) {};
	Node(int value) {
		this->Value = value;
		Next = NULL;
	}

	int Value;
	Node* Next;
};

void ShowLinkedListCreation()
{
	Node Node1;
	Node Node2;
	Node Node3;

	Node1.Next = &Node2;
	Node2.Next = &Node3;
	Node3.Next = NULL;

	Node1.Value = 1;
	Node2.Value = 2;
	Node3.Value = 3;

	Node* Head = &Node1;

	while (Head != NULL)
	{
		std::cout << Head->Value << std::endl << std::endl;

		Head = Head->Next;
	}
}

void Print(Node* Head)
{
	while (Head != NULL)
	{
		std::cout << Head->Value << "  ";

		Head = Head->Next;
	}
	cout << endl;
}

// Passing a pointer by reference
void InsertAtBeginning(Node*& Head, int Value)
{
	Node* NewNode = new Node;

	NewNode->Value = Value;

	NewNode->Next = Head;

	Head = NewNode;
}

void ShwoInsertion()
{
	Node* Head = NULL;

	InsertAtBeginning(Head, 1);
	InsertAtBeginning(Head, 2);
	InsertAtBeginning(Head, 3);
	InsertAtBeginning(Head, 3434);

	Print(Head);
}

// Passing pointer by val
Node* Find(Node* Head, int Value)
{
	while (Head != NULL)
	{
		if (Head->Value == Value)
			return Head;

		Head = Head->Next;
	}
	return NULL;
}

void ShwoFindNode()
{
	Node* Head = NULL;

	InsertAtBeginning(Head, 1);
	InsertAtBeginning(Head, 2);
	InsertAtBeginning(Head, 3);
	InsertAtBeginning(Head, 3434);

	if (Find(Head, 334) != NULL)
		std::cout << "Found\n";
	else
		std::cout << "Not Found\n";
}

void InsertAfter(Node* Head, int Value, int NewValue)
{
	Node* NodeAt = Find(Head, Value); // This returns an object or an actual Node

	Node* NewNode = new Node;

	NewNode->Value = NewValue;

	NewNode->Next = NodeAt->Next;

	NodeAt->Next = NewNode;
}

void ShowInsertAfter()
{
	Node* Head = NULL;

	InsertAtBeginning(Head, 1);
	InsertAtBeginning(Head, 2);
	InsertAtBeginning(Head, 3);
	InsertAtBeginning(Head, 4);

	InsertAfter(Head, 3, 10);

	Print(Head);
}

void InsertAtTheEnd(Node*& Head, int Value)
{
	if (Head == nullptr) {
		Head = new Node(Value);
		return;
	}
	Node* current = Head;

	while (current != nullptr) {
		if (current->Next == nullptr) {
			current->Next = new Node(Value);
			current = current->Next;
		}
		current = current->Next;
	}
}

void ShowInsertAtTheEnd()
{
	Node* Head = NULL;

	InsertAtTheEnd(Head, 5);
	InsertAtTheEnd(Head, 6);
	InsertAtTheEnd(Head, 7);
	InsertAtTheEnd(Head, 8);

	InsertAtBeginning(Head, 4);

	Print(Head);
}

void Delete(Node*& Head, int Value)
{
	Node* Current, * Previous;
	Current = Head;
	Previous = Head;

	if (Current == NULL)
	{
		return;
	}

	if (Current->Value == Value)
	{
		Head = Current->Next;
		delete Current;
		return;
	}

	while (Current->Next != nullptr && Current->Value != Value)
	{
		Previous = Current;
		Current = Current->Next;
	}

	// IF last Node;
	if (Current->Value == NULL) return;

	Previous->Next = Current->Next;
	delete Current;
}

void ShowDeleteNode()
{
	Node* Head = NULL;

	InsertAtTheEnd(Head, 5);
	InsertAtBeginning(Head, 4);
	InsertAtTheEnd(Head, 6);
	InsertAtTheEnd(Head, 7);
	InsertAtTheEnd(Head, 8);
	Print(Head); cout << endl;

	Delete(Head, 4);
	Delete(Head, 7);
	Delete(Head, 8);

	Print(Head);
}

void DeleteFirstNode(Node*& Head)
{
	if (Head == nullptr)
	{
		return;
	}

	Node* CurrentNode = Head;

	Head = Head->Next;

	cout << endl;

	delete CurrentNode;
}

void ShowDeleteFirstNode()
{
	Node* Head = NULL;

	InsertAtTheEnd(Head, 5);
	InsertAtBeginning(Head, 4);
	InsertAtTheEnd(Head, 6);
	InsertAtTheEnd(Head, 7);
	InsertAtTheEnd(Head, 8);
	Print(Head);

	DeleteFirstNode(Head);
	DeleteFirstNode(Head);

	Print(Head);
}

void DeleteLastNode(Node* Head)
{
	if (Head == nullptr)
		return;

	Node* Current = Head, * Prev = Head;

	if (Head->Next == nullptr)
	{
		Head = nullptr;
		delete Current;
		return;
	}

	while (Current->Next != nullptr)
	{
		Prev = Current;
		Current = Current->Next;
	}

	Prev->Next = nullptr;
	delete Current;
}


void ShowDeleteLastNode()
{
	Node* Head = NULL;

	InsertAtTheEnd(Head, 5);
	InsertAtBeginning(Head, 4);
	InsertAtTheEnd(Head, 6);
	InsertAtTheEnd(Head, 7);
	InsertAtTheEnd(Head, 8);
	Print(Head);

	DeleteLastNode(Head);
	DeleteLastNode(Head);

	Print(Head);
}

namespace DublyLinkedListOperations
{
#include <iostream>
	using namespace std;

	class Node
	{
	public:
		int Value;
		Node* Next;
		Node* Prev;
	};

	void InsertAtBeginning(Node*& Head, int Value)
	{
		Node* NewNode = new Node;

		// Assign a value
		NewNode->Value = Value;

		// The new Node Points to the first Node
		NewNode->Next = Head;

		if (Head != NULL)
		{
			// The first Node points to the new first NewNode
			Head->Prev = NewNode;
		}

		// The New node points to the previous NULL
		NewNode->Prev = NULL;

		// The Head points to the first Node;
		Head = NewNode;
	}

	void Print(Node* Head)
	{
		while (Head != NULL)
		{
			cout << Head->Value << "  ";
			Head = Head->Next;
		}
		cout << endl;
	}

	Node* FindNode(Node* Head, int Value)
	{
		while (Head != NULL)
		{
			if (Head->Value == Value)
			{
				return Head;
			}
			Head = Head->Next;
		}

		cout << "Not Found\n";
		return NULL;
	}

	void InsertAfter(Node* Current, int Value)
	{
		if (Current->Next == nullptr) {
			Current->Next = new Node(); Current->Next->Value = Value, Current->Next->Prev = Current;
		}
		else
		{
			Node* New = new Node(); New->Value = Value;
			New->Next = Current->Next;
			New->Prev = Current;

			Current->Next->Prev = New;

			Current->Next = New;
		}
	}
	void InsertAtTheEnd(Node*& Head, int Value);
	void ShowInsertAfter()
	{
		Node* head = new Node ();
		head->Value = 1;


		InsertAtTheEnd(head, 2);
		InsertAtTheEnd(head, 3);
		InsertAtTheEnd(head, 4);
		InsertAtTheEnd(head, 5);
		InsertAtTheEnd(head, 6);

		Node* node4 = head->Next->Next->Next;
		Print(head);

		InsertAfter(node4, 100);

		Print(head);
	}

	void InsertAtTheEnd(Node*& Head, int Value)
	{

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->Next = NULL;

		if (Head == NULL)
		{
			NewNode->Prev = NULL;
			Head = NewNode;
		}
		else
		{
			Node* Current = Head;
			while (Current->Next != NULL)  
			{
				Current = Current->Next;
			}

			Current->Next = NewNode;
			NewNode->Prev = Current;
		}

	}

	void DeleteNode(Node*& Head, Node*& NodeToDelete)
	{
		if (Head == NULL || NodeToDelete == NULL) {
			return;
		}

		// If first Node
		if (Head == NodeToDelete) {
			Head = NodeToDelete->Next;
		}

		// If Not The Last
		if (NodeToDelete->Next != NULL) { // Link the next with the prev
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		// If Not The First                    Is it always better to check if is not rather to check if is?
		if (NodeToDelete->Prev != NULL) { // Link the prev with the next
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		delete NodeToDelete;
	}

	void DeleteFirstNode(Node*& Head)
	{
		if (Head == NULL) {
			return;
		}

		// This temp is to delete the first node from the memory
		Node* Temp = Head;

		Head = Head->Next;
		if (Head != NULL) {
			Head->Prev = NULL;
		}

		delete Temp;
	}

	void DeleteLastNode(Node* Head)
	{
		if (Head == NULL) {
			return;
		}

		// IF just 1
		if (Head->Next == NULL)
		{
			delete Head;
			Head = NULL;
			return;
		}

		Node* Current = Head;
		// The node before the last node
		while (Current->Next->Next != NULL)
		{
			Current = Current->Next;
		}

		Node* Temp = Current->Next;

		Current->Next = NULL;

		delete Temp;
	}

	int main()
	{
		Node* Head = NULL;

		InsertAtTheEnd(Head, 1);
		InsertAtTheEnd(Head, 2);
		InsertAtTheEnd(Head, 3);
		InsertAtTheEnd(Head, 4);
		InsertAtTheEnd(Head, 5);
		Print(Head);

		Node* First = FindNode(Head, 1);
		Node* Middle = FindNode(Head, 3);
		Node* Last = FindNode(Head, 5);

		DeleteLastNode(Head);

		Print(Head);

		return 0;
	}
}


int main()
{
#pragma region SinglyLinkedList


	//ShwoInsertion();
	//ShwoFindNode();
	//ShowInsertAfter();
	//ShowInsertAtTheEnd();
	//ShowDeleteNode();
	//ShowDeleteFirstNode();
	//ShowDeleteLastNode();
#pragma endregion
#pragma region DublyLinkedList

	//DublyLinkedListOperations::ShwoInsertion();
	//DublyLinkedListOperations::ShwoFindNode();
	DublyLinkedListOperations::ShowInsertAfter();
	//DublyLinkedListOperations::ShowInsertAtTheEnd();
	//DublyLinkedListOperations::ShowDeleteNode();
	//DublyLinkedListOperations::ShowDeleteFirstNode();
	//DublyLinkedListOperations::ShowDeleteLastNode();
#pragma endregion
}