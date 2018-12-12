#include "functions.h"

bool palindrometest(char& stackpopped, char& queuepopped);

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	
	Node* stackptr = NULL;
	
	bool check;
	char stackpopped;
	char queuepopped;
	string userinput;
	
	cout << "Enter a word to determine if it is a palindrome" << endl;
	getline(cin, userinput);

	pushqueue(head, tail, userinput);
	pushstack(stackptr, userinput);

	for(int i = 0; i < userinput.length(); i++)
	{
		popqueue(head, tail, queuepopped);
		popstack(head, tail, stackptr, stackpopped);
		check = palindrometest(stackpopped, queuepopped);
	}

	if(check == true)
		cout << "Yes, palindrome" << endl;
		
	else
		cout << "This is not a palindrome" << endl;
}
