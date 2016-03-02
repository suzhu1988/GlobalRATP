#ifndef _PathSize_h_
#define _PathSize_h_

#include <vector>

struct PathSize{
	int	link;
	double proba;
	double cost;

	PathSize(int _link, double _proba, double _cost){
		link = _link;
		proba = _proba;
		cost = _cost;
	}
};

#endif