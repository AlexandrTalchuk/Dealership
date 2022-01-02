#include "SmartPointer.h"
template<class T>
SmartPointer<T>::SmartPointer(T* obj) {
	if (!obj) smartptr = NULL;
	else {
		smartptr = new Counter<T>;
		smartptr->obj = obj;
		smartptr->count = 1;
	}
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj) {
	smartptr = obj.smartptr;
	if (smartptr)
		smartptr->count++;
}

template<class T>
SmartPointer<T>::~SmartPointer() {
	if (smartptr) {
		smartptr->count--;
		if (smartptr->count <= 0) {
			delete smartptr->obj;
			delete smartptr;
		}
	}
}

template <class T>
T* SmartPointer<T>::operator->() const {
	if (smartptr) return smartptr->obj;
	else return NULL;
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& obj) {
	if (smartptr) {
		smartptr->count--;
		if (smartptr->count <= 0) {
			delete smartptr->obj;
			delete smartptr;
		}
	}
	smartptr = obj.smartptr;
	if (smartptr) smartptr->count++;
	return *this;
}