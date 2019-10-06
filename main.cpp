/**
 *===========================================================================
 * Copyright 2019 Mateusz Dyrdół. All rights reserved.
 *===========================================================================
 *
 * Main function
 *
 * This is the main function for k nearest neighbours algorithm to predict numbers in MNIST database of handwritten digits.
 * MNIST dataset contains 60,000 training images and 10,000 testing images.
 * Every image is a 28x28 pixel box in 8-bit grayscale.
 * Pixels are organized row-wise. Pixel values are 0 to 255. 0 means background (white), 255 means foreground (black).
 *  
 * Output is the efficiency of algorithm.
 * Default k is set to 7
 *
 * Note: Please define TEST_SIZE and TRAIN_SIZE in MNISTread.h before executing 
 * Note: Please define MNIST files paths in MNISTdatabe.h before executing
 * More about MNIST: http://yann.lecun.com/exdb/mnist/
 *
 */

#include "MNISTread.h"
#include "MNISTdatabase.h"

int main()
{
	/*variables*/
	unsigned int** tab_test_image = new unsigned int*[TEST_SIZE];
	for (int i = 0; i < TEST_SIZE; ++i) {
		tab_test_image[i] = new unsigned int[PIXEL_SIZE];
	}
	
	unsigned int** tab_train_image = new unsigned int*[TRAIN_SIZE];
	for (int j = 0; j < TRAIN_SIZE; ++j) {
		tab_train_image[j] = new unsigned int[PIXEL_SIZE];
	}

	unsigned int** tab_dist = new unsigned int*[TEST_SIZE];
	for (int k = 0; k < TEST_SIZE; ++k) {
		tab_dist[k] = new unsigned int[TRAIN_SIZE];
	}
	
	unsigned int** tab_train_label_dist = new unsigned int*[TEST_SIZE];
	for (int k = 0; k < TEST_SIZE; ++k) {
		tab_train_label_dist[k] = new unsigned int[TRAIN_SIZE];
	}

	unsigned int* tab_train_label = new unsigned int[TRAIN_SIZE];
	
	unsigned int* tab_test_label = new unsigned int[TEST_SIZE];

	unsigned int* tab_assigned_labels = new unsigned int[TEST_SIZE];

	float eff = 0;

	/*functions*/
	distance(tab_test_image, tab_train_image, tab_dist);
	assign_label(tab_train_label, tab_dist, tab_train_label_dist, tab_assigned_labels);
	eff = compare(tab_test_label, tab_assigned_labels);
	std::cout << "efficiency: " << eff << "%"<<std::endl;

	/*cleaning*/
	for(int i = 0; i < TEST_SIZE; ++i) {
		delete [] tab_test_image[i];
	}
	delete [] tab_test_image;
	
	for(int i = 0; i < TRAIN_SIZE; ++i) {
		delete [] tab_train_image[i];
	}
	delete [] tab_train_image;
	
	for(int i = 0; i < TEST_SIZE; ++i) {
		delete [] tab_dist[i];
	}
	delete [] tab_dist;
	
	for(int i = 0; i < TEST_SIZE; ++i) {
		delete [] tab_train_label_dist[i];
	}
	delete [] tab_train_label_dist;
	
	delete [] tab_train_label;
	delete [] tab_test_label;
	delete [] tab_assigned_labels;
	
	system("pause");
	return 0;
}