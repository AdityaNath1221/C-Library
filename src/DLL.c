#include "DLL.h"

int add_beg(node** head, int data){
    node* temp = (node*) malloc(sizeof(node));
    if(temp==NULL)
        return MEM_ERROR;
    temp->data = data;
    if((*head)==NULL){
        temp->next = NULL;
        temp->prev = NULL;
        (*head) = temp;
        return SUCCESS;
    }
    temp->prev = NULL;
    temp->next = (*head);
    (*head)->prev = temp;
    (*head) = temp;
    return SUCCESS;
}

int add_end(node** head, int data){
    if((*head)==NULL)
        return add_beg(head, data);
    node *temp, *curr; 
    temp = (node*) malloc(sizeof(node));
    if(temp == NULL)
        return MEM_ERROR;
    temp->data = data;
    curr = (*head);
    while(curr->next!=NULL)
        curr = curr->next;
    temp->next = NULL;
    temp->prev = curr;
    curr->next = temp;
    return SUCCESS;
}

int add_pos(node**head, int data, int pos){
    if(pos<1)
        return INVALID_POS_ERROR;
    if(pos == 1)
        return add_beg(head, data);
    node* temp = (node*) malloc(sizeof(node));
    if(temp == NULL)
        return MEM_ERROR;
    temp->data = data;
    node* curr = *head;
    int count = 1;
    while(count!=(pos-1) && curr!=NULL){
        curr=curr->next;
        count++;
    }
    if(curr == NULL)
        return POS_OOB_ERROR;
    if(curr->next == NULL){
        temp->next = NULL;
        temp->prev = curr;
        curr->next = temp;
        return SUCCESS;
    }
    temp->next = curr->next;
    temp->prev = curr;
    curr->next->prev = temp;
    curr->next = temp;
    return SUCCESS;
}

int rem_beg(node** head){
    if((*head) == NULL)
        return UNDERFLOW_ERROR;
    if((*head)->next==NULL){
        node* temp = *head;
        int data = temp->data;
        free(temp);    
        *head = NULL;
        return data; 
    }
    node* temp = *head;
    (*head) = temp->next;
    (*head)->prev = NULL;
    int data = temp->data;
    free(temp);     
    return data;
}

int rem_end(node** head){
    if((*head) == NULL)
        return MEM_ERROR;
    node* curr = *head;
    while(curr->next != NULL)
        curr = curr->next;
    node* prev = curr->prev;
    prev->next = NULL;
    int data = curr->data;
    free(curr);
    return data;
}

int rem_pos(node** head, int pos){
    if((*head)==NULL)
        return UNDERFLOW_ERROR;
    if(pos<1)
        return INVALID_POS_ERROR;
    if(pos==1)
        return rem_beg(head);
    node* curr = *head;
    int count = 1;
    while(count!=pos && curr!=NULL){
        curr = curr->next;
        count++;
    }
    if(curr==NULL)
        return POS_OOB_ERROR;
    // if(curr->next==NULL && curr->prev== NULL){
    //     return rem_beg(head);
    // }
    if(curr->next == NULL){
        curr->prev->next = NULL;
        int data = curr->data;
        free(curr);
        return data;
    }
    int data = curr->data;
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    free(curr);
    return data;
}

int display_list(node* head){
    if(head==NULL){
        printf("List is empty.\n");
        return UNDERFLOW_ERROR;
    }
    node* ptr = head;
    while(ptr!=NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return SUCCESS;
}