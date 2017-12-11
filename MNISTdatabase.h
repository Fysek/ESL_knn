#include <cstdlib>
#include <string>
#include <math.h>
#include "MNISTread.h"
#define KNN 7
#define TEN 10

const std::string filename_images_test = "C:/t10k-images-idx3-ubyte";
const std::string filename_label_test = "C:/t10k-labels-idx1-ubyte";
const std::string filename_images_train = "C:/train-images-idx3-ubyte";
const std::string filename_label_train = "C:/train-labels-idx1-ubyte";

void distance(
	unsigned int** tab_test,
	unsigned int** tab_train,
	unsigned int** tab_dist
	);

void assign_label(
	unsigned int* tab_train_label,
	unsigned int** tab_distance,
	unsigned int* tab_assigned_labels
	);

float compare(
	unsigned int* tab_test_label,
	unsigned int* tab_assigned_labels
	);