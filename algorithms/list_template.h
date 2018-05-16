/*
 * list.h
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */

#ifndef LIST_TEMPLATE_H_
#define LIST_TEMPLATE_H_

template <typename Elem> class List {

	virtual void clear() = 0;

	virtual bool insert(const Elem&) = 0;

	virtual bool append(const Elem&) = 0;

	virtual bool remove(Elem&) = 0;

	virtual void setStart() = 0;

	virtual void setEnd() = 0;

	virtual void prev() = 0;

	virtual void next() = 0;

	virtual int leftLength() const = 0;

	virtual int rightLength() const = 0;

	virtual bool setPos(int pos) = 0;

	virtual bool getValue(Elem&) = 0;

	virtual void print() const = 0;
};

#endif /* LIST_TEMPLATE_H_ */
