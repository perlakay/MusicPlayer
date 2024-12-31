#ifndef CIRCLEDLINKEDLIST_H
#define CIRCLEDLINKEDLIST_H

#include "DNode.h"

class CircleDLinkedList {
private:
    DNode* cursor; // Pointer to the current node
    int n;         // Number of elements in the list

public:
    CircleDLinkedList();
    ~CircleDLinkedList();

    bool empty() const;
    int size() const;

    void add(const Song& song);
    void remove();
    void advance();
    void retreat();
    Song getCurrentSong() const;

    void print(bool forward = true) const;

};

#endif
