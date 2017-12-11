#include <iostream>
#include <vector>
#include <fstream>
#define TEST_SIZE 100
#define TRAIN_SIZE 600
#define PIXEL_SIZE 784



/*

struct testImage {
	unsigned short label;
	unsigned short index;
	std::vector<unsigned short> pixels;//r,c - 1,1 1,2 1,2 ... 28,27 28,28
	std::vector<unsigned int> distance;//60k wartosci 
};

struct trainImage {
	unsigned short label;
	unsigned short index;
	std::vector<unsigned short> pixels;
};
*/


int ReverseInt(int i);
void read_Mnist_Image_Train(std::string filename, unsigned int** tab_train);
void read_Mnist_Image_Test(std::string filename, unsigned int** tab_test);
void read_Mnist_Label_Train(std::string filename, unsigned int* tab_train_label);
void read_Mnist_Label_Test(std::string filename, unsigned int* tab_test_label);

