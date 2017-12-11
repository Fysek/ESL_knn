#include <iostream>
#include <vector>
#include <fstream>
#define TEST_SIZE 1000
#define TRAIN_SIZE 5000
#define PIXEL_SIZE 784

int ReverseInt(int i);
void read_Mnist_Image_Train(std::string filename, unsigned int** tab_train);
void read_Mnist_Image_Test(std::string filename, unsigned int** tab_test);
void read_Mnist_Label_Train(std::string filename, unsigned int* tab_train_label);
void read_Mnist_Label_Test(std::string filename, unsigned int* tab_test_label);

