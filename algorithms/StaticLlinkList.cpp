/*
 * StaticLlinkList.cpp
 *
 *  Created on: 2018年5月19日
 *      Author: Administrator
 */

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

typedef struct {
	ElemType data;
	int cur_pos;/* 游标(Cursor) ，为0时表示无指向 */
}Component,StaticLinkList[MAXSIZE];


Status InitList(StaticLinkList space)
{
	for(int i = 0; i < MAXSIZE; i ++) {
		space[i].cur_pos = i + 1;
	}

	space[MAXSIZE - 1] = 0;

	return TRUE;
}

int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur_pos;

	if(i) {
		space[0].cur_pos = space[i].cur_pos;
	}

	return i;
}

void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur_pos = space[0].cur_pos;
	space[0].cur_pos = k;
}

int ListLength(StaticLinkList L)
{
	int len = 1;

	int i = L[MAXSIZE - 1].cur_pos;

	while(i) {
		i = L[i].cur_pos;
		len ++;
	}

	return len;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;   /* 注意k首先是最后一个元素的下标 */

    if (i < 1 || i > ListLength(L) + 1)
       return ERROR;

    j = Malloc_SLL(L);   /* 获得空闲分量的下标 */

    if (j)
    {
		L[j].data = e;   /* 将数据赋值给此分量的data */

		for(l = 1; l <= i - 1; l++)   /* 找到第i个元素之前的位置 */
		   k = L[k].cur_pos;

		L[j].cur_pos = L[k].cur_pos;    /* 把第i个元素之前的cur赋值给新元素的cur */
		L[k].cur_pos = j;           /* 把新元素的下标赋值给第i个元素之前元素的ur */

		return OK;
    }

    return ERROR;

	return TRUE;
}

Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;

    for (j = 1; j <= i - 1; j++)
        k = L[k].cur_pos;

    j = L[k].cur_pos;
    L[k].cur_pos = L[j].cur_pos;
    Free_SSL(L, j);

	return TRUE;
}









