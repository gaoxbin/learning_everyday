/*
 * linkstack.cpp
 *
 *  Created on: 2018年5月23日
 *      Author: Administrator
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
}Node, *LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitLinkStack(LinkStack *ls)
{
//	if(ls == NULL) return FALSE;
//
//	ls->count = 0;
//	ls->top = 0;

//	ls = (LinkStack)malloc(sizeof(LinkStack));
	ls->count = 0;
	ls->top = NULL;

	return TRUE;
}

Status DestroyLinkStack(LinkStack *ls)
{
	if(ls->count == 0) return FALSE;

	LinkStackPtr tmp_node;

	while(ls->count --) {
		tmp_node = ls->top;
		ls->top = ls->top->next;
		free(tmp_node);
	}

	ls->count = 0;
	return TRUE;
}

Status ClearLinkStack(LinkStack *ls)
{
	if(ls->count == 0) return FALSE;

	LinkStackPtr tmp_node;

	while(ls->count --) {
		tmp_node = ls->top;
		ls->top = ls->top->next;
		free(tmp_node);
	}

	ls->count = 0;
	return TRUE;
}

Status StackEmpty(LinkStack *ls)
{
	if(ls->count == 0) return TRUE;

	return FALSE;
}

Status GetTop(LinkStack *ls, ElemType *e)
{
	if(ls->count == 0) return FALSE;

	*e = ls->top->data;

	return TRUE;
}

Status Push(LinkStack *s, ElemType e)
{
	LinkStackPtr n = (LinkStackPtr)malloc(sizeof(Node));
	n->data = e;

	n->next = s->top;
	s->top = n;
	s->count ++;

//	while(-- m) {
//		n = n->next;
//	}
//
//	n->next = ;
//	n->data = e;
//	s->count ++;

	return TRUE;
}

Status Pop(LinkStack *s, ElemType *e)
{
	if(s->count == 0) return FALSE;

	*e = s->top->data;

	LinkStackPtr n = s->top;
	s->top = s->top->next;
	free(n);

	s->count --;

	return TRUE;
}

int StackLength(LinkStack *s)
{
	return s->count;
}




