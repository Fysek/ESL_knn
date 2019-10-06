/**
 *===========================================================================
 * Copyright 2019 Mateusz Dyrdół. All rights reserved.
 *===========================================================================
 */

#include "MNISTdatabase.h"

/**
 * Distance between two images
 *
 * This function calculates euclidean distance between two images for set amount training and testing images.
 * For every pixel in one image there is one corresponding pixel in second image.
 * Substract values of two corresponding pixels and raise to power of two. Then add result to sum.
 * Square root of sum is a distance between two pixels.
 *
 * @param tab_test - double pointer to array with test images
 * @param tab_train - double pointer to array with train images
 * @param tab_dist - double pointer to array with distance of images
 * @return void.
 */
void distance(
	unsigned int** tab_test,
	unsigned int** tab_train,
	unsigned int** tab_dist
	) 
{ 
	read_Mnist_Image_Test(filename_images_test, tab_test);
	read_Mnist_Image_Train(filename_images_train, tab_train);

	unsigned int temp, sum = 0;

	for (int i = 0; i < TEST_SIZE; ++i){
		for (int j = 0; j < TRAIN_SIZE;j++) {
			for (int rc = 0;rc < PIXEL_SIZE;rc++) {
				temp = pow(tab_test[i][rc] - tab_train[j][rc],2);
				sum = temp + sum; 
			}
			sum = sqrt(sum);
			tab_dist[i][j] = sum;
		}
	} 
}

/**
 * Assign label to image based on k-nn algorithm
 *
 * This function is assinging label to the image based on provided train images.
 * Function takes labels of training images and calculated distances.
 * Then distances for every test image are sorted and written in tab_train_label_dist.
 * K smallest distances decide which label test image will get.
 * Classified label is written in tab_assigned_labels.
 * 
 * @param tab_train_label - pointer to table with train labels
 * @param tab_distance - double pointer to array with d
 * @param tab_train_label_dist - double pointer to array with train labels and sorted distances
 * @param tab_assigned_labels - pointer to table with test images
 * @return void
 */
void assign_label(
	unsigned int* tab_train_label,
	unsigned int** tab_distance,
	unsigned int** tab_train_label_dist,
	unsigned int* tab_assigned_labels
	)
{
	int sort_temp_label;
	int sort_temp;
	int temp_label = 0;
	int temp_freq = 0;
	int freq[TEN];

	read_Mnist_Label_Train(filename_label_train, tab_train_label);

	/*sort distances from min to max */
	for (int i = 0;i < TEST_SIZE;i++) {
		for (int j = 0; j < TRAIN_SIZE-1; j++){
			if (tab_distance[i][j] > tab_distance[i][j+1]){
				sort_temp = tab_distance[i][j];				
				sort_temp_label = tab_train_label[j];

				tab_distance[i][j] = tab_distance[i][j + 1];	
				tab_train_label[j] = tab_train_label[j + 1];
				
				tab_distance[i][j + 1] = sort_temp;				
				tab_train_label[j + 1] = sort_temp_label;
			}
			tab_train_label_dist[i][j] = tab_train_label[j];
		}
	}

	/*assign labels to  */
	for (int i = 0;i < TEST_SIZE;i++){
		/*insert zeros to frequency table */
		for (int a = 0;a < TEN;a++) {
			freq[a] = 0;
		}
		/*generate frequencies for every label from 0 to 9 */
		for (int knn = 0; knn < KNN; knn++){
			switch(tab_train_label_dist[i][knn]){
			case 0:
				freq[0]++;
				break;
			case 1:
				freq[1]++;
				break;
			case 2:
				freq[2]++;
				break;
			case 3:
				freq[3]++;
				break;
			case 4:
				freq[4]++;
				break;
			case 5:
				freq[5]++;
				break;			
			case 6:
				freq[6]++;
				break;
			case 7:
				freq[7]++;
				break;			
			case 8:
				freq[8]++;
				break;
			case 9:
				freq[9]++;
				break;
			}
		}
		
		/*classify image label to biggest value in frequency table*/
		for(int i = 0; i < TEN; i++){
			if(freq[i] > temp_freq){
				temp_freq = freq[i];
				temp_label = i;
			}
			
		}
		tab_assigned_labels[i] = temp_label; //assign the label	
	}

}

/**
 * Compare assigned labels with test labels
 *
 * This function compares classified labels with provided test labels og test images.
 * As a result, efficiency is returned as a precentage of correct classifications.
 *
 * @param tab_test_label pointer to table with test labels
 * @param tab_assigned_labels pointer to table with classified labels
 * @return float efficiency of the algorithm
 */
float compare(
	unsigned int* tab_test_label,
	unsigned int* tab_assigned_labels
	)
{
	float valid_value = 0;
	float efficiency = 0;
	read_Mnist_Label_Test(filename_label_test, tab_test_label);

	for (int i=0; i < TEST_SIZE;i++) {
		if (tab_assigned_labels[i] = tab_test_label[i])
			valid_value++;
	}
	efficiency = (valid_value*100)/TEST_SIZE;
	return efficiency;
}


