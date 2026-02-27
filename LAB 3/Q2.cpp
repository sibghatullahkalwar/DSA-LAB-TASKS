#include<iostream>
using namespace std;

class Node{
	public:
		int bookID;
		string title;
		string author;
		Node* next;
		
		Node(int bookID, string title, string author){
			this -> bookID = bookID;
			this -> title = title;
			this -> author = author;
			this -> next = NULL;
		}
};

void insertAtStart(Node* &head, int bookID, string title, string author){
	Node* temp = new Node(bookID, title, author);
	temp -> next = head;
	head = temp;
}

void insertAtEnd(Node* &head, int bookID, string title, string author){
	Node* temp = new Node(bookID, title, author);
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

void insertAtPosition(Node* &head, int bookID, string title, string author, int pos){
	if(pos == 0){
		insertAtStart(head, bookID, title, author);
		return;
	}
	
	Node* temp = new Node(bookID, title, author);
	Node* curr = head;
	Node* prev = NULL;
	
	for(int i = 0 ; i < pos && curr != NULL ; i++){
		prev = curr;
		curr = curr -> next;
	}
	
	if(prev != NULL){
		prev -> next = temp;
		temp -> next = curr;
	}
}

void deleteAtStart(Node* &head){
	if(head == NULL){
		cout<<"No books available"<<endl;
		return;
	}
	Node* temp = head;
	head = head -> next;
	delete temp;
}

void deleteAtEnd(Node* &head){
	if(head == NULL){
		cout<<"No books available"<<endl;
		return;
	}
	
	if(head -> next == NULL){
		delete head;
		head = NULL;
		return;
	}
	
	Node* curr = head;
	Node* prev = NULL;
	
	while(curr -> next != NULL){
		prev = curr;
		curr = curr -> next;
	}
	
	prev -> next = NULL;
	delete curr;
}

void deleteAtPosition(Node* &head, int pos){
	if(head == NULL){
		cout<<"No books available"<<endl;
		return;
	}
	
	if(pos == 0){
		deleteAtStart(head);
		return;
	}
	
	Node* curr = head;
	Node* prev = NULL;
	
	for(int i = 0 ; i < pos && curr != NULL ; i++){
		prev = curr;
		curr = curr -> next;
	}
	
	if(curr == NULL){
		cout<<"Position out of range"<<endl;
		return;
	}
	
	prev -> next = curr -> next;
	delete curr;
}

void searchBook(Node* head, int bookID){
	if(head == NULL){
		cout<<"No books available"<<endl;
		return;
	}
	
	Node* curr = head;
	while(curr != NULL){
		if(curr -> bookID == bookID){
			cout<<"Book Found:"<<endl;
			cout<<"Book ID: "<<curr -> bookID<<"  Title: "<<curr -> title<<"  Author: "<<curr -> author<<endl;
			return;
		}
		curr = curr -> next;
	}
	
	cout<<"Book with ID "<<bookID<<" not found"<<endl;
}

void print(Node* head){
	if(head == NULL){
		cout<<"No books available"<<endl;
		return;
	}
	
	Node* temp = head;
	while(temp != NULL){
		cout<<"Book ID: "<<temp -> bookID<<"  Title: "<<temp -> title<<"  Author: "<<temp -> author<<endl;
		temp = temp -> next;
	}
}

int main(){
	Node* head = NULL;
	
	insertAtEnd(head, 103, "Aag Ka Darya", "Qurratulain Hyder");
	insertAtEnd(head, 104, "Khuda Aur Mohabbat", "Hashim Nadeem");
	insertAtEnd(head, 105, "Raja Gidh", "Bano Qudsia");
	
	cout<<"after insert at end"<<endl;
	print(head);
	
	insertAtStart(head, 101, "Udas Naslain", "Abdullah Hussein");
	insertAtStart(head, 100, "Meri Kahani", "Zulfiqar Ali Bhutto");
	
	cout<<endl<<"after insert at start"<<endl;
	print(head);
	
	insertAtPosition(head, 102, "Andhera Ujala", "Ashfaq Ahmed", 2);
	
	cout<<"after insert at position 2"<<endl;
	print(head);
	
	deleteAtStart(head);
	
	cout<<"after insert at start"<<endl;
	print(head);
	
	deleteAtEnd(head);
	
	cout<<"after insert at end"<<endl;
	print(head);
	
	deleteAtPosition(head, 2);
	
	cout<<"after delte at position 2"<<endl;
	print(head);
	
	cout<<"search for book id 103-"<<endl;
	searchBook(head, 103);
	
	cout<<"search for book id 999"<<endl;
	searchBook(head, 999);
}
