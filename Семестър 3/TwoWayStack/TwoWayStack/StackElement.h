#pragma once

template <typename T>
struct StackElement
{
public:
	T data;
	StackElement<T>* child;
	StackElement<T>* parent;
};