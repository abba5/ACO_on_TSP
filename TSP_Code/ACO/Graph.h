/*
@author:    Abbas M. Rangwala
@contact:   abbastrick@gmail.com
*/

#include <iostream>
#include <vector>

class Graph_of_city{
    
    int number_of_city;
    std::vector< std::vector< int > > cost;

public:

    Graph_of_city(int n);
    Graph_of_city(){}
    ~Graph_of_city();
    void get_input(int n);
    int at(int u, int v);
    void print_cost();

};

Graph_of_city::Graph_of_city(int n){

    number_of_city = n;
    cost.resize(n, std::vector< int > (n));

    get_input(n);

}

Graph_of_city::~Graph_of_city(){
    cost.clear();
}

void Graph_of_city::get_input(int n){

    int q = (n*(n-1)) >> 1;
    int u, v, dis;

    for(int i = 0; i < q; ++i){

        std::cin >> u >> v >> dis;

        --u, --v;
        cost[u][v] = dis;
        cost[v][u] = dis;

    }

}

int Graph_of_city::at(int u, int v){
    return cost[u][v];
    
}

void Graph_of_city::print_cost(){

    for(int i = 0; i < number_of_city; ++i)
        for(int j = 0; j < number_of_city; ++j)
            std::cout << cost[i][j] << " \n"[number_of_city - 1 == j];

}


