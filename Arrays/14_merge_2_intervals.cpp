#include<bits/stdc++.h>
using namespace std;

void merger(vector<vector<int>>& intervals){
    vector<vector<int>> ans;
    if(intervals.size()<2)
        return;
    sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){return a[0]<b[0];});
    ans.push_back({intervals[0][0],intervals[0][1]});
    int indx = 0,i = 1;
    while(i<intervals.size()){
        if(ans[0][1] >= intervals[i][0]){
            ans[indx][1] = max(intervals[i][1],ans[indx][1]);
        }
        else{
            ans.push_back({intervals[i][0],intervals[i][1]});
            indx++;
        }
        i++;
    }
    intervals = ans;
}

void print(vector<vector<int>>& intervals){
    for(int i=0;i<intervals.size();i++)
        cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"],";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals;
    while(n--){
        int a,b;
        cin>>a>>b;
        intervals.push_back({a,b});
    }
    print(intervals);
    merger(intervals);
    print(intervals);
}