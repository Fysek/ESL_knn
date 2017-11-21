// C++ program to find groups of unknown
// Points using K nearest neighbour algorithm.
#include "KNNfunctions.h"


bool comparison(Point a, Point b)
{
	return (a.distance < b.distance);
}
// This function finds classification of point p using
// k nearest neighbour algorithm. It assumes only two
// groups and returns 0 if p belongs to group 0, else
// 1 (belongs to group 1).
int classifyAPoint(Point arr[], int n, int k, Point p)
{
	// Fill distances of all points from p
	for (int i = 0; i < n; i++)
		arr[i].distance =
		sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + (arr[i].y - p.y) * (arr[i].y - p.y));

	// Sort the Points by distance from p
	std::sort(arr, arr + n, comparison);

	// Now consider the first k elements and only
	// two groups
	int freq1 = 0;   // Frequency of group 0
	int freq2 = 0;   // Frequency of group 1
	for (int i = 0; i < k; i++)
	{
		if (arr[i].val == 0)
			freq1++;
		else if (arr[i].val == 1)
			freq2++;
	}

	return (freq1 > freq2 ? 0 : 1);
}

// Driver code
/*															  */
/*	int main()												  */
/*	{														  */
/*		const int n = 17; // Number of data points			  */
/*		Point arr[n];										  */
/*															  */
/*		arr[0].x = 1;										  */
/*		arr[0].y = 12;										  */
/*		arr[0].val = 0;										  */
/*															  */
/*		///itd...											  */
/*		arr[16].x = 1;										  */
/*		arr[16].y = 7;										  */
/*		arr[16].val = 0;									  */
													 
		/*Testing Point*/									 
/*		Point p;											  */
/*		p.x = 2.5;											  */
/*		p.y = 7;											  */
/*															  */
/*		// Parameter to decide groupr of the testing point	  */
/*		int k = 3;											  */
/*		printf("The value classified to unknown point"		  */
/*			" is %d.\n", classifyAPoint(arr, n, k, p));		  */
/*		return 0;											  */
/*	}														  */
/*															  */
														  