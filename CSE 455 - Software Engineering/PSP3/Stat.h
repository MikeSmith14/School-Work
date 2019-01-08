

#ifndef STAT_H
#define STAT_H

#include "Singly_LList.h"


class stats {

private:
	float sumx;
	float sumy;
	float xsq;
	float ysq;
	float corr;
	float prodxy;
	float n;

public:
	stats() {
		sumx = 0;
		sumy = 0;
		xsq = 0;
		ysq = 0;
		corr = 0;
		prodxy = 0;
		n = 0;
	}
	void calc(Singly_llist x);
	float correlation(Singly_llist x);
};
#endif 
