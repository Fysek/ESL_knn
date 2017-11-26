#include "MNISTdatabase.h"

std::vector<std::vector<unsigned int> > vec_images_test;
std::vector<std::vector<unsigned int> > vec_images_train;
std::vector<unsigned int> vec_label_test;
std::vector<unsigned int> vec_label_train;

void distance(std::vector<std::vector <unsigned int>> &vec_dist) {//vector vec [10k][60k] for 10k vector 60k distances
	//include data
	read_Mnist_Image(filename_images_test, vec_images_test);
	read_Mnist_Image(filename_images_train, vec_images_train);
	//calculate the distance between 10k test and 60k train
	for (int i = 0; i < vec_images_test.size(); ++i)
	{
		std::vector<unsigned int> tp;
		unsigned int temp;

		for (int j = 0; j < 28 ; j++ )//rows
		{
			for (int k = 0; k < 28 ;k++)//columns
			{

			}
		}
		//sqrt()
		vec_dist.push_back(tp);
	}
}

std::vector <unsigned int> assign_label(std::vector<std::vector <unsigned int>> &vec_dist){//assign the label using knn, vec contains assigned labels for 10k test images
	std::vector <unsigned int> assigned_labels_vec;
	read_Mnist_Label(filename_label_train, vec_label_train);
	for (;;) {}

	return assigned_labels_vec;
}

float compare(std::vector <unsigned int> &assigned_labels_vec){//compare assigned label with the provided one
	int valid_value = 0;
	float efficiency = 0;
	read_Mnist_Label(filename_label_test, vec_label_test);
	for (int i=0; i < assigned_labels_vec.size();i++) {
		if (assigned_labels_vec[i] = vec_label_test[i])
			valid_value++;
	}
	efficiency = valid_value/assigned_labels_vec.size();
	return efficiency;
}


