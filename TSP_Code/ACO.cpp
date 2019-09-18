/*
@author:    Abbas M. Rangwala
@contact:   abbastrick@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include "/home/abbas/ACO_on_TSP/TSP_Code/Pheromone.cpp"
#include "/home/abbas/ACO_on_TSP/TSP_Code/Ant.cpp"

class ACO{

    int ITERATIONS;
    int Number_of_Ants;
    int num;
    Pheromone p;
public:

    ACO(){}
    ACO(int ncity, int it, int ant, double c, double r, double a, double b, double q);
    int find_best_path();
    int move_ants();

};

ACO::ACO(int ncity, int it, int A, double c, double r, double a, double b, double q){
    p = Pheromone(ncity, c, r, a, b, q);
    ITERATIONS = it;
    Number_of_Ants = A;
    num = ncity;
}

int ACO::find_best_path(){
    
    int min_dist = INT_MAX;

    for(int i = 0; i < ITERATIONS; ++i){
        min_dist = std::min(min_dist, move_ants());
    }

    return min_dist;
}

int ACO::move_ants(){

    int min_dist = INT_MAX;

    for(int i = 0; i < Number_of_Ants; ++i){    
        Ant ant(num);
        min_dist = std::min(min_dist, ant.find_path(p));
    }

    p.update_pheromone();
    return min_dist;

}

