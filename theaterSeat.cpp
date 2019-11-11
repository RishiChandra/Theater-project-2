#include "theaterSeat.h"

// Very basic destructor
theaterSeat::~theaterSeat()
{
    // Delete the pointer if they arnt null
    // Make the nodes pointing to them know it is now deleted
    if (up != nullptr){
        up->setDown(nullptr);
        delete up;
    }
    if (down != nullptr){
        down->setUp(nullptr);
        delete down;
    }
    if (left != nullptr){
        left->setRight(nullptr);
        delete left;
    }
    if (right != nullptr){
        right->setLeft(nullptr);
        delete right;
    }
}
