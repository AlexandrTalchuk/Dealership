#pragma once
#include<iostream>
using namespace std;
template<class T>
struct Counter 
{
	T* obj;
	int count = 0;
};

template<class T>
class SmartPointer 
{
Counter<T>* smartptr;
public:
	SmartPointer(T* obj = 0);
	SmartPointer(const SmartPointer&);
	~SmartPointer();
	SmartPointer& operator=(const SmartPointer&);
	T* operator->() const;
	void ShowCount() { cout << smartptr->count; }
};


