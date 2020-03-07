#pragma once

template <class T>
/**
 * @brief a simple doubly-linked list. 
 * 
 */
class DLL
{
private:
    T *_item;
    DLL<T> *_next;
    DLL<T> *_previous;

public:
    /**
     * @brief Construct a new DLL node and specify the previous DLL node
     * 
     * @param item 
     * @param previous 
     */
    DLL(T *item, DLL<T> *previous=nullptr);
    /**
     * @brief get pointer to the stored item
     * 
     * @return T* 
     */
    T *item();
    /**
     * @brief append an item to the chain of DLL nodes and return a pointer to the new node
     * 
     * @param nextItem 
     * @return DLL<T>* 
     */
    DLL<T> *append(T *nextItem);
    /**
     * @brief Traverse backwards to return a pointer to the first DLL node
     * 
     * @return DLL<T>* 
     */
    DLL<T> *first();
    /**
     * @brief returns the next DLL node, or nullptr if there is no next node
     * 
     * @return DLL<T>* 
     */
    DLL<T> *next();
    /**
     * @brief reurns the previous DLL node, or nullptr if there is no previous node
     * 
     * @return DLL<T>* 
     */
    DLL<T> *previous();
};
