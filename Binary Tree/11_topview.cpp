#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int value;
        node* left;
        node* right;
};

class width_tree{
    public:
        int hd;
        node* nnode;
    width_tree(node* temp,int hd){
        this->hd = hd;
        nnode = temp;
    }
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
    void top_view(node* temp){
        unordered_map<int,int> m;
        queue<width_tree*> q;
        q.push(new width_tree(temp,0));
        int mx = 0,mn = 0;
        while(!q.empty()){
            width_tree* t = q.front();
            q.pop();
            int hd = t->hd;
            if(m.find(hd) == m.end())
                m[hd] = t->nnode->value;
            if(t->nnode->left)
                q.push(new width_tree(t->nnode->left,hd-1));
            if(t->nnode->right)
                q.push(new width_tree(t->nnode->right,hd+1));
            mx = max(mx,hd);
            mn = min(mn,hd);
        }
        for(;mn<=mx;mn++)
            cout<<m[mn]<<" ";
        cout<<endl;
    }
};

int main(){
    tree t;
    t.add_node(6);
    t.add_node(1);
    t.add_node(9);
    t.add_node(10);
    t.add_node(0);
    t.add_node(2);
    t.add_node(3);
    t.add_node(4);
    t.add_node(5);
    t.add_node(5);
    t.dfs(t.root);
    cout<<endl;
    t.bfs(t.root);
    t.top_view(t.root);
}