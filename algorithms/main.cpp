/*
 * main.cpp
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */

#include "AList.h"

void test_alist()
{
	AList<int> alist;

	alist.setStart();

	alist.insert(100);
	alist.insert(99);
	alist.insert(98);
	alist.insert(97);

	alist.setPos(2);

	alist.print();
}

int main(int argc, char **argv)
{
	test_alist();

	return 0;
}
