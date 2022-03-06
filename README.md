# Audio-processing-library

use ```sudo apt-get install libopenblas-dev``` if not installed already

## Overview of the program

This program includes 
1. audiolib.cpp : The cpp file used to make the library

2. audiolib.h : The header file of the library

3. main.cpp : The main file of the program which uses the funciton from the library audio.so library.

4. dnn_weights.h : The file provided for the wieights and bias matrices.

5. makefile : To compile the program


## Instructions to use the program

1. First  set the environment variable path for the open blas library using ```$ export MKL_BLAS_PATH = path/of/openblaslib```.  For example use ```$ export MKL_BLAS_PATH=/opt/OpenBLAS```

2. Then use the ```make``` command.

3. Then enter ```./yourcode.out audiofile.txt outputfile.txt```. The paths of the audio files and the output files should be relative to the current directory.

4. The output will be appended to the outputfile.txt.

5. Use ````make clean``` command to delete the produced files
