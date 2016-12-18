#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Observation{
	private:
	pair <double,double> coordinates;
	map <string,int> observed_species;
	public:
	Observation(string filename);
	void import(ifstream& strm);
	pair<double,double> getCoords();
	map<string,int> getObserved_species();
	map<string,int> readBirds(list<string>& l);
	friend ostream& operator<<(ostream& os, const Observation& obs);
};