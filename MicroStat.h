#ifndef MicroStat_h
#define MicroStat_h
#endif

#include <math.h>
#include <vector>
#include <numeric>

struct Nugget
{
    std::vector <double> data;
    void Add(double);
    void Add(std::vector<double>);
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
    void Regression(Nugget&, Nugget&);
    double Interpolate(double);
    double RSD(Nugget&);
    double slope;
    double intercept;
    private: 
    double sumxyproduct(Nugget&, Nugget&);
    double sumsquared(Nugget&);
    double stdev(Nugget&);
    double sum(Nugget&);
    double average(Nugget&);
};

