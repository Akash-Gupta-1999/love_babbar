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
    void left_viewer(node* temp, int level, int& max_level){
        if(temp == NULL)
            return;
        if(max_level < level){
            cout<<temp->value<<" ";
            max_level = level;
        }
        left_viewer(temp->left,level+1,max_level);
        left_viewer(temp->right,level+1,max_level);
    }
    void left_view(node* temp){
        int max_level = 0;
        left_viewer(temp,1,max_level);
        cout<<endl;
    }
};

int main(){
    tree t;
    t.add_node(10);
    t.add_node(4);
    t.add_node(2);
    t.add_node(5);
    t.add_node(15);
    t.add_node(12);
    t.add_node(16);
    t.add_node(9);
    t.add_node(11);
    t.add_node(20);
    t.add_node(19);
    t.add_node(24);
    t.add_node(30);
    t.dfs(t.root);
    cout<<endl;
    t.bfs(t.root);
    t.left_view(t.root);
}