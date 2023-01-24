#include <iostream>
#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include "CIndividual.h"

int main(int argc, char *argv[] ){
    int myValues[] = {5,1,4,3};
    int mySizes[] = {4,1,3,2};
    int myValues2[] = {10, 40, 30, 50, 14, 20, 9, 19};
    int mySizes2[] = {5, 4, 6, 3, 5, 2, 6, 8};
    CKnapsackProblem myKnapsackProblem = CKnapsackProblem( 5, 4, myValues, mySizes);    
    CGeneticAlgorithm myGeneticAlgorithm = CGeneticAlgorithm( 100, 0.5, 0.1, &myKnapsackProblem);
    myGeneticAlgorithm.vCalculateIterations(1);
    std::cout << "Best solution: ";
    myGeneticAlgorithm.cGetBestSolution().vPrintGenotype();
    std::cout << "Value: " << myGeneticAlgorithm.cGetBestSolution().iFitness(&myKnapsackProblem) << "\n";

    std::cout << "\nSecond problem:\n";
    CKnapsackProblem myKnapsackProblem2 = CKnapsackProblem(30, 8, myValues2, mySizes2);
    myGeneticAlgorithm.vSetKnapsack(&myKnapsackProblem2);

    myGeneticAlgorithm.vCalculateIterations(4);
    std::cout << "Best solution second problem: ";
    myGeneticAlgorithm.cGetBestSolution().vPrintGenotype();
    std::cout << "Value: " << myGeneticAlgorithm.cGetBestSolution().iFitness(&myKnapsackProblem2) << "\n";
   
    return 0;
}
