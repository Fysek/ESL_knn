#include "MNISTdatabase.h"

std::string filename_images_test = "C:/t10k-images-idx3-ubyte";
std::string filename_label_test = "C:/t10k-labels-idx1-ubyte";
std::string filename_images_train = "C:/train-images-idx3-ubyte";
std::string filename_label_train = "C:/train-labels-idx1-ubyte";

std::vector<std::vector<double> > vec_images_test;
std::vector<std::vector<double> > vec_images_train;
std::vector<double> vec_label_test;
std::vector<double> vec_label_train;


void distance(std::vector<std::vector <double>> &vec) {//vector vec [10k][60k] for 10k vector 60k distances
	//include data
	read_Mnist_Image(filename_images_test, vec_images_test);
	read_Mnist_Image(filename_images_train, vec_images_train);
	//calculate the distance between 10k test and 60k train
	for (int i = 0; i < vec_images_test.size(); ++i)
	{
		
		for (;;)//rows
		{
			for (;;)//columns
			{

			}
		}
		//sqrt()
		//vec.push_back(tp);
	}
}

void assign_label(std::vector <double > &vec){//assign the label using knn, vec contains assigned labels for 10k test images
	read_Mnist_Label(filename_label_train, vec_label_train);
	for (;;) {}


}

void compare(std::vector <double> &assigned_labels_vec){//compare assigned label with the provided one
	read_Mnist_Label(filename_label_test, vec_label_test);
	for (int i=0; i < assigned_labels_vec.size();i++) {
	
	}


}


