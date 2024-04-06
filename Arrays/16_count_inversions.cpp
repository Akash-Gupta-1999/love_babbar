#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int merger(vector<int>& a,vector<int>& temp,int low,int mid,int high){
    int count = 0;
    int i = low,j = mid,k = low;
    while(i<=(mid-1) && j<=high){
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            count+=mid-i;
        }
    }
    while(i<=(mid-1)){
        temp[k++] = a[i++];
    }
    while(j<=high){
        temp[k++] = a[j++];
    }
    for(int i = low;i<=high;i++)
        a[i] = temp[i];
    return count;
}

int _merge_sort(vector<int>& a,vector<int>& temp,int low,int high){
    int inv_count = 0;
    if(low<high){
        int mid = low + (high-low)/2;
        inv_count+=(_merge_sort(a,temp,low,mid));
        inv_count+=(_merge_sort(a,temp,mid+1,high));
        inv_count+=(merger(a,temp,low,mid+1,high));
    }
    return inv_count;
}

int count_inversions(vector<int> a){
    int n = a.size();
    vector<int> temp(n,0);
    return _merge_sort(a,temp,0,n-1);
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
    cout<<count_inversions(a);
}
