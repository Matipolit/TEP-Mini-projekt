#include "CIndividual.h"
#include <iostream>
#include <stdlib.h>

void vPrintArray(int arr[], int len){
    for(int i = 0; i<len; i++){
        std::cout << arr[i];
    }
    std::cout << "\n";
}

void CIndividual::vRandomizeGenotype(){
    for(int i = 0; i<i_genotype_length; i++){
        i_genotype[i] = rand() % 2;
    }
}

void CIndividual::vCopyGenotype(int iNewGenotype[]){
     for(int i = 0; i<i_genotype_length; i++){
        i_genotype[i] = iNewGenotype[i];
    }
}

CIndividual::CIndividual(int iGenotypeLength){
    i_genotype_length = iGenotypeLength;
    i_genotype = new int[iGenotypeLength];
    vRandomizeGenotype();
}

CIndividual::CIndividual(int iGenotypeLength, int iGenotype[]){
    i_genotype_length = iGenotypeLength;
    i_genotype = new int[iGenotypeLength];
    vCopyGenotype(iGenotype);
}


CIndividual::~CIndividual(){
}

int CIndividual::iFitness(CKnapsackProblem* knapsack){
    int valueSum = 0;
    int weightSum = 0;
    int maxWeight = knapsack->iGetCapacity();
    for(int i = 0; i < i_genotype_length; i++){
        weightSum+=i_genotype[i]*knapsack->iGetWeightAt(i);

        valueSum+=i_genotype[i]*knapsack->iGetValueAt(i);
        if(weightSum > maxWeight){
            return 0;
        }
    }
    return valueSum;
}

void CIndividual::vMutate(double dMutationChance){
   for(int i = 0; i<i_genotype_length; i++){
        double randNum = (rand() % 1001)/(double)1000;
        if(randNum<dMutationChance){        
            i_genotype[i] = abs(i_genotype[i]-1);
        }
    }
}

std::pair<CIndividual, CIndividual> CIndividual::cross(CIndividual* mate){
    int crossPoint = rand() % 3 + 1;
    int child1[i_genotype_length];
    int child2[i_genotype_length];
    for(int i = 0; i<i_genotype_length; i++){
        if(i<crossPoint){
            child1[i] = i_genotype[i];
            child2[i] = mate->i_genotype[i];
        }else{
            child1[i] = mate->i_genotype[i];
            child2[i] = i_genotype[i];
        }
    }
    std::pair<CIndividual, CIndividual> children(CIndividual(i_genotype_length, child1), CIndividual(i_genotype_length, child2));
    return children;
}

void CIndividual::vSetGenotype(int *iGenotype) {
    i_genotype = iGenotype;
}


void CIndividual::vPrintGenotype(){
    vPrintArray(i_genotype, i_genotype_length);
}
