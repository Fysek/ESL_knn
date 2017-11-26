#include <iostream>
#include <vector>
#include <fstream>

/*

struct testImage {
	unsigned short label;
	unsigned short index;
	std::vector<unsigned short> pixels;//r,c - 1,1 1,2 1,2 ... 28,27 28,28
	std::vector<unsigned int> distance;//60k wartosci 
};

struct trainImage {
	unsigned short label;
	unsigned short index;
	std::vector<unsigned short> pixels;
};
*/



int ReverseInt(int i);
void read_Mnist_Image(std::string filename, std::vector<std::vector<unsigned int> > &vec);
void read_Mnist_Label(std::string filename, std::vector<unsigned int> &vec);


