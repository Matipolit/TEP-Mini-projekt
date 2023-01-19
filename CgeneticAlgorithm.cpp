#include "CGeneticAlgorithm.h"
#include <iostream>
CGeneticAlgorithm::CGeneticAlgorithm(int iPopulationSize, double dCrossProbability, double dMutationProbability, CKnapsackProblem* cKnapsackProblem){

    i_population_size = iPopulationSize;
    d_cross_probability = dCrossProbability;
    d_mutation_probability = dMutationProbability;
    c_knapsack_problem = cKnapsackProblem;
    i_knapsack_item_count = cKnapsackProblem->iGetItemCount();
    std::cout << "Inited genetic algorith\n";
}

CGeneticAlgorithm::~CGeneticAlgorithm(){
}

void CGeneticAlgorithm::vGeneratePopulation(){
    //std::cout << "Generating population\n";
    for(int i = 0 ; i < i_population_size; i++){
        CIndividual individual = CIndividual(i_knapsack_item_count);
        c_population.push_back(individual);
    }
    //std::cout << "Generated population\n" ;
}

void CGeneticAlgorithm::vCrossPopulation(){
    //std::cout << "Crossing population\n";
    std::vector<CIndividual> newPopulation;
    int newPopulationSize = 0;
    while(newPopulationSize < i_population_size){
        bool doesCross = ((rand() % 1001)/(double)1000) < d_cross_probability;
        newPopulationSize += 2;
        int iParent1 = rand() % i_population_size;
        int iParent2 = rand() % i_population_size;
        CIndividual cParent1 = c_population[iParent1];    
        CIndividual cParent2 = c_population[iParent2];
        if(doesCross){
            std::pair<CIndividual, CIndividual> children = cParent1.cross(&cParent2);
            newPopulation.push_back(children.first);
            newPopulation.push_back(children.second);

        }else{
            newPopulation.push_back(cParent1);
            newPopulation.push_back(cParent2);
        }
    }
    c_population = newPopulation;
}

void CGeneticAlgorithm::vMutatePopulation(){
    //std::cout << "Mutating population\n";
    for(int i = 0; i< i_population_size; i++){
        c_population[i].vMutate(d_mutation_probability);
    }
}

void CGeneticAlgorithm::vCalculateIterations(int iIterations) {
    std::cout << "Calculating solutions in " << iIterations << " iterations\n";
    vGeneratePopulation();
    c_best_solution = c_population[0];
    vCheckForBetterSolution();
    for(int i = 0; i < iIterations; i++){
        //std::cout << "Iteration " << i << "\n";
        vCrossPopulation();
        vMutatePopulation();
        vCheckForBetterSolution();
    }
}

void CGeneticAlgorithm::vCheckForBetterSolution(){
    for(int i = 0; i < i_population_size; i++){
        if(c_population[i].iFitness(c_knapsack_problem) > c_best_solution.iFitness(c_knapsack_problem)){
            c_best_solution = c_population[i];
        }
    }
}

CIndividual CGeneticAlgorithm::cGetBestSolution(){
    return c_best_solution;
}
