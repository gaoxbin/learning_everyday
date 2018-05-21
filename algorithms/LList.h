/*
 * LList.h
 *
 *  Created on: 2018年5月17日
 *      Author: Administrator
 */

#ifndef LLIST_H_
#define LLIST_H_

#if 0
#include <iostream>

#include "list_template.h"

using namespace std;

/// 单列表节点类
template <typename Elem>
class Link{
	Elem element;
	Link *next;

	Link(Elem *elemval, Link *nextval = NULL) { element = elemval; next = nextval;}
	Link(Link *nextval = NULL) { next = nextval;}
};

template <typename Elem>
class LList : public List<Elem>
{
private:
	Link<Elem> *head;
	Link<Elem> *tail;
	Link<Elem> *fence;

	int leftcnt;
	int rightcnt;

	void init() {
		head = tail = fence = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}

	void removeall() {
		while(head != NULL) {
			fence = head;
			head = head->next;
			delete fence;
		}
	}

public:
	LList(int size = DefaultListSize) { init(); }
	~LList() {removeall();}

	virtual void clear() { removeall(); init();}

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
bool LList<Elem>::insert(const Elem& item)
{
	/// 往头插
	fence->next = new Link<Elem>(item, fence->next);

	return true;
}
#endif



#endif /* LLIST_H_ */
