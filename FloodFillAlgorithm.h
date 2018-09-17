#pragma once
#include <iostream>
#include <vector>
using namespace std;
class FloodFill
{
    public:
        void floodFillUntil(vector<vector<int>> screen, int x, int y, int prevColor, int newColor);
};