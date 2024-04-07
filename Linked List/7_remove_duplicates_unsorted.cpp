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
    void remove_duplicate_unsorted(){
        unordered_set<int> tracker;
        node *temp = head->next,*prev = head;
        tracker.insert(head->data);
        while(temp!=NULL){
            if(tracker.find(temp->data) != tracker.end()){
                prev->next = temp->next;
            }
            else{
                tracker.insert(temp->data);
                prev = temp;
            }
            temp = temp->next;
        }
    }
};

int main(){
    ll l1;
    l1.add_node(5);
    l1.add_node(2);
    l1.add_node(2);
    l1.add_node(4);
    //l1.add_node(1);
    //l1.add_node(20);
    //l1.add_node(1);
    //l1.add_node(17);
    //l1.add_node(21);
    l1.print();
    l1.remove_duplicate_unsorted();
    l1.print();
}