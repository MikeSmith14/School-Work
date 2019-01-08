// Michael Smith
// C Lab for Quicksort
// This file is for the runtime measuring of the algorithm over an 100 int array.

#include <time.h>
#include <stdio.h>

int partition(int arr[], int low, int high);
void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);


int main() {

	//Setting up clock to measure run time of the program
	clock_t t1, t2;
	t1 = clock();

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

	//Sorting Arrays
	//1st
	int n = sizeof(data1) / sizeof(data1[0]);
	quickSort(data1, 0, n - 1);

	//Printing Arrays after sorting
	printf("First Set after sorting");
	printArray(data1, 100);
	printf("\n");

	t2 = clock();
	float diff = ((float)t2 - (float)t1);
	float seconds = (diff / CLOCKS_PER_SEC);
	printf("Runtime is ");
	printf("%f", seconds);


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