/*
    Author  : Abbas Rangwala
    Contact : abbastrick@gmail.com
    
    definition of class Ant
        
    -> this class will place Ant at random cities and also find travel sequence of cities
*/

#include <vector>
#include "Random.h"

class Ant{

    int num;
    int start_city; // from which cities it will travel first
    std::vector< bool > visit; // to check it cities visited erlier or not

public:
    
    Ant();
    Ant(int n);
    ~Ant();

    /* It will give travel sequence of cities */
    Data find_path(Pheromone &p);

    /* find next city for Ant*/
    int next_node(int cur_node, Pheromone &p);

    void clear();
    void reset(int n);

};

Ant::Ant(int n){

    visit.resize(n, 0);
    start_city = random_n(n); // uniform distriybuterd random function 
    num = n;

}

Ant::~Ant(){ 
    visit.clear(); 
}

Data Ant::find_path(Pheromone &p){
    
    std::vector<int> path;
    path.push_back(start_city); // push starting city

    for(int i = 1; i < num; ++i){

        visit[start_city] = 1; // mark current city as visited
        start_city = next_node(start_city, p); // calculate next city 
        if(start_city == -1) continue; // if -1 that means no city remain 
        path.push_back(start_city);// push new city in path

    }

    return p.update_pheromone_on_path(path); // find and update in temporary matrix after that upatede using Eq.

}

int Ant::next_node(int cur_node, Pheromone &p){

    std::vector<int> allowed;

    for(int i = 0;i < num; ++i)
        if(visit[i] == 0){
            allowed.push_back(i); // find remain city connected with current city
        }
    
    double max_p = 0; 
    int node = -1;
    double sum = p.find_down_sum(cur_node, allowed); // sum of (Pheromone)^alpha * (visiblity)^beta   

    for(int i = 0; i < allowed.size(); ++i){
        double temp = p.find_probability(cur_node, allowed[i], sum); // finding probability
      
        if(temp > max_p){
            max_p = temp;
            node = allowed[i]; // which node is perfect for next move
        }
    }

    return node;
}


void Ant::clear(){
    visit.clear();
}
