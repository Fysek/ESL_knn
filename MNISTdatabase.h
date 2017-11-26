#include <cstdlib>
#include <string>
#include "MNISTread.h"

const std::string filename_images_test = "C:/t10k-images-idx3-ubyte";
const std::string filename_label_test = "C:/t10k-labels-idx1-ubyte";
const std::string filename_images_train = "C:/train-images-idx3-ubyte";
const std::string filename_label_train = "C:/train-labels-idx1-ubyte";

void distance(std::vector<std::vector <unsigned int>> &vec_dist);
std::vector <unsigned int> assign_label(std::vector<std::vector <unsigned int>> &vec_dist);
float compare(std::vector <unsigned int> &assigned_labels_vec);