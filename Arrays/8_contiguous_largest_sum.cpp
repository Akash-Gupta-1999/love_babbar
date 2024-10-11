#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int max_sum(vector<int> arr,int n){
    int sum =0, ans = 0;
    int i= 0, maximum = INT_MIN;
    while(arr[i]<0 && i<arr.size()){
        maximum = max(arr[i],maximum);
        i++;
    }
    if(i == arr.size())
        return maximum;
    while(i<arr.size()){
        sum+=arr[i];
        if(sum>ans)
            ans = sum;
        if(sum<0)
            sum = 0;
        i++;
    }
    return ans;
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