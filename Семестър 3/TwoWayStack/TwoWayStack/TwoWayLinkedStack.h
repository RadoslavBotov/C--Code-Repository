#pragma once
//#include<iostream>
#include "StackElement.h"

template <typename T>
class TWLStack // Two Way Linked Stack
{
public:
	TWLStack();
	TWLStack(TWLStack const&);
	TWLStack& operator = (TWLStack const&);
	~TWLStack();

	bool empty() const;
	void push(T const& x);
	T pop();
	T top() const;

	void print1() const;
	void print2();

private:
	StackElement<T>* topPtr;
	void copy(StackElement<T>*);
	void eraseStack();
	void copyStack(TWLStack const&);
};

template <typename T>	// constructor
TWLStack<T>::TWLStack() : topPtr(nullptr) {}

template<typename T>
inline TWLStack<T>::TWLStack(TWLStack const& source)
{
	copyStack(source);
}

template<typename T>
inline TWLStack<T>& TWLStack<T>::operator = (TWLStack<T> const& source)
{
	if (this != &source)
	{

	}
	return *this;
}

template <typename T>	// helper for destructor
void TWLStack<T>::eraseStack()
{
	while (!empty())
		pop();
}

template <typename T> // destructor
TWLStack<T>::~TWLStack()
{
	eraseStack();
}

template <typename T>	// check if stack is empty
bool TWLStack<T>::empty() const
{
	return (topPtr == nullptr);
}

template <typename T>	// add element to stack
void TWLStack<T>::push(T const& x)
{
	StackElement<T>* newElemPtr = new StackElement<T>;
	newElemPtr->data = x;
	newElemPtr->child = topPtr;
	if (topPtr!=nullptr)
	{
		newElemPtr->parent = topPtr->parent;
		topPtr->parent = newElemPtr;
	}
	else
		newElemPtr->parent = topPtr;
	topPtr = newElemPtr;
}

template <typename T> // remove element from stack
T TWLStack<T>::pop()
{
	if (empty())
	{
		std::cerr << "Cannot remove element when stack is empty!.\n";
		return T();
	}
	if (topPtr->child != nullptr)
	{
		topPtr = topPtr->child;
		T x = topPtr->parent->data;
		delete topPtr->parent;
		topPtr->parent = nullptr;
		return x;
	}
	else
	{
		T x = topPtr->data;
		delete topPtr;
		topPtr = nullptr;
		return x;
	}
}

template <typename T>	// get data of top element of stack
T TWLStack<T>::top() const
{
	if (empty())
	{
		std::cerr << "Empty steck!\n";
		return T();
	}
	return topPtr->data;
}

template <typename T>	// deep copy stack element to stack
void TWLStack<T>::copy(StackElement<T>* toCopy)
{
	if (toCopy == nullptr)
		return;

	copy(toCopy->child);
	push(toCopy->data);
}

template <typename T>	// copy whole stack
void TWLStack<T>::copyStack(TWLStack const& stack)
{
	topPtr = nullptr;
	copy(stack.topPtr);
}

template<typename T>
inline void TWLStack<T>::print1() const
{
	StackElement<T>* tempPtr = topPtr;

	while (tempPtr != nullptr)
	{
		std::cout << tempPtr->data << " ";
		tempPtr = tempPtr->child;
	}

	std::cout << std::endl;
}

template<typename T>
inline void TWLStack<T>::print2()
{
	while (topPtr->child != nullptr)
	{
		std::cout << topPtr->data << " ";
		topPtr = topPtr->child;
	}
	std::cout << topPtr->data;

	while (topPtr->parent != nullptr)
		topPtr = topPtr->parent;

	std::cout << std::endl;
}