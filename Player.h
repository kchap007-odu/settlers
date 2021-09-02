#ifndef INCLUDED_PLAYER_H
#define INCLUDED_PLAYER_H

#include<iostream>
#include<iomanip>
#include "Resources.h"

const int WINNING_SCORE = 5;

class Player {
    public:
        Player(char);
        char repr;
        void display(void);
        void addResource(char c)        {resources.add(c);};
        bool checkWin(void)             {return score >= WINNING_SCORE;};
        void addPoint(void)             {score++;};
        Resources resources;
    private:
        int score = 0;
};

#endif