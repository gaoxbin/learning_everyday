/*
 * hash.cpp
 *
 *  Created on: 2018年5月23日
 *      Author: Administrator
 */

#include <stdio.h>

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct {
	int *elem;
	int count;
}HashTable;

int m = 0;


Status InitHashTable(HashTable *ht)
{
	m = HASHSIZE;

	ht->count = 0;
	ht->elem = (int *)malloc(sizeof(int) * m);

	for(int i = 0; i < m; i ++) {
		ht->elem[i] = NULLKEY;
	}

	return TRUE;
}

int Hash(int key)
{
	return key % m;
}

void InsertHash(HashTable *ht, int key)
{
	int addr = Hash(key);

	while(ht->elem[addr] != NULLKEY) {
		addr = (addr + 1)  % m;
	}

	ht->elem[addr] = key;
	ht->count ++;
}

Status SearchHash(HashTable *ht, int key, int *addr)
{
	*addr = Hash(key);

	while(ht->elem[*addr] != key) {
		*addr = (*addr + 1) % m;

		if(ht->elem[*addr] == NULLKEY || *addr == ht->elem[key]) {
			return FALSE;
		}
	}

	return TRUE;
}


