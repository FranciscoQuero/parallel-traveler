#include <string>
#include <Problem.h>
#include <omp.h>

#ifndef MAINTSP_H
#define MAINTSP_H

using namespace std;

class MainTSP
{
    public:
        main(int args);
        Problem readCitiesFromFile();
};

#endif // MAINTSP_H
