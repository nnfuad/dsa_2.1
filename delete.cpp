#include <iostream>
using namespace std;

void trav(int a[]){
    cout<<"Array elements are: ";
    for(int i = 0 ; i<5 ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void del(int a[], int p){
    for(int i=p ; i<=5 ; i++){
        a[i] = a[i+1];
    }
    cout<<"Array elements after deletion are: ";
    for(int i = 0 ; i<4 ;i++){
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
    cout<<"What positioned number do you want to delete? (array indexing starts from 0) ";
    cin>>pos;
    del(a,pos);

}

