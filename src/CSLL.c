#include "CSLL.h"

int add_beg(node** head, int data){
    node* temp = (node*) malloc(sizeof(node));
    if(temp==NULL)
        return MEM_ERROR;
    temp->data = data;
    if((*head)==NULL){
        *head = temp;
        temp->next = *head;
        return SUCCESS;
    }
    node* ptr = (*head);
    while(ptr->next!=(*head))
        ptr=ptr->next;
    temp->next = (*head);
    *head = temp;
    ptr->next = *head;
    return SUCCESS;
}

int add_end(node** head, int data){
    if(*head==NULL)
        return add_beg(head, data);
    node *temp = (node*) malloc(sizeof(node));
    if(temp == NULL)
        return MEM_ERROR;
    temp->data = data;
    node* ptr = *head;
    while(ptr->next!=*head)
        ptr=ptr->next;
    temp->next = *head;
    ptr->next = temp;
    return SUCCESS;
}

int add_pos(node** head, int data, int pos){
    if(pos<1)
        return INVALID_POS_ERROR;
    if(pos==1)
        return add_beg(head, data);
    node* temp = (node*) malloc(sizeof(node));
    if(temp==NULL)
        return MEM_ERROR;
    temp->data = data;
    int c = 1;
    node* ptr = *head;
    while(c!=pos-1 && ptr->next!=*head){
        ptr=ptr->next;
        c++;
    }
    if(ptr->next==*head)
        return POS_OOB_ERROR;
    temp->next = ptr->next;
    ptr->next = temp;
    return SUCCESS;
}

int rem_beg(node** head){
    if(*head==NULL)
        return UNDERFLOW_ERROR;
    if((*head)->next = *head){
        int data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }
    node* ptr = *head;
    while(ptr->next!=*head)
        ptr=ptr->next;
    int data = (*head)->data;
    ptr->next = (*head)->next;
    free(*head);
    *head = ptr->next;
    return data;
}

int rem_end(node** head){
    if(*head == NULL)
        return UNDERFLOW_ERROR;
    if((*head)->next == *head)
        return rem_beg(head);
    node *ptr = *head;
    while(ptr->next->next!=*head)
        ptr=ptr->next;
    node* temp = ptr->next;
    int data = temp->data;
    ptr->next = *head;
    free(temp); 
    return data;
}

int rem_pos(node** head, int pos){
    if(*head==NULL)
        return UNDERFLOW_ERROR;
    if(pos<1)
        return INVALID_POS_ERROR;
    if(pos==1)
        return rem_beg(head);
    node* ptr = *head;
    int c = 1;
    while(c!=pos-1 && ptr->next!=*head){
        ptr = ptr->next;
        c++;
    }
    if(ptr->next==*head)
        return POS_OOB_ERROR;
    node *temp = ptr->next;
    int data = temp->data;
    ptr->next = temp->next;
    free(temp);
    return data;
}

int display_list(node* head){
    if(head==NULL)
        return UNDERFLOW_ERROR;
    node* ptr = head;
    do{
        printf("%d -> ", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("NULL\n");
}

int search(node* head, int key){
    if (head == NULL)
        return UNDERFLOW_ERROR;
    int pos = 1;
    node* ptr = head;
    do{
        if(ptr->data == key)
            return pos;
        ptr = ptr->next;
        pos++;
    }while(ptr!=head); 
    return ELE_NOT_FOUND_ERROR;
}

int reverse(node** head){
    if(*head == NULL)
        return UNDERFLOW_ERROR;
    if((*head)->next==*head)
        return SUCCESS;
    node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    node *curr, *prev, *next;
    prev = last;
    curr = *head;
    do{
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }while(curr!=*head);
    *head = prev;
    return SUCCESS;
}