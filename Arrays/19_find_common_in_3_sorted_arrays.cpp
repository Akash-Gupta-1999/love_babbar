#include<bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

vector <int> print_duplicate(vector<int> A,vector<int> B,vector<int> C, int n1, int n2, int n3)
        {
            int i,j,k;
            i=j=k=0;
            vector<int> ans;
            int num;
            while(i<n1 && j<n2 && k<n3){
                if(A[i] == B[j] && A[i] == C[k]){
                    if(num != A[i]){
                        ans.push_back(A[i]);
                        num = A[i];
                    }
                    i++;
                    j++;
                    k++;
                }
                else if(A[i] <= B[j] && A[i] <= C[k])
                    i++;
                else if(B[j] <= A[i] && B[j] <= C[k])
                    j++;
                else
                    k++;
            }
            return ans;
        }

int main(){
    vector<int> A,B,C;
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    for(int i = 0;i<n1;i++){
        int num;
        cin>>num;
        A.push_back(num);
    }
    for(int i = 0;i<n2;i++){
        int num;
        cin>>num;
        B.push_back(num);
    }
    for(int i = 0;i<n3;i++){
        int num;
        cin>>num;
        C.push_back(num);
    }
    print(A,n1);
    print(B,n2);
    print(C,n3);
    vector<int> ans = print_duplicate(A,B,C,n1,n2,n3);
    print(ans,ans.size());
}