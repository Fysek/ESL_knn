#include <iostream>
#include <vector>
#include <fstream>


int ReverseInt(int i);
void read_Mnist(std::string filename, std::vector<std::vector<double> > &vec);
void read_Mnist_Label(std::string filename, std::vector<double> &vec);
