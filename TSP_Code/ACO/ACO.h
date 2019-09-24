/*
    Author  : Abbas Rangwala
    Contact : abbastrick@gmail.com
    
    definition of class ACO
        
    -> this class will calculate path of ant and cost of same using Pheromone and 
        Ant library.  
*/

#include <iostream>
#include <climits>
#include <vector>
#include "Data.h"
#include "Pheromone.h"
#include "Ant.h"

class ACO{

    int ITERATIONS;
    int Number_of_Ants;
    int num;
    Pheromone p;
    Data res;
    
public:

    ACO(){}
    
    /* constroctor = [number of cities, number of iterations, number of ants, intial -
                    Pheromone, vaporization factor, Alpha, Beta, Q ]*/
    ACO(int ncity, int it, int ant, double c, double r, double a, double b, double q);

    /* find best optimize path and store in res */
    void find_best_path();


    /* Ant will travel N cities and return path and cost of traveling */
    Data move_ants();

    /* Operator overloading for print path and cost */
    friend std::ostream& operator << (std::ostream& os, const ACO&a);

};



ACO::ACO(int ncity, int it, int A, double c, double r, double a, double b, double q){
    p = Pheromone(ncity, c, r, a, b, q);
    ITERATIONS = it;
    Number_of_Ants = A;
    num = ncity;
}



void ACO::find_best_path(){

    for(int i = 0; i < ITERATIONS; ++i){
        Data temp = move_ants(); // all Ant will travel using move_ant()
        res = min(res, temp);
    }
}

Data ACO::move_ants(){

    Data min_dist;

    for(int i = 0; i < Number_of_Ants; ++i){    
        Ant ant(num);   // new born ant
        Data temp = ant.find_path(p); // find the path of k th ant using equation given in paper 
        res = min(res, temp);
    }

    p.update_pheromone(); // update pheromone
    return min_dist;

}

std::ostream& operator << (std::ostream& os, const ACO&a){
    os << a.res << '\n';
    return os;
}
