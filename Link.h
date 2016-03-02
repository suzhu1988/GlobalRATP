#ifndef _Link_h_
#define _Link_h_

struct Link{
	int	snode;
	int	enode;
	double cost;
	double freq;
	char type;

	Link(){
	}

	Link(int _snode, int _enode, double _cost, double _freq, char _type){
		snode = _snode;
		enode = _enode;
		cost = _cost;
		freq = _freq;
		type = _type;
	}
};

#endif