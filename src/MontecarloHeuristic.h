#include "Route.h"
#include "Problem.h"
#include <omp.h>

#ifndef MONTECARLOHEURISTIC_H
#define MONTECARLOHEURISTIC_H

class MontecarloHeuristic
{
public:
    static Route solveMontecarlo(Problem problem, int iterations);
};

#endif // MONTECARLOHEURISTIC_H
