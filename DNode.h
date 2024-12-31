#ifndef DNODE_H
#define DNODE_H

#include "Song.h"

class DNode {
private:
    Song elem;       // Song element stored in the node
    DNode* next;     // Pointer to next node
    DNode* prev;     // Pointer to previous node

    static int activeNodes; // Static member to track active nodes

public:
    DNode(const Song& e, DNode* p = nullptr, DNode* n = nullptr);
    ~DNode();

    friend class CircleDLinkedList; // Grant access to CircleDLinkedList
};

#endif
