/**
 *===========================================================================
 * Copyright 2019 Mateusz Dyrdół. All rights reserved.
 *===========================================================================
 *
 */
 
#ifndef MNISTDATABASE_H
#define MNISTDATABASE_H
 
#include <cstdlib>
#include <string>
#include <math.h>
#include "MNISTread.h"
#define KNN 7
#define TEN 10

/* MNIST files paths */
const std::string filename_images_test = "t10k-images-idx3-ubyte";
const std::string filename_label_test = "t10k-labels-idx1-ubyte";
const std::string filename_images_train = "train-images-idx3-ubyte";
const std::string filename_label_train = "train-labels-idx1-ubyte";

void distance(
	unsigned int** tab_test,
	unsigned int** tab_train,
	unsigned int** tab_dist
	);

void assign_label(
	unsigned int* tab_train_label,
	unsigned int** tab_distance,
	unsigned int** tab_train_label_dist,
	unsigned int* tab_assigned_labels
);

float compare(
	unsigned int* tab_test_label,
	unsigned int* tab_assigned_labels
	);
	
#endif /* MNISTDATABASE_H */
	