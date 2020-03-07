#include "DLL.h"

template <class T>
DLL<T>::DLL(T *item, DLL<T> *previous)
{
    _item = item;
    _previous = previous;
    _next = nullptr;
};

template <class T>
T *DLL<T>::item() { return _item; }

template <class T>
DLL<T> *DLL<T>::append(T *nextItem)
{
    if (_next == nullptr)
    {
        _next = new DLL<T>(nextItem, this);
        ;
        return _next;
    }
    else
    {
        return _next->append(nextItem);
    }
}

template <class T>
DLL<T> *DLL<T>::first()
{
    if (_previous == nullptr)
    {
        return this;
    }
    else
    {
        return _previous->first();
    }
}

template <class T>
DLL<T> *DLL<T>::next()
{
    if (_next == nullptr)
    {
        return this;
    }
    else
    {
        return _next;
    }
}

template <class T>
DLL<T> *DLL<T>::previous()
{
    if (_previous == nullptr)
    {
        return this;
    }
    else
    {
        return _previous;
    }
}

#include "screen/Screen.h"
template class DLL<Screen>;
#include "setting/Setting.h"
template class DLL<Setting>;