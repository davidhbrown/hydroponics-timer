#pragma once

/**
 * @brief a simple doubly-linked list node. 
 * 
 */
template <class T>
class ListNode 
{
private:
    T *_item;
    ListNode<T> *_next;
    ListNode<T> *_previous;
    template<class U>
    friend class List;
public:
    /**
     * @brief Construct a new DLL node and specify the previous DLL node
     * 
     * @param item 
     * @param previous 
     */
    ListNode(T *item, ListNode<T> *next=nullptr, ListNode<T> *previous=nullptr) : _item{item}, _next{next}, _previous{previous}{};
    /**
     * @brief get pointer to the stored item
     * 
     * @return T* 
     */
    T *item();
    /**
     * @brief 
     * 
     * @return ListNode<T>* 
     */
    ListNode<T> *next();
    /**
     * @brief reurns the previous ListNode, or nullptr if there is no previous node
     * 
     * @return ListNode<T>*  
     */
    ListNode<T> *previous();
};
