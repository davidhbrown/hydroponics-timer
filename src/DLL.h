#pragma once

template <class T>
/**
 * @brief a simple doubly-linked list. 
 * 
 */
class DLL {
    private:
    T *_item;
    DLL<T> *_next;
    DLL<T> *_previous;
    public:
   
    /**
     * @brief Construct a new DLL node; can specify the previous DLL if known
     * 
     * @param item 
     * @param previous 
     */
    DLL(T *item, DLL<T> *previous=nullptr);
    T *item();
    /**
     * @brief append an item to the chain of DLL nodes and return the new node
     * 
     * @param nextItem 
     * @return DLL<T>* 
     */
    DLL<T> *append(T *nextItem);
    /**
     * @brief Traverse backwards to return the first DLL node
     * 
     * @return DLL<T>* 
     */
    DLL<T> *first();
    /**
     * @brief returns the next DLL node, or this one if there is no next node
     * 
     * @return DLL<T>* 
     */
    DLL<T> *next();
    /**
     * @brief reurns the previous DLL node, or this one if there is no previous node
     * 
     * @return DLL<T>* 
     */
    DLL<T> *previous();
};
