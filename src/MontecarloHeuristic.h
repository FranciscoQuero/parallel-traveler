#include "Route.h"
#include "Problem.h"
#include <omp.h>

#ifndef MONTECARLOHEURISTIC_H
#define MONTECARLOHEURISTIC_H

class MontecarloHeuristic
{
public:
    static double solveMontecarlo(Problem problem, int iterations, int argc, char **argv);
};

#endif // MONTECARLOHEURISTIC_H
