#include <iostream>
#include "CKnapsackProblem.h"

#ifndef CINDIVIDUAL_H
#define CINDIVIDUAL_H

class CIndividual{
    private:
        int i_genotype_length;
        int* i_genotype;
        void vRandomizeGenotype();
        void vCopyGenotype(int iNewGenotype[]);
    public:
        CIndividual(int iGenotypeLength );
        CIndividual(int iGenotypeLength, int iGenotype[]);
        ~CIndividual();
        int iFitness(CKnapsackProblem* knapsack);
        void vMutate(double dMutationChance);
        std::pair<CIndividual, CIndividual> cross(CIndividual* mate);
        void vSetGenotype(int iGenotype[]);
        void vPrintGenotype();
};

#endif
