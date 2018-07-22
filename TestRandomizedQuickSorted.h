#pragma once
#include "RandomizedQuickSorted.h"
#include "TestRandomizedQuickSorted.h"
#include <assert.h>
class TestRandomizedQuickSorted
{
    public:
        void testSmallCases();
        void testBigCases();                        
        void testSwap();
        void testPickPivot();
};