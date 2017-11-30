#include "MNISTdatabase.h"

void classify_label( unsigned int tab_small[TEST_SIZE][KNN])//to do
{	
	unsigned int small[KNN];
	
	
	for (int i = 0;i < TEST_SIZE;i++) {
		for (int kkn = 0; knn < KNN; knn++){
			small[knn] = tab_distance[i][0]; 			//init with the first value
			for(int j = 0; j < TRAIN_SIZE;j++){
				
				

			}	
		}
	}
	
	
}




void distance(
	unsigned int tab_test[TEST_SIZE][PIXEL_SIZE],
	unsigned int tab_train[TRAIN_SIZE][PIXEL_SIZE]
	unsigned int tab_dist[TRAIN_SIZE][PIXEL_SIZE]
	) 
{ 
	//vector vec [10k][60k] for 10k vector 60k distances
	//include data
	read_Mnist_Image_Test(filename_images_test, tab_test);
	read_Mnist_Image_Train(filename_images_train, tab_train);
	//calculate the distance between 10k test and 60k train
	unsigned int tab_dist[TEST_SIZE][TRAIN_SIZE];
	unsigned int temp, sum = 0;

	for (int i = 0; i < TEST_SIZE; ++i){
		for (int j = 0; j < TRAIN_SIZE;j++) {
			for (int rc = 0;rc < PIXEL_SIZE;rc++) {
				temp = pow(tab_test[i][rc] - tab_train[j][rc],2);
				sum = temp + sum;  // zsumowanie 
			}
			sum = sqrt(sum);
			tab_dist[i][j];
		}
	} 
}

void assign_label(//todo
	unsigned int tab_train_label[TRAIN_SIZE],
	unsigned int tab_distance[TEST_SIZE][TRAIN_SIZE],
	unsigned int tab_assigned_labels[TEST_SIZE],
	)
{
	read_Mnist_Label_Train(filename_label_train, tab_train_label);
	unsigned int tab_assigned_labels[TEST_SIZE];
	unsigned int tab_small[TEST_SIZE][KNN];
	unsigned int small[KNN];
	
	for (int i = 0;i < TEST_SIZE;i++) {
		for (int kkn = 0; knn < KNN; knn++){
			small[knn] = tab_distance[i][0]; 			//init with the first value
			for(int j = 0; j < TRAIN_SIZE;j++){
				
				
				
				if(tab_distance[i][j] < small[knn])
					small[knn] = tab_distance[i][j];
			}	
		}
	}
}

float compare(
	unsigned int tab_test_label[TEST_SIZE],
	unsigned int tab_assigned_labels[TEST_SIZE]
	)
{
	//compare assigned label with the provided one
	int valid_value = 0;
	float efficiency = 0;
	read_Mnist_Label_Test(filename_label_test, tab_test_label);

	for (int i=0; i < TEST_SIZE;i++) {
		if (tab_assigned_labels[i] = tab_test_label[i])
			valid_value++;
	}
	efficiency = valid_value/TEST_SIZE;
	return efficiency;
}


