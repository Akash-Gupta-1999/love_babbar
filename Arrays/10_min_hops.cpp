#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int min_hops(vector<int> a,int n){
    int hops = 0;
    if(n<=1)
        return 0;
    if(a[0] >= n-1)
        return 1;
    if(a[0] == 0)
        return -1;
    int steps;
    int i = 0;
    while(i<n){
        if(i == n-1)
            return hops;
        if(a[i] >= n-1-i)
            return hops+1;
        steps = a[i];
        int max_hop = 0;
        while(steps--){
            max_hop = max(max_hop,a[i + steps] + i);
        }
        if(max_hop == i)
            return -1;
        hops++;
        i = max_hop;
    }
    return hops;
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
    cout<<min_hops(a,n);
}