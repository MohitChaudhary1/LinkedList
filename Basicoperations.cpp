
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
    
    void insertatkposition(int k, int data){
        if(head==NULL){
            cout<<"Empty List"<<endl;
            return;
        }
        
        Node *newnode=new Node(data);
        
        if(k==0){
            newnode->next=head;
            head=newnode;
            return;
        }
        
        else{
            Node *curr=head;
            while(curr->next!=NULL && --k){
                curr= curr->next;
            }
            if(k==0){
                newnode->next=curr->next;
                curr->next=newnode;
            }
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
    
    void reverselist(){
        Node *curr=head, *prev=NULL, *nxt=NULL;
        while(curr != NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
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
        cout<<"NULL"<<endl;
    }
};

int main()
{
    LinkedList l1=LinkedList();
    l1.insertatend(10);
    l1.insertatend(25);
    l1.insertatend(30);
    l1.insertatbeginning(15);
    l1.insertatkposition(2,50);
    l1.deletenode(10);
    l1.print();
    l1.reverselist();
    l1.print();
    return 0;
}
