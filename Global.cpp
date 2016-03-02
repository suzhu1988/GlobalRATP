#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

#include "Graph.h"

void PrintGraphInfo(Graph G){
	cout << "Graph Details:" << endl;
	cout << "Graph has " << G.nodes.size() << " nodes; " << G.nNonFicNode << " of them are non-fictive." << endl;
	cout << "Graph has " << G.links.size() << " links; " << G.nNonFicLink << " of them are non-fictive." << endl;
	cout << "Graph has " << G.misns.size() << " missions; " << G.nNonFicMisn << " of them are non-fictive." << endl;
	cout << "Graph has " << G.zones.size() << " zones." << endl;
	cout << endl;
}

void PrintZoneInfo(Graph G){
	for (vector<Zone>::iterator it = G.zones.begin(); it != G.zones.end(); it++){
		sort(it->nodes.begin(), it->nodes.end());
		cout << "Zone " << it->ID << " has nodes ";
		for (vector<int>::iterator it2 = it->nodes.begin(); it2 != it->nodes.end(); it2++){
			cout << *it2 << " ";
		}
		cout << ";" << endl;
	}
	cout << endl;
}

void PrintMisnInfo(Graph G){
	for (vector<Misn>::iterator it = G.misns.begin(); it != G.misns.end(); it++){
		cout << "Mission " << it->ID;
		if (it->isfic == false)
			cout << ", non-fictive";
		else {
			cout << ", fictive";
			for (int j = 0; j < G.lieux.at(it->pmisns.at(0)).nodes.size(); j++){
				if (j == 0)
					cout << "(M" << G.lieux.at(it->pmisns.at(0)).misns.at(j);
				else 
					cout << ",M" << G.lieux.at(it->pmisns.at(0)).misns.at(j);
			}
			cout << ")";
		}
		cout << ", frequency " << it->freq << endl;
		for (int i = 0; i < it->nstop; i++){
			if (i == 0){
				cout << "  " << it->nstop << " stations: " << it->ston[i];
				if (it->isfic){
					for (int j = 0; j < G.lieux.at(it->pmisns.at(i)).nodes.size(); j++){
						if (j == 0)
							cout << "(" << G.lieux.at(it->pmisns.at(i)).nodes.at(j);
						else 
							cout << "," << G.lieux.at(it->pmisns.at(i)).nodes.at(j);
					}
					cout << ")";
				}
			}
			else {
				cout << " -> " << it->ston[i];
				if (it->isfic){
					for (int j = 0; j < G.lieux.at(it->pmisns.at(i)).nodes.size(); j++){
						if (j == 0)
							cout << "(" << G.lieux.at(it->pmisns.at(i)).nodes.at(j);
						else 
							cout << "," << G.lieux.at(it->pmisns.at(i)).nodes.at(j);
					}
					cout << ")";
				}
			}
		}
		cout << ";" << endl;
	}
	cout << endl;
}

void PrintODPaths(int o, int d, Graph G, vector<vector<int>> odPaths, vector<double> odUtility, vector<double> odPathSize, vector<double> odProba){
	if (G.links.at(odPaths.at(0).front()).snode != o || G.links.at(odPaths.at(0).back()).enode != d)
		return;

	for (int i = 0; i < odPaths.size(); i++){
		cout << "Path " << i << ": " << G.links.at(odPaths.at(i).at(0)).snode;
		for (int j = 0; j < odPaths.at(i).size(); j++){
			cout << " -> " << G.links.at(odPaths.at(i).at(j)).enode;
		}
		cout << endl;
		cout << "  U: " << odUtility.at(i) << ", PS: " << odPathSize.at(i) << ", Pr: " << odProba.at(i) << "." << endl;
	}
	cout << endl;
}

void PrintMisnLoad(int m, Graph G){
	if (m >= G.nNonFicMisn)
		return;
	cout << "Missions " << m << endl;
	cout << "Load:" << endl;
	for (int i = 0; i < G.misns.at(m).nstop; i++){
		for (int j = 0; j < G.misns.at(m).nstop; j++){
			cout << "\t" << G.misns.at(m).mflow[i][j];
		}
		cout << endl;
	}
	cout << "Cost:" << endl;
	for (int i = 0; i < G.misns.at(m).nstop; i++){
		for (int j = 0; j < G.misns.at(m).nstop; j++){
			cout << "\t" << G.misns.at(m).cost[i][j];
		}
		cout << endl;
	}
	cout << "Wait time:" << endl;
	for (int i = 0; i < G.misns.at(m).nstop; i++){
		cout << "\t" << G.misns.at(m).wtime[i];
	}
	cout << endl;
}

