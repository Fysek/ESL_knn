
#include "KNNfunctions.h"


unsigned int classify_label(	
	std::vector<unsigned int> &vec_label_train,
	std::vector<std::vector <unsigned int>> vec_dist,
	int k
	)
{
	unsigned int label = 0;


	//wybierz najmniejszy dystans
	//dwa wskazniki i wybieraja najmniejsze	
	
	for (std::vector<std::vector<unsigned int>>::iterator i = vec_dist.begin(); i!=vec_dist.end(); ++i ){
		for (std::vector<unsigned int>::iterator j = i->begin(); j != i->end(); ++j) {
			std::cout << *j << std::endl;
		}	
	}
	return label;
}





								  