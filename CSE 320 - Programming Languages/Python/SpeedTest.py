
# Michael Smtih
# Lab 3 Python
# CSE 320 Programming Languages

import time
start_time = time.time()

def partition(arr,low,high):
	i = ( low-1 )		 
	pivot = arr[high]	 

	for j in range(low , high):
		if arr[j] <= pivot:
			i = i+1
			arr[i],arr[j] = arr[j],arr[i]
	arr[i+1],arr[high] = arr[high],arr[i+1]
	return ( i+1 )

def quickSort(arr,low,high):
	if low < high:
		pi = partition(arr,low,high)
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)

# One Set for speed testing
data1= [ 8389,	41705,	55440,	49803,	83858,
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
					31361,	37327,	78019,	45864,	50048 ]


n1 = len(data1)
quickSort(data1,0,n1-1)

print ("Sorted array 1 is:")
for i in range(n1):
	print ("%d" %data1[i])

print("--- %s seconds ---" % (time.time() - start_time))





