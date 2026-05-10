#pragma once

#include <iostream>
using namespace std;

namespace Project1
{
	namespace MySol
	{

		template <typename T>
		class clsDblLinkedList
		{
			T _Value;
			clsDblLinkedList <T>* _Next = NULL;
			clsDblLinkedList <T>* _Prev = NULL;

		public:
			clsDblLinkedList <T>* Head = NULL;

			void InsertAtBeginning(T Value)
			{
				clsDblLinkedList <T>* NewNode = new clsDblLinkedList;
				NewNode->_Value = Value;

				if (Head == nullptr)
				{
					Head = NewNode;
					return;
				}

				NewNode->_Prev = NULL;
				NewNode->_Next = Head;

				Head->_Prev = NewNode;

				Head = NewNode;
			}

			void PrintList()
			{
				if (Head == NULL)
				{
					cout << "Empty!\n";
					return;
				}

				clsDblLinkedList <T>* Temp = Head;

				while (Temp != NULL)
				{
					cout << Temp->_Value << " ";

					Temp = Temp->_Next;
				}
				cout << endl;
			}

			void DeleteFirstNode()
			{
				if (Head == NULL) {
					return;
				}

				clsDblLinkedList <T>* Temp = Head;

				Head = Head->_Next;

				delete Temp;
			}

			bool DeleteLastNode()
			{
				if (Head == NULL) {
					return false;
				}

				// IF just 1
				if (Head->_Next == NULL)
				{
					delete Head;
					Head = NULL;
					return true;
				}

				clsDblLinkedList <T>* Current = Head;

				// The node before the last node
				while (Current->_Next->_Next != NULL)
				{
					Current = Current->_Next;
				}

				// The last one
				clsDblLinkedList <T>* Temp = Current->_Next;

				// Before last one points to NULL
				Current->_Next = NULL;

				// Delete last one
				delete Temp;

				return true;
			}

			bool DeleteNode(clsDblLinkedList <T>* Position)
			{
				if (Head == NULL)
					return false;

				if (Position->_Next != NULL)
				{
					Position->_Next->_Prev = Position->_Prev;
				}

				if (Position->_Prev != NULL)
				{
					Position->_Prev->_Next = Position->_Next;
				}
				else { Head = Position->_Next; }

				delete Position;
				Position = NULL;

				return true;

			}

			clsDblLinkedList* Find(T Value)
			{
				if (Head == NULL) {
					return NULL;
				}

				clsDblLinkedList <T>* Temp = Head;

				while (Temp != NULL)
				{
					if (Temp->_Value == Value)
					{
						return Temp;
					}
					Temp = Temp->_Next;
				}
				return NULL;
			}

			bool InsertAfter(clsDblLinkedList <T>* Position, T Value)
			{
				if (Position == NULL)  return false;

				clsDblLinkedList <T>* NewItem = new clsDblLinkedList;
				NewItem->_Value = Value;
				NewItem->_Next = Position->_Next;
				NewItem->_Prev = Position;

				// IF NOOOOOOOT the last
				if (Position->_Next != NULL)
				{
					Position->_Next->_Prev = NewItem;
				}

				Position->_Next = NewItem;

				return true;
			}

			bool InsertAtEnd(T Value)
			{
				clsDblLinkedList <T>* New = new clsDblLinkedList;
				New->_Value = Value;
				New->_Next = NULL;


				if (Head == NULL)
				{
					Head = New;
					return true;
				}

				clsDblLinkedList <T>* Temp = Head;
				while (Temp->_Next != NULL)
				{
					Temp = Temp->_Next;
				}

				Temp->_Next = New;

				New->_Prev = Temp;

				return true;
			}
		};
	}
	namespace AbuHadhoudSOl
	{
		template <typename T>
		class clsDblLinkedList
		{
		public:
			class Node
			{
			public:
				T value;
				Node * next = NULL;
				Node * prev = NULL;
			};
			Node* Head = NULL;

			void InsertAtBeginning(T Value)
			{
				Node* NewNode = new Node;
				NewNode->value = Value;

				if (Head == nullptr)
				{
					Head = NewNode;
					return;
				}

				NewNode->prev = NULL;
				NewNode->next = Head;

				Head->prev = NewNode;

				Head = NewNode;
			}

			void PrintList()
			{
				if (Head == NULL)
				{
					cout << "Empty!\n";
					return;
				}

				Node* Temp = Head;

				while (Temp != NULL)
				{
					cout << Temp->value << " ";

					Temp = Temp->next;
				}
				cout << endl;
			}

			void DeleteFirstNode()
			{
				if (Head == NULL) {
					return;
				}

				Node* Temp = Head;

				Head = Head->next;

				delete Temp;
			}

			bool DeleteLastNode()
			{
				if (Head == NULL) {
					return false;
				}

				// IF just 1
				if (Head->next == NULL)
				{
					delete Head;
					Head = NULL;
					return true;
				}

				Node * Current = Head;

				// The node before the last node
				while (Current->next->next != NULL)
				{
					Current = Current->next;
				}

				// The last one
				Node * Temp = Current->next;

				// Before last one points to NULL
				Current->next = NULL;

				// Delete last one
				delete Temp;

				return true;
			}

			bool DeleteNode(Node* node)
			{
				if (Head == NULL)
					return false;

				if (node->next != NULL)
				{
					node->next->prev = node->prev;
				}

				if (node->prev != NULL)
				{
					node->prev->next = node->next;
				}
				else { Head = node->next; }

				delete node;
				node = NULL;

				return true;

			}

			Node* Find(T Value)
			{
				if (Head == NULL) {
					return NULL;
				}

				Node * Temp = Head;

				while (Temp != NULL)
				{
					if (Temp->value == Value)
					{
						return Temp;
					}
					Temp = Temp->next;
				}
				return NULL;
			}

			bool InsertAfter(Node* Position, T Value)
			{
				if (Position == NULL)  return false;

				Node* NewItem = new Node;
				NewItem->value = Value;
				NewItem->next = Position->next;
				NewItem->prev = Position;

				// IF NOOOOOOOT the last
				if (Position->next != NULL)
				{
					Position->next->prev = NewItem;
				}

				Position->next = NewItem;

				return true;
			}

			bool InsertAtEnd(T Value)
			{
				Node* New = new Node;
				New->value = Value;
				New->next = NULL;


				if (Head == NULL)
				{
					Head = New;
					return true;
				}

				Node* Temp = Head;
				while (Temp->next != NULL)
				{
					Temp = Temp->next;
				}

				Temp->next = New;

				New->prev = Temp;

				return true;
			}
		};
	}
}
