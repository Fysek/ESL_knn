#include "MNISTdatabase.h"

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

void assign_label(
	unsigned int tab_train_label[TRAIN_SIZE],
	unsigned int tab_distance[TEST_SIZE][TRAIN_SIZE],
	unsigned int tab_assigned_labels[TEST_SIZE],
	int k
	)
{
	//assign the label using knn, vec contains assigned labels for 10k test images
	read_Mnist_Label_Train(filename_label_train, tab_train_label);
	unsigned int tab_assigned_labels[TEST_SIZE];
	unsigned int temp;
	//int k = 7;
	
	//mam labele, mam dystanse
	//k najblizszych sprawdzamy
	//i przyporzdkowywujemy 
	
	for (int i = 0;i < 10000;i++) {
		//temp = classify_label(vec_label_train,vec_dist,k);
		//vec_assigned_labels.push_back(temp);
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
	read_Mnist_Label_Test(filename_label_test, vec_label_test);

	for (int i=0; i < assigned_labels_vec.size();i++) {
		if (assigned_labels_vec[i] = vec_label_test[i])
			valid_value++;
	}
	efficiency = valid_value/assigned_labels_vec.size();
	return efficiency;
}


