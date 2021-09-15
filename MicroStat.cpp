#include <MicroStat.h>

using namespace std;

void Nugget::Add(double _value)
{
    data.insert(data.end(), _value);
}

void Nugget::Add(std::vector<double> _values)
{
    
    data.insert(data.end(), _values.begin(), _values.end());
}

double Nugget::Sum()
{
    return accumulate(data.begin(), data.end(), 0.0);
}

double Nugget::Average()
{
    double sum = accumulate(data.begin(), data.end(), 0.0);
    return sum / (data.size() * 1.0);       
}

double Nugget::SumSquared()
{
    double sum_squared = 0.0;
     for(auto itr : data)
    {
        sum_squared += (itr * itr);
    } 
    return sum_squared;
}

// MicroStat Methods

MicroStat::MicroStat()
{

}

double MicroStat::SumXYProduct(Nugget* xdata, Nugget* ydata)
{
    double SumXYProduct = 0.0;
    int loopsize = xdata->data.size() - 1;
    for(int i = 0; i <= loopsize ; i++)
    {
        SumXYProduct += xdata->data[i] * ydata->data[i];
    } 
    return SumXYProduct ;
}

void MicroStat::AddNugget()
{
    Nugget* newnugget = new Nugget();
    Nuggets.insert(Nuggets.end(), *newnugget);
}

void MicroStat::AddNugget(std::vector<Nugget> _nuggets)
{
    Nuggets.insert(Nuggets.end(), _nuggets.begin(), _nuggets.end());
}

void MicroStat::AddValue(double _value, int _nugget)
{
    Nuggets[_nugget].Add(_value);
}

void MicroStat::AddValue(std::vector<double> _value, int _nugget)
{
    Nuggets[_nugget].Add(_value);
}

void MicroStat::Regression(Nugget* xdata, Nugget* ydata)
{
    std::vector <double> x = xdata->data; // required to get actual size it seems
    std::vector <double> y = ydata->data;
    double xsum = xdata->Sum(); double ysum = ydata->Sum();
    double n = (x.size() * 1.0); double _slope; double _intercept;
    double sumxsquared = xdata->SumSquared(); double sumxy = SumXYProduct(xdata, ydata);
    _slope = ((n*sumxy-xsum*ysum)/(n*sumxsquared-(xsum*xsum)));
    _intercept = (ysum - _slope*xsum)/n;
    slope = &_slope;
    intercept = &_intercept;

}