
#include "MNISTread.h"
#include "MNISTdatabase.h"
#include "KNNfunctions.h"


int main()
{
	std::vector<std::vector<unsigned int>> vec_images_test;
	std::vector<std::vector<unsigned int>> vec_images_train;
	std::vector<std::vector<unsigned int>> vec_distance;
	std::vector<unsigned int> vec_label_train;
	std::vector<unsigned int> vec_label_test;
	std::vector<unsigned int> vec_assigned_labels;
	
	float eff = 0;
	//read_Mnist_Image(filename_images_train, vec_images_train);
	vec_distance = distance(vec_images_test, vec_images_train);
	for (std::vector<std::vector<unsigned int>>::iterator i = vec_distance.begin(); i != vec_distance.end(); ++i) {
		for (std::vector<unsigned int>::iterator j = i->begin(); j != i->end(); ++j) {
			std::cout << *j << " " << std::endl;
		}
	}


	//vec_assigned_labels = assign_label(vec_label_train, vec_distance);
	//eff = compare(vec_label_test, vec_assigned_labels);




	system("pause");
	return 0;
}