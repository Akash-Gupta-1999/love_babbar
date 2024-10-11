#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int minimize(vector<int> a,int n,int k){
    sort(a.begin(),a.end());
    if(a.size() == 1)
        return 0;
    int tempmin,tempmax;
    int mini = a[a.size()-1] - a[0];
    for(int i =1;i<n;i++){
        if(a[i] < k)
            continue;
        tempmin = min(a[0] + k, a[i] - k);
        tempmax = max(a[i-1] + k , a[n-1] - k);
        mini = min(mini,tempmax-tempmin);
    }
    return mini;
}

int main(){
    vector<int> a;
    int n,k;
    cin>>n>>k;
    cout<<n<<endl;
    cout<<"input integers for Array : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,n);
    cout<<minimize(a,n,k);
}