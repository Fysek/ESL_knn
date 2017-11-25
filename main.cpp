#include <cstdlib>
#include <string>
#include "MNISTread.h"
#include "KNNfunctions.h"
//wyswietlanie vectorow


int main()
{
	std::string filename_images_10k = "C:/Users/Fysek/Documents/Visual Studio 2015/Projects/ESL_knn/ESL_knn/t10k-images-idx3-ubyte";
	std::vector<std::vector<double> > vec_images_10k;
	read_Mnist(filename_images_10k, vec_images_10k);
	std::cout << vec_images_10k.size() << std::endl;
	for (int i = 0; i < vec_images_10k.size();i++) {
			std::cout << vec_images_10k[i][20]<<std::endl;
	}
	
	//read MNIST label into double vector
	std::string filename_label_10k = "C:/Users/Fysek/Documents/Visual Studio 2015/Projects/ESL_knn/ESL_knn/t10k-labels-idx1-ubyte";
	std::vector<double> vec_label_10k; // (number_of_labels);
	read_Mnist_Label(filename_label_10k, vec_label_10k);
	std::cout << vec_label_10k.size() << std::endl;
	//for (int i = 0; i < vec_label_10k.size();i++)
	//	std::cout << vec_label_10k[i] << std::endl;
	

	system("pause");
	return 0;
}