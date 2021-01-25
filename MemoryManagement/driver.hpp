
/*  Program: Memory Management Simulation
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 6/2/2020
 *	Description: This program includes the MemoryManagement class, which allows us to run simulations of memory allocation heuristics. 
 *               It includes the first fit and best fit algorithms.
 *               The simulation outputs the average unused memory after 100 runs and the total running time for each algorithm.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include "MemoryManagement.hpp"

void memoryManagementMain()
{
    MemoryManagement mm;

    //running the first fit simulation once and outputting the unused memory
    cout << "Running the first fit simulation once..." << endl;
    cout << "Unused memory: " << mm.runFirstFitSimulation() << endl;
    mm.outputAvailableBlocks();

    //reseting the memory
    mm.clear(); mm.allocateHalf();
    cout << "\n\n";

    //running the best fit simulation once and outputting the unused memory
    cout << "Running the best fit simulation once..." << endl;
    cout << "Unused memory: " << mm.runBestFitSimulation() << endl;
    mm.outputAvailableBlocks();

    //reseting the memory
    mm.clear(); mm.allocateHalf();
    cout << "\n\n";

    mm.runSimulation();
}