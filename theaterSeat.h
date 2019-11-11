#ifndef THEATERSEAT_H
#define THEATERSEAT_H

#include "base.h"


class theaterSeat : public base
{
    public:
        // Constructor essentially just calls the base class constructor
        theaterSeat(int r, char s, bool res, char t):base(r, s, res, t){};
        virtual ~theaterSeat();

        // Mutator methods
        void setUp(theaterSeat* u){up = u;}
        void setDown(theaterSeat* d){down = d;}
        void setLeft(theaterSeat* l){left = l;}
        void setRight(theaterSeat* r){right = r;}
        void setType(char t){type = t;}

        // Accessor Methods
        theaterSeat* getUp() {return up;}
        theaterSeat* getDown() {return down;}
        theaterSeat* getLeft() {return left;}
        theaterSeat* getRight() {return right;}

    protected:
        // Members
        theaterSeat* up = nullptr;
        theaterSeat* down = nullptr;
        theaterSeat* left = nullptr;
        theaterSeat* right = nullptr;

    private:
};

#endif // THEATERSEAT_H
