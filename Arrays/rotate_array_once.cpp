#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void rotate(vector<int>& a,int n){
    int temp=a[0];
    for(int i=1;i<n;i++){
        swap(temp,a[i]);
    }
    a[0] = temp;
}

int main(){
    vector<int> a;
    int n;
    cin>>n;
    cout<<n<<endl;
    cout<<"input integers for Array 1 : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,n);
    rotate(a,n);
    print(a,n);
}