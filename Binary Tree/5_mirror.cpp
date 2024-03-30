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
    void mirroring(node* &newnode,node* left, node* right){
        if(left!=NULL){
            node* nodel = new node;
            newnode->left = nodel;
            nodel->value = left->value;
            nodel->left = nodel->right = NULL;
            mirroring(nodel,left->right,left->left);
        }
         if(right!=NULL){
            node* noder = new node;
            newnode->right = noder;
            noder->value = right->value;
            noder->left = noder->right = NULL;
            mirroring(noder,right->right,right->left);
        }
    }
    node* mirror(){
        if(root == NULL)
            return root;
        node* newnode = new node;
        newnode->value = root->value;
        newnode->left = newnode->right = NULL;
        mirroring(newnode,root->right,root->left);
        return newnode;
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
    /*t.add_node(5);
    t.add_node(3);
    t.add_node(6);
    t.add_node(2);
    t.add_node(4);*/
    t.dfs(t.root);
    cout<<endl;
    int h = 0;
    node* mir = t.mirror();
    t.dfs(mir);
}