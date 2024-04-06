#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void next_permutation(vector<int>& num){
    int idx = -1;
    for(int i = num.size()-2;i>=0;i--){
        if(num[i] < num[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(num.begin(),num.end());
        return;
    }
    sort(num.begin()+idx+1,num.end());
    for(int i = idx+1;i<num.size();i++){
        if(num[i]>num[idx]){
            swap(num[i],num[idx]);
            break;
        }
    }
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
    next_permutation(a);
    print(a,n);
}