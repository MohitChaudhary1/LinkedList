

#include <bits/stdc++.h>

using namespace std;

class LinkedList{
    struct Node{
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
    };
    
    Node *head,*tail;
    
    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    
    void deletenode(int dat){
        Node *curr=head;
        if(head->data=dat){
            head=head->next;
            free(curr);
        }
        else{
           while(curr->next->data!=dat){
            curr=curr->next;
           }
        curr=curr->next->next;
        }
    }
    
    void insertatbeginning(int data){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
        }
        newnode->next=head;
        head=newnode;
    }
    
    void insertatend(int data){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=head;
        }
        else{
            
            tail->next=newnode;
            tail=tail->next;
            // Node *curr=head;
            // while(curr->next!=NULL){
            //     curr=curr->next; 
                
            // }
            // curr->next=newnode;
        }
    }
    
    void print(){
        if(head==NULL){
            cout<<"List Empty"<<endl;
            return;
        }
        Node *cur=head;
        while(cur->next!=NULL){
            cout<<cur->data<<"->";
            cur=cur->next;
        }
        cout<<"NULL";
    }
};

int main()
{
    LinkedList l1=LinkedList();
    l1.insertatend(10);
    l1.insertatend(25);
    l1.insertatend(30);
    l1.insertatbeginning(15);
    l1.deletenode(10);
    l1.print();
    return 0;
}
