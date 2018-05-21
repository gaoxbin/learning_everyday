/*
 * list.h
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */

#ifndef ALIST_H_
#define ALIST_H_

#if 0
#include <iostream>

#include "list_template.h"

using namespace std;

template <typename Elem>
class AList : public List<Elem>
{
private:
	int maxSize;
	int listSize;
	int fence;
	Elem *listArray;
public:
	AList(int size = DefaultListSize);
	~AList() {delete [] listArray;}

	virtual void clear();
	virtual bool insert(const Elem&);
	virtual bool append(const Elem&);
	virtual bool remove(Elem&);

	virtual void setStart() {fence = 0;}
	virtual void setEnd() {fence = maxSize;}
	virtual void prev() {if(fence != 0) fence --;}
	virtual void next() {if(fence <= listSize) fence ++;}

	virtual int leftLength() const{return fence;}
	virtual int rightLength() const{return listSize - fence;}

	virtual bool setPos(int pos) {
		if(pos >= 0 && pos <= listSize) fence = pos;
		return (pos >= 0 && pos <= listSize);
	}

	virtual bool getValue(Elem& item) {
		if(rightLength() == 0) return false;
		else item = listArray[fence];

		return true;
	}

	virtual void print() const;
};

template <typename Elem>
AList<Elem>::AList(int size)
{
	maxSize = size;
	listSize = fence = 0;

	listArray = new Elem[size];
}

template <typename Elem>
void AList<Elem>::clear()
{
	delete [] listArray;
	listSize = fence = 0;
	listArray = new Elem[maxSize];
}

template <typename Elem>
bool AList<Elem>::insert(const Elem& item)
{
	if(listSize == maxSize) return false;

	for(int i = listSize; i > fence; i--) {
		listArray[i] = listArray[i - 1];
	}

	listArray[fence] = item;
	listSize ++;

	return true;
}

template <typename Elem>
bool AList<Elem>::append(const Elem& item)
{
	if(listSize == maxSize) return false;

	listArray[listSize ++] = item;

	return true;
}

template <typename Elem>
bool AList<Elem>::remove(Elem& item)
{
	if(listSize == 0) return false;

	item = listArray[fence];

	for(int i = fence; i < listSize - 1; i ++) {
		listArray[i] = listArray[i + 1];
	}

	listSize --;

	return true;
}


template <typename Elem>
void AList<Elem>::print() const
{
	int temp = 0;

	cout << "< ";
	while(temp < fence) cout << listArray[temp++]<< " ";
	cout << "| ";
	while(temp < listSize) cout << listArray[temp++]<< " ";
	cout << ">" << endl;
}
#endif

#endif /* ALIST_H_ */
