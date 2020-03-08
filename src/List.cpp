#include "List.h"

/**
     * @brief get pointer to the stored item
     * 
     * @return T* 
     */
template <class T>
T *List<T>::get_item()
{
    if(nullptr == _current) { return nullptr; }
    return _current->item();
}
template <class T>
void List<T>::insert(T *nextItem){
    ListNode<T> *inserted = new ListNode<T>(nextItem, _current);
    _current->_previous = inserted;
    _current = inserted;
};
template <class T>
void List<T>::rewind(){
    while(this->has_previous()) {
        this->iter_previous();
    }
}
template <class T>
void List<T>::iter_next(){
    if(this->has_next()) {
        _current = _current->next();
    }
}
template <class T>
void List<T>::iter_previous(){
    if(this->has_previous()) {
        _current = _current->previous();
    }
}
template <class T>
bool List<T>::has_next() {
    return (nullptr != _current) && (nullptr != (_current->next()));
};
template <class T>
bool List<T>::has_previous() {
    return (nullptr != _current) && (nullptr != (_current->previous()));
}

#include "screen/Screen.h"
template class List<Screen>;
#include "setting/Setting.h"
template class List<Setting>;