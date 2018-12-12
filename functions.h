#include <iostream>
#include <string>

using namespace std;

struct Node
{
	char letter;
	Node* next;
};

//bool full();
void pushqueue(Node* &head, Node* &tail, string);
void popqueue(Node* &head, Node* &tail);
void pushstack(string);
void popstack(Node* &head, Node &tail, Node* &stackptr, char&);
bool empty(Node* &head, Node* &tail);
bool palindrometest(char&, char&);

bool empty(Node* &head, Node* &tail)
{
	return (head == NULL && tail == NULL);
}

void pushqueue(Node* &head, Node* &tail, string input)
{
	Node* pushnode;
	
	for(int i = 0; i < input.length(); i++)
	{
			pushnode = new Node;
			pushnode -> letter = input[i];
			pushnode -> next = NULL;

		
		if(head == NULL) //if first element in the list
		{
			head = pushnode;
			tail = pushnode;
			//tail -> next = NULL;
		}
		
		else
		{
			tail -> next = pushnode;
			tail = pushnode;
			//tail -> next = NULL;
		}
	}
}

void popqueue(Node* &head, Node* &tail, char &queuepopped)
{
	Node* temp;
	queuepopped = head -> letter;
	
	if(empty(head, tail) == true)
	{
		cout << "Queue is empty" << endl;
		head = NULL;
		tail = NULL;
		return;
	}
	
	else{
		temp = head;
		head = head -> next;
		cout << temp->letter << endl;
		delete temp;
	}
}

void pushstack(Node* &stackptr, string input)
{	
	Node* pushnode;
	for(int i = 0; i < input.length(); i++)
	{
		pushnode = new Node;
		
		pushnode -> letter = input[i];
		pushnode -> next = stackptr;
		
		stackptr = pushnode;
	}
}

void popstack(Node* &head, Node* &tail, Node* &stackptr, char &popstack)
{
	Node* popnode;
	
	if(empty(head, tail) == true)
		cout << "Empty stack!" << endl;
	
	else{
		popstack = stackptr -> letter;
		popnode = stackptr;
		stackptr = stackptr -> next;
		delete popnode;
	}
		
}

bool palindrometest(char &stackpopped, char &queuepopped)
{
	bool determine = true;

	if(determine == true){
		if(stackpopped == queuepopped)
			return true;
		else
			return false;
	}
}
