#ifndef INCLUDED_RESOURCES_H
#define INCLUDED_RESOURCES_H

#include<iostream>
#include<iomanip>

class Resources {
    public:
        Resources(void);
        int get(char);
        void add(char);
        void remove(char, int);
        bool hasResourcesForRoad(void)          {return (get('w') >= 1 && get('o') >= 1);};
        bool hasResourcesForSettlement(void)    {return (w >= 1 && b >= 1 && s >= 1 && h >= 1);};
        bool hasResourcesForTrade(char c)       {return (get(c) >= 3);};
        void display(void);
    private:
        int h;
        int o;
        int b;
        int w;
        int s;
};

#endif