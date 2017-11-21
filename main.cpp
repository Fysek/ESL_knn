#include "MNISTread.h"
#include "knn_functions.h"

int main()
{
	std::string filename = "mnist/t10k-images-idx3-ubyte";
	int number_of_images = 10000;
	int image_size = 28 * 28;

	std::vector<std::vector<double> > vec1;
	read_Mnist(filename, vec1);
	std::cout << vec1.size() << std::endl;
	std::cout << vec1[0].size() << std::endl;


	
	//read MNIST label into double vector
	std::string filename = "mnist/t10k-labels-idx1-ubyte";
	int number_of_images = 10000;


	std::vector<double> vec(number_of_images);
	read_Mnist_Label(filename, vec);
	std::cout << vec.size() << std::endl;

	return 0;
}