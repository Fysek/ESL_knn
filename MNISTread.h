#include <iostream>
#include <vector>
#include <fstream>


int ReverseInt(int i);
std::vector<std::vector<double>>  read_Mnist(std::string filename, std::vector<std::vector<double> > &vec);
std::vector<double> read_Mnist_Label(std::string filename, std::vector<double> &vec);
