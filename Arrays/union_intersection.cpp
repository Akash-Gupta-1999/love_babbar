#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void union_intersect(vector<int> a,vector<int> b){
    unordered_set<int> s;
    vector<int> uni,inter;
    int m = a.size();
    int n = b.size();
    for(int i=0;i<m;i++){
        s.insert(a[i]);
        uni.push_back(a[i]);
    }  
    for(int i=0;i<n;i++){
        if(s.find(b[i]) == s.end())
            uni.push_back(b[i]);
        else    
            inter.push_back(b[i]);
    }
    print(uni,uni.size());
    print(inter,inter.size());
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
    print(a,n);
    cout<<"input integers for Array 2 : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        b.push_back(num);
    }
    print(b,n);

    union_intersect(a,b);
}