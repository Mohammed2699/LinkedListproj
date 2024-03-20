#include<iostream>
#include "LinkedList.h"
using namespace std;
template <class Mo>
Node<Mo>::Node(Mo val) {
    value = val;
    next = nullptr;
}
template<class T>
Node<T>::Node() {
    next = nullptr;
}
template<class Mo>
Mo LinkedList<Mo>::GetMinimumValue()
{
    return head->value;
}
template <class Mo>
LinkedList<Mo>::LinkedList()
{
    head = NULL;
    tail = NULL;
    Size = 0;
}
template <class Mo>
void LinkedList<Mo>::display()
{
    Node<Mo>* temp = head;
    while (temp != NULL) {
        cout << temp->value;
        cout<<endl;
        temp = temp->next;
    }
}
template <class Mo>
void LinkedList<Mo>::Append(Mo InsertedValue)
{
    Node<Mo>* Ptr = new Node<Mo>(InsertedValue);
    if (!Size) {
        head = tail = Ptr;
    } else {
        Node<Mo>* TP = head;
        if (TP->value >= InsertedValue) {
            Ptr->next = TP;
            head = Ptr;
        } else {
            while (TP != NULL) {
                if (TP->next == NULL) {
                    TP->next = Ptr;
                    Ptr->next = NULL;
                    tail = Ptr;
                    break;
                }
                if (TP->next->value >= InsertedValue) {
                    Ptr->next = TP->next;
                    TP->next = Ptr;
                    break;
                }
                TP = TP->next;
            }
        }
    }
    Size++;
}


template<class Mo>
void LinkedList<Mo>::merge(LinkedList MergeList)
{
    Node <Mo>* temp = MergeList.head;
    while (temp != NULL) {
        Append(temp->value);
        temp = temp->next;
    }
}

template<class Mo>
LinkedList<Mo> LinkedList<Mo>::intersection(LinkedList<Mo>list1) {
    LinkedList<Mo> newList;
    Node<Mo>* temp1 = head;
    Node<Mo>* temp2 = list1.head;
    Mo lastInsertedValue;
    bool isFirstInsertion = true;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->value == temp2->value) {
            if (isFirstInsertion || lastInsertedValue != temp1->value) {
                newList.Append(temp1->value);
                lastInsertedValue = temp1->value;
                isFirstInsertion = false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->value < temp2->value) {

            temp1 = temp1->next;
        } else {
            temp2 = temp2->next;
        }
    }
    return newList;
}
