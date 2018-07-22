cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
project(/home/qtran/CPLUSPLUS/AlgorithmCoding)
# project(AlgorithmCodingToolBox)

add_executable(
    run    
    TestLongestIncreasingSub.h
    TestLongestIncreasingSub.cpp
    longestIncreasingSub.h
    longestIncreasingSub.cpp
    TestRandomizedQuickSorted.h
    TestRandomizedQuickSorted.cpp
    RandomizedQuickSorted.h
    majorityElementValidate.h
    majorityElementValidate.cpp
    TestmajorityElementValidate.h
    TestmajorityElementValidate.cpp
    PriorityQueueBinaryHeap.h
    TestPriorityQueueBinaryHeap.h
    TestPriorityQueueBinaryHeap.cpp
    BalanceRedBlackTree.h
    TestBalanceRedBlackTree.h
    TestBalanceRedBlackTree.cpp
    ClosestPairOfPointsOnPlane.h
    TestClosestPairOfPointsOnPlane.h
    TestClosestPairOfPointsOnPlane.cpp

    main.cpp
 )       
#  add_executable(
#      AlgorithmCodingToolBox.cpp
#  )