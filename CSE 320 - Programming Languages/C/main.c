// Michael Smith
// C Lab for Quicksort
// This file is for the 5 multiple sets to run on the algorithm over an 100 int array.

#include <stdio.h>

int partition(int arr[], int low, int high);
void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);


int main() {

	//Multiple sets for testing
	int data1[100] = { 8389,	41705,	55440,	49803,	83858,
					31120,	93579,	38904,	50096,	71802,
					76960,	2818,	12335,	11089,	17154,
					26067,	95870,	88013,	79460,	74341,
					8044,	88389,	86132,	60750,	48412,
					5850,	89701,	91661,	57370,	57190,
					56867,	28112,	6560,	65027,	94299,
					51655,	13587,	25357,	50894,	76139,
					45930,	3375,	14244,	96612,	60667,
					1702,	49443,	44349,	91948,	66122,
					90074,	4371,	92212,	71058,	63988,
					55892,	43701,	65765,	20906,	2492,
					97986,	77830,	61432,	43604,	38210,
					26985,	56302,	1076,	21377,	17783,
					19316,	3810,	7072,	29368,	85428,
					42233,	36912,	7259,	64490,	52030,
					38953,	33072,	22882,	85857,	30802,
					39660,	71532,	86490,	88070,	6391,
					58737,	95610,	8551,	28514,	57788,
					31361,	37327,	78019,	45864,	50048 };

	int data2[100] = { 8389,	4175,	5440,	4903,	8858,
		3110,	3579,	3904,	50096,	1802,
		7660,	818,	12335,	11089,	1154,
		2067,	5870,	8013,	79460,	7441,
		8044,	8389,	86132,	6750,	48412,
		5850,	9701,	1661,	5370,	57190,
		5867,	8112,	6560,	6527,	4299,
		5165,	1587,	2357,	5894,	7139,
		4530,	3375,	14244,	9612,	6067,
		1702,	9443,	4349,	9948,	6612,
		9074,	471,	9212,	71058,	63988,
		5892,	431,	65765,	2906,	492,
		9986,	7783,	6432,	43604,	3210,
		2985,	6302,	176,	1377,	17783,
		1316,	310,	7072,	29368,	8528,
		42233,	3612,	759,	4490,	5200,
		3953,	3302,	2882,	5857,	802,
		9660,	7132,	6490,	88070,	391,
		8737,	9610,	551,	2514,	5788,
		1361,	3727,	719,	4864,	5048 };

	int data3[100] = { 8389,	4105,	5540,	4803,	3858,
		3120,	9357,	3890,	5096,	7182,
		7960,	218,	1235,	1089,	1154,
		2667,	9580,	8803,	7940,	4341,
		844,	8838,	8612,	6050,	48412,
		5850,	8701,	91661,	5370,	57190,
		56867,	2812,	6560,	6027,	94299,
		51655,	1357,	2357,	50894,	76139,
		45930,	3375,	4244,	96612,	60667,
		1702,	4943,	4349,	91948,	66122,
		9004,	4371,	9212,	71058,	63988,
		5592,	43701,	6575,	20906,	2492,
		9986,	77830,	61432,	4304,	38210,
		26985,	5602,	1076,	2377,	17783,
		1316,	3810,	7072,	29368,	85428,
		42233,	3692,	7259,	6449,	5030,
		3953,	3372,	2282,	8557,	3002,
		3660,	7152,	6490,	88070,	6391,
		5837,	95610,	8551,	2854,	5788,
		3161,	3327,	7819,	4864,	5048 };

	int data4[100] = { 8389,	4170,	5440,	4903,	8858,
		310,	939,	384,	596,	712,
		760,	28,		125,	189,	1154,
		267,	970,	13,		760,	7341,
		844,	889,	6132,	750,	8412,
		550,	701,	9161,	570,	5190,
		567,	112,	6560,	627,	9299,
		555,	1587,	357,	508,	7139,
		430,	375,	244,	962,	667,
		172,	443,	349,	948,	6612,
		974,	471,	212,	758,	6388,
		892,	401,	765,	206,	292,
		986,	730,	432,	404,	810,
		285,	502,	076,	277,	1783,
		316,	310,	72,		368,	5428,
		423,	392,	79,		490,	5230,
		953,	332,	882,	857,	3802,
		390,	712,	490,	880,	391,
		737,	950,	51,		284,	5788,
		311,	377,	789,	864,	48 };

	int data5[100] = { 83,	417,	55,	498,	838,
		311,	93,		38,		50,		718,
		769,	28,		125,	110,	171,
		26,		970,	813,	790,	741,
		80,		889,	832,	600,	412,
		58,		891,	911,	570,	590,
		568,	2112,	660,	627,	999,
		515,	1387,	357,	504,	769,
		459,	75,		144,	962,	607,
		172,	443,	349,	918,	622,
		974,	71,		922,	718,	638,
		552,	401,	665,	206,	249,
		979,	730,	432,	404,	380,
		269,	302,	106,	277,	173,
		116,	38,		702,	298,	854,
		423,	36912,	759,	690,	520,
		353,	33072,	282,	857,	302,
		390,	712,	860,	870,	631,
		587,	956,	851,	214,	588,
		313,	373,	789,	464,	548 };

	//Printing Arrays before sorting
	printf("First Set before sorting");
	printArray(data1, 100);
	printf("\n");

	printf("Second Set before sorting");
	printArray(data2, 100);
	printf("\n");

	printf("Third Set before sorting");
	printArray(data3, 100);
	printf("\n");

	printf("Fourth Set before sorting");
	printArray(data4, 100);
	printf("\n");

	printf("Fifth Set before sorting");
	printArray(data5, 100);
	printf("\n");

	//Sorting Arrays
	//1st
	int n = sizeof(data1) / sizeof(data1[0]);
	quickSort(data1, 0, n - 1);
	//2nd
	n = sizeof(data2) / sizeof(data2[0]);
	quickSort(data2, 0, n - 1);
	//3rd
	n = sizeof(data3) / sizeof(data3[0]);
	quickSort(data3, 0, n - 1);
	//4th
	n = sizeof(data4) / sizeof(data4[0]);
	quickSort(data4, 0, n - 1);
	//5th
	n = sizeof(data5) / sizeof(data5[0]);
	quickSort(data5, 0, n - 1);

	//Printing Arrays after sorting
	printf("First Set after sorting");
	printArray(data1, 100);
	printf("\n");

	printf("Second Set after sorting");
	printArray(data2, 100);
	printf("\n");

	printf("Third Set after sorting");
	printArray(data3, 100);
	printf("\n");

	printf("Fourth Set after sorting");
	printArray(data4, 100);
	printf("\n");

	printf("Fifth Set after sorting");
	printArray(data5, 100);
	printf("\n");

	int tests;
	tests = getchar();
	return 0;
	
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];     
	int i = (low - 1);   

	for (int j = low; j <= high - 1; j++)
	{ 
		if (arr[j] <= pivot)
		{
			i++;     
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{		
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}