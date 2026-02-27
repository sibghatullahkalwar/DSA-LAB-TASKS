#include<iostream>
using namespace std;

class Node{
	public:
		int rollNumber;
		string name;
		string department;
		Node* next;
		
		Node(int rollNumber, string name, string department){
			this -> rollNumber = rollNumber;
			this -> name = name;
			this -> department = department;
			this -> next = NULL;
		}
};

void addStudent(Node* &head, int rollNumber, string name, string department){
	Node* temp = new Node(rollNumber, name, department);
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

void deleteStudent(Node* &head, int rollNumber){
	if(head == NULL){
		return;
	}
	
	if(head -> rollNumber == rollNumber){
		Node* temp = head;
		head = head -> next;
		delete temp;
		return;
	}
	
	Node* curr = head;
	Node* prev = NULL;
	
	while(curr != NULL && curr -> rollNumber != rollNumber){
		prev = curr;
		curr = curr -> next;
	}
	
	if(curr == NULL){
		cout<<"Student with roll number "<<rollNumber<<" not found"<<endl;
		return;
	}
	
	prev -> next = curr -> next;
	delete curr;
}

void print(Node* head){
	if(head == NULL){
		cout<<"No students registered"<<endl;
		return;
	}
	
	Node* temp = head;
	while(temp != NULL){
		cout<<"Roll Number: "<<temp -> rollNumber<<"  Name: "<<temp -> name<<"  Department: "<<temp -> department<<endl;
		temp = temp -> next;
	}
}

int main(){
	Node* head = NULL;
	
	addStudent(head, 101, "sibhat", "Computer Science");
	addStudent(head, 102, "muneer", "Electrical Engineering");
	addStudent(head, 103, "ali noor", "Mechanical Engineering");
	addStudent(head, 104, "Dev", "Civil Engineering");
	
	print(head);
	
	cout<<endl;
	deleteStudent(head, 102);
	deleteStudent(head, 999);
	
	cout<<endl;
	print(head);
}
