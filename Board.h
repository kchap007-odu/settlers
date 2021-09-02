#ifndef INCLUDED_BOARD_H
#define INCLUDED_BOARD_H

#include<iostream>
#include<iomanip>
#include<fstream>
#include "constants_and_macros.h"

const int NUM_ROWS = 11;
const int NUM_COLS = 11;
const int SPACING = 4;
const int NUM_RESOURCES = 5;
const char ROAD_HORZ = '|';
const char ROAD_VERT = '-';
const char RESOURCE_TYPES[6] = "wbsoh";
const char INIT_RESOURCES[26] = "bsbwwwshhswoowhbbhohsobos";
// Defined in constants_and_macros.h
extern int randBetween(int, int);

class Board {
    public:
        Board(void);
        void setInitConfig(void);
        bool isLocationOnBoard(int r, int c)        {return ((r >= 0) && (c >= 0) && (r < NUM_ROWS) && (c < NUM_COLS));};
        bool isLocationValid(int, int, char);
        bool isRoadValid(int, int);
        bool isRoadValid(int, int, char);
        bool isSettlementValid(int, int);
        char getNextResource(int&);
        bool isOccupied(int r, int c)               {return getState(r, c) != ' ';};
        void setState(int r, int c, char a)         {state[r][c] = a;};
        void setState(int r, int c)                 {state[r][c] = (r % 2 == 0) ? '-' : '|';};
        char getState(int r, int c)                 {return (isLocationOnBoard(r, c) ? state[r][c] : ' ');};
        void print(void);
    private:
        char state[NUM_ROWS][NUM_COLS];
};

#endif