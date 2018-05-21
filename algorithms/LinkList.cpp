/*
 * LinkList.cpp
 *
 *  Created on: 2018年5月19日
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node{
	ElemType data;
	Node *next;
}Node;

typedef Node *LinkList;

Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(*L == NULL) return FALSE;

	(*L)->next = NULL;

	return TRUE;
}

Status ListEmpty(LinkList L)
{
	if(L->next == NULL) return TRUE;

	return FALSE;
}

Status ClearList(LinkList *L)
{
	LinkList p,q;

	p = (*L)->next;

	while(p) {
		q = p->next;
		free(p);
		p = q;
	}

	(*L)->next = NULL;

	return TRUE;
}

int ListLength(LinkList *L)
{
	LinkList p = (*L)->next;
	int len = 0;

	while(p) {
		p = p->next;
		len ++;
	}

	return len;
}

Status GetElem(LinkList L,int i,ElemType *e)
{
	LinkList p = L->next;
	int len = 1;

	while(p && len < i) {
		p = p->next;
		len ++;
	}

	if(p == NULL || i > len)
		return FALSE;

	*e = p->data;

	return TRUE;
}

int LocateElem(LinkList L,ElemType e)
{
	int len = 1;
	LinkList p = L->next;

	while(p) {
		if(e == p->data) {
			return len;
		}
		p = p->next;
		len++;
	}

	return len;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList p = (*L)->next, tmp;
	LinkList p_new = NULL;
	int len = 1;

	while(p && len < i) {

		p = p->next;
		len ++;
	}

	if(!p && len < i) return FALSE;

	p_new = (LinkList)malloc(sizeof(Node));

//	tmp = p->next;
//	p->next = p_new;
//	p_new->next = tmp;

	p_new->next = p->next;
	p->next = p_new;
	p_new->data = e;

	return TRUE;
}

Status ListDelete(LinkList *L,int i, ElemType *e)
{
	LinkList p = (*L)->next;
	LinkList tmp;
	int len = 1;

	while(p && i > len) {
		p = p->next;

		len ++;
	}

	if(!(p->next) && i > len)
		return FALSE;


	tmp = p->next;
	p->next = tmp->next;
    *e = tmp->data;

	free(tmp);


	return TRUE;
}

void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	srand(time(0));

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for(int i = 0; i < n; i ++) {

		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;

		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	srand(time(0));

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	r = *L;

	for(int i = 0; i < n; i ++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;

		r->next = p;
		r = p;
	}

	r->next = NULL;
}

void test_LinkList()
{

}


