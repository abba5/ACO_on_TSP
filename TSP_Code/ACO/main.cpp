#include <iostream>
#include "ACO.h"

#define ITERATIONS      (int) 6
#define NUMBEROFANTS    (int) 3
#define NUMBEROFCITIES  (int) 5
#define ALPHA           (double) 0.5
#define BETA            (double) 0.8
#define Q               (double) 80
#define RO              (double) 0.2
#define C               (double) 2

int main(){

    ACO a(NUMBEROFCITIES, ITERATIONS, NUMBEROFANTS, C, RO, ALPHA, BETA, Q);
    std::cout << a.find_best_path() << '\n';

}
