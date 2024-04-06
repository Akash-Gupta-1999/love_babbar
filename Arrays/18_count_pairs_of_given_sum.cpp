#include<bits/stdc++.h>
using namespace std;

int count_pairs(vector<int> a,int k){
    int ans = 0;
    unordered_map<int,int> map;
    for(int i=0;i<a.size();i++){
        if(map.find(k-a[i]) != map.end())
            ans+=map[k-a[i]];
        map[a[i]]++;
    }
    return ans;
}

int main(){
    vector<int> a;
    int n,k;
    cin>>n>>k;
    cout<<n<<endl;
    cout<<"input integers for Array 1 : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    cout<<count_pairs(a,k);
}