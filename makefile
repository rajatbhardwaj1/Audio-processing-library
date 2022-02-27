all: p1 p2 p7 p8
	

p1 : 
	g++ -c -Wall -Werror -fPIC foo.cpp


p2 : 
	g++ -shared -o libaudio.so foo.cpp


p3: 
	g++  -Wall -o test main.cpp -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -laudio


p4:
	g++ -Wall -o test main.cpp  -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -Wl,-rpath=/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -laudio



p6:
	./test

p7:
	g++ -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -Wall -o test main.cpp -laudio -include cblas.h -I /opt/OpenBLAS/include/ -L/opt/OpenBLAS/lib -lopenblas -lpthread -lgfortran

p8:
	g++  -Wall -o test main.cpp -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -laudio -include cblas.h  -I /opt/OpenBLAS/include/ -L/opt/OpenBLAS/lib -lopenblas -lpthread -lgfortran -lm -Wl,-rpath=/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library


clean:
	rm -rf *.ext *.o *.so 


