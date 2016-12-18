#include "observation.h"

using namespace std;

int main(){
	list<string> l = {"birds.txt","caen.txt"};


	Observation birdies("birds.txt");
	Observation cirdies("caen.txt");
	cout << birdies;
	cout << cirdies;

	map<string,int> my_byrds = birdies.readBirds(l);
	for(auto specie : my_byrds){
			cout <<specie.first <<":"<<specie.second;
		}
	/*for(string filename : l){

	}*/
	return 0;
}