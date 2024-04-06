#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        prices.push_back(price);
    }
    int run_min = prices[0];
    int profit = 0;
    for(int i=1;i<prices.size();i++){
        profit = max(profit,prices[i]-run_min);
        run_min = min(run_min,prices[i]);
    }
    cout<<profit<<endl;
}