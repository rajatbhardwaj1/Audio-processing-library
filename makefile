all: p1 p2 p7 p8
	

p1 : foo.cpp
	g++ -c -Wall -Werror -fPIC foo.cpp


p2 : foo.cpp
	g++ -shared -o libfoo.so foo.cpp


p3: main.cpp
	g++  -Wall -o test main.cpp -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -lfoo


p4:
	g++ -Wall -o test main.cpp  -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -Wl,-rpath=/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -lfoo



p6:
	./test

p7:
	g++ -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -Wall -o test main.cpp -lfoo -include cblas.h -I /opt/OpenBLAS/include/ -L/opt/OpenBLAS/lib -lopenblas -lpthread -lgfortran

p8:
	g++  -Wall -o test main.cpp -L/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library -lfoo -include cblas.h  -I /opt/OpenBLAS/include/ -L/opt/OpenBLAS/lib -lopenblas -lpthread -lgfortran -lm -Wl,-rpath=/home/rajat/Desktop/COL290/Subtask3/Audio-processing-library


clean:
	rm -rf *.ext *.o *.so 


