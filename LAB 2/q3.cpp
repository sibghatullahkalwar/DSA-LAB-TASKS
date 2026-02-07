#include<iostream>
using namespace std;
int main(){
	int subjects = 5;
	int depart;
	cout<<"Enter the number of departments: ";
	cin>>depart;
	int* students = new int[depart];
	cout<<"Enter the students in each department: ";
	for(int i = 0 ;i < depart; i++){
		cout<<"Enter the no of students into the depart# "<<i+1<<". ";
		cin>>students[i];
	}
	
	int** deptmarks = new int*[depart];
	for(int i = 0 ; i < depart ; i++){
		deptmarks[i] = new int [students[i]];
	}
	
	cout<<"Enter the marks of each subject for each student: "<<endl;
	for(int i = 0 ; i < depart; i++){
		for(int j = 0 ; j < students[i] ; j++){
			int total = 0;
			int m = 0;
			cout<<"Enter the marks for student# "<<j+1<<". "<<endl;
			
			for(int k = 0 ; k < subjects ; k++){
				cout<<"Enter the marks for subject#"<<k+1<<". ";
				cin>>m;
				total += m;
			}
			
			deptmarks[i][j] = total;
		}
	}
	
	for(int i = 0 ; i < depart ; i++){
		int highest = deptmarks[i][0];
		int lowest  = deptmarks[i][0];
		int sum = 0;
		
		for(int j = 0 ; j < students[i] ; j++){
			if(deptmarks[i][j] > highest)
				highest = deptmarks[i][j];
			if(deptmarks[i][j] < lowest)
				lowest = deptmarks[i][j];
			sum += deptmarks[i][j];
		}
		
		float avg = (float)sum / students[i];
		
		cout<<"Department# "<<i+1<<endl;
		cout<<"Highest Marks: "<<highest<<endl;
		cout<<"Lowest Marks: "<<lowest<<endl;
		cout<<"Average Marks: "<<avg<<endl;
	}
	
	for(int i = 0 ; i < depart ; i++){
		delete[] deptmarks[i];
	}
	delete[] deptmarks;
	delete[] students;
	
}

