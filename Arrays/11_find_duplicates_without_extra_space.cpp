#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

vector<int> dupl(vector<int> &a,int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        a[a[i]%n]+=n;
    }
    for(int i=0;i<n;i++){
        if(a[i]/n > 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    vector<int> a;
    int n;
    cin>>n;
    cout<<n<<endl;
    cout<<"input integers for Array : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,n);
    vector<int> ans = dupl(a,n);
    print(ans,ans.size());
}