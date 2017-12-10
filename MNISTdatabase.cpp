#include "MNISTdatabase.h"

//d classify_label( unsigned int tab_small[TEST_SIZE][KNN])//to do
//
//unsigned int small[KNN];
//
//
//for (int i = 0;i < TEST_SIZE;i++) {
//	for (int knn = 0; knn < KNN; knn++){
//		small[knn] = tab_distance[i][0]; 			//init with the first value
//		for(int j = 0; j < TRAIN_SIZE;j++){
//			
//			
//
//		}	
//	}
//}
//
//
//

 
 
void zero_table(unsigned int tab[KNN]) {
	for (int i = 0; i < KNN; i++) {
		tab[i] = 0;
	}
}
 
void distance(
	unsigned int** tab_test,
	unsigned int** tab_train,
	unsigned int** tab_dist
	) 
{ 
	//vector vec [10k][60k] for 10k vector 60k distances
	//include data
	read_Mnist_Image_Test(filename_images_test, tab_test);
	read_Mnist_Image_Train(filename_images_train, tab_train);
	//calculate the distance between 10k test and 60k train
	unsigned int temp, sum = 0;

	for (int i = 0; i < TEST_SIZE; ++i){
		for (int j = 0; j < TRAIN_SIZE;j++) {
			for (int rc = 0;rc < PIXEL_SIZE;rc++) {
				temp = pow(tab_test[i][rc] - tab_train[j][rc],2);
				sum = temp + sum;  // zsumowanie 
			}
			sum = sqrt(sum);
			tab_dist[i][j] = sum;
		}
	} 
}



void assign_label(//todo
	unsigned int* tab_train_label,
	unsigned int** tab_distance,
	unsigned int* tab_assigned_labels
	)
{
	read_Mnist_Label_Train(filename_label_train, tab_train_label);
	
	//unsigned int tab_assigned_labels[TEST_SIZE];
	int zamiana;
	int schowek_label;
	int schowek;
	//unsigned int tab_small_dist[TEST_SIZE][KNN];//smallest distances
	//unsigned int tab_small_label[TEST_SIZE][KNN];// labels for distances
	
	
	for (int i = 0;i < TEST_SIZE;i++) {//dla 10000 labeli
		do
		{
			zamiana = 0;//przed ka¿dym "przejazdem" pêtli for zmienna zamiana jest zerowana
			for (int j = 0; j < TRAIN_SIZE+1; j++)
			{
				if (tab_distance[i][j] > tab_distance[i][j+1])// jeœli element tablicy jest wiêkszy od nastêpnego elementu
				{
					zamiana = zamiana + 1;						//jeœli jest jakaœ zmiana, to zmienne zamiana powiêksza swoj¹ wartoœæ

					schowek = tab_distance[i][j];				//wartoœæ t[i] jest kopiowana do schowka
					schowek_label = tab_train_label[j];

					tab_distance[i][j] = tab_distance[i][j + 1];	//t[i] przyjmuje wartoœæ nastêpnego elementu, gdy¿ jest on mniejszy
					tab_train_label[j] = tab_train_label[j + 1];

					tab_distance[i][j + 1] = schowek;				//kolejny element tablicy przejmuje wczeœniejsz¹ wartoœæ poprzedniego elementu, gdy¿ jest on wiêkszy
					tab_train_label[j + 1] = schowek_label;
				}
			}
		} while (zamiana != 0);
	}



}

float compare(
	unsigned int* tab_test_label,
	unsigned int* tab_assigned_labels
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


