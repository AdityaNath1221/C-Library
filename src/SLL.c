#include "SLL.h"

int add_beg(node** head, int data){
    node* temp = (node*) malloc(sizeof(node));
    if(temp==NULL){
        return MEM_ERROR;
    }
    temp->data = data;
    if((*head)==NULL){
        (*head) = temp;
        temp->next = NULL;
        return SUCCESS;
    }
    else{
        temp->next = *head;
        (*head) = temp;
        return SUCCESS;
    }
}

int add_end(node** head, int data){
    node* temp = (node*) malloc(sizeof(node));
    if(temp==NULL){
        return MEM_ERROR;
    }
    temp->data = data;
    if((*head)==NULL){
        (*head) = temp;
        temp->next=NULL;
        return SUCCESS;
    }
    else{
        temp->next = NULL;
        node* ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
        return SUCCESS;
    }
}

int add_pos(node** head, int data, int pos) {
    if (pos < 1)
        return INVALID_POS_ERROR;
    if (pos == 1)      
        return add_beg(head, data);
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
        return MEM_ERROR;
    temp->data = data;
    node* current = *head;
    int count = 1;
    while (count < pos - 1 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        free(temp); 
        return POS_OOB_ERROR;
    }
    temp->next = current->next;
    current->next = temp;      
    return SUCCESS;
}

int rem_beg(node** head){
    if((*head)==NULL){
        return UNDERFLOW_ERROR;
    }
    node* temp = *head;
    int data = temp->data;
    (*head) = temp->next;
    free(temp);
    return data;
}

int rem_end(node** head){
    if((*head)==NULL)
        return UNDERFLOW_ERROR;
    node* ptr = *head;
    if(ptr->next==NULL)
        return rem_beg(head);
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    int data = ptr->next->data;
    free(ptr->next);
    ptr->next = NULL;
    return data;
}

int rem_pos(node** head, int pos){
    if((*head)==NULL)
        return UNDERFLOW_ERROR;
    if(pos<1)
        return INVALID_POS_ERROR;
     if (pos == 1) {
        return rem_beg(head);
    }
    node* ptr = *head;
    int count = 1;
    while(count!=pos-1 && ptr!=NULL){
        ptr = ptr->next;
        count++;
    }
    if(ptr==NULL)
        return POS_OOB_ERROR;
    node* temp = ptr->next;
    int data = temp->data;
    ptr->next = temp->next;
    free(temp);
    return data;
}

int display_list(node* head){
    node* ptr = head;
    if(ptr==NULL){
        return UNDERFLOW_ERROR;
    }
    printf("\nThe contents of the list: \n");
    while(ptr!=NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return SUCCESS;
}