/*
 * hash.h
 *
 *  Created on: 2018年5月18日
 *      Author: Administrator
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list_template.h"

typedef struct HashTable HashTable;

/* new an instance of HashTable */
HashTable* hash_table_new();

/*
delete an instance of HashTable,
all values are removed auotmatically.
*/
void hash_table_delete(HashTable* ht);

/*
add or update a value to ht,
free_value(if not NULL) is called automatically when the value is removed.
return 0 if success, -1 if error occurred.
*/
#define hash_table_put(ht,key,value) hash_table_put2(ht,key,value,NULL);
int hash_table_put2(HashTable* ht, char* key, void* value, void(*free_value)(void*));

/* get a value indexed by key, return NULL if not found. */
void* hash_table_get(HashTable* ht, char* key);

/* remove a value indexed by key */
void hash_table_rm(HashTable* ht, char* key);


#define TABLE_SIZE (1024*1024)

/// node info
struct kv
{
    struct kv* next;
    char* key;
    void* value;
    void(*free_value)(void*);
};

/* HashTable */
struct HashTable
{
    struct kv ** table;
//    struct kv * table;
};

/* constructor of struct kv */
static void init_kv(struct kv* kv)
{
    kv->next = NULL;
    kv->key = NULL;
    kv->value = NULL;
    kv->free_value = NULL;
}

/* destructor of struct kv */
static void free_kv(struct kv* kv)
{
    if (kv) {
        if (kv->free_value) {
            kv->free_value(kv->value);
        }
        free(kv->key);
        kv->key = NULL;
        free(kv);
    }
}

/* the classic Times33 hash function */
static unsigned int hash_33(char* key)
{
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + hash + *key++;
    }
    return hash;
}

/* new a HashTable instance */
HashTable* hash_table_new()
{
    HashTable * ht = (HashTable *)malloc(sizeof(HashTable));
    if (NULL == ht) {
        hash_table_delete(ht);
        return NULL;
    }

    ht->table = (struct kv **)malloc(sizeof(struct kv*) * TABLE_SIZE);
    if (NULL == ht->table) {
        hash_table_delete(ht);
        return NULL;
    }

    memset(ht->table, 0, sizeof(struct kv*) * TABLE_SIZE);

    return ht;
}

/* delete a HashTable instance */
void hash_table_delete(HashTable* ht)
{
    if (ht) {
        if (ht->table) {
            int i = 0;
            for (i = 0; i<TABLE_SIZE; i++) {
                struct kv* p = ht->table[i];
                struct kv* q = NULL;
                while (p) {
                    q = p->next;
                    free_kv(p);
                    p = q;
                }
            }
            free(ht->table);
            ht->table = NULL;
        }
        free(ht);
    }
}

/* insert or update a value indexed by key */
int hash_table_put2(HashTable* ht, char* key, void* value, void(*free_value)(void*))
{
    int i = hash_33(key) % TABLE_SIZE;
    struct kv* p = ht->table[i];
    struct kv* prep = p;

    while (p) { /* if key is already stroed, update its value */
        if (strcmp(p->key, key) == 0) {
            if (p->free_value) {
                p->free_value(p->value);
            }
            p->value = value;
            p->free_value = free_value;
            break;
        }
        prep = p;
        p = p->next;
    }

    if (p == NULL) {/* if key has not been stored, then add it */
        char* kstr = (char *)malloc(strlen(key) + 1);
        if (kstr == NULL) {
            return -1;
        }
        struct kv * kv = (struct kv *)malloc(sizeof(struct kv));
        if (NULL == kv) {
            free(kstr);
            kstr = NULL;
            return -1;
        }
        init_kv(kv);
        kv->next = NULL;
        strcpy(kstr, key);
        kv->key = kstr;
        kv->value = value;
        kv->free_value = free_value;

        if (prep == NULL) {
            ht->table[i] = kv;
        }
        else {
            prep->next = kv;
        }
    }
    return 0;
}

/* get a value indexed by key */
void* hash_table_get(HashTable* ht, char* key)
{
    int i = hash_33(key) % TABLE_SIZE;
    struct kv* p = ht->table[i];
    while (p) {
        if (strcmp(key, p->key) == 0) {
            return p->value;
        }
        p = p->next;
    }
    return NULL;
}

/* remove a value indexed by key */
void hash_table_rm(HashTable* ht, char* key)
{
    int i = hash_33(key) % TABLE_SIZE;

    struct kv* p = ht->table[i];
    struct kv* prep = p;
    while (p) {
        if (strcmp(key, p->key) == 0) {
            free_kv(p);
            if (p == prep) {
                ht->table[i] = NULL;
            }
            else {
                prep->next = p->next;
            }
        }
        prep = p;
        p = p->next;
    }
}


#endif /* HASHTABLE_H_ */
