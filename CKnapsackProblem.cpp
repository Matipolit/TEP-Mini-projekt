#include "CKnapsackProblem.h"
#include <iostream>

CKnapsackProblem::CKnapsackProblem(int iCapacity, int iItemCount, int* iValues, int* iWeights){
    i_capacity = iCapacity;
    i_item_count = iItemCount;
    i_values = iValues;
    i_weights = iWeights;
    std::cout << "Inited knapsack\n";
}

CKnapsackProblem::~CKnapsackProblem() {}
