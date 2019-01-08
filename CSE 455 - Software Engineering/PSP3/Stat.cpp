#include "Stat.h"
#include<iostream>
#include <math.h> 

using namespace std;

void stats::calc(Singly_llist x) {
	
	Node *temp;
	
	for (temp = x.begin(); temp != NULL; temp = temp->forward) {
		sumx = sumx + temp->data;
		xsq = xsq + (temp->data * temp->data);
		sumy = sumy + temp->data2;
		ysq = ysq + (temp->data2 * temp->data2);
		prodxy = prodxy + (temp->data * temp->data2);
		n++;
	}


}

float stats::correlation(Singly_llist x) {

	calc(x);
	
	corr = (n*prodxy - (sumx * sumy)) / (sqrt((n*xsq - (sumx * sumx)) * (n*ysq - (sumy * sumy))));

	return corr;
}