#include <MicroStat.h>
#include <Arduino.h>
#include <sstream>
#include <string>


using namespace std;

template <typename T>
std::string to_string(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

MicroStat Stat;
void Print(string message)
{
  char printable[message.length() + 1];
  strcpy(printable, message.c_str());
  Serial.print(printable);
} 

void setup()
{
 
 
 Serial.begin(9600);

 Stat.AddNugget(std::vector<Nugget> {{},{}}); // overload that takes vector of nuggets
 Stat.AddValue(std::vector<double> {1.0, 2.0, 3.0}, 0);
 Stat.AddValue(std::vector<double> {20.0, 30.0, 40.0}, 1);
 Stat.Regression(&Stat.Nuggets[0], &Stat.Nuggets[1]);
 Print(to_string(*Stat.slope));
 
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
}