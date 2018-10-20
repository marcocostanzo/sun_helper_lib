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


#ifndef MYLIB_HELPER_H
#define MYLIB_HELPER_H

#include <TooN/TooN.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "HelperColors.h"

//TooN::Vector<> readFileV(const char* path,unsigned  int dim);
TooN::Vector<> readFileV(const std::string& path,unsigned  int dim);// { return readFileV(path.c_str() , dim); }
//TooN::Matrix<> readFileM(const char* path,unsigned  int n_r,unsigned  int n_c);
TooN::Matrix<> readFileM(const std::string& path,unsigned  int n_r,unsigned  int n_c);//{ return readFileM(path.c_str(), n_r, n_c); }

/* == ASK FOR CHAR == */
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
char askForChar( const char* str);

#endif
