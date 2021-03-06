/*
 * Hash Table: Implemented as a array of linklist of size 21 (total no. of 
 * alphabet). Each location of the array consists of linklist denoting the 
 * index of that alphabet in the selected word.
 * Eg. if at location 0 of the array there is a linked list like
 * 1-->5-->8. It means that, in the selected word 'a'(idx 0 of array) is
 * present in location 1 5 8 in the selected word
 * */

#include<ctype.h>

#include "hangman.h"
#include "hash_table.h"

//Add node in the beginning of linklist
int list_add_start(index_list_t** head, int data){
    index_list_t *newnode = malloc(sizeof(hashdata_t));
    
    if (NULL == newnode) {
        return -1;
    }
    newnode->idx = data;
    newnode->next = *head;
    *head = newnode;
    return 0;
}

//Delete node from the beginnig of linklist
int32_t list_delete_start(index_list_t **head) {
    index_list_t *tmp = NULL;
    if(NULL == *head){
        return -1;
    }
    uint32_t deleted_val = 0;
    tmp = *head;
    *(index_list_t **)head = tmp->next;
    deleted_val = tmp->idx;
    free (tmp);
    return deleted_val;
}

void hash_insert(char data, int idx){
    int err = 0;
    data = tolower(data);
    if(-1 == (err = list_add_start(&(ht->tbl[data-97].head), idx))) {
        printf("Insertion in list failed\n");
    }
}

int32_t hash_del(char data){
    data = tolower(data);
    if(!is_empty(data)){
        return (list_delete_start(&ht->tbl[data-97].head));
    }
    return -1;
}

uint8_t hash_search(char data){
    data = tolower(data);
    if(NULL != ht->tbl[data-97].head){
        return TRUE;
    }
    return FALSE;
}

uint8_t is_empty(char data) {
    data = tolower(data);
    if(NULL == ht->tbl[data-97].head){
        return TRUE;
    }
    return FALSE;
}
