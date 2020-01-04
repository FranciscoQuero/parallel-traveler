#include <string>
#include "Problem.h"
#include <omp.h>

#ifndef MAINTSP_H
#define MAINTSP_H

using namespace std;

class MainTSP
{
    public:
        int main(int argc, char **argv);
        Problem readCitiesFromFile(string filename);
};

#endif // MAINTSP_H
