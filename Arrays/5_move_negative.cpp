#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void sort_negative(vector<int>& a,int n){
    int j = 0;
    for(int i=0;i<n;i++){
        if(a[i] < 0){
            swap(a[i],a[j]);
            j++;
        }
    }
}

int main(){
    vector<int> a;
    int n;
    cin>>n;
    cout<<n<<endl;
    cout<<"input integers : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,n);
    sort_negative(a,n);
    print(a,n);
}