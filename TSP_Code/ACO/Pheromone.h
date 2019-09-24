/*
    Author  : Abbas Rangwala
    Contact : abbastrick@gmail.com
    
    definition of class Ant
        
    -> this class will store Pheromone of all path and also find it's probability
*/


#include <vector>
#include <cmath>
#include "Graph.h"

class Pheromone{

    Graph_of_city g;
    int num;
	double roh;										// vaporization factor
	double alpha, beta;		
	double Q;										
    std::vector<std::vector<double>> tau; 			// tau to store Pheromone
    std::vector<std::vector<double>> delata_tau; 	// for temp dalta_tau 
    

public:

	Pheromone(){}

	/* constroctor = [number of cities, intial -Pheromone, 
						vaporization factor, Alpha, Beta, Q ] */
    Pheromone(int n, double c, double r, double a, double b, double q);
    
    /* update pheromone on path and also give its distance and path */
    Data update_pheromone_on_path(std::vector<int> &path);

    /* update tau = roh*tau + delta_tau*/
    void update_pheromone();

    /* find probability of curent node with next node*/
    double find_probability(int cur_node, int next_node, double sum);

    /* find denominator sum */
    double find_down_sum(int cur_node, std::vector<int> &node);
    
    /* what is pheromone from path u -> v */ 
    double at(int u, int v);
    void delata_clear();
    ~Pheromone();
};

Pheromone::Pheromone(int n, double c, double r, double a, double b, double q){
	
	Q = q;
	alpha = a;
	beta = b;
	num = n;
    tau.resize(n, std::vector<double> (n, c));
    delata_tau.resize(n, std::vector<double> (n, 0));
    roh = r;
    g = Graph_of_city(n); // make graph of cities 

} 

double Pheromone::at(int x, int y){
    return tau[x][y];
}


Pheromone::~Pheromone(){
	tau.clear();
}

/* 
	
	Pr = ( tau^alpha *  d^beta) / sum (tau^alpha * d^beta)
	d = visiblity
	tau = Pheromone
*/

double Pheromone::find_probability(int cur_node, int next_node, double sum){
	return pow(tau[cur_node][next_node], alpha) / (sum * pow( g.at(cur_node, next_node), beta ));
}

double Pheromone::find_down_sum(int cur_node, std::vector<int> &node){

	double res = 0;


	// find denominator sum
	for(auto i: node){
		res += pow(tau[i][cur_node], alpha)/pow(g.at(i, cur_node), beta);
	}

	return res;
}

// for clear delta tau
void Pheromone::delata_clear(){
	delata_tau.resize(num, std::vector<double> (num, 0));
}


// update Pheromone for every path from ant pass
Data Pheromone::update_pheromone_on_path(std::vector<int> &path){
	

	int Lk = 0;

	for(int i = 0; i < path.size(); ++i){
		Lk += g.at(path[i], path[(i+1) % path.size()]);
	}

	for(int i = 0; i < path.size(); ++i){
		delata_tau[path[i]][path[ (i+1) % path.size() ]] += (Q / (double)Lk);
	}

	Data nk(Lk, path);
	return nk;
}



// add delta_tau and update tau
void Pheromone::update_pheromone(){

	for(int i = 0; i < num; ++i)
		for(int j = 0; j < num; ++j)
			tau[i][j] = (roh*tau[i][j]) + delata_tau[i][j];

	delata_clear();
}