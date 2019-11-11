#ifndef BASE_H
#define BASE_H

// Abstract class
class base
{
    public:
        base(){};
        // Overloaded Constructor
        base(int r, char s, bool res, char t) { row = r; seat = s; reserved = res; type = t;}

        virtual ~base(){};

        // Mutator Methods
        void setRow(int r){row = r;}
        void setSeat(char s){seat = s;}
        void setRes(bool res){reserved = res;}
        virtual void setType(char t) = 0; // Made it pure virtual to indicate class as abstract

        // Accessor Methods
        int getRow() {return row;}
        char getSeat() {return seat;}
        bool getRes() {return reserved;}
        char getType() {return type;}

    protected:
        // Members
        int row;
        char seat;
        bool reserved;
        char type;

    private:
};

#endif // BASE_H
