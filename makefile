all: p1 p2  p3
	

p1 : 
	g++ -c -Wall -Werror -fPIC audiolib.cpp


p2 : 
	g++ -shared -o libaudio.so audiolib.o


p3:
	g++  -Wall -o yourcode.out main.cpp -L$(PWD) -laudio -include cblas.h  -I $(MKL_BLAS_PATH)/include/ -L$(MKL_BLAS_PATH)/lib -lopenblas -lpthread -lgfortran -lm -Wl,-rpath=$(PWD)


clean:
	rm -rf *.ext *.o *.so  *.out


.PHONY: clean

