/*
@author:    Abbas M. Rangwala
@contact:   abbastrick@gmail.com
*/

#include <iostream>
#include <vector>
// #include "/home/abbas/ACO_on_TSP/TSP_Code/Pheromone.cpp"
#include "/home/abbas/ACO_on_TSP/TSP_Code/Random.cpp"

class Ant{

    int num;
    int start_city;
    std::vector< bool > visit;

public:
    
    Ant();
    Ant(int n);
    ~Ant();
    int find_path(Pheromone &p);
    int next_node(int cur_node, Pheromone &p);
    void clear();
    void reset(int n);

};

Ant::Ant(int n){

    visit.resize(n, 0);
    start_city = random_n(n);
    num = n;
    visit[start_city] = 1;

}

Ant::~Ant(){ 
    visit.clear(); 
}

int Ant::find_path(Pheromone &p){
    
    std::vector<int> path;
    path.push_back(start_city);

    for(int i = 1; i < num; ++i){

        start_city = next_node(start_city, p);
        if(start_city == -1) continue;
        visit[start_city] = 1;
        path.push_back(start_city);

    }

    return p.update_pheromone_on_path(path);

}


int Ant::next_node(int cur_node, Pheromone &p){

    std::vector<int> allowed;

    for(int i = 0;i < num; ++i)
        if(visit[i] == 0 and cur_node != i){
            allowed.push_back(i);
        }
    
    double max_p = 0;
    int node = -1;
    double sum = p.find_down_sum(cur_node, allowed);

    for(int i = 0; i < allowed.size(); ++i){
        double temp = p.find_probability(cur_node, allowed[i], sum);
        if(temp > max_p){
            max_p = temp;
            node = i;
        }
    }

    return node;
}


void Ant::clear(){
    visit.clear();
}
