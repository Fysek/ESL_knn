#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#define TEST_SIZE 10000
#define TRAIN_SIZE 60000



unsigned int classify_label(
	std::vector<unsigned int> &vec_label_train,
	std::vector<std::vector <unsigned int>> vec_dist,
	int k
);