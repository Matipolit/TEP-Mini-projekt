#include <iostream>
#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include "CIndividual.h"

int main(int argc, char *argv[] ){
    //int myValues[] = {5,1,4,3};
    //int mySizes[] = {4,1,3,2};
    int myValues[] = {20, 5, 10, 40, 15, 25};
    int mySizes[] = {1,2,3,8,7,4};
    CKnapsackProblem myKnapsackProblem = CKnapsackProblem( 10, 6, myValues, mySizes);    
    CGeneticAlgorithm myGeneticAlgorithm = CGeneticAlgorithm( 100, 0.5, 0.1, &myKnapsackProblem);
    myGeneticAlgorithm.vCalculateIterations(3000);
    std::cout << "Best solution: ";
    myGeneticAlgorithm.cGetBestSolution().vPrintGenotype();
    std::cout << "Value: " << myGeneticAlgorithm.cGetBestSolution().iFitness(&myKnapsackProblem) << "\n";
    
    return 0;
}
