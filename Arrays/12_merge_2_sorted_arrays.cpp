#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

vector<int> merge(vector<int> a,vector<int> b){
    vector<int> ans;
    int m = a.size(),n = b.size();
    int i=0,j = 0;
    while(i<m && j<n){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<m){
        ans.push_back(a[i]);
        i++;
    }
    while(j<n){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

int main(){
    vector<int> a,b;
    int m,n;
    cin>>m>>n;
    cout<<m<<" "<<n<<endl;
    cout<<"input integers for Array 1 : ";
    for(int i = 0;i<m;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,m);
    cout<<"input integers for Array 2 : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        b.push_back(num);
    }
    print(b,n);
    vector<int> ans = merge(a,b);
    print(ans,ans.size());
}