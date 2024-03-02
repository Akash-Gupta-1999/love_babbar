#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void sort_0_1_2(vector<int>& a,int n){
    int low = 0,high = n-1;
    int i=0;
    while(i<=high){
        if(a[i] == 0){
            swap(a[i],a[low]);
            low++;
            i++;
        }
        else if(a[i] == 2){
            swap(a[i],a[high]);
            high--;
        } 
        else    
            i++;
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
    sort_0_1_2(a,n);
    print(a,n);
}