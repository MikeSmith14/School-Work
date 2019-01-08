/*
	This is the cpp file for the Stat.h header. This file included the function definitions of calc() and correlation().
*/

#include "Stat.h"
#include <iostream>
#include <math.h> 

using namespace std;

//Calculates all the needed values from the list to provide into the formula for correlation
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

	averx = (sumx / n);
	avery = (sumy / n);


}

//Calls calc() then uses the class variables to calculate the passed lists correlation value.
float stats::correlation(Singly_llist x) {

	calc(x);
	
	corr = (n*prodxy - (sumx * sumy)) / (sqrt((n*xsq - (sumx * sumx)) * (n*ysq - (sumy * sumy))));

	return corr;
}

//Calculates the significance of the data sets, using the class variable corr as the r value in the expressions.
float stats::significance() {

	if (corr == 0) {
		cout << "Please calculate correlation first before you calculate signifance" << endl;
	}

	if (abs(corr) > 0.7) {
		cout << "R is a valid value, calculating Significance." << endl;
		return ((abs(corr)) * (sqrt(n - 2))) / (sqrt(1 - (corr*corr)));
	} else {
		cout << "R is not a valid number, unable to calculate significance." << endl;
		return 0;
	}
}

//Calculates the Beta One of the set and returns it as a float
float stats::betaOne() {

	beta1 = ((prodxy - (n*(averx * avery))) / (xsq - (n * (averx * averx))));
	return beta1;
}

//Calculates the Beta Zero of the set using the value of Beta one, returns as a float
float stats::betaZero() {

	beta0 = (avery - (beta1 * averx));
	return beta0;
}

//Calculates the variance of the set, returns a float
float stats::variance(Singly_llist x) {

	Node *temp;
	float num = 0;

	for (temp = x.begin(); temp != NULL; temp = temp->forward) {
		num = num + (((temp->data2) - beta0 - (beta1 * temp->data)) * ((temp->data2) - beta0 - (beta1 * temp->data)));
	}

	var = ((1 / (n - 2)) * num);
	return var;
}

//Uses variance to calculate the standard deviation and returns as a float
float stats::standardDeviation() {
	stddev = sqrt(var);
	return stddev;
}

//Calculates the range and outputs the upper and lower as well
void stats::range(Singly_llist x) {
	float N = 644.43;
	float xk = 386;
	float t70 = 1.108;
	float t90 = 1.860;
	int answer;
	float num = 0;
	Node *temp;

	for (temp = x.begin(); temp != NULL; temp = temp->forward) {
			num = num + ((temp->data - averx) * (temp->data - averx));
		}
	

	ran = (t70 * stddev * (sqrt(1 + (1 / n) + (((xk - averx)*(xk - averx)) / num))));
	cout << "The range is: " << ran << ". The upper is: " << N + ran << ". The lower is: " << N - ran << "." << endl;

	ran = (t90 * stddev * (sqrt(1 + (1 / n) + (((xk - averx)*(xk - averx)) / num))));
	cout << "The range is: " << ran << ". The upper is: " << N + ran << ". The lower is: " << N - ran << "." << endl;

}