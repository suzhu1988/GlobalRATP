#ifndef _Node_h_
#define _Node_h_

#include <vector>
#include <string>

#include "Link.h"

struct Node{
	int	ID;
	char type;
	int lieu;
	int misn;
	int stop;
	int zone;
	std::vector<int>	inlinks;
	std::vector<int>	outlinks;

	Node(int _ID, char _type, int _lieu, int _misn, int _stop, int _zone){
		ID = _ID;
		type = _type;
		lieu = _lieu;
		misn = _misn;
		stop = _stop;
		zone = _zone;
	}

	Node(int _ID, char _type, int _misn, int _stop, int _zone){
		ID = _ID;
		type = _type;
		lieu = -1;
		misn = _misn;
		stop = _stop;
		zone = _zone;
	}

	Node(int _ID, char _type, int _zone){
		ID = _ID;
		type = _type;
		lieu = -1;
		zone = _zone;
		misn = -1;
		stop = -1;
	}

};

#endif