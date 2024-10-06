#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

pair<int,int> getminmax(vector<int> a,int n){
    int min = INT_MAX, max = INT_MIN, i = 0;
    if(n%2 != 0){
        min = max = a[0];
        i++;
    }
    while(i<n-1){
        if(a[i] > a[i+1]){
            if(a[i] > max)
                max = a[i];
            if(a[i+1] < min)
                min = a[i+1];
        }
        else{
            if(a[i+1] > max)
                max = a[i+1];
            if(a[i] < min)
                min = a[i];
        }  
        i+=2;
    }
    return make_pair(min,max);
}

int main(){
    vector<int> a;
    int n;
    cin>>n;
    cout<<n<<endl;
    cout<<"input integers : ";
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    print(a,n);
    pair<int,int> minmax  = getminmax(a,n);
    cout<<"This is minimum element : "<<minmax.first << " :: This is Maximum Element: " << minmax.second<<endl;
}