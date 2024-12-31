#include "CircleDLinkedList.h"
#include <stdexcept>

// Define the static member variable
int DNode::activeNodes = 0;

// DNode implementation
DNode::DNode(const Song& e, DNode* p, DNode* n) 
    : elem(e), prev(p), next(n) { // Corrected initialization order
    DNode::activeNodes++; // Access static variable using class name
}

DNode::~DNode() {
    DNode::activeNodes--; // Access static variable using class name
}

// CircleDLinkedList implementation
CircleDLinkedList::CircleDLinkedList() : cursor(nullptr), n(0) {}

CircleDLinkedList::~CircleDLinkedList() {
    while (!empty()) remove();
}

bool CircleDLinkedList::empty() const {
    return n == 0;
}

int CircleDLinkedList::size() const {
    return n;
}

void CircleDLinkedList::add(const Song& song) {
    DNode* newNode = new DNode(song);
    if (empty()) {
        cursor = newNode;
        cursor->next = cursor;
        cursor->prev = cursor;
    } else {
        DNode* nextNode = cursor->next;
        newNode->next = nextNode;
        newNode->prev = cursor;
        cursor->next = newNode;
        nextNode->prev = newNode;
    }
    cursor = newNode;
    n++;
}

void CircleDLinkedList::remove() {
    if (empty()) return;
    DNode* toDelete = cursor;
    if (n == 1) {
        cursor = nullptr;
    } else {
        DNode* prevNode = cursor->prev;
        DNode* nextNode = cursor->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        cursor = nextNode;
    }
    delete toDelete;
    n--;
}

void CircleDLinkedList::advance() {
    if (!empty()) cursor = cursor->next;
}

void CircleDLinkedList::retreat() {
    if (!empty()) cursor = cursor->prev;
}

Song CircleDLinkedList::getCurrentSong() const {
    if (empty()) throw std::runtime_error("Playlist is empty");
    return cursor->elem;
}

void CircleDLinkedList::print(bool forward) const {
    if (empty()) {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    DNode* start = cursor;
    DNode* temp = cursor;
    do {
        std::cout << temp->elem << std::endl;
        temp = forward ? temp->next : temp->prev;
    } while (temp != start);
}
