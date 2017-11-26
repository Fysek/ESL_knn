#include <cstdlib>
#include <string>
#include <math.h>
#include "MNISTread.h"
#include "KNNfunctions.h"


const std::string filename_images_test = "C:/t10k-images-idx3-ubyte";
const std::string filename_label_test = "C:/t10k-labels-idx1-ubyte";
const std::string filename_images_train = "C:/train-images-idx3-ubyte";
const std::string filename_label_train = "C:/train-labels-idx1-ubyte";

std::vector<std::vector<unsigned int>> distance(
	std::vector<std::vector<unsigned int>> &vec_images_test,
	std::vector<std::vector<unsigned int>> &vec_images_train
	);

std::vector <unsigned int> assign_label(
	std::vector<unsigned int> &vec_label_train,
	std::vector<std::vector <unsigned int>> &vec_dist
	);

float compare(
	std::vector<unsigned int> &vec_label_test,
	std::vector <unsigned int> &assigned_labels_vec
	);