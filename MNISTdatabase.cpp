#include "MNISTdatabase.h"

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
	/*sortowanie start*/
	for (int i = 0;i < TEST_SIZE;i++) {//dla 10000 labeli
		do
		{
			zamiana = 0;//przed ka¿dym "przejazdem" pêtli for zmienna zamiana jest zerowana
			for (int j = 0; j < TRAIN_SIZE-1; j++)
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
				tab_train_label_dist[i][j] = tab_train_label[j];
				
			}
		} while (zamiana != 0);
	}
	/*sortowanie end*/

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


