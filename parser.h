#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "specs.h"

using namespace std;

//int* parse();

inline vector<int> parse(const string filepath) {
	vector<int> parsed_program;
	ifstream in(filepath.c_str());
	string line;

	getline(in, line);
	while (!in.fail()) {
		string buf; // create a buffer string
		stringstream ss(line); // Insert the string into a stream

		// reads every element and tries to write it
		while (ss >> buf) {	
			if (buf.at(0) > '9' || buf.at(0) < '0')
				parsed_program.push_back(cpuMap.at(buf));
			else
				parsed_program.push_back(stoi(buf));
		}
		getline(in, line);
	}

	return parsed_program;
}