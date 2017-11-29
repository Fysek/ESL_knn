
#include "MNISTread.h"
#include "MNISTdatabase.h"
#include "KNNfunctions.h"


int main()
{
	unsigned int tab_test_image[TEST_SIZE][PIXEL_SIZE];
	unsigned int tab_train_image[TRAIN_SIZE][PIXEL_SIZE];
	unsigned int tab_dist[TRAIN_SIZE][PIXEL_SIZE];
	unsigned int tab_train_label[TRAIN_SIZE];
	unsigned int tab_test_label[TEST_SIZE];
	unsigned int tab_assigned_labels[TEST_SIZE];
	
	float eff = 0;
	//read_Mnist_Image(filename_images_train, vec_images_train);
	//vec_assigned_labels = assign_label(vec_label_train, vec_distance);
	//eff = compare(vec_label_test, vec_assigned_labels);


	system("pause");
	return 0;
}