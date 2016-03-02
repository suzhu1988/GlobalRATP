#ifndef _Graph_h_
#define _Graph_h_

#include <iostream>
//#include <algorithm>
#include <assert.h>
#include <queue>
#include <random>
#include <math.h>

#include "Node.h"
#include "Zone.h"
#include "Link.h"
#include "Misn.h"
#include "Lieu.h"
#include "PathSize.h"

#include "Define.h"

using namespace std;

struct Graph{
	vector<Node> nodes;
	vector<Link> links;
	vector<Zone> zones;
	vector<Misn> misns;
	vector<Lieu> lieux;

	double** OD;

	vector<vector<vector<int>>> paths;

	int nNonFicMisn;
	int nNonFicLink;
	int nNonFicNode;

	Graph(){

		nodes.push_back(Node( 0,'z', 0));
		nodes.push_back(Node( 1,'z', 1));
		nodes.push_back(Node( 2,'z', 2));
		nodes.push_back(Node( 3,'z', 3));
		nodes.push_back(Node( 4,'z', 4));
		nodes.push_back(Node( 5,'m', 0, 0, 0, 0));
		nodes.push_back(Node( 6,'m', 1, 0, 1, 2));
		nodes.push_back(Node( 7,'m', 2, 0, 2, 4));
		nodes.push_back(Node( 8,'m', 0, 1, 0, 0));
		nodes.push_back(Node( 9,'m', 1, 1, 1, 2));
		nodes.push_back(Node(10,'m', 2, 1, 2, 4));
		nodes.push_back(Node(11,'m', 0, 2, 0, 0));
		nodes.push_back(Node(12,'m', 1, 2, 1, 2));
		nodes.push_back(Node(13,'m', 4, 3, 0, 2));
		nodes.push_back(Node(14,'m', 3, 3, 1, 0));
		nodes.push_back(Node(15,'m', 5, 4, 0, 4));
		nodes.push_back(Node(16,'m', 4, 4, 1, 2));
		nodes.push_back(Node(17,'m', 3, 4, 2, 0));
		nodes.push_back(Node(18,'m', 5, 5, 0, 4));
		nodes.push_back(Node(19,'m', 4, 5, 1, 2));
		nodes.push_back(Node(20,'m', 3, 5, 2, 0));
		nodes.push_back(Node(21,'m', 6, 0, 0));
		nodes.push_back(Node(22,'m', 6, 1, 1));
		nodes.push_back(Node(23,'m', 6, 2, 2));
		nodes.push_back(Node(24,'m', 6, 3, 3));
		nodes.push_back(Node(25,'m', 6, 4, 3));
		nodes.push_back(Node(26,'m', 6, 5, 4));
		nodes.push_back(Node(27,'m', 6, 6, 4));
		nodes.push_back(Node(28,'m', 7, 0, 4));
		nodes.push_back(Node(29,'m', 7, 1, 4));
		nodes.push_back(Node(30,'m', 7, 2, 3));
		nodes.push_back(Node(31,'m', 7, 3, 3));
		nodes.push_back(Node(32,'m', 7, 4, 2));
		nodes.push_back(Node(33,'m', 7, 5, 1));
		nodes.push_back(Node(34,'m', 7, 6, 0));

		links.push_back(Link( 5, 6, 3,-1,'m'));
		links.push_back(Link( 6, 7, 4,-1,'m'));
		links.push_back(Link( 8, 9, 3,-1,'m'));
		links.push_back(Link( 9,10, 4,-1,'m'));
		links.push_back(Link(11,12, 3,-1,'m'));
		links.push_back(Link(18,19, 4,-1,'m'));
		links.push_back(Link(19,20, 3,-1,'m'));
		links.push_back(Link(15,16, 4,-1,'m'));
		links.push_back(Link(16,17, 3,-1,'m'));
		links.push_back(Link(13,14, 3,-1,'m'));
		links.push_back(Link(21,22, 2,-1,'m'));
		links.push_back(Link(22,23, 2,-1,'m'));
		links.push_back(Link(23,24, 2,-1,'m'));
		links.push_back(Link(24,25, 2,-1,'m'));
		links.push_back(Link(25,26, 2,-1,'m'));
		links.push_back(Link(26,27, 2,-1,'m'));
		links.push_back(Link(28,29, 2,-1,'m'));
		links.push_back(Link(29,30, 2,-1,'m'));
		links.push_back(Link(30,31, 2,-1,'m'));
		links.push_back(Link(31,32, 2,-1,'m'));
		links.push_back(Link(32,33, 2,-1,'m'));
		links.push_back(Link(33,34, 2,-1,'m'));
		links.push_back(Link( 0, 5, 1,10,'a'));
		links.push_back(Link( 0, 8, 1, 8,'a'));
		links.push_back(Link( 0,11, 1,12,'a'));
		links.push_back(Link( 2, 6, 1,10,'a'));
		links.push_back(Link( 2, 9, 1, 8,'a'));
		links.push_back(Link( 2,12, 1,12,'a'));
		links.push_back(Link( 4,15, 1, 8,'a'));
		links.push_back(Link( 4,18, 1,10,'a'));
		links.push_back(Link( 2,13, 1,12,'a'));
		links.push_back(Link( 2,16, 1, 8,'a'));
		links.push_back(Link( 2,19, 1,10,'a'));
		links.push_back(Link( 6, 2, 1,-1,'e'));
		links.push_back(Link( 9, 2, 1,-1,'e'));
		links.push_back(Link(12, 2, 1,-1,'e'));
		links.push_back(Link( 7, 4, 1,-1,'e'));
		links.push_back(Link(10, 4, 1,-1,'e'));
		links.push_back(Link(13, 2, 1,-1,'e'));
		links.push_back(Link(16, 2, 1,-1,'e'));
		links.push_back(Link(19, 2, 1,-1,'e'));
		links.push_back(Link(14, 0, 1,-1,'e'));
		links.push_back(Link(17, 0, 1,-1,'e'));
		links.push_back(Link(20, 0, 1,-1,'e'));
		links.push_back(Link( 0,21, 1,30,'a'));
		links.push_back(Link( 1,22, 2,30,'a'));
		links.push_back(Link( 2,23, 1,30,'a'));
		links.push_back(Link( 3,24, 2,30,'a'));
		links.push_back(Link( 3,25, 2,30,'a'));
		links.push_back(Link( 4,26, 3,30,'a'));
		links.push_back(Link( 4,28, 4,30,'a'));
		links.push_back(Link( 4,29, 3,30,'a'));
		links.push_back(Link( 3,30, 2,30,'a'));
		links.push_back(Link( 3,31, 2,30,'a'));
		links.push_back(Link( 2,32, 1,30,'a'));
		links.push_back(Link( 1,33, 2,30,'a'));
		links.push_back(Link(22, 1, 2,-1,'e'));
		links.push_back(Link(23, 2, 1,-1,'e'));
		links.push_back(Link(24, 3, 2,-1,'e'));
		links.push_back(Link(25, 3, 2,-1,'e'));
		links.push_back(Link(26, 4, 3,-1,'e'));
		links.push_back(Link(27, 4, 4,-1,'e'));
		links.push_back(Link(29, 4, 3,-1,'e'));
		links.push_back(Link(30, 3, 2,-1,'e'));
		links.push_back(Link(31, 3, 2,-1,'e'));
		links.push_back(Link(32, 2, 1,-1,'e'));
		links.push_back(Link(33, 1, 2,-1,'e'));
		links.push_back(Link(34, 0, 1,-1,'e'));
		links.push_back(Link(14, 5,0.5,10,'t'));
		links.push_back(Link(17, 5,0.5,10,'t'));
		links.push_back(Link(20, 5,0.5,10,'t'));
		links.push_back(Link(34, 5, 1,10,'t'));
		links.push_back(Link(14, 8,0.5, 8,'t'));
		links.push_back(Link(17, 8,0.5, 8,'t'));
		links.push_back(Link(20, 8,0.5, 8,'t'));
		links.push_back(Link(34, 8, 1, 8,'t'));
		links.push_back(Link(14,11,0.5,12,'t'));
		links.push_back(Link(17,11,0.5,12,'t'));
		links.push_back(Link(20,11,0.5,12,'t'));
		links.push_back(Link(34,11, 1,12,'t'));
		links.push_back(Link(14,21, 1,30,'t'));
		links.push_back(Link(17,21, 1,30,'t'));
		links.push_back(Link(20,21, 1,30,'t'));
		links.push_back(Link(34,21,0.5,30,'t'));
		links.push_back(Link(22,33,0.5,30,'t'));
		links.push_back(Link(33,22,0.5,30,'t'));
		links.push_back(Link( 6, 6, 0,10,'t'));
		links.push_back(Link( 9, 6, 0,10,'t'));
		links.push_back(Link(12, 6, 0,10,'t'));
		links.push_back(Link(13, 6,0.5,10,'t'));
		links.push_back(Link(16, 6,0.5,10,'t'));
		links.push_back(Link(19, 6,0.5,10,'t'));
		links.push_back(Link(23, 6, 1,10,'t'));
		links.push_back(Link(32, 6, 1,10,'t'));
		links.push_back(Link( 6, 9, 0, 8,'t'));
		links.push_back(Link( 9, 9, 0, 8,'t'));
		links.push_back(Link(12, 9, 0, 8,'t'));
		links.push_back(Link(13, 9,0.5, 8,'t'));
		links.push_back(Link(16, 9,0.5, 8,'t'));
		links.push_back(Link(19, 9,0.5, 8,'t'));
		links.push_back(Link(23, 9, 1, 8,'t'));
		links.push_back(Link(32, 9, 1, 8,'t'));
		links.push_back(Link( 6,19,0.5,10,'t'));
		links.push_back(Link( 9,19,0.5,10,'t'));
		links.push_back(Link(12,19,0.5,10,'t'));
		links.push_back(Link(16,19, 0,10,'t'));
		links.push_back(Link(19,19, 0,10,'t'));
		links.push_back(Link(23,19, 1,10,'t'));
		links.push_back(Link(32,19, 1,10,'t'));
		links.push_back(Link( 6,16,0.5, 8,'t'));
		links.push_back(Link( 9,16,0.5, 8,'t'));
		links.push_back(Link(12,16,0.5, 8,'t'));
		links.push_back(Link(16,16, 0, 8,'t'));
		links.push_back(Link(19,16, 0, 8,'t'));
		links.push_back(Link(23,16, 1, 8,'t'));
		links.push_back(Link(32,16, 1, 8,'t'));
		links.push_back(Link( 6,13,0.5,12,'t'));
		links.push_back(Link( 9,13,0.5,12,'t'));
		links.push_back(Link(12,13,0.5,12,'t'));
		links.push_back(Link(16,13, 0,12,'t'));
		links.push_back(Link(19,13, 0,12,'t'));
		links.push_back(Link(23,13, 1,12,'t'));
		links.push_back(Link(32,13, 1,12,'t'));
		links.push_back(Link( 6,23, 1,30,'t'));
		links.push_back(Link( 9,23, 1,30,'t'));
		links.push_back(Link(12,23, 1,30,'t'));
		links.push_back(Link(13,23, 1,30,'t'));
		links.push_back(Link(16,23, 1,30,'t'));
		links.push_back(Link(19,23, 1,30,'t'));
		links.push_back(Link(32,23,0.5,30,'t'));
		links.push_back(Link( 6,32, 1,30,'t'));
		links.push_back(Link( 9,32, 1,30,'t'));
		links.push_back(Link(12,32, 1,30,'t'));
		links.push_back(Link(13,32, 1,30,'t'));
		links.push_back(Link(16,32, 1,30,'t'));
		links.push_back(Link(19,32, 1,30,'t'));
		links.push_back(Link(23,32,0.5,30,'t'));
		links.push_back(Link(24,31,0.5,30,'t'));
		links.push_back(Link(31,24,0.5,30,'t'));
		links.push_back(Link(25,30,0.5,30,'t'));
		links.push_back(Link(30,25,0.5,30,'t'));
		links.push_back(Link(26,29,0.5,30,'t'));
		links.push_back(Link(29,26,0.5,30,'t'));
		links.push_back(Link(27,28,0.5,30,'t'));
		links.push_back(Link( 7,18,0.5,10,'t'));
		links.push_back(Link(10,18,0.5,10,'t'));
		links.push_back(Link( 7,15,0.5, 8,'t'));
		links.push_back(Link(10,15,0.5, 8,'t'));
		links.push_back(Link( 0, 1, 7,-1,'w'));
		links.push_back(Link( 1, 2, 5,-1,'w'));
		links.push_back(Link( 2, 3, 8,-1,'w'));
		links.push_back(Link( 3, 4, 8,-1,'w'));
		links.push_back(Link( 1, 0, 7,-1,'w'));
		links.push_back(Link( 2, 1, 5,-1,'w'));
		links.push_back(Link( 3, 2, 8,-1,'w'));
		links.push_back(Link( 4, 3, 8,-1,'w'));

		OD = new double*[Kz];
		for (int i = 0; i < Kz; i++){
			OD[i] = new double[Kz];
		}
/*		OD[0][0] = 0;
		OD[0][1] = 400;
		OD[0][2] = 2100;
		OD[0][3] = 200;
		OD[0][4] = 3200;
		OD[1][0] = 1000;
		OD[1][1] = 0;
		OD[1][2] = 400;
		OD[1][3] = 200;
		OD[1][4] = 1200;
		OD[2][0] = 3200;
		OD[2][1] = 800;
		OD[2][2] = 0;
		OD[2][3] = 1200;
		OD[2][4] = 2800;
		OD[3][0] = 1400;
		OD[3][1] = 500;
		OD[3][2] = 2200;
		OD[3][3] = 0;
		OD[3][4] = 2200;
		OD[4][0] = 3800;
		OD[4][1] = 300;
		OD[4][2] = 2600;
		OD[4][3] = 1200;
		OD[4][4] = 0; */

		OD[0][0] = 0;
		OD[0][1] = 0;
		OD[0][2] = 0;
		OD[0][3] = 0;
		OD[0][4] = 10000;
		OD[1][0] = 0;
		OD[1][1] = 0;
		OD[1][2] = 0;
		OD[1][3] = 0;
		OD[1][4] = 0;
		OD[2][0] = 0;
		OD[2][1] = 0;
		OD[2][2] = 0;
		OD[2][3] = 0;
		OD[2][4] = 0;
		OD[3][0] = 0;
		OD[3][1] = 0;
		OD[3][2] = 0;
		OD[3][3] = 0;
		OD[3][4] = 0;
		OD[4][0] = 0;
		OD[4][1] = 0;
		OD[4][2] = 0;
		OD[4][3] = 0;
		OD[4][4] = 0;
	}

