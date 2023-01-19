#include <iostream>
#ifndef CKNAPSACKPROBLEM_H
#define CKNAPSACKPROBLEM_H
class CKnapsackProblem{
    private:
        int i_capacity;
        int i_item_count;
        int* i_values;
        int* i_weights;
    public:
        CKnapsackProblem(int iCapacity, int iItemCount, int* iValues, int* iWeights);
        ~CKnapsackProblem();
        int iGetValueAt(int index){ return i_values[index]; }
        int iGetItemCount(){ return i_item_count; }
        int iGetWeightAt(int index){ return i_weights[index]; }
        int iGetCapacity() { return i_capacity; }
};

#endif
