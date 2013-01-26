#include "d_node.h"
#include "card.h"
#include <cstdlib>
#include <string> 
#include <iostream> 


class deck {
    public:
        deck();
        node<card>* getFirst();
        void setFirst(node<card>* newFirst);
        friend std::ostream& operator<<(std::ostream& out, deck d);
    private:
        node<card>* first;
};

// Constructor
deck::deck() {
    // Initialize deck of 52 cards
    // For each number value
    node<card>* prevNode;
    for(unsigned int i = 0; i < sizeof(values)/sizeof(std::string); i++) {
        // For each suit value
        for(unsigned int j = 0; j < sizeof(suits)/sizeof(std::string); j++) {
            // Create a new card and add it to the deck
            card currentCard(i, j);
            node<card>* currentNode = new node<card>(currentCard);
            if(i == 0 && j == 0) {
                first = currentNode; // set as first
            } else {
                prevNode->next = currentNode;
            }
            prevNode = currentNode;
        }
    }


            
}

// Getters and setters for private variables
node<card>* deck::getFirst() {
    return first;
}

void deck::setFirst(node<card>* newFirst) {
    first = newFirst;
}

// Outstream operator
std::ostream& operator<<(std::ostream &out, const deck d) {
    node<card>* currentNode = d.first;
    while(currentNode != NULL) {
        out << currentNode->nodeValue << "\n";
        currentNode = currentNode->next;
    }
    return out;
}
