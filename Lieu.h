#ifndef _Lieu_h_
#define _Lieu_h_

#include <vector>

struct Lieu{
	int	ID;
	std::vector<int> nodes;
	std::vector<int> misns;

	Lieu(int _ID){
		ID = _ID;
	}
};

#endif