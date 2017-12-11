#include "MNISTdatabase.h"

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


void assign_label(
	unsigned int* tab_train_label,
	unsigned int** tab_distance,
	unsigned int** tab_train_label_dist,
	unsigned int* tab_assigned_labels
	)
{
	int zamiana;
	int schowek_label;
	int schowek;
	int temp_label = 0;
	int temp_freq = 0;
	int freq[TEN];

	read_Mnist_Label_Train(filename_label_train, tab_train_label);

	/*sortowanie*/
	for (int i = 0;i < TEST_SIZE;i++) {
		do
		{
			zamiana = 0;
			for (int j = 0; j < TRAIN_SIZE-1; j++)
			{
				if (tab_distance[i][j] > tab_distance[i][j+1])
				{
					zamiana = zamiana + 1;						

					schowek = tab_distance[i][j];				
					schowek_label = tab_train_label[j];

					tab_distance[i][j] = tab_distance[i][j + 1];	
					tab_train_label[j] = tab_train_label[j + 1];
					

					tab_distance[i][j + 1] = schowek;				
					tab_train_label[j + 1] = schowek_label;
				}
				tab_train_label_dist[i][j] = tab_train_label[j];
				
			}
		} while (zamiana != 0);
	}

	/*klasyfikacja*/
	for (int i = 0;i < TEST_SIZE;i++){
		for (int a = 0;a < TEN;a++) {
			freq[a] = 0;
		}
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
		for(int i = 0; i < TEN; i++){
			if(freq[i] > temp_freq){
				temp_freq = freq[i];
				temp_label = i;
			}
			
		}
		tab_assigned_labels[i] = temp_label;	
	}

}

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


