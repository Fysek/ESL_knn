#include "MNISTread.h"
#include "MNISTdatabase.h"

int main()
{
	unsigned int** tab_test_image = new unsigned int*[TEST_SIZE];
	for(int i = 0; i < TEST_SIZE; ++i)
		tab_test_image[i] = new unsigned int[PIXEL_SIZE];
	
	unsigned int** tab_train_image = new unsigned int*[TRAIN_SIZE];
	for(int i = 0; i < TRAIN_SIZE; ++i)
		tab_test_image[i] = new unsigned int[PIXEL_SIZE];
	
	unsigned int** tab_dist = new unsigned int*[TEST_SIZE];
	for(int i = 0; i < TRAIN_SIZE; ++i)
		tab_test_image[i] = new unsigned int[PIXEL_SIZE];
	
	unsigned int* tab_train_label = new unsigned int[TRAIN_SIZE];
	
	unsigned int* tab_test_label = new unsigned int[TEST_SIZE];

	unsigned int* tab_assigned_labels = new unsigned int[TEST_SIZE];

	float eff = 0;

	distance(tab_test_image, tab_train_image, tab_dist);
	assign_label(tab_train_label, tab_dist, tab_assigned_labels);
	//read_Mnist_Image(filename_images_train, vec_images_train);
	//vec_assigned_labels = assign_label(vec_label_train, vec_distance);
	//eff = compare(vec_label_test, vec_assigned_labels);

	//deletion of arrays
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
	
	delete [] tab_train_label;
	delete [] tab_test_label;
	delete [] tab_assigned_labels;
	
	system("pause");
	return 0;
}