void PrintGap(int k, vector<double> Gap){
	cout << "Step " << k << "\t"; 
	for (int i = 0; i < Gap.size(); i++)
		cout << Gap.at(i) << "\t";
	cout << endl;
}

void SaveLoadJson(Graph G, int k){
	char data[100];
	char str_name[] = "    \"name\": \"Link ";
	char str_load[] = "    \"load\": ";
	char str_load2[] = ",";

	ifstream infile;
	ofstream outfile;
	infile.open("Leaflet/Data/loadlinks_0.json");
	char str_outfile[] = "Leaflet/Data/loadlinks_";
	char str_outfile2[5];
	char str_outfile3[] = ".json";
	strcpy(data, str_outfile);
	strcat(data, itoa(k, str_outfile2, 10));
	strcat(data, str_outfile3);
	outfile.open(data);

	infile.getline(data, 100);
	char str_headline[] = "loadlinks[";
	char str_headline2[5];
	char str_headline3[] = "] = [{";
	strcpy(data, str_headline);
	strcat(data, itoa(k, str_headline2, 10));
	strcat(data, str_headline3);
	outfile << data << endl;

	while (!infile.eof()){
		infile.getline(data, 100);
		if (strncmp(data, str_name, 10) == 0){
			outfile << data << endl;
			char str_link[10];
			int i = 18;
			while (data[i] != '\"'){
				str_link[i-18] = data[i];
				i++;
			}
			str_link[i-18] = (char)0;
			int int_link = atoi(str_link);

			double load = 0.0;
			assert(G.links.at(int_link).type == 'm');
			int snode = G.links.at(int_link).snode;
			int enode = G.links.at(int_link).enode;
			int misn = G.nodes.at(snode).misn;
			int sstop = G.nodes.at(snode).stop;
			int estop = G.nodes.at(enode).stop;
			assert(estop - sstop == 1);
			for (int i = 0; i < G.misns.at(misn).nstop; i++){
				for (int j = i+1; j < G.misns.at(misn).nstop; j++){
					if (i <= sstop && j >= estop){
						load += G.misns.at(misn).mflow[i][j];
					}
				}
			}

			infile.getline(data, 100);
			strcpy(data, str_load);
			strcat(data, itoa((int)(load / (H * G.misns.at(misn).freq)), str_link, 10));
			strcat(data, str_load2);
			outfile << data << endl;
		}
		else{
			outfile << data << endl;
		}
	}
	infile.close();
	outfile.close();
}


int main(){

	int methodIteration = ITERATION_MSA;
	int methodProba = PROBA_PSLOGIT;

	double inc[Ki] = {0.4, 0.2, 0.1, 0.05, 0.05, 0.05, 0.05, 0.05, 0.03, 0.02};
	
	Graph G;

	G.GenerateLinks();
	G.GenerateMisns();
	G.GenerateFicMisns();
	G.GenerateZones();
	
//	PrintGraphInfo(G);
//	PrintZoneInfo(G);
//	PrintMisnInfo(G);
	
	G.EnumeratePaths();

	for (int k = 1; k <= Ks; k++){
		G.RecalculateFicMisns();
		G.ClearLoad();
		for (int o = 0; o < Kz; o++){
			for (int d = 0; d < Kz; d++){
				if (o == d)
					continue;

				vector<vector<int>> odPaths = G.GetODPaths(o, d);
				vector<double> odUtility = G.GetCongestedUtility(odPaths);
				vector<double> odPathSize = G.GetPathSize(odPaths);
				
				vector<double> odProba;
				switch (methodProba){
				case PROBA_PSLOGIT:
					odProba = G.GetProbaPSLogit(odUtility, odPathSize);
					break;
				case PROBA_LOGIT:
					odProba = G.GetProbaLogit(odUtility);
					break;
				case PROBA_SHORTEST:
					odProba = G.GetProbaShortest(odUtility);
					break;
				}
				
				PrintODPaths(0, 4, G, odPaths, odUtility, odPathSize, odProba);

				G.LoadODPair(o, d, odProba);
			}
		}

		vector<double> Gap = G.LoadGap(k, methodIteration);
		PrintGap(k, Gap);

		switch (methodIteration) {
		case ITERATION_MSA:
			G.MSAIteration(k);
			break;
		case ITERATION_SIMPLE:
			G.SimpleIteration();
			break;
		case ITERATION_INC:
			if (k <= Ki)
				G.IncrementalIteration(inc[k-1]);
			break;
		}
		
		G.SeatAllocation();

//		PrintMisnLoad(0, G);

		SaveLoadJson(G, k);

		getchar();
	}

	return 0;
}
