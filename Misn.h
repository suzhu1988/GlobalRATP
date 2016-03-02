#ifndef _Misn_h_
#define _Misn_h_

#include <vector>

struct Misn{
	int	ID;
	bool isfic;
	int nstop;
	double freq;
	int skapa;
	int tkapa;
	int* ston;
	double** flow;
	double** mflow;
	double* wtime;
	double** cost0;
	double** cost;
	std::vector<int> pmisns;

	Misn(int _ID){
		ID = _ID;
		nstop = -1;
		freq = -1;
	}
};

#endif