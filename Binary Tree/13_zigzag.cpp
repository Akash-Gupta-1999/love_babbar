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
    tree(){
        root = NULL;
        size = 0;
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
    void zigzag(node* temp){
        stack<node*> s,is;
        s.push(temp);
        bool flag = true;
        while(!s.empty()){
            node* t = s.top();
            s.pop();
            cout<<t->value<<" ";
            if(flag){
                if(t->left)
                    is.push(t->left);
                if(t->right)
                    is.push(t->right);
            }
            else{
                if(t->right)
                    is.push(t->right);
                if(t->left)
                    is.push(t->left);
            }
            if(s.empty()){
                swap(s,is);
                flag = !flag;
            }
        }
    }
};

int main(){
    tree t;
    t.add_node(20);
    t.add_node(15);
    t.add_node(25);
    t.add_node(10);
    t.add_node(18);
    t.add_node(16);
    t.add_node(17);
    t.add_node(9);
    t.add_node(11);
    t.add_node(22);
    t.add_node(26);
    t.add_node(19);
    t.dfs(t.root);
    cout<<endl;
    t.bfs(t.root);
    t.zigzag(t.root);
}