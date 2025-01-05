#include <iostream>
using namespace std;

void trav(int a[]){
    cout<<"Array elements are: ";
    for(int i = 0 ; i<5 ;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Insert an array of 5 elements: ";
    int a[5];
    for(int i = 0 ; i<5 ;i++){
        cin>>a[i];
    }
    trav(a);
}
