#include<iostream>
using namespace std;

class DeepBox{
public:
    int *n; 
    
    DeepBox(int num){
        n = new int(num);
    }
    
    ~DeepBox(){
        delete n;
    }
    
    DeepBox(const DeepBox& obj){
        n = new int(*obj.n);
    }
    
    DeepBox& operator=(const DeepBox& obj){        
        if(this == &obj){
            return *this;
        }
        
        delete n;
        n = new int(*obj.n);
        
        return *this;
    }
    
    void display(){
        cout << "Value: " << *n << " address: " << n << endl;
    }
};

class Box{
public:
    int *n; 
    
    Box(int num){
        n = new int(num);
    }
    
    ~Box(){
        delete n;
    }
    
    Box(const Box& obj){
        n = obj.n;
    }
    
    Box& operator=(const Box& obj){
        if(this != &obj){
            delete n;
            n = obj.n;
        }
        return *this;
    }
};

int main(){
    cout<<"deep copy"<<endl;
    DeepBox db1(100);
    db1.display();
    
    DeepBox db2 = db1;
    db2.display();
    
    DeepBox db3(999);
    db3 = db1;
    db3.display();
    
    *db2.n = 777;
    cout << endl;
    cout << "After changing db2:" << endl;
    cout << "db1: "; db1.display();
    cout << "db2: "; db2.display();
    
    cout<<"shallow copy"<<endl;
    Box b1(50);
    Box b2 = b1;
    
    *b2.n = 999;
    cout << "b1.n = " << *b1.n << endl;
    cout << "b2.n = " << *b2.n << endl;
    
    return 0;
}
