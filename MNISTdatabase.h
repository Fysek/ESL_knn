#include <cstdlib>
#include <string>
#include <math.h>
#include "MNISTread.h"
#include "KNNfunctions.h"


const std::string filename_images_test = "C:/t10k-images-idx3-ubyte";
const std::string filename_label_test = "C:/t10k-labels-idx1-ubyte";
const std::string filename_images_train = "C:/train-images-idx3-ubyte";
const std::string filename_label_train = "C:/train-labels-idx1-ubyte";

void distance(
	unsigned int tab_test[TEST_SIZE][PIXEL_SIZE],
	unsigned int tab_train[TRAIN_SIZE][PIXEL_SIZE],
	unsigned int tab_dist[TRAIN_SIZE][PIXEL_SIZE]
	);

void assign_label(
	unsigned int tab_train_label[TRAIN_SIZE],
	unsigned int tab_distance[TEST_SIZE][TRAIN_SIZE],
	unsigned int tab_assigned_labels[TEST_SIZE],
	int k
	);

float compare(
	unsigned int tab_test_label[TEST_SIZE],
	unsigned int tab_assigned_labels[TEST_SIZE]
	);