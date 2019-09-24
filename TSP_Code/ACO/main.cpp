/*
	 _______________________________________
	|										|
	|	  ANT COLONY OPTIMIZATION ON TSP	|		
	|_______________________________________|


	Author 	: Abbas Rangwala
	Contact : abbastrick@gmail.com

*/


#include <iostream>
#include "ACO.h"

#define ITERATIONS      (int) 2				// number of iterations 
#define NUMBEROFANTS    (int) 9				// number of Ants
#define NUMBEROFCITIES  (int) 11			// number of cities in graph
#define ALPHA           (double) 0.5		// ALPHA parameter require in ACO
#define BETA            (double) 0.8		// BETA parameter require in ACO
#define Q               (double) 80			// Q parameter require in ACO
#define RO              (double) 0.2		// Roho parameter require in ACO (vaporization factor)
#define C               (double) 2			// intial Pheromone for every path

int main(){

    ACO a(NUMBEROFCITIES, ITERATIONS, NUMBEROFANTS, C, RO, ALPHA, BETA, Q);
	
    a.find_best_path();

    std::cout << a << '\n';

}
