#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* start=nullptr;
    node* temp;
    node* ptr;
    node* new_node;
    node* preptr;
    void create();
    void display();
    void insertbeg();
    void insertend();
    void insertaft();
    void insertbef();
    void deletstart();
    void deletlast();
    void deletaft();
};
void node::create(){
    int n;
    cout<<"Enter the data for the node"<<endl;
    cin>>n;
    temp=new node;
    temp->data=n;
    temp->next=nullptr;
    start=temp;
}
void node::display(){
    ptr=start;
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void node::insertbeg(){
    int val;
    cout<<"Enter the value to be inserted"<<endl;
    cin>>val;
    new_node=new node;
    new_node->data=val;
    new_node->next=start;
    start=new_node;
}
void node::insertend(){
    int val;
    cout<<"Enter the value to be inserted"<<endl;
    cin>>val;
    new_node=new node;
    new_node->data=val;
    new_node->next=nullptr;
    ptr=start;
    while(ptr->next!=nullptr){
        ptr=ptr->next;
    }
    ptr->next=new_node;
}
void node::insertaft(){
    int val, pos;
    cout<<"Enter the value to be inserted"<<endl;
    cin>>val;
    cout<<"Enter the position"<<endl;
    cin>>pos;
    new_node=new node;
    new_node->data=val;
    ptr=start;
    preptr=ptr;
    while(preptr->data!=pos){
        preptr=ptr;
        preptr=preptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
}
void node::insertbef(){
    int val, pos;
    cout<<"Enter the value to be inserted"<<endl;
    cin>>val;
    cout<<"Enter the position"<<endl;
    cin>>pos;
    new_node=new node;
    new_node->data=val;
    ptr=start;
    node* preptr=ptr;
    while(preptr->data!=pos){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
}
void node::deletstart(){
    if(start=nullptr){
        cout<<"underflow";
    }
    else{
        ptr=start;
        start=start->next;
        cout<<"data of deleted node: "<<ptr->data;
    }
}
void node::deletlast(){
    if(start=nullptr){
        cout<<"underflow";
    }
    else{
        ptr=start;
        while(ptr->next!=nullptr){
            preptr=ptr;
            preptr->next=preptr;
        }
        preptr->next=nullptr;
        cout<<"data of deleted node: "<<ptr->data;
    }
}
void node::deletaft(){
    if(start=nullptr){
        cout<<"underflow";
    }
    else{
        int pos;
        cout<<"Enter the position"<<endl;
        cin>>pos;
        ptr=start;
        preptr=ptr;
        while(preptr->data=pos){
            preptr=ptr;
            ptr=ptr->next;
        }
        node* t1=ptr;
        preptr->next=ptr->next;
        cout<<"data of deleted node: "<<t1->data;
    }
}
int main(){
    node ll;
    ll.create();
    char ch;

    do{
        cout<<"1.Insert at the begening"<<endl;
        cout<<"2.Insert at the end"<<endl;
        cout<<"3.Insert after node"<<endl;
        cout<<"4.Insert before node"<<endl;
        cout<<"5.Delet node at start"<<endl;
        cout<<"6.Delet node at end"<<endl;
        cout<<"7.Delet node after node"<<endl;
        int choice;
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            ll.insertbeg();
            break;
            case 2:
            ll.insertend();
            break;
            case 3:
            ll.insertaft();
            break;
            case 4:
            ll.insertbef();
            break;
            case 5:
            ll.deletstart();
            break;
            case 6:
            ll.deletlast();
            break;
            case 7:
            ll.deletaft();
            break;
            default:
            cout<<"invalid choice";
        }
        cout<<"Do you want to continue? (y/n) ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
    ll.display();
}