#include <cstdlib>
#include <string>
#include "MNISTread.h"
#include "KNNfunctions.h"
//wyswietlanie vectorow


int main()
{
	std::string filename_images_10k = "t10k-images-idx3-ubyte.gz";
	int number_of_images = 10000;
	int image_size = 28 * 28;

	std::vector<std::vector<double> > vec_images_10k;
	read_Mnist(filename_images_10k, vec_images_10k);
	std::cout << vec_images_10k.size() << std::endl;
	//std::cout << vec_images_10k[0].size() << std::endl;


	
	//read MNIST label into double vector
	std::string filename_label_10k = "t10k-labels-idx1-ubyte.gz";
	int number_of_labels = 10000;


	std::vector<double> vec_label_10k; // (number_of_labels);
	read_Mnist_Label(filename_label_10k, vec_label_10k);
	std::cout << vec_label_10k.size() << std::endl;
	
	system("pause");
	return 0;
}