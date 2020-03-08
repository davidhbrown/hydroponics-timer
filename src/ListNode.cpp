#include "ListNode.h"

template <class T>
T *ListNode<T>::item() { return _item; }

template <class T>
ListNode<T> *ListNode<T>::next()
{
    return _next;
}

template <class T>
ListNode<T> *ListNode<T>::previous()
{
    return _previous;
}

#include "screen/Screen.h"
template class ListNode<Screen>;
#include "setting/Setting.h"
template class ListNode<Setting>;