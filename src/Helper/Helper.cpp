/*
    Helper Lib

    Copyright 2017-2018 Università della Campania Luigi Vanvitelli

	Author: Marco Costanzo <marco.costanzo@unicampania.it>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Helper.h>

using namespace TooN;
using namespace std;

Vector<> readFileV(const string& path, unsigned int dim){
	FILE *f;
	f = fopen(path.c_str(), "r");
	if (f == NULL){
		printf(BOLDRED "Error opening file..." CRESET);
		printf(BOLDBLUE " %s\n" CRESET,path.c_str());
		throw std::runtime_error("Could not open file");
	}

	Vector<> out = Zeros(dim);
	double tmp;
	for (int i = 0; i < dim; i++) {
		fscanf(f, "%lf,", &tmp);
		out[i] = tmp;
	}
	fclose(f);

	return out;
}



Matrix<> readFileM(const string& path, unsigned int n_r, unsigned int n_c){
	FILE *f;
	f = fopen(path.c_str(), "r");
	if (f == NULL){
		printf(BOLDRED "Error opening file..." CRESET);
		printf(BOLDBLUE " %s\n" CRESET,path.c_str());
		throw std::runtime_error("Could not open file");
	}

	Matrix<> out = Zeros(n_r,n_c);
	double tmp;
	for (int i = 0; i < n_r; i++) {
		for (int j = 0; j < n_c; j++) {
			fscanf(f, "%lf", &tmp);
			out[i][j] = tmp;
		}
	}
	fclose(f);

	return out;
}


char askForChar( const char* str){
	/* USAGE
	char ans = askForChar( "Continue? [y = YES / n = nextIter / e = exit ]: " );
		switch( ans ){
			case 'n' :
			case 'N' :
				continue;
			case 'y' :
			case 'Y' :
			case 's' :
			case 'S' :
				break;
			default:
				exit(1);			
		}
		ans = 0;
	*/

	char ans;
	cout << str;
	cin >> ans;
	cout << endl;

	return ans;
}

double SchmittTrigger( double input, bool& state, double min, double max, double output_when_active ){
	if( !state && input < min ){
		state = true;
	} else if( state && input > max ){
		state = false;
	}
	if(state){
		return output_when_active;
	}
	return input;
}
