/*
	This class is made to calculate the correlation between two sets of numbers. It is passed a Singly_llist into the correlation function.
	Then correlation sends the list to the calc function to calculate all the needed values for the final calculation of r. Calc can not
	does not need to be called outside of the class. Correlation will call the calc function and pass the parameter.
*/

#ifndef STAT_H
#define STAT_H

#include "Singly_LList.h"


class stats{

private:
	float sumx;
	float sumy;
	float xsq;
	float ysq;
	float corr;
	float prodxy;
	float n;
	float avery;
	float averx;
	float beta1;
	float beta0;
	float var;
	float stddev;
	float ran;
	float upper;
	float lower;

public:
	stats(){
		sumx = 0;
		sumy = 0;
		xsq = 0;
		ysq = 0;
		corr = 0;
		prodxy = 0;
		n = 0;
		beta1 = 0;
		beta0 = 0;
	}
	void calc(Singly_llist x);
	float correlation(Singly_llist x);
	float significance();
	float betaOne();
	float betaZero();
	float variance(Singly_llist x);
	float standardDeviation();
	void range(Singly_llist x);
};
#endif 
