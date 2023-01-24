#include <iostream>
#include <vector>
#include "CIndividual.h"
#include "CKnapsackProblem.h"

#ifndef CGENETIC_H
#define CGENETIC_H

class CGeneticAlgorithm{
    private:
        int i_population_size;
        int i_knapsack_item_count;
        double d_cross_probability;
        double d_mutation_probability;
        CKnapsackProblem* c_knapsack_problem = NULL;
        std::vector<CIndividual> c_population;
        CIndividual c_best_solution = NULL;
        void vCrossPopulation();
        void vMutatePopulation();
        void vCheckForBetterSolution();
    public:
        CGeneticAlgorithm(int iPopulationSize, double dCrossProbability, double dMutationProbability, CKnapsackProblem* cKnapsackProblem);
        ~CGeneticAlgorithm();
        void vSetKnapsack(CKnapsackProblem* knapsack);
        void vCalculateIterations(int iIterations);
        void vCalculateMilliseconds(int iMillisecondsPassed);
        void vCalculateCount(int iCalculationCount);
        void vGeneratePopulation();
        void vClear();
        CIndividual cGetBestSolution();

};

#endif
