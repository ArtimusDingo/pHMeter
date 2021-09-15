#ifndef Probe_h
#define Probe_h
#endif

#include <math.h>
#include <vector>
#include <numeric>

struct Nugget
{

    std::vector <double> data;
    char* Name;
    void Add(double);
    void Add(std::vector<double>);
    double Sum();
    double Average();
    double SumSquared();
};

class MicroStat
{
    public:
   
    std::vector <Nugget> Nuggets;
    MicroStat();
    void AddNugget();
    void AddNugget(std::vector<Nugget>);
    void AddValue(double, int);
    void AddValue(std::vector<double>, int);
    void Regression(Nugget*, Nugget*);
    double* slope;
    double* intercept;
    private: 
    double SumXYProduct(Nugget*, Nugget*);
    
};

