#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int value;
        node* left;
        node* right;
};

class tree{
    public:
        node* root;
        int size;
        bool flag;
    tree(){
        root = NULL;
        size = 0;
        flag = true;
    }
    void find_node(node* newnode,node* temp){
        if(newnode->value < temp->value){
            if(temp->left!=NULL)
                find_node(newnode,temp->left);
            else    
                temp->left = newnode;
        }   
        else{
            if(temp->right!=NULL)
                find_node(newnode,temp->right);
            else    
                temp->right = newnode;
        }          
    }
    void add_node(int num){
        node* newnode = new node;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->value = num;
        if(root == NULL)
            root = newnode;
        else    
            find_node(newnode,root);
        size++;
    }
    void dfs(node* temp){
        if(temp==NULL)
            return;
        dfs(temp->left);
        cout<<temp->value<<" ";
        dfs(temp->right);
    }
    
    void bfs(node* temp){
        queue<node*> q;
        q.push(temp);
        while(q.empty() == false){
            node* t = q.front();
            cout<<t->value<<" ";
            q.pop();
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        cout<<endl;
    }
    int checker(node* root){
        if(root == NULL)
            return 0;
        int lh=0,rh=0;
        if(flag)
            lh = checker(root->left);
        if(flag)
            rh = checker(root->right);
        if(abs(lh-rh) > 1)
            flag = false;
        return (1+max(lh,rh));
    }

    void checkbalance(node* root){
        checker(root);
        if(flag)
            cout<<"Balanced"<<endl;
        else   
            cout<<"Not Balanced"<<endl;
    }
};

int main(){
    tree t;
    t.add_node(10);
    t.add_node(5);
    //t.add_node(39);
    t.add_node(1);
    //t.add_node(18);
    cout<<endl;
    t.bfs(t.root);
    t.checkbalance(t.root);
}