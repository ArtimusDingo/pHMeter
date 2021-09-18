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

// MicroStat Methods

MicroStat::MicroStat()
{

}

double MicroStat::sumxyproduct(Nugget& xdata, Nugget& ydata)
{
    double SumXYProduct = 0.0;
    int loopsize = xdata.data.size();
    for(int i = 0; i < loopsize ; i++)
    {
        SumXYProduct += xdata.data[i] * ydata.data[i];
    } 
    return SumXYProduct;
}

double MicroStat::sumsquared(Nugget& data)
{
    double sum_squared = 0.0;
     for(auto itr : data.data)
    {
        sum_squared += (itr * itr);
    } 
    return sum_squared;
}

double MicroStat::sum(Nugget& data)
{
    return accumulate(data.data.begin(), data.data.end(), 0.0);
}

double MicroStat::average(Nugget& data)
{
    double sum = accumulate(data.data.begin(), data.data.end(), 0.0);
    return sum / (data.data.size() * 1.0);       
}


double MicroStat::stdev(Nugget& data)
{
    int loop = data.data.size();
    double mean = average(data);
    double dev = 0.0;
    for(int i = 0; i < loop; i++)
    {
        dev = dev + ((data.data[i] - mean) * (data.data[i] - mean));
    }
    return sqrt(dev / ((loop - 1)* 1.0));
}

void MicroStat::AddNugget()
{
    Nugget newnugget; 
    Nuggets.insert(Nuggets.end(), newnugget);
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

void MicroStat::Regression(Nugget& xdata, Nugget& ydata)
{
  //  std::vector <double> x = xdata.data; // required to get actual size it seems
  //  std::vector <double> y = ydata.data;
    double xsum = sum(xdata); double ysum = sum(ydata);
    double n = (xdata.data.size() * 1.0); 
    double sumxsquared = sumsquared(xdata); double sumxy = sumxyproduct(xdata, ydata);
    slope = ((n*sumxy-xsum*ysum)/(n*sumxsquared-(xsum*xsum)));
    intercept = (ysum - slope*xsum)/n;
}

double MicroStat::RSD(Nugget& data)
{ 
  return ((stdev(data) / average(data)) * 1.0) * 100.0;
}

double MicroStat::Interpolate(double _reading)
{
    double output = (_reading - intercept)/ (slope);
    return output;
}
