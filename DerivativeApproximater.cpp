/* Author:	Raphael J. Sandor 
* Date:	9/16/2019
* Version:	1.0	
*  
* Description: This program computes an approximate value for the derivative
* of f(x) using the finite difference formula.
* 
* For the derivative of sin(x), which is cos(x).
*/

#include <iostream>
#include <math.h>
#include <iomanip> 
#include <cstring>
#include <fstream>
#include <sstream>

#include "DerivativeApproximater.h"


using namespace std;
double const known	= cos(1);
double const x		= 1;

int main(int  argc, char *argv[])
{
	//Do the derivative of (f(x+h) -f(x)) )/ h 
	double approx[30];
	double absErr[30];
	fPrime(approx);
	printTable(approx, absErr);
	makeCSV(approx, absErr);
}

/*
 * Prints the table of the results
 */
void printTable (double* approxResult, double* absErr)
{
	cout << "|  h   |        x       | Approx. f'(x)  |  Known f'(x)  |  Abs. Error   |" << endl;
	cout << "|:----:|---------------:|---------------:|--------------:|--------------:|" << endl;

	for(int i = 0; i < 30; i++)
	{
		absErr[i]=abs(approxResult[i]-known);													//X																			
		cout << "|2^-"<< setprecision(8) << setw(2) << left << i+1 << " " <<  "|" << setw(15) << right << setprecision(8) << fixed << 1.00000000  << " |" <<
		// Approx							//Known										//	Abs. Error		
		setw(16) << approxResult[i]  << "|" << setw(15) << known  << "|" << setw(15) <<  absErr[i]<< "|" << endl;
	}
}

void fPrime(double *approxResult)
{
	
	double qoutient		= 0; 
	double h			= pow(2, -1);
	double result		= 0;
	for(int i = 0; i < 30; i++)
	{
		qoutient	= sin(x+h)-sin(x);
		result		= abs(qoutient/h);
		
		//get the next h 	
		h = pow(2, -(i+2));
		
		approxResult[i] = result;
	}
}

void makeCSV(double* approxResult, double* absErr)
{
	std::ostringstream stream;
	ofstream outF;
	outF.open("calculations.csv");
	outF << "h, x, approx, known, abs. err. \n";
	for(int i = 0; i < 30; i++)
	{
		stream << pow(2, -(i+1)) << ",";
		string sH		= stream.str(); 
		stream.str("");
		stream << x << ",";
		string sX		= stream.str();
		stream.str("");
		stream << approxResult[i] << ",";
		string sApprox	= stream.str();
		stream.str("");
		stream << known << ",";
		string sKnown	= stream.str();
		stream.str("");
		stream << known << ",";
		stream.str("");
		stream << absErr[i];
		string sAbsErr	= stream.str(); 
		outF <<  sH  << sX << sApprox <<  sKnown  << sAbsErr << "\n";
	}
	outF << "semi;colon";
	outF.close();
}

