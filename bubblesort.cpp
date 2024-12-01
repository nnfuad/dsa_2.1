#include <iostream>
using namespace std;

void bubble(int a[]){
    for(int i = 0 ; i<5-1 ; i++){
        for(int j= 0 ; j<5-1-i ; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"Sorted array is: ";
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
    bubble(a);

}
