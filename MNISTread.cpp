/**
 *===========================================================================
 * Copyright 2019 Mateusz Dyrdół. All rights reserved.
 *===========================================================================
 */
#include "MNISTread.h"

/**
 * Reverse integer.
 *
 * This function is reversing integer.
 * All integers in the files are stored in the MSB first (high endian) format thus integers must be reverse.
 * Users of Intel processors and other low-endian machines must flip the bytes of the header. 
 *
 * @param i - integer to reverse
 * @return int reversed integer
 */
int ReverseInt(int i)
{
	unsigned char c1, c2, c3, c4;

	c1 = i & 255;
	c2 = (i >> 8) & 255;
	c3 = (i >> 16) & 255;
	c4 = (i >> 24) & 255;

	return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

/**
 * Read MNIST train images to two dimension table
 *
 * This function takes MNIST images as a file 
 *
 * @param filename - path to file with train images
 * @param tab_train - double pointer to array with train images
 * @return void
 */
void read_Mnist_Image_Train(std::string filename, unsigned int** tab_train)
{
	std::ifstream file(filename, std::ios::binary);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;
		unsigned char temp = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);
		file.read((char*)&n_rows, sizeof(n_rows));
		n_rows = ReverseInt(n_rows);
		file.read((char*)&n_cols, sizeof(n_cols));
		n_cols = ReverseInt(n_cols);

		for (int i = 0; i < TRAIN_SIZE; ++i)
		{
			for (int j = 0; j < n_rows * n_cols; ++j)
			{
				file.read((char*)&temp, sizeof(temp));
				tab_train[i][j] = (unsigned int)temp;
			}
		}
		file.close();
	}
	else
		std::cout << "unable to open file" << std::endl;
}

/**
 * Read MNIST test images to two dimension table
 *
 * This function takes MNIST images as a file 
 *
 * @param filename - path to file with test images
 * @param tab_test - double pointer to array with test images
 * @return void
 */
void read_Mnist_Image_Test(std::string filename, unsigned int** tab_test)
{
	std::ifstream file(filename, std::ios::binary);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;
		unsigned char temp = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);
		file.read((char*)&n_rows, sizeof(n_rows));
		n_rows = ReverseInt(n_rows);
		file.read((char*)&n_cols, sizeof(n_cols));
		n_cols = ReverseInt(n_cols);

		for (int i = 0; i < TEST_SIZE; ++i)
		{
			for (int j = 0; j < n_rows * n_cols; ++j)
			{
				file.read((char*)&temp, sizeof(temp));
				tab_test[i][j] = (unsigned int)temp;
			}
		}
		file.close();
	}
	else
		std::cout << "unable to open file" << std::endl;
}

/**
 * Read MNIST train labels to two dimension table
 *
 * This function takes MNIST images as a file 
 *
 * @param filename - path to file with train labels
 * @param tab_train_label - pointer to table with train labels
 * @return void
 */
void read_Mnist_Label_Train(std::string filename, unsigned int* tab_train_label)
{
	std::ifstream file (filename);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
		unsigned char temp = 0;

        file.read((char*) &magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
		if (magic_number != 2049) 
			std::cout<<"Invalid MNIST image file!"<<std::endl;
        file.read((char*) &number_of_images,sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);

        for(int i = 0; i < TRAIN_SIZE; ++i)
        {
			file.read((char*)&temp, sizeof(temp));
			tab_train_label[i] = (unsigned int)temp;
        }
		file.close();
    }
	else
		std::cout << "unable to open file" << std::endl;
}

/**
 * Read MNIST test labels to two dimension table
 *
 * This function takes MNIST images as a file 
 *
 * @param filename - path to file with test labels
 * @param tab_test_label - pointer to table with test labels
 * @return void
 */
void read_Mnist_Label_Test(std::string filename, unsigned int* tab_test_label)
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		unsigned char temp = 0;

		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		if (magic_number != 2049)
			std::cout << "Invalid MNIST image file!" << std::endl;
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);

		for (int i = 0; i < TEST_SIZE; ++i)
		{
			file.read((char*)&temp, sizeof(temp));
			tab_test_label[i] = (unsigned int)temp;
		}
		file.close();
	}
	else
		std::cout << "unable to open file" << std::endl;
}

