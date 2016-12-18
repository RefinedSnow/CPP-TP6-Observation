#include "observation.h"
using namespace std;

Observation::Observation(string filename){
	ifstream filestrm(filename, ifstream::in);
	import(filestrm);
	filestrm.close();
}

void Observation::import(ifstream& strm){
	strm >> coordinates.first;
	strm >> coordinates.second;
	string name;
	int count;

	while(!strm.eof()){
		strm >> name;
		strm >> count;

		observed_species[name] = count;
		if(strm.eof()){
			break;
		}
	}
}

pair<double,double> Observation::getCoords(){
	return coordinates;
}

map<string,int> Observation::getObserved_species(){
	return observed_species;
}

map<string,int> Observation::readBirds(list<string>& l){
	map<string,int> new_birds;

	for(string file : l){
		ifstream filestrm(file, ifstream::in);
		import(filestrm);
		for(auto specie : getObserved_species()){
			new_birds[specie.first] += specie.second;
			new_birds["total"] += specie.second;
		}

	}
	return new_birds;
}


ostream& operator<<(ostream& os, const Observation& obs){
	os << "### Fiche d'observation ###" <<endl;
	os << "GPS coordinates : " << obs.coordinates.first << ";" << obs.coordinates.second << endl;
	os << "<<Birdies list>>" << endl ;
	for(pair<string,int> specie : obs.observed_species){
		cout << specie.first << ":" << specie.second << endl;
	}
	return os << endl;
}