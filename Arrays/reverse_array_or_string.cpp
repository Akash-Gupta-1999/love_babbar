#include<bits/stdc++.h>
using namespace std;

void reverse(auto* a,int n){
    int i = 0, j = n-1;
    while(i<j){
        swap(a[i],a[j]);
        i++;
        j--;
    }
}

void print(auto* a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int a[10];
    char c[10];
    cout<<"input integers : ";
    for(int i = 0;i<10;i++){
        cin>>a[i];
    }
    print(a,10);
    cout<<"Input string: ";
    for(int i = 0;i<10;i++){
        cin>>c[i];
    }
    print(c,10);
    reverse(a,10);
    reverse(c,10);
    print(a,10);
    print(c,10);
}