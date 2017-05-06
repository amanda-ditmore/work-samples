/*Amanda Ditmore
CS110C
4-01-2017*/

#include "stack.h"
#include "queue.h"
#include <iostream>
using namespace std;


int main()
{
	string input;
	Stack<char> testStk;
	Queue<char> testQ;

	cout << "Enter a word or sentence to test: ";
	getline(cin, input);	
		
	//store input in stack and queue
	for (int i = 0; i < input.length(); i++)
	{
		testStk.push(input[i]);
		testQ.enQ(input[i]);
	}

	//loop through stack and queue one char at a time
	//if a difference is found, its not a palindrome.
	bool isPal = true; 
	for(int i = 0; i < input.length() && isPal; i++)
	{ 
			
		if(testStk.peek() != testQ.peek())
		{
			isPal = false;
		}
		else
		{
			testQ.deQ();
			testStk.pop();			
		}	
	}

	if(isPal)
		cout << "\"" << input << "\" is a palindrome." << endl;
	else
		cout << "\"" << input << "\" is not a palindrome." << endl;

}


