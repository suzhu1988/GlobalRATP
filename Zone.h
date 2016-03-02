#ifndef _Zone_h_
#define _Zone_h_

#include <vector>

struct Zone{
	int ID;
	int	node;
	std::vector<int> nodes;

	Zone(int _ID, int _node){
		ID = _ID;
		node = _node;
	}
};

#endif