	void GenerateLinks(){
		for (int i = 0; i < links.size(); i++){
			nodes.at(links.at(i).snode).outlinks.push_back(i);
			nodes.at(links.at(i).enode).inlinks.push_back(i);
		}
		return;
	}

	void GenerateMisns(){
		int nmisns = -1;
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
			if (it->misn + 1 > nmisns){
				nmisns = it->misn + 1;
			}
		}
		for (int i = 0; i < nmisns; i++){
			misns.push_back(Misn(i));
		}
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
			if (it->type == 'm'){
				if (it->stop+1 > misns.at(it->misn).nstop){
					misns.at(it->misn).nstop = it->stop+1;
				}
			}
		}
		for (int i = 0; i < nmisns; i++){
			misns.at(i).isfic = false;
			misns.at(i).skapa = sK;
			misns.at(i).tkapa = tK;
			misns.at(i).ston = new int[misns.at(i).nstop];
			misns.at(i).flow = new double*[misns.at(i).nstop];
			misns.at(i).mflow = new double*[misns.at(i).nstop];
			for (int j = 0; j < misns.at(i).nstop; j++){
				misns.at(i).flow[j] = new double[misns.at(i).nstop];
				misns.at(i).mflow[j] = new double[misns.at(i).nstop];
				for (int k = 0; k < misns.at(i).nstop; k++){
					misns.at(i).flow[j][k] = 0;
					misns.at(i).mflow[j][k] = 0;
				}
			}
			misns.at(i).cost = new double*[misns.at(i).nstop];
			misns.at(i).cost0 = new double*[misns.at(i).nstop];
			for (int j = 0; j < misns.at(i).nstop; j++){
				misns.at(i).cost[j] = new double[misns.at(i).nstop];
				misns.at(i).cost0[j] = new double[misns.at(i).nstop];
				for (int k = 0; k < misns.at(i).nstop; k++){
					misns.at(i).cost[j][k] = 0;
					misns.at(i).cost0[j][k] = 0;
				}
			}
	 	}
		for (vector<Link>::iterator it = links.begin(); it != links.end(); it++){
			if (it->type == 'a'){
				if (misns.at(nodes.at(it->enode).misn).freq == -1){
					misns.at(nodes.at(it->enode).misn).freq = it->freq;
				}
				else{
					assert(misns.at(nodes.at(it->enode).misn).freq == it->freq);
				}
			}
			else if (it->type == 't'){
				if (misns.at(nodes.at(it->enode).misn).freq == -1){
					misns.at(nodes.at(it->enode).misn).freq = it->freq;
				}
				else{
					assert(misns.at(nodes.at(it->enode).misn).freq == it->freq);
				}
			}
			else if (it->type == 'm'){
				misns.at(nodes.at(it->snode).misn).ston[nodes.at(it->snode).stop] = it->snode;
				misns.at(nodes.at(it->enode).misn).ston[nodes.at(it->enode).stop] = it->enode;
				misns.at(nodes.at(it->enode).misn).cost[nodes.at(it->snode).stop][nodes.at(it->enode).stop] = it->cost;
				misns.at(nodes.at(it->enode).misn).cost0[nodes.at(it->snode).stop][nodes.at(it->enode).stop] = it->cost;
			}
		}
		for (int i = 0; i < nmisns; i++){
			misns.at(i).wtime = new double[misns.at(i).nstop];
			for (int k = 0; k < misns.at(i).nstop; k++){
				misns.at(i).wtime[k] = 1.0 / 2 / misns.at(i).freq * 60;
			}
			for (int j = 0; j < misns.at(i).nstop-2; j++){
				for (int k = j+2; k < misns.at(i).nstop; k++){
					for (int h = j; h+1 <= k; h++){
						misns.at(i).cost[j][k] += misns.at(i).cost[h][h+1];
						misns.at(i).cost0[j][k] += misns.at(i).cost0[h][h+1];
					}
				}
			}
		}
		nNonFicNode = nodes.size();
		nNonFicLink = links.size();
		nNonFicMisn = misns.size();
		return;
	}

	void GenerateFicMisns(){

		vector<vector<int>> pmisns;

		int nlieux = -1;
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
			if (it->lieu+1 > nlieux){
				nlieux = it->lieu+1;
			}
		}
		for (int i = 0;  i < nlieux; i++){
			lieux.push_back(Lieu(i));
		}
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
			if (it->lieu != -1){
				lieux.at(it->lieu).misns.push_back(it->misn);
				lieux.at(it->lieu).nodes.push_back(it->ID);
			}
		}
		for (int i = 0; i < lieux.size(); i++){
			if (lieux.at(i).misns.size() > 2){
				for (int j = 0; j < lieux.at(i).misns.size(); j++){
					Lieu lieu(lieux.at(i).ID);
					for (int  k = 0; k < lieux.at(i).misns.size(); k++){
						if (k != j){
							lieu.misns.push_back(lieux.at(i).misns.at(k));
							lieu.nodes.push_back(lieux.at(i).nodes.at(k));
						}
					}
					lieux.push_back(lieu);
				}
			}
		}
		for (int i = 0; i < lieux.size(); i++){
			for (int j = lieux.at(i).misns.size()-1; j > 0; j--){
				for (int k = 0; k < j; k++){
					if (lieux.at(i).misns.at(k) >= lieux.at(i).misns.at(k+1)){
						int temp1 = lieux.at(i).misns.at(k);
						lieux.at(i).misns.at(k) = lieux.at(i).misns.at(k+1);
						lieux.at(i).misns.at(k+1) = temp1;
						int temp2 = lieux.at(i).nodes.at(k);
						lieux.at(i).nodes.at(k) = lieux.at(i).nodes.at(k+1);
						lieux.at(i).nodes.at(k+1) = temp2;
					}
				}
			}
		}
		for (int i = 0; i < lieux.size(); i++){
			vector<int> vec;
			vec.push_back(i);
			int j;
			for (j = i+1; j < lieux.size(); j++){
				if (lieux.at(j).misns.size() == lieux.at(i).misns.size() && lieux.at(j).ID != -1){
					int k;
					for (k = 0; k < lieux.at(j).misns.size(); k++){
						if (lieux.at(i).misns.at(k) != lieux.at(j).misns.at(k))
							break;
					}
					if (k == lieux.at(j).misns.size()){
						lieux.at(j).ID = -1;
						vec.push_back(j);
					}
				}
			}
			if (vec.size() > 1){
				pmisns.push_back(vec);
			}
		}
		for (int i = 0; i < pmisns.size(); i++){
			for (int j = pmisns.at(i).size()-1; j > 0; j--){
				for (int k = 0; k < j; k++){
					if (nodes.at(lieux.at(pmisns.at(i).at(k)).nodes.at(0)).stop > nodes.at(lieux.at(pmisns.at(i).at(k+1)).nodes.at(0)).stop){
						int temp = pmisns.at(i).at(k);
						pmisns.at(i).at(k) = pmisns.at(i).at(k+1);
						pmisns.at(i).at(k+1) = temp;
					}
				}
			}
		}
		for (int i = 0; i < pmisns.size(); i++){
			int msize = misns.size();
			misns.push_back(Misn(msize));
			misns.at(msize).isfic = true;
			misns.at(msize).nstop = pmisns.at(i).size();
			misns.at(msize).ston = new int[misns.at(msize).nstop];
			misns.at(msize).pmisns = pmisns.at(i);
			double freq = 0;
			for (int p = 0; p < lieux.at(pmisns.at(i).at(0)).misns.size(); p++){
				freq += misns.at(lieux.at(pmisns.at(i).at(0)).misns.at(p)).freq;
			}
			misns.at(msize).freq = freq;
			misns.at(msize).wtime = new double[misns.at(msize).nstop];
			for (int k = 0; k < misns.at(msize).nstop; k++){
					misns.at(msize).wtime[k] = 0;
				}
			misns.at(msize).cost = new double*[misns.at(msize).nstop];
			for (int j = 0; j < misns.at(msize).nstop; j++){
				misns.at(msize).cost[j] = new double[misns.at(i).nstop];
				for (int k = 0; k < misns.at(msize).nstop; k++){
					misns.at(msize).cost[j][k] = 0;
				}
			}
			int newnode1, newnode2;
			for (int j = 0; j < pmisns.at(i).size()-1; j++){
				int snode = lieux.at(pmisns.at(i).at(j)).nodes.at(0);
				int enode = lieux.at(pmisns.at(i).at(j+1)).nodes.at(0);
				if (j == 0){
					newnode1 = nodes.size();
					nodes.push_back(Node(newnode1, 'f', msize, j, nodes.at(snode).zone));
					misns.at(msize).ston[j] = newnode1;
				}
				else{
					newnode1 = newnode2;
				}
				for (int it = 0; it < nodes.at(snode).inlinks.size(); it++){
					if (links.at(nodes.at(snode).inlinks.at(it)).type == 'm')
						continue;
					double freq = links.at(nodes.at(snode).inlinks.at(it)).freq;
					double cost = links.at(nodes.at(snode).inlinks.at(it)).cost;
					for (int k = 1; k < lieux.at(pmisns.at(i).at(j)).nodes.size(); k++){
						int snode2 = lieux.at(pmisns.at(i).at(j)).nodes.at(k);
						for (int it2 = 0; it2 < nodes.at(snode2).inlinks.size(); it2++){
							if (links.at(nodes.at(snode).inlinks.at(it)).snode == links.at(nodes.at(snode2).inlinks.at(it2)).snode){
								if (links.at(nodes.at(snode2).inlinks.at(it2)).freq != -1)
									freq += links.at(nodes.at(snode2).inlinks.at(it2)).freq;
								if (links.at(nodes.at(snode2).inlinks.at(it2)).cost > cost)
									cost = links.at(nodes.at(snode2).inlinks.at(it2)).cost;
								break;
							}
						}
					}
					AddLink(links.at(nodes.at(snode).inlinks.at(it)).snode, newnode1, cost, freq, links.at(nodes.at(snode).inlinks.at(it)).type);
				}
				newnode2 = nodes.size();
				nodes.push_back(Node(newnode2, 'f', msize, j+1, nodes.at(enode).zone));
				misns.at(msize).ston[j+1] = newnode2;
				double cost = 0;
				for (int it = 0; it < lieux.at(pmisns.at(i).at(j)).nodes.size(); it++){
					int snode1 = lieux.at(pmisns.at(i).at(j)).nodes.at(it);
					int enode1 = lieux.at(pmisns.at(i).at(j+1)).nodes.at(it);
					if (misns.at(nodes.at(snode1).misn).cost[nodes.at(snode1).stop][nodes.at(enode1).stop] > cost)
						cost = misns.at(nodes.at(snode1).misn).cost[nodes.at(snode1).stop][nodes.at(enode1).stop];
				}
				AddLink(newnode1, newnode2, cost, -1, 'm');
				for (int it = 0; it < nodes.at(enode).outlinks.size(); it++){
					if (links.at(nodes.at(enode).outlinks.at(it)).type == 'm')
						continue;
					double freq = links.at(nodes.at(enode).outlinks.at(it)).freq;
					double cost = links.at(nodes.at(enode).outlinks.at(it)).cost;
					for (int k = 1; k < lieux.at(pmisns.at(i).at(j+1)).nodes.size(); k++){
						int enode2 = lieux.at(pmisns.at(i).at(j+1)).nodes.at(k);
						for (int it2 = 0; it2 < nodes.at(enode2).outlinks.size(); it2++){
							if (links.at(nodes.at(enode).outlinks.at(it)).enode == links.at(nodes.at(enode2).outlinks.at(it2)).enode){
								if (links.at(nodes.at(enode2).outlinks.at(it2)).cost > cost)
									cost = links.at(nodes.at(enode2).outlinks.at(it2)).cost;
								break;
							}
						}
					}
					AddLink(newnode2, links.at(nodes.at(enode).outlinks.at(it)).enode, cost, freq, links.at(nodes.at(enode).outlinks.at(it)).type);
				}
			}
		}

		return;
	}

	void AddLink(int _snode, int _enode, double _cost, double _freq, char _type){
		Link l = Link();
		l.snode = _snode;
		l.enode = _enode;
		l.cost = _cost;
		l.freq = _freq;
		l.type = _type;
		links.push_back(l);
		nodes.at(_snode).outlinks.push_back(links.size()-1);
		nodes.at(_enode).inlinks.push_back(links.size()-1);
		return;
	}

	void GenerateZones(){
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
			if (it->type == 'z'){
				zones.push_back(Zone(zones.size(),it->zone));
			}
		}
		for (vector<Link>::iterator it = links.begin(); it != links.end(); it++){
			if (it->type == 'a'){
				bool flag = true;
				for (vector<int>::iterator it2 = zones.at(it->snode).nodes.begin(); it2 != zones.at(it->snode).nodes.end(); it2++){
					if ((*it2) == it->enode){
						flag = false;
						break;
					}
				}
				if (flag){
					zones.at(it->snode).nodes.push_back(it->enode);
				}
			}
			else if (it->type == 'e'){
				bool flag = true;
				for (vector<int>::iterator it2 = zones.at(it->enode).nodes.begin(); it2 != zones.at(it->enode).nodes.end(); it2++){
					if ((*it2) == it->snode){
						flag = false;
						break;
					}
				}
				if (flag){
					zones.at(it->enode).nodes.push_back(it->snode);
				}
			}
		}
		assert(zones.size() == Kz);
		return;
	}

	void EnumeratePaths(){
		for (int o = 0; o <  zones.size(); o++){
			vector<vector<int>> kpath;
			kpath.push_back(Dijkstra(o, 0, false));
			for (int k = 1; k < Kp; k ++){
				kpath.push_back(Dijkstra(o, k, true));
			}
			paths.push_back(kpath);
		}
	}

	vector<int> Dijkstra(int o, int k, bool random){
		std::random_device rd;
		std::default_random_engine gen;
//		gen.seed(1);
		switch (k){
		case 1:
			gen.seed(132);
			break;
		case 2:
			gen.seed(373);
			break;
		case 3:
			gen.seed(401);
			break;
		case 4:
			gen.seed(257);
			break;
		}
		std::tr1::normal_distribution<double> dist(1, 0.5);

		int size = nodes.size();
		vector<int> path, visited;
		vector<double> gcost;
		for (int i = 0; i < size; i++){
			path.push_back(-1);
			visited.push_back(-1);
			gcost.push_back(-100000);
		}
		gcost.at(o) = 0;
		queue<int> q;
		q.push(o);
		while (!q.empty()){
			int node = q.front();
			q.pop();
			if (visited.at(node) == -1){
				visited.at(node) = 1;
				for (int it = 0; it < nodes.at(node).outlinks.size(); it++){
					assert(links.at(nodes.at(node).outlinks.at(it)).snode == node);
					double gc;
					if (links.at(nodes.at(node).outlinks.at(it)).type == 'm')
						gc = links.at(nodes.at(node).outlinks.at(it)).cost * Bm;
					else if (links.at(nodes.at(node).outlinks.at(it)).type == 't')
						gc = links.at(nodes.at(node).outlinks.at(it)).cost * Bw + (1.0 / links.at(nodes.at(node).outlinks.at(it)).freq) * 60 * Bm + Bt;
					else if (links.at(nodes.at(node).outlinks.at(it)).type == 'a')
						gc = links.at(nodes.at(node).outlinks.at(it)).cost * Bw + (1.0 / links.at(nodes.at(node).outlinks.at(it)).freq) * 60 * Bm;
					else if (links.at(nodes.at(node).outlinks.at(it)).type == 'e')
						gc = links.at(nodes.at(node).outlinks.at(it)).cost * Bw;
					else if (links.at(nodes.at(node).outlinks.at(it)).type == 'w')
						gc = links.at(nodes.at(node).outlinks.at(it)).cost * Bw;
					if (random)
						gc *= max(dist(gen), 0.001);
					if (gcost.at(links.at(nodes.at(node).outlinks.at(it)).enode) < gcost.at(node) + gc){
						gcost.at(links.at(nodes.at(node).outlinks.at(it)).enode) = gcost.at(node) + gc;
						path.at(links.at(nodes.at(node).outlinks.at(it)).enode) = node;
					}
					if (visited.at(links.at(nodes.at(node).outlinks.at(it)).enode) == -1){
						q.push(links.at(nodes.at(node).outlinks.at(it)).enode);
					}
				}
			}
		}
		return path;
	}

	vector<vector<int>> GetODPaths(int o, int d){
		vector<vector<int>> odpaths;
		for (int k = 0; k < Kp; k ++){
			vector<int> odpath;
			int start = o;
			while (true){
				int end = d;
				while (true){
					if (paths.at(o).at(k).at(end) == start)
						break;
					else end = paths.at(o).at(k).at(end);
				}
				for (int i = 0; i < nodes.at(start).outlinks.size(); i++){
					if (links.at(nodes.at(start).outlinks.at(i)).enode == end){
						odpath.push_back(nodes.at(start).outlinks.at(i));
						break;
					}
				}
				start = end;
				if (start == d)
					break;
			}
			odpaths.push_back(odpath);
		}

		return odpaths;
	}

	vector<double> GetUtility(vector<vector<int>> odpaths){
		vector<double> odutility;
		for (int k = 0; k < Kp; k ++){
			double u = 0;
			for (int i = 0; i < odpaths.at(k).size(); i++){
				double gc;
				if (links.at(odpaths.at(k).at(i)).type == 'm')
					gc = links.at(odpaths.at(k).at(i)).cost * Bm;
				else if (links.at(odpaths.at(k).at(i)).type == 't'){
					int enode = links.at(odpaths.at(k).at(i)).enode;
					if (links.at(odpaths.at(k).at(i+1)).type == 't' || links.at(odpaths.at(k).at(i+1)).type == 'e')
						gc = links.at(odpaths.at(k).at(i)).cost * Bw + Bt;
					else 
						gc = links.at(odpaths.at(k).at(i)).cost * Bw + (1.0 / 2 / links.at(odpaths.at(k).at(i)).freq) * 60 * Bm + Bt;
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'a'){
					int enode = links.at(odpaths.at(k).at(i)).enode;
					if (links.at(odpaths.at(k).at(i+1)).type == 't' || links.at(odpaths.at(k).at(i+1)).type == 'e')
						gc = links.at(odpaths.at(k).at(i)).cost * Bw;
					else 
						gc = links.at(odpaths.at(k).at(i)).cost * Bw + (1.0 / 2 / links.at(odpaths.at(k).at(i)).freq) * 60 * Bm;
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'e')
					gc = links.at(odpaths.at(k).at(i)).cost * Bw;
				else if (links.at(odpaths.at(k).at(i)).type == 'w')
					gc = links.at(odpaths.at(k).at(i)).cost * Bw;
				u += gc;
			}
			odutility.push_back(u);
		}
		return odutility;
	}

	vector<double> GetPathSize(vector<vector<int>> odpaths){
		vector<double> odpathsize;
		vector<vector<PathSize>> pathsizes;
		for (int k = 0; k < Kp; k ++){
			vector<PathSize> pathsize;
			for (int i = 0; i < odpaths.at(k).size(); i++){
				if (nodes.at(links.at(odpaths.at(k).at(i)).snode).type != 'f' && nodes.at(links.at(odpaths.at(k).at(i)).enode).type != 'f'){
					pathsize.push_back(PathSize(odpaths.at(k).at(i), 1.0, links.at(odpaths.at(k).at(i)).cost));
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'a' ||
					links.at(odpaths.at(k).at(i)).type == 't' && nodes.at(links.at(odpaths.at(k).at(i)).snode).type != 'f'){
					int snode = links.at(odpaths.at(k).at(i)).snode;
					int misn = nodes.at(links.at(odpaths.at(k).at(i)).enode).misn;
					double freq = misns.at(misn).freq;
					vector<int> pnodes;
					for (int l = 0; l < misns.at(misn).nstop; l++){
						if (misns.at(misn).ston[l] == links.at(odpaths.at(k).at(i)).enode){
							pnodes = lieux.at(misns.at(misn).pmisns.at(l)).nodes;
							break;
						}
					}
					for (int j = 0; j < nodes.at(snode).outlinks.size(); j++){
						for (int k = 0; k < pnodes.size(); k++){
							if (links.at(nodes.at(snode).outlinks.at(j)).enode == pnodes.at(k)){
								pathsize.push_back(PathSize(nodes.at(snode).outlinks.at(j), misns.at(nodes.at(pnodes.at(k)).misn).freq / freq, links.at(nodes.at(snode).outlinks.at(j)).cost));
								break;
							}
						}
					}
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'e' ||
					links.at(odpaths.at(k).at(i)).type == 't' && nodes.at(links.at(odpaths.at(k).at(i)).enode).type != 'f'){
					int enode = links.at(odpaths.at(k).at(i)).enode;
					int misn = nodes.at(links.at(odpaths.at(k).at(i)).snode).misn;
					double freq = misns.at(misn).freq;
					vector<int> pnodes;
					for (int l = 0; l < misns.at(misn).nstop; l++){
						if (misns.at(misn).ston[l] == links.at(odpaths.at(k).at(i)).snode){
							pnodes = lieux.at(misns.at(misn).pmisns.at(l)).nodes;
							break;
						}
					}
					for (int j = 0; j < nodes.at(enode).inlinks.size(); j++){
						for (int k = 0; k < pnodes.size(); k++){
							if (links.at(nodes.at(enode).inlinks.at(j)).snode == pnodes.at(k)){
								pathsize.push_back(PathSize(nodes.at(enode).inlinks.at(j), misns.at(nodes.at(pnodes.at(k)).misn).freq / freq, links.at(nodes.at(enode).inlinks.at(j)).cost));
								break;
							}
						}
					}
				}
				else if (links.at(odpaths.at(k).at(i)).type == 't'){
					int snode = links.at(odpaths.at(k).at(i)).snode;
					int emisn = nodes.at(links.at(odpaths.at(k).at(i)).enode).misn;
					double efreq = misns.at(emisn).freq;			
					vector<int> epnodes;
					for (int l = 0; l < misns.at(emisn).nstop; l++){
						if (misns.at(emisn).ston[l] == links.at(odpaths.at(k).at(i)).enode){
							epnodes = lieux.at(misns.at(emisn).pmisns.at(l)).nodes;
							break;
						}
					}
					int smisn = nodes.at(links.at(odpaths.at(k).at(i)).snode).misn;
					double sfreq = misns.at(smisn).freq;
					vector<int> spnodes;
					for (int l = 0; l < misns.at(smisn).nstop; l++){
						if (misns.at(smisn).ston[l] == links.at(odpaths.at(k).at(i)).snode){
							spnodes = lieux.at(misns.at(smisn).pmisns.at(l)).nodes;
							break;
						}
					}
					for (int j1 = 0; j1 < nodes.at(snode).outlinks.size(); j1++){
						for (int k1 = 0; k1 < epnodes.size(); k1++){
							if (links.at(nodes.at(snode).outlinks.at(j1)).enode == epnodes.at(k1)){
								int enode = links.at(nodes.at(snode).outlinks.at(j1)).enode;
								for (int j2 = 0; j2 < nodes.at(enode).inlinks.size(); j2++){
									for (int k2 = 0; k2 < spnodes.size(); k2++){
										if (links.at(nodes.at(enode).inlinks.at(j2)).snode == spnodes.at(k2)){
											pathsize.push_back(PathSize(
												nodes.at(enode).inlinks.at(j2),
												misns.at(nodes.at(epnodes.at(k1)).misn).freq * misns.at(nodes.at(spnodes.at(k2)).misn).freq / sfreq / efreq,
												links.at(nodes.at(enode).inlinks.at(j2)).cost));
											break;
										}
									}
								}
							}
						}
					}
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'm'){
					int emisn = nodes.at(links.at(odpaths.at(k).at(i)).enode).misn;			
					vector<int> epnodes, epmisns;
					for (int l = 0; l < misns.at(emisn).nstop; l++){
						if (misns.at(emisn).ston[l] == links.at(odpaths.at(k).at(i)).enode){
							epnodes = lieux.at(misns.at(emisn).pmisns.at(l)).nodes;
							epmisns = lieux.at(misns.at(emisn).pmisns.at(l)).misns;
							break;
						}
					}
					int smisn = nodes.at(links.at(odpaths.at(k).at(i)).snode).misn;
					vector<int> spnodes, spmisns;
					for (int l = 0; l < misns.at(smisn).nstop; l++){
						if (misns.at(smisn).ston[l] == links.at(odpaths.at(k).at(i)).snode){
							spnodes = lieux.at(misns.at(smisn).pmisns.at(l)).nodes;
							spmisns = lieux.at(misns.at(smisn).pmisns.at(l)).misns;
							break;
						}
					}
					assert(emisn == smisn);
					assert(epmisns.size() == spmisns.size());
					double freq = misns.at(emisn).freq;
					for (int j = 0; j < epmisns.size(); j++){
						assert(epmisns.at(j) == spmisns.at(j));
						for (int k = 0; k < misns.at(epmisns.at(j)).nstop; k++){
							if (misns.at(epmisns.at(j)).ston[k] == spnodes.at(j)){
								int snode = spnodes.at(j);
								while (true) {
									int enode = -1;
									for (int p = 0; p < nodes.at(snode).outlinks.size(); p++){
										if (nodes.at(links.at(nodes.at(spnodes.at(j)).outlinks.at(p)).enode).misn == epmisns.at(j)){
											pathsize.push_back(PathSize(
												nodes.at(spnodes.at(j)).outlinks.at(p),
												misns.at(epmisns.at(j)).freq / freq,
												links.at(nodes.at(spnodes.at(j)).outlinks.at(p)).cost));
											enode = links.at(nodes.at(spnodes.at(j)).outlinks.at(p)).enode;
											break;
										}
									}
									if (enode == epnodes.at(j))
										break;
									else 
										snode = enode;
								}
							}
						}
					}
				}
			}
			pathsizes.push_back(pathsize);
		}
		for (int k = 0; k < Kp; k ++){
			double pssum = 0;
			double ps = 0;
			for (int i = 0; i < pathsizes.at(k).size(); i++){
				double linkoccr = 0;
				for (int k2 = 0; k2 < Kp; k2 ++){
					for (int i2 = 0; i2 < pathsizes.at(k2).size(); i2++){
						if (pathsizes.at(k).at(i).link == pathsizes.at(k2).at(i2).link){
							linkoccr += pathsizes.at(k2).at(i2).proba / pathsizes.at(k).at(i).proba;
							break;
						}
					}
				}
				ps += pathsizes.at(k).at(i).cost * pathsizes.at(k).at(i).proba / linkoccr;
				pssum += pathsizes.at(k).at(i).cost * pathsizes.at(k).at(i).proba;
			}
			odpathsize.push_back(ps/pssum);
		}
		return odpathsize;
	}

	vector<double> GetProbaPSLogit(vector<double> odUtility, vector<double> odPathSize){
		vector<double> odProba;
		double sum = 0;
		for (int k = 0; k < Kp; k ++){
			sum += exp(odUtility.at(k) + Bps * log(odPathSize.at(k)));
		}
		for (int k = 0; k < Kp; k ++){
			if (abs(sum) < SMALL )
				odProba.push_back(0.0);
			else
				odProba.push_back( exp(odUtility.at(k) + Bps * log(odPathSize.at(k))) / sum );
		}
		return odProba;
	}

	vector<double> GetProbaLogit(vector<double> odUtility){
		vector<double> odProba;
		double sum = 0;
		for (int k = 0; k < Kp; k ++){
			sum += exp(odUtility.at(k));
		}
		for (int k = 0; k < Kp; k ++){
			if (abs(sum) < SMALL)
				odProba.push_back(0.0);
			else
				odProba.push_back( exp(odUtility.at(k)) / sum );
		}
		return odProba;
	}

	vector<double> GetProbaShortest(vector<double> odUtility){
		vector<double> odProba;
		double max = 0.0;
		int nmax = -1;
		for (int k = 0; k < Kp; k ++){
			if (exp(odUtility.at(k)) > max){
				max = exp(odUtility.at(k));
				nmax = k;
			}
		}
		for (int k = 0; k < Kp; k ++){
			if (k == nmax)
				odProba.push_back(1.0);
			else 
				odProba.push_back(0.0);
		} 
		return odProba;
	}

	void ClearLoad(){
		for (int i = 0; i < nNonFicMisn; i++){
			for (int m = 0; m < misns.at(i).nstop; m++){
				for (int n = 0; n < misns.at(i).nstop; n++){
					misns.at(i).flow[m][n] = 0;
				}
			}
		}
	}

	void LoadODPair(int o, int d, vector<double> odProba){
		vector<vector<int>> odPaths = GetODPaths(o, d);
		for (int k = 0; k < Kp; k++){
			int sstop, estop;
			int misn = -1;
			for (int i = 0; i < odPaths.at(k).size(); i++){
				if (links.at(odPaths.at(k).at(i)).type != 'm' && misn == -1)
					continue;
				else if (links.at(odPaths.at(k).at(i)).type == 'm' && misn == -1){
					misn = nodes.at(links.at(odPaths.at(k).at(i)).snode).misn;
					sstop = nodes.at(links.at(odPaths.at(k).at(i)).snode).stop;
					estop = nodes.at(links.at(odPaths.at(k).at(i)).enode).stop;
				}
				else if (links.at(odPaths.at(k).at(i)).type == 'm' && misn != -1){
					assert(misn == nodes.at(links.at(odPaths.at(k).at(i)).snode).misn);
					estop = nodes.at(links.at(odPaths.at(k).at(i)).enode).stop;
				}
				else if (links.at(odPaths.at(k).at(i)).type != 'm' && misn != -1){
					if (misn < nNonFicMisn){
						misns.at(misn).flow[sstop][estop] += OD[o][d] * odProba.at(k);
					}
					else{
						double freq = misns.at(misn).freq;
						vector<int> spnodes = lieux.at(misns.at(misn).pmisns.at(sstop)).nodes;
						vector<int> epnodes = lieux.at(misns.at(misn).pmisns.at(estop)).nodes;
						for (int j = 0; j < spnodes.size(); j++){
							assert(nodes.at(spnodes.at(j)).misn == nodes.at(epnodes.at(j)).misn);
							misns.at(nodes.at(spnodes.at(j)).misn).flow[nodes.at(spnodes.at(j)).stop][nodes.at(epnodes.at(j)).stop] +=
								OD[o][d] * odProba.at(k) * misns.at(nodes.at(spnodes.at(j)).misn).freq / freq;
						}
					}
					misn = -1;
				}
			}
		}
		return;
	}

	void MSAIteration(int k) {
		for (int i = 0; i < nNonFicMisn; i++){
			for (int m = 0; m < misns.at(i).nstop; m++){
				for (int n = 0; n < misns.at(i).nstop; n++){
					if (k == 1)
						misns.at(i).mflow[m][n] = misns.at(i).flow[m][n];
					else {
						misns.at(i).mflow[m][n] = (k-1)/(double)k * misns.at(i).mflow[m][n] + 1.0/k * misns.at(i).flow[m][n];
					}
				}
			}
		}
		return;
	}

	void SimpleIteration() {
		for (int i = 0; i < nNonFicMisn; i++){
			for (int m = 0; m < misns.at(i).nstop; m++){
				for (int n = 0; n < misns.at(i).nstop; n++){
					misns.at(i).mflow[m][n] = misns.at(i).flow[m][n];
				}
			}
		}
		return;
	}

	void IncrementalIteration(double inc){
		for (int i = 0; i < nNonFicMisn; i++){
			for (int m = 0; m < misns.at(i).nstop; m++){
				for (int n = 0; n < misns.at(i).nstop; n++){
					misns.at(i).mflow[m][n] += inc * misns.at(i).flow[m][n];
				}
			}
		}
		return;
	}

	double AlphaSeat(double y){
		if (y < 0.75*sK)
			return 1.0;
		else if (y < 1.5*sK)
			return (0.32 * (y/sK - 0.75) + 1);
		else
			return (0.16 * (y/sK - 1.5) + 0.75 * 0.32 + 1);
	}

	double AlphaStand(double y){
		if (y < sK)
			return 1.0;
		else if (y < 1.5*sK)
			return (0.4 * (y/sK - 1) + 1.2);
		else
			return (0.2 * (y/sK - 1.5) + 0.5 * 0.4 + 1.2);
	}

	void SeatAllocation(){
		for (int i = 0; i < nNonFicMisn; i++){
			int n = misns.at(i).nstop;
			double **qin = new double*[n];
			double **qout = new double*[n];
			for (int o = 0; o < n; o++){
				qin[o] = new double[n];
				qout[o] = new double[n];
				for (int d = 0; d < n; d++){
					qin[o][d] = misns.at(i).mflow[o][d] / (H * misns.at(i).freq);
				}
			}
			double **ya1 = new double*[n];
			double **ya2 = new double*[n];
			double **yb1 = new double*[n];
			double **yb2 = new double*[n];
			for (int o = 0; o < n; o++){
				ya1[o] = new double[n];
				ya2[o] = new double[n];
				yb1[o] = new double[n];
				yb2[o] = new double[n];
				for (int d = 0; d < n; d++){
					ya1[o][d] = 0;
					ya2[o][d] = 0;
					yb1[o][d] = 0;
					yb2[o][d] = 0;
				}
			}
			double *p = new double[n];
			double *pa = new double[n];
			double *pb = new double[n];
			double *b = new double[n];
			double *y = new double[n];
			int k1 = misns.at(i).skapa;
			int k2 = misns.at(i).tkapa - k1;
			double rk1 = k1, rk2 = k2;
			for (int s = 0 ; s < n-1; s++){
				double qsum = 0; 
				for (int d = s+1; d < n; d++){
					qsum += qin[s][d];
				}
				if (abs(rk1 + rk2) < SMALL)
					p[s] = 0.0;
				else if (abs(qsum) < SMALL)
					p[s] = 1.0; 
				else
					p[s] = min(1.0, (rk1 + rk2) / (qsum));
				for (int d = s+1; d < n; d++){
					qout[s][d] = qin[s][d] * p[s];
				}
				b[s] = qsum * p[s];

				if (abs(p[s]) < SMALL)
					misns.at(i).wtime[s] = BIG;
				else 
					misns.at(i).wtime[s] = 60 / 2 / misns.at(i).freq + 60 * H / 2 * (1 - p[s]) / p[s];

				if (abs(rk1) < SMALL)
					pb[s] = 0.0;
				else if (abs(b[s]) < SMALL)
					pb[s] = 1.0; 
				else
					pb[s] = min(1.0, rk1 / (b[s]));
				for (int d = s+1; d < n; d++){
					yb1[s][d] = ya1[s][d] + pb[s] * qout[s][d];
					yb2[s][d] = ya2[s][d] + (1-pb[s]) * qout[s][d];	
				}
				rk1 = rk1 - pb[s] * b[s];
				rk2 = rk2 - (1-pb[s]) * b[s];

				y[s] = 0;
				for (int d = s+1; d < n; d++){
					y[s] += yb1[s][d] + yb2[s][d];
				}
				assert (abs(y[s] - (k1 + k2 - rk1 -rk2)) < SMALL);

				rk1 = rk1 + yb1[s][s+1];
				rk2 = rk2 + yb2[s][s+1];
				if (abs(rk1) < SMALL)
					pa[s+1] = 0.0;
				else if (abs(k2 - rk1) < SMALL)
					pa[s+1] = 1.0; 
				else
					pa[s+1] = min(1.0, rk1 / (k2 - rk1));
				for (int d = s+2; d < n; d++){
					ya1[s+1][d] = yb1[s][d] + yb2[s][d] * pa[s+1];
					rk1 = rk1 - yb2[s][d] * pa[s+1];
					ya2[s+1][d] = yb2[s][d] - yb2[s][d] * pa[s+1];
					rk2 = rk2 + yb2[s][d] * pa[s+1];
				}
			}

			for (int d = n-1; d > 0; d--){
				for (int o = d-1; o >= 0; o--){
					if (d-o == 1){
						misns.at(i).cost[o][d] = (pb[o] * AlphaSeat(y[o]) + (1-pb[o]) * AlphaStand(y[o])) * misns.at(i).cost0[o][d];
					}
					else {
						double c1 = 0;
						for (int k = o; k < d; k++){
							c1 += AlphaSeat(y[k]) * misns.at(i).cost0[k][k+1];
						}
						double c2 = 0;
						for (int k = o+1; k < d; k++){
							c2 += AlphaSeat(y[k]) * misns.at(i).cost0[k][k+1];
						}
						misns.at(i).cost[o][d] = pb[o] * c1 + 
							(1-pb[o]) * (AlphaStand(y[o]) * misns.at(i).cost0[o][o+1] + pa[o+1] * c2 + (1-pa[o+1] * misns.at(i).cost[o+1][d]));
					}
				}
			}
		}

		return;
	}

	vector<double> GetCongestedUtility(vector<vector<int>> odpaths){
		vector<double> odutility;
		for (int k = 0; k < Kp; k ++){
			double u = 0;
			for (int i = 0; i < odpaths.at(k).size(); i++){
				double gc = 0.0;
				if (links.at(odpaths.at(k).at(i)).type == 'm') {
					int snode = links.at(odpaths.at(k).at(i)).snode;
					while (links.at(odpaths.at(k).at(i+1)).type == 'm'){
						i++;
					}
					int enode = links.at(odpaths.at(k).at(i)).enode;
					assert(nodes.at(snode).misn == nodes.at(enode).misn);
					gc = misns.at(nodes.at(snode).misn).cost[nodes.at(snode).stop][nodes.at(enode).stop] * Bm;
				}
				else if (links.at(odpaths.at(k).at(i)).type == 't'){
					int enode = links.at(odpaths.at(k).at(i)).enode;
					if (links.at(odpaths.at(k).at(i+1)).type == 't' || links.at(odpaths.at(k).at(i+1)).type == 'e')
						gc = links.at(odpaths.at(k).at(i)).cost * Bw + Bt;
					else 
						gc = links.at(odpaths.at(k).at(i)).cost * Bw + misns.at(nodes.at(enode).misn).wtime[nodes.at(enode).stop] * Bm + Bt;
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'a'){
					int enode = links.at(odpaths.at(k).at(i)).enode;
					if (links.at(odpaths.at(k).at(i+1)).type == 't' || links.at(odpaths.at(k).at(i+1)).type == 'e')
						gc = links.at(odpaths.at(k).at(i)).cost * Bw;
					else {
						gc = links.at(odpaths.at(k).at(i)).cost * Bw;
						gc += misns.at(nodes.at(enode).misn).wtime[nodes.at(enode).stop] * Bm;
					}
				}
				else if (links.at(odpaths.at(k).at(i)).type == 'e')
					gc = links.at(odpaths.at(k).at(i)).cost * Bw;
				else if (links.at(odpaths.at(k).at(i)).type == 'w')
					gc = links.at(odpaths.at(k).at(i)).cost * Bw;
				u += gc;
			}
			odutility.push_back(u);
		}
		return odutility;
	}

	void RecalculateFicMisns(){
		for (int i = nNonFicMisn; i < misns.size(); i++){
			for (int s = 0; s < misns.at(i).nstop - 1; s++){
				double freq = 0.0;
				for (int k = 0; k < lieux.at(misns.at(i).pmisns.at(s)).misns.size(); k++){
					freq += 60 / 2 / misns.at(lieux.at(misns.at(i).pmisns.at(s)).misns.at(k)).wtime[nodes.at(lieux.at(misns.at(i).pmisns.at(s)).nodes.at(k)).stop];
				}
				misns.at(i).wtime[s] = 60 / 2 / freq;
			}
			for (int s = 0; s < misns.at(i).nstop - 1; s++){
				for (int t = s+1; t < misns.at(i).nstop; t++){
					double cost = 0.0;
					for (int k = 0; k < lieux.at(misns.at(i).pmisns.at(s)).misns.size(); k++){
						double mcost = misns.at(lieux.at(misns.at(i).pmisns.at(s)).misns.at(k)).cost
							[nodes.at(lieux.at(misns.at(i).pmisns.at(s)).nodes.at(k)).stop][nodes.at(lieux.at(misns.at(i).pmisns.at(t)).nodes.at(k)).stop];
						if (mcost > cost)
							cost = mcost;
					}
					misns.at(i).cost[s][t] = cost;
				}
			}
		}
	}

	vector<double> LoadGap(int k, int methodIteration){
		vector<double> Gap;
		double RG;
		RG = 0.0;
		switch (methodIteration) {
		case ITERATION_MSA:
			for (int i = 0; i < nNonFicMisn; i++){
				for (int m = 0; m < misns.at(i).nstop; m++){
					for (int n = 0; n < misns.at(i).nstop; n++){
						double mflow;
						if (k == 1)
							mflow = misns.at(i).flow[m][n];
						else {
							mflow = (k-1)/(double)k * misns.at(i).mflow[m][n] + 1.0/k * misns.at(i).flow[m][n];
						}
						RG += abs(misns.at(i).mflow[m][n] - mflow);
					}
				}
			}
			Gap.push_back(RG);
			RG = 0.0;
			for (int i = 0; i < nNonFicMisn; i++){
				for (int m = 0; m < misns.at(i).nstop; m++){
					for (int n = 0; n < misns.at(i).nstop; n++){
						double mflow;
						if (k == 1)
							mflow = misns.at(i).flow[m][n];
						else {
							mflow = (k-1)/(double)k * misns.at(i).mflow[m][n] + 1.0/k * misns.at(i).flow[m][n];
						}
						RG += (misns.at(i).mflow[m][n] - mflow);
					}
				}
			}
			Gap.push_back(RG);
			break;
		case ITERATION_SIMPLE:
			for (int i = 0; i < nNonFicMisn; i++){
				for (int m = 0; m < misns.at(i).nstop; m++){
					for (int n = 0; n < misns.at(i).nstop; n++){
						RG += abs(misns.at(i).mflow[m][n] - misns.at(i).flow[m][n]);
					}
				}
			}
			Gap.push_back(RG);
			RG = 0.0;
			for (int i = 0; i < nNonFicMisn; i++){
				for (int m = 0; m < misns.at(i).nstop; m++){
					for (int n = 0; n < misns.at(i).nstop; n++){
						RG += misns.at(i).mflow[m][n] - misns.at(i).flow[m][n];
					}
				}
			}
			Gap.push_back(RG);
			break;
		case ITERATION_INC:
			return Gap;
		}
		return Gap;
	}

	double UtilityGap(int o, int d, vector<double> odUtility, vector<double> odPathSize, vector<double> odProba){
		double RG = 0.0;
		double max = 0.0;
		int nmax = -1;
		double bps = 0.0;
		for (int k = 0; k < odProba.size(); k++){
			if (exp(odUtility.at(k) + bps * log(odPathSize.at(k))) > max){
				max = exp(odUtility.at(k) + bps * log(odPathSize.at(k)));
				nmax = k;
			}
		}
		for (int k = 0; k < odProba.size(); k++){
			RG += (max - exp(odUtility.at(k) + bps * log(odPathSize.at(k)))) * odProba.at(k);
		}
		RG *= OD[o][d];
		return RG;
	}
};


#endif