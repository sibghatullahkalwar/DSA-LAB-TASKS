#include<iostream>
using namespace std;

class Exam{
	public:
		string* name;
		int* date;
		float* score;
		
		void setter(string name_, int date_, float score_){
			name = new string(name_);
			date = new int(date_);
			score = new float(score_);
		}
		
		string getter(){
			return *name;
		}
		
		int getter1(){
			return *date;
		}
		
		float getter2(){
			return *score;
		}
		
		void display(){
			cout << "Name = "<<*name<<endl;
			cout << "Date = "<<*date<<endl;
			cout << "Score = "<<*score<<endl;
			cout<<endl;
		}
		
};

int main(){
	Exam e1;
	e1.setter("Sibghatullah", 25,79);
	e1.display();
	Exam e2;
	e2 = e1; // copy assignment construcor
	e2.display();
}

