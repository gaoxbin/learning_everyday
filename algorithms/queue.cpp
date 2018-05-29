/*
 * queue.cpp
 *
 *  Created on: 2018年5月29日
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

typedef struct {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;


Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;

	return TRUE;
}

Status DestroyQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;

	return TRUE;
}

Status ClearQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;

	return TRUE;
}



