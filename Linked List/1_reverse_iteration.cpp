#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

class ll{
    public:
        int size;
        node* head;
    ll(){
        head = NULL;
        size = 0;
    }
    void add_node(int data){
        node* newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        if(head == NULL)
            head = newnode;
        else{
            node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }
    void add_node_at_pos(int data,int pos){
        node* newnode = new node;
        newnode->data = data;
        newnode->next == NULL;
        if(size<pos){
            cout<<"Invalid"<<endl;
            return;
        }
        node* temp = head;
        while(pos > 2){
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
    }
    void remove_at_pos(int pos){
        if(size<pos){
            cout<<"Invalid"<<endl;
            return;
        }
        node* temp = head;
        while(pos > 2){
            temp = temp->next;
            pos--;
        }
        temp->next = temp->next->next;
        size--;
    }
    void print(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reverse(){
        node* temp = head;
        node* prev = NULL;
        node* next;
        while(temp!=NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp= next;
        }
        head = prev;
    }
    void reverse_rec(node* temp,node* prev){
        if(temp == NULL){
            head = prev;
            return;
        }
        node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        return reverse_rec(temp,prev);
    }
};

int main(){
    ll l1;
    l1.add_node(1);
    l1.add_node(2);
    l1.add_node(3);
    l1.add_node(4);
    l1.add_node(5);
    l1.add_node(6);
    l1.add_node(7);
    l1.add_node(8);
    l1.add_node(9);
    l1.print();
    l1.add_node_at_pos(10,4);
    l1.print();
    l1.add_node_at_pos(18,10);
    l1.print();
    l1.remove_at_pos(6);
    l1.print();
    l1.remove_at_pos(10);
    l1.print();
    l1.add_node_at_pos(18,12);
    l1.reverse();
    l1.print();
    l1.reverse_rec(l1.head,NULL);
    l1.print();
}