#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this -> data = data;
			this -> next = NULL;
		}
};

void insertAtEnd(Node* &head, int val){
	Node* temp = new Node(val);
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

void segregateEvenOdd(Node* &head){
	if(head == NULL){
		return;
	}
	
	Node* evenHead = NULL;
	Node* evenTail = NULL;
	Node* oddHead  = NULL;
	Node* oddTail  = NULL;
	
	Node* curr = head;
	
	while(curr != NULL){
		if(curr -> data % 2 == 0){
			if(evenHead == NULL){
				evenHead = curr;
				evenTail = curr;
			} else {
				evenTail -> next = curr;
				evenTail = curr;
			}
		} else {
			if(oddHead == NULL){
				oddHead = curr;
				oddTail = curr;
			} else {
				oddTail -> next = curr;
				oddTail = curr;
			}
		}
		curr = curr -> next;
	}
	
	if(evenHead == NULL || oddHead == NULL){
		return;
	}
	
	evenTail -> next = oddHead;
	oddTail -> next = NULL;
	head = evenHead;
}

void print(Node* head){
	if(head == NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	
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
	Node* head = NULL;
	
	int n, val;
	cout<<"Enter number of elements: ";
	cin >> n;
	
	cout<<"Enter elements: ";
	for(int i = 0 ; i < n ; i++){
		cin >> val;
		insertAtEnd(head, val);
	}
	
	cout<<"\nInput:  ";
	print(head);
	
	segregateEvenOdd(head);
	
	cout<<"Output: ";
	print(head);
	
	cout<<endl<<"Addtional test cases"<<endl;
	
	Node* head2 = NULL;
	insertAtEnd(head2, 17);
	insertAtEnd(head2, 15);
	insertAtEnd(head2, 8);
	insertAtEnd(head2, 12);
	insertAtEnd(head2, 10);
	insertAtEnd(head2, 5);
	insertAtEnd(head2, 4);
	insertAtEnd(head2, 1);
	insertAtEnd(head2, 7);
	insertAtEnd(head2, 6);
	
	cout<<"\nInput:  ";
	print(head2);
	segregateEvenOdd(head2);
	cout<<"Output: ";
	print(head2);
	
	Node* head3 = NULL;
	insertAtEnd(head3, 8);
	insertAtEnd(head3, 12);
	insertAtEnd(head3, 10);
	
	cout<<"\nInput:  ";
	print(head3);
	segregateEvenOdd(head3);
	cout<<"Output: ";
	print(head3);
	
	Node* head4 = NULL;
	insertAtEnd(head4, 1);
	insertAtEnd(head4, 3);
	insertAtEnd(head4, 5);
	insertAtEnd(head4, 7);
	
	cout<<"\nInput:  ";
	print(head4);
	segregateEvenOdd(head4);
	cout<<"Output: ";
	print(head4);
}
