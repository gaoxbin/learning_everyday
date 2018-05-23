/*
 * stack.cpp
 *
 *  Created on: 2018年5月23日
 *      Author: Administrator
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int SElemType;

typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status InitStack(SqStack *s)
{
	memset(s->data, 0, sizeof(s->data));

	s->top = -1;

	return TRUE;
}

void DestroyStack(SqStack *s)
{
	memset(s->data, 0, sizeof(s->data));

	s->top = -1;
}

void ClearStack(SqStack *s)
{
	memset(s->data, 0, sizeof(s->data));

	s->top = -1;
}

Status StackEmpty(SqStack *s)
{
	if(s->top == -1) {
		return TRUE;
	}

	return FALSE;
}

Status GetTop(SqStack *s, SElemType *e)
{
	if(s->top == -1) {
		return FALSE;
	}

	*e = s->data[s->top];

	return TRUE;
}

Status Push(SqStack *s, SElemType *e)
{
	if(s->top == MAXSIZE - 1)
		return FALSE;

	s->data[++(s->top)] = *e;

	return TRUE;
}

Status Pop(SqStack *s, SElemType *e)
{
	if(s->top == -1)
		return FALSE;

	*e = s->data[(s->top)--];

	return TRUE;
}

int StackLength(SqStack *s)
{
	return s->top + 1;
}

