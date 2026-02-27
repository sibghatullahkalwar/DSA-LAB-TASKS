#include<iostream>
#include<string>
using namespace std;

class Node{
	public:
		char data;
		Node* next;
		
		Node(char data){
			this -> data = data;
			this -> next = NULL;
		}
};

void insertAtEnd(Node* &head, char ch){
	Node* temp = new Node(ch);
	if(head == NULL){
		head = temp;
		return;
	}
	
	Node* n = head;
	while(n -> next != NULL){
		n = n -> next;
	}
	
	n -> next = temp;
}

void buildList(Node* &head, string word){
	for(int i = 0 ; i < word.length() ; i++){
		insertAtEnd(head, word[i]);
	}
}

int getLength(Node* head){
	int count = 0;
	Node* temp = head;
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}

Node* reverseList(Node* head){
	Node* prev = NULL;
	Node* curr = head;
	Node* next = NULL;
	
	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

bool checkPalindrome(Node* head){
	if(head == NULL || head -> next == NULL){
		return true;
	}
	
	int len = getLength(head);
	int mid = len / 2;
	
	Node* curr = head;
	for(int i = 0 ; i < mid ; i++){
		curr = curr -> next;
	}
	
	if(len % 2 != 0){
		curr = curr -> next;
	}
	
	Node* secondHalf = reverseList(curr);
	Node* firstHalf  = head;
	Node* temp       = secondHalf;
	
	bool isPalindrome = true;
	
	while(temp != NULL){
		if(firstHalf -> data != temp -> data){
			isPalindrome = false;
			break;
		}
		firstHalf = firstHalf -> next;
		temp      = temp -> next;
	}
	
	reverseList(secondHalf);
	
	return isPalindrome;
}

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp -> data;
		if(temp -> next != NULL){
			cout<<" -> ";
		}
		temp = temp -> next;
	}
	cout<<" -> NULL"<<endl;
}

int main(){
	string word;
	cout<<"Hamza (Text Editor Developer) - Palindrome Checker"<<endl;
	cout<<"Enter a word to check: ";
	cin >> word;
	
	Node* head = NULL;
	buildList(head, word);
	
	cout<<"\nLinked List: ";
	print(head);
	
	if(checkPalindrome(head)){
		cout<<"Palindrome: true"<<endl;
	} else {
		cout<<"Palindrome: false"<<endl;
	}
	
	cout<<"test cases"<<endl;
	
	string testWords[] = {"Shan", "Tapal", "Gul", "Haleeb", "civic", "Engro", "aja", "Noon", "Pakola", "ana"};
	string testedBy[]  = {"Bilal", "Zara", "Usman", "Fatima", "Hamza", "Ayesha", "Tariq", "Sana", "Ali", "Hina"};
	
	for(int i = 0 ; i < 10 ; i++){
		Node* testHead = NULL;
		buildList(testHead, testWords[i]);
		cout<<"\nTested By : "<<testedBy[i]<<endl;
		cout<<"Word      : "<<testWords[i]<<endl;
		cout<<"Linked List: ";
		print(testHead);
		if(checkPalindrome(testHead)){
			cout<<"Palindrome: true"<<endl;
		} else {
			cout<<"Palindrome: false"<<endl;
		}
	}
}
