# ESL_knn

This is an implementation of k-nearest neighbours algorithm to classify numbers in MNIST database of handwritten digits in C++.
In pattern recognition, the k-nearest neighbors algorithm (k-NN) is a non-parametric method used for classification and regression. 
In both cases, the input consists of the k closest training examples in the feature space.

MNIST dataset contains 60,000 training images and 10,000 testing images.
Every image is a 28x28 pixel box in 8-bit grayscale.
Pixels are organized row-wise. Pixel values are 0 to 255. 0 means background (white), 255 means foreground (black).

Default k is set to 7

Note: Before execution, please specify paths to MNIST database in MNISTdatabase.h file.

More about MNIST: http://yann.lecun.com/exdb/mnist/
Copyright 2019 Mateusz Dyrdół. All rights reserved.
 
