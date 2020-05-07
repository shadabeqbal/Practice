//Linked List
//Author: Shadab Eqbal

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
void delete_at_pos(struct node **p,int pos){
    struct node *temp = *p;
    struct node *temp1;
    pos--;
    while(pos--){
        temp=temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}
void delete_front(struct node **p){
    if(*p != NULL){
        struct node *temp=*p;
        *p = (*p)->next;
        delete(temp);
    }
}
void delete_rear(struct node **p){
    struct node *temp= *p;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    struct node *x = temp;
    x=x->next;
    temp->next=NULL;
    delete(x);
}
void reverse(struct node **p){
    struct node *temp,*temp1;
    temp = *p;
    temp1 = *p;
    temp = temp->next;
    temp1->next = NULL;
    while(temp != NULL){
        temp1 = temp->next;
        temp->next = *p;
        *p = temp;
        temp = temp1;
    }

}
void insert_at_pos(struct node **p,int data,int pos){
    pos--;
    struct node *temp,*temp1;
    temp1 = *p;
    temp = new node();
    temp->data = data;
    while(pos--){
        temp1=temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}
void ll_insert_beg(struct node **p,int data){
    struct node *temp;
    temp = new node();
    temp->data = data;
    temp->next = *p;
    *p = temp;
}
void ll_insert(struct node **p, int data)
{
    struct node *temp,*temp1;
    if (*p == NULL)
    {
        temp = new node();
        temp->data = data;
        temp->next = NULL;
        *p = temp;
    }
    else
    {
        temp1 = *p;
        temp = new node();
        temp->data = data;
        temp->next = NULL;
        while(temp1->next != NULL)
            temp1=temp1->next;
        
        temp1->next = temp;

    }
}
void display(struct node *p){
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    struct node *head = NULL;
    int n,num,pos;
    while(1){
        cout<<"1.Insert At End\n"
        "2.Insert At Beginning\n"
        "3.Insert At Position\n"
        "4.Delete At front\n"
        "5.Delete At Rear\n"
        "6.Delete At Position\n"
        "7.Reverse Linked List\n"
        "8.Display\n"
        "9.Exit\n"
        "Enter Choice: ";
        cin>>n;
        switch(n){
            case 1:
                cout<<"Enter Number: ";
                cin>>num;
                ll_insert(&head,num);
                cout<<num<<" Inserted Successfully\n";
                break;
            case 2:
                cout<<"Enter Number: ";
                cin>>num;
                ll_insert_beg(&head,num);
                cout<<num<<" Inserted Successfully\n";
                break;
            case 3:
                cout<<"Enter Number: ";
                cin>>num>>pos;
                insert_at_pos(&head,num,pos);
                cout<<num<<" Inserted Successfully\n";
                break;
            case 4:
                delete_front(&head);
                cout<<"Deleted Successfully\n";
                break;
            case 5:
                delete_rear(&head);
                cout<<"Deleted Successfully\n";
                break;
            case 6:
                cout<<"Enter Position: ";
                cin>>pos;
                delete_at_pos(&head,pos);
                cout<<"Deleted Successfully\n";
                break;
            case 7:
                reverse(&head);
                cout<<"Linked List Reversed\n";
                break;
            case 8:
                display(head);
                break;
            case 9:
                exit(0);
        }
    }
    
}