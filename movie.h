#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;
class movie
{
protected:
	string name;
	int durationInMinutes;

public:
	movie()
	{
		this->durationInMinutes = 0;
	}
	movie(string name, int durationInMinutes)
	{
		this->name = name;
		this->durationInMinutes = durationInMinutes;
	}
	void setName(string n)
	{
		name = n;
	}
	void setDurationInMinutes(int s)
	{
		durationInMinutes = s;
	}
	string getName()
	{
		return name;
	}
	int getDurationInMinutes()
	{
		return durationInMinutes;
	}
};
#endif

