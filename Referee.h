#ifndef INCLUDED_REFEREE_H
#define INCLUDED_REFEREE_H

#include "Player.h"
#include "Board.h"
#include <iostream>
#include "constants_and_macros.h"

class Referee {
    public:
        void doTurn(Player&, int);
        void promptForMove(Player&, bool&);
        void buildSettlement(Player&, int, int, bool&);
        void buildRoad(Player&, int, int, bool&, bool);
        void awardResources(Player&);
        void executeMove(Player&, char, bool&);
        void facilitateBuild(Player&, bool&);
        void facilitateTrade(Player&, bool&);
    private:
        Board board;
};

#endif