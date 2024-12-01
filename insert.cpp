#include <iostream>
using namespace std;

void trav(int a[]){
    cout<<"Array elements are: ";
    for(int i = 0 ; i<5 ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insert(int a[],int num, int p){
    for(int i=4 ; i>=p ; i--){
        a[i+1] = a[i];
    }
    a[p] =num;
    cout<<"Array elements after insertion are: ";
    for(int i = 0 ; i<6 ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

int main(){
    cout<<"Insert an array of 5 elements: ";
    int a[100];
    for(int i = 0 ; i<5 ;i++){
        cin>>a[i];
    }
    trav(a);

    int pos,number ;
    cout<<"Where do you want to insert your number?(array indexing starts from 0) ";
    cin>>pos;
    cout<<"What is the number? ";
    cin>>number;
    insert(a,number,pos);

}
