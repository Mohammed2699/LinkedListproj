#include<iostream>
using namespace std;
template <class Mo>
class Node {
public:
    Mo value;
    Node<Mo>* next;
    Node(Mo);
    Node();
};
template <class Mo>
class LinkedList
{public:
    int Size;
    Node<Mo>* head;
    Node<Mo>* tail;
    LinkedList();
    void Append(Mo);
    void display();
    Mo GetMinimumValue();
    void merge(LinkedList);
    LinkedList<Mo>intersection(LinkedList <Mo>);
};