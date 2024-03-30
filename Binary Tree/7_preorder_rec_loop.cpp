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
    void preorder(node* temp){
        if(temp==NULL)
            return;
        cout<<temp->value<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void preorder_it(node* temp){
        stack<node*> s;
        if(temp == NULL)
            return;
        cout<<temp->value<<" ";
        s.push(temp);
        temp = temp->left;
        while(!s.empty() || temp){
            if(temp!=NULL){
                cout<<temp->value<<" ";
                s.push(temp);
                temp = temp->left;
            }
            else{
                temp = s.top();
                s.pop();
                temp = temp->right;
            }
        }
        cout<<endl;
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
    t.preorder(t.root);
    cout<<endl;
    t.preorder_it(t.root);
}