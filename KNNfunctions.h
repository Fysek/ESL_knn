#include <cmath>
#include <iostream>
#include <algorithm>

struct Point
{
	int val;     // Group of point
	double x, y;     // Co-ordinate of point
	double distance; // Distance from test point
};
bool comparison(Point a, Point b);
int classifyAPoint(Point arr[], int n, int k, Point p);