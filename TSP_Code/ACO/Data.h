/*
    Author  : Abbas Rangwala
    Contact : abbastrick@gmail.com
    
    definition of class Ant
        
    -> this class will store data of path and its cost and also print path
*/


#include <vector>
#include <iostream>
#include <climits>

class Data{
	int Cost;
	std::vector<int> path;

public:

	Data();
	// copy constructor
	Data(int c, std::vector<int> &res);

	// operator overloding to print value of Data class
	friend std::ostream& operator << (std::ostream& os, const Data& dt);
	int cost();
};

// intial value shoud be max
Data::Data(){Cost = INT_MAX;}

Data::Data(int c, std::vector<int> &res){
	Cost = c;
	path = res;
}


std::ostream& operator << (std::ostream& os, const Data& dt){

	int n = dt.path.size();
	
	os << dt.Cost << "\n";

	for(int i = 0; i < n; ++i)
		os << dt.path[i] + 1 << ' ';
	os << '\n';

	return os;
}

int Data::cost(){
	return Cost;
}

// find min cost
Data min(Data &a, Data &b){
	if(a.cost() > b.cost())
		return b;
	else
		return a;
}