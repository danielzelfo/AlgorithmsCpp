#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <time.h>
#include <chrono> 

using namespace std::chrono;
using namespace std;

class MemoryManagement {
	vector<int> mMemory;
	int memoryUsage;


public:
	MemoryManagement(int size = 1024) : mMemory(size, 0), memoryUsage(0) { 
		srand(time(0));
		allocateHalf();
	}

	void clear() {
		memoryUsage = 0;
		for (int i = 0; i < mMemory.size(); i++)
			mMemory[i] = 0;
	}
	void allocateHalf() {
		int startIndex, allocateSize;
		while (memoryUsage < mMemory.size() / 2) {
			startIndex = rand() % mMemory.size();
			allocateSize = rand() % 16 + 5;
			for (int i = startIndex; i < mMemory.size() && i < startIndex + allocateSize; i++) {
				if (mMemory[i]==0) {
					mMemory[i] = 1;
					memoryUsage++;
				}
			}
		}
	}

	int runFirstFitSimulation() {
		//cout << "Running first fit algorithm simulation: " << "\n\n";
		int maxSize = 20;
		int allocateSize = rand() % 16 + 5;
		while (maxSize >= 5) {
			allocateSize = rand() % (maxSize - 5 + 1) + 5;
			if (!allocateFirstFit(allocateSize))
				maxSize--;
		}
		
		//cout << "\nUnused Memory: " << availableSpace() << endl;
		//outputAvailableBlocks();
		return availableSpace();
	}

	int runBestFitSimulation() {
		//cout << "Running best fit algorithm simulation: " << "\n\n";
		int allocateSize = rand() % 16 + 5;
		int maxSize = 20;
		while (maxSize >= 5) {
			allocateSize = rand() % (maxSize - 5 + 1) + 5;
			if (!allocateBestFit(allocateSize))
				maxSize--;
		}
		
		//cout << "\nUnused Memory: " << availableSpace() << endl;
		//outputAvailableBlocks();
		return availableSpace();
	}


	void runSimulation() {
		float totalUnusedFirst = 0, totalUnusedBest = 0;

		cout << "Running best fit simulation 100 times...\n";
		auto bestStart = high_resolution_clock::now();
		for (int i = 0; i < 100; i++) {
			totalUnusedBest += runBestFitSimulation();
			clear();
			allocateHalf();
		}
		auto bestStop = high_resolution_clock::now();
		auto bestDuration = duration_cast<milliseconds>(bestStop - bestStart);
		

		cout << "Running first fit simulation 100 times...\n\n";
		auto firstStart = high_resolution_clock::now();
		for (int i = 0; i < 100; i++) {
			totalUnusedFirst += runFirstFitSimulation();
			clear();
			allocateHalf();
		}
		auto firstStop = high_resolution_clock::now();
		auto firstDuration = duration_cast<milliseconds>(firstStop - firstStart);

		cout << "Average unused space for first fit algorithm: " << totalUnusedFirst/100 << endl;
		cout << "Running time of first fit simulation: " << firstDuration.count() << " milliseconds" << "\n\n";
		cout << "Average unused space for best fit algorithm: " << totalUnusedBest / 100 << endl;
		cout << "Running time of best fit simulation: " << bestDuration.count() << " milliseconds" << endl;
	}

	bool allocateFirstFit(int n) {
		if (n < 5 || n > 20) {
			//cout << "You can only allocate between 5 and 20 integers";
			return false;
		}


		for (int i = 0; i < mMemory.size()-n; i++) {
			
			if (mMemory[i]==0) {

				for (int j = i + 1; j < i + n; j++) {
					if (mMemory[j]!=0)
						goto next;
					
				}

				//found first fit

				//tallying used blocks
				for (int x = i; x < i + n; x++) 
					mMemory[x] = 1;
				memoryUsage += n;

				//cout << "allocated from " << i << " to " << i + n - 1 << endl;
				return true;
				
			}
		next:
			continue;
		}
		//cout << "No match found." << endl;
		return false;
	}


	bool allocateBestFit(int n) {

		int bestFit = INT8_MAX;
		int bestFitStartIndex = -1;

		if (n < 5 || n > 20) {
			//cout << "You can only allocate between 5 and 20 integers";
			return false;
		}

		for (int i = 0; i < mMemory.size() - n; i++) {
			
			if (mMemory[i]==0) {
				int j = i + 1;
				for (; j < i + n; j++) {
					if (mMemory[j]!=0)
						goto next;

				}

				//found fit
				while (j < mMemory.size() && !mMemory[j++]) {}
				
				if (j - i < bestFit) {
					bestFit = j - i;
					bestFitStartIndex = i;
				}

				i = i + j - 1;

			}
		next:
			continue;
		}

		if (bestFitStartIndex != -1) {
			for (int i = bestFitStartIndex; i < bestFitStartIndex + n; i++)
				mMemory[i] = 1;
			memoryUsage += n;
			//cout << "allocated from " << bestFitStartIndex << " to " << bestFitStartIndex + n - 1 << endl;
			return true;
		}
		else {
			//cout << "No match found." << endl;
			return false;
		}
		
	}



	int availableSpace() {
		return mMemory.size() - memoryUsage;
	}

	void outputAvailableBlocks() {
		cout << "Available blocks: " << endl;
		for (int i = 0; i < mMemory.size(); i++) {

			if (mMemory[i]==0) {

				int j = i + 1;
				while(j < mMemory.size() && !mMemory[j++]){

				}
				

				cout << "(" << i << " to " << j <<  ") ";
				i = j - 1;
			}
		next:
			continue;
		}
	}

};