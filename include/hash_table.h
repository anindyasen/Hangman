#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__
typedef struct index_list_{
    int idx;
    struct index_list *next;
}index_list_t;

typedef struct hashdata_ {
    index_list_t *head;    
}hashdata_t;

typedef struct hashtable_{
    hashdata_t tbl[26];
}hashtable_t;


//insert beginning of linklist
int list_add_start(index_list_t **head, int data);

//delete from begining of the linklist
int32_t list_delete_start(index_list_t **head);

//insert in hash table
void hash_insert(char data, int idx);

//delete in hash table
int32_t hash_del(char data);

//search in hash table
uint8_t hash_search(char data);

uint8_t is_empty(char data);

#endif //__HASH_TABLE_H__
