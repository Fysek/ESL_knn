#include "MNISTdatabase.h"

std::vector<std::vector<unsigned int>> distance(
	std::vector<std::vector<unsigned int>> &vec_images_test,
	std::vector<std::vector<unsigned int>> &vec_images_train
	) 
{
	std::vector<std::vector<unsigned int>> vec_dist;
	
	//vector vec [10k][60k] for 10k vector 60k distances
																													   //include data
	read_Mnist_Image(filename_images_test, vec_images_test);
	read_Mnist_Image(filename_images_train, vec_images_train);
	//calculate the distance between 10k test and 60k train
	for (std::vector<std::vector<unsigned int>>::iterator i = vec_images_test.begin(); i != vec_images_test.end(); ++i)
	{
		
		std::vector<unsigned int> tp;//ten wektor musi miec 60k size, 60 dystansow dla jednego obrazku
		unsigned int temp, sum = 0;

		for (std::vector<std::vector<unsigned int>>::iterator a = vec_images_train.begin();a!= vec_images_train.end();a++) {
			std::vector<unsigned int> ::iterator t10k_i = i->begin();
			for (std::vector<unsigned int>::iterator train_i = a->begin(); train_i != a->end(); ++train_i) {
				temp = pow( *t10k_i - *train_i, 2);
				sum = temp + sum;  // zsumowanie 
				t10k_i++;
				}
			sum = sqrt(sum);
			tp.push_back(sum);
			}
		vec_dist.push_back(tp);//wrzuc wektor 60k 10k razy
	} 
	return vec_dist;
}

std::vector <unsigned int> assign_label(
	std::vector<unsigned int> &vec_label_train,
	std::vector<std::vector<unsigned int>> &vec_dist
	)
{
	//assign the label using knn, vec contains assigned labels for 10k test images
	std::vector<unsigned int> vec_assigned_labels;
	read_Mnist_Label(filename_label_train, vec_label_train);
	unsigned int temp;
	//mam labele, mam dystanse
	//k najblizszych sprawdzamy
	//i przyporzdkowywujemy 
	int k = 7;
	for (int i = 0;i < 10000;i++) {
		temp = classify_label(vec_label_train,vec_dist,k);
		vec_assigned_labels.push_back(temp);
	}
	return vec_assigned_labels;
}

float compare(
	std::vector<unsigned int> &vec_label_test,
	std::vector<unsigned int> &assigned_labels_vec
	)
{
	//compare assigned label with the provided one
	int valid_value = 0;
	float efficiency = 0;
	read_Mnist_Label(filename_label_test, vec_label_test);

	for (int i=0; i < assigned_labels_vec.size();i++) {
		if (assigned_labels_vec[i] = vec_label_test[i])
			valid_value++;
	}
	efficiency = valid_value/assigned_labels_vec.size();
	return efficiency;
}


