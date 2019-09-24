/*
@author:    Abbas M. Rangwala
@contact:   abbastrick@gmail.com
*/

#include <vector>
#include <cmath>
#include "Graph.h"

class Pheromone{

    Graph_of_city g;
    int num;
	double roh;
	double alpha, beta;
	double Q;
    std::vector<std::vector<double>> tau;
    std::vector<std::vector<double>> delata_tau;
    

public:

	Pheromone(){}
    Pheromone(int n, double c, double r, double a, double b, double q);
    int update_pheromone_on_path(std::vector<int> &path);
    void update_pheromone();
    double find_probability(int cur_node, int next_node, double sum);
    double find_down_sum(int cur_node, std::vector<int> &node);
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
    g = Graph_of_city(n);

} 

double Pheromone::at(int x, int y){
    return tau[x][y];
}


Pheromone::~Pheromone(){
	tau.clear();
}

double Pheromone::find_probability(int cur_node, int next_node, double sum){
	return pow(tau[cur_node][next_node], alpha) / (sum * pow( g.at(cur_node, next_node), beta ));
}

double Pheromone::find_down_sum(int cur_node, std::vector<int> &node){

	double res = 0;

	for(auto i: node){
		res += pow(tau[i][cur_node], alpha)/pow(g.at(i, cur_node), beta);
	}

	return res;
}

void Pheromone::delata_clear(){
	delata_tau.resize(num, std::vector<double> (num, 0));
}

int Pheromone::update_pheromone_on_path(std::vector<int> &path){
	

	int Lk = 0;

	for(int i = 0; i < path.size(); ++i){
		Lk += g.at(path[i], path[(i+1) % path.size()]);
	}

	for(int i = 0; i < path.size(); ++i){
		delata_tau[path[i]][path[ (i+1) % path.size() ]] += (Q / (double)Lk);
	}

	return Lk;
}

void Pheromone::update_pheromone(){

	for(int i = 0; i < num; ++i)
		for(int j = 0; j < num; ++j)
			tau[i][j] = (roh*tau[i][j]) + delata_tau[i][j];

	delata_clear();
}