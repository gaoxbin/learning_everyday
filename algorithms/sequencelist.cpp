/*
 * list.cpp
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 28

typedef int Status;
typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status InitList(SqList *L)
{
	L->length = 0;

	return OK;
}

Status ListEmpty(SqList *L)
{
	Status tmp = FALSE;

	if(0 == L->length) {
		tmp = TRUE;
	}

	return tmp;
}

Status ClrearList(SqList *L)
{
//	int i = L->length;
	L->length = 0;

//	for(; i > 0; i --) {
//		L->data[i] = 0;
//	}

	return OK;
}

Status GetElem(SqList *L, int i, ElemType *e)
{
	if(L->length == 0 || i < 1 || i > L->length) {
		return FALSE;
	}

	*e = L->data[i - 1];

	return OK;
}

int LocateElem(SqList *L, ElemType e)
{
	int i = L->length - 1;

	if(i == 0) {
		return FALSE;
	}

	for(; i >= 0; i --) {
		if(L->data[i] == e) {
			return i + 1;
		}
	}

	return 0;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	int j = L->length - 1;

	if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;

	if(i < 1 || i > (L->length + 1)) {
		return ERROR;
	}

	for(; j > i - 1; j --) {
		L->data[i + 1] = L->data[i];
	}

	L->data[i - 1] = e;
	L->length ++;

	return OK;
}


Status ListDelete(SqList *L, int i, ElemType *e)
{
	int j = L->length;

	if(L->length == 0) return FALSE;
	if(i < 1 || i > L->length) return FALSE;

	*e = L->data[i - 1];

	for(; i < j; i ++) {
		L->data[i] = L->data[i + 1];
	}

	L->length --;

	return OK;
}


int ListLength(SqList *L)
{
	return L->length;
}

void ListUnion(SqList *La, SqList *Lb)
{
	int La_len = La->length;
	int Lb_len = Lb->length;
	ElemType e;

	for(int i = 0; i < Lb_len; i ++) {
		GetElem(Lb, i, &e);

		if(!LocateElem(La, e)) {
			ListInsert(La, La_len++, e);
		}
	}
}

void test_sequencelist()
{

}


