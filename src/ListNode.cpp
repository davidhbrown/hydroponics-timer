#include "ListNode.h"


template <class T>
T *ListNode<T>::item() { return _item; }

template <class T>
ListNode<T> *ListNode<T>::next()
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
ListNode<T> *ListNode<T>::previous()
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
template class ListNode<Screen>;
#include "setting/Setting.h"
template class ListNode<Setting>;