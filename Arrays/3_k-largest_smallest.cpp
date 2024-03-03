#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int find_smallest_k(vector<int>& a,int low,int high,int k){
    int pivot = high;
    int j = low;
    for(int i=low;i<=high-1;i++){
        if(a[i] < a[pivot]){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[pivot]);
    //print(a,a.size());
    if(j == k-1)
        return a[j];
    if(j > k-1)
        find_smallest_k(a,low,j-1,k);
    else
        find_smallest_k(a,j+1,high,k);
}

int find_largest_k(vector<int>& a,int low,int high,int k){
    int pivot = high;
    int j = low;
    for(int i=low;i<=high-1;i++){
        if(a[i] > a[pivot]){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[pivot]);
    //print(a,a.size());
    if(j == k-1)
        return a[j];
    if(j > k-1)
        find_largest_k(a,low,j-1,k);
    else
        find_largest_k(a,j+1,high,k);
}

int main(){
    vector<int> a;
    int n,k;
    cin>>n>>k;
    cout<<n<<endl;
    cout<<"input integers : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,n);
    cout<<find_largest_k(a,0,n-1,k)<<endl;
}