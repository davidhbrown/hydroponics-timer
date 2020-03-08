#pragma once
#include "ListNode.h"

template <class T>
class List
{
private:
    ListNode<T> *_current;

public:
    List() : _current{nullptr}{};
    /**
     * @brief get pointer to the stored item
     * 
     * @return T* 
     */
    T *get_item();
    /**
     * @brief insert an item at the head of the chain of nodes 
     * 
     * @param nextItem 
     */
    void insert(T *nextItem);
    /**
     * @brief Traverse backwards to the first node
     * 
     */
    void rewind();
    /**
     * @brief move to the next if there is one
     * 
     */
    void iter_next();
    /**
     * @brief move to the previous if there is one
     * 
     */
    void iter_previous();
    /**
     * @brief Check whether there is a next item
     * 
     * @return true if there is a next item
     * @return false when we're at the end of the list
     */
    bool has_next();
    /**
     * @brief Check whether there is a previous item
     * 
     * @return true if there is a previous item
     * @return false when we're at the beginning of the list
     */
    bool has_previous();
};
