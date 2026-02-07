#include<iostream>
using namespace std;

int main(){
    int students = 5;
    int subjects = 4;
    int t_marks = 0;

    int* student_total_marks = new int[students];
    int* student_avg_marks = new int[subjects];

    int** arr = new int*[students];
    for(int i = 0 ; i < students ; i++){
        arr[i] = new int[subjects];
    }

    for(int i = 0 ; i < students; i++){
        student_total_marks[i] = 0;
    }

    for(int i = 0 ; i < subjects; i++){
        student_avg_marks[i] = 0;
    }

    cout<<"Enter the marks of each subject for each student"<<endl;

    for(int i = 0 ; i < students ; i++){
        cout<<"Enter the marks for the student# "<<i+1<<endl;
        for(int j = 0 ; j < subjects ; j++){
            cout<<"Subject#"<<j+1<<". ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    for(int i = 0 ; i < students ; i++){
        for(int j = 0 ; j < subjects ; j++){
            student_total_marks[i] += arr[i][j];
        }
    }

    for(int i = 0 ; i < subjects; i++){
        t_marks = 0;
        for(int j = 0 ; j < students ; j++){
            t_marks += arr[j][i];
        }
        student_avg_marks[i] = t_marks / students;
    }

    cout<<"Total marks of each student are:"<<endl;
    for(int i = 0 ; i < students; i++){
        cout<<"Student "<<i+1<<". "<<student_total_marks[i]<<endl;
    }

    cout<<endl;

    cout<<"Average marks of each subject are:"<<endl;
    for(int i = 0 ; i < subjects; i++){
        cout<<"Subject "<<i+1<<". "<<student_avg_marks[i]<<endl;
    }

    cout<<endl;

    int top_marks = student_total_marks[0];
    int topper = 1;

    for(int i = 1 ; i < students; i++){
        if(student_total_marks[i] > top_marks){
            top_marks = student_total_marks[i];
            topper = i + 1;
        }
    }

    cout<<"Topper student is Student "<<topper<<" with total marks "<<top_marks<<endl;

    for(int i = 0 ; i < students; i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete[] student_total_marks;
    delete[] student_avg_marks;

    return 0;
}

