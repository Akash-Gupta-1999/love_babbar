#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int max_sum(vector<int> a,int n){
    int i=0;
    while(a[i] < 0)
        i++;
    int max_so_far = 0,sum = 0;
    for(i;i<n;i++){
        if(sum<0)
            sum = 0;
        sum+=a[i];
        max_so_far=max(sum,max_so_far);
    }
    return max_so_far;
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
    cout<<max_sum(a,n);
}