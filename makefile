all:
	swig -c++ -python calibration.i
	g++ -std=c++11 -Wall -fPIC -c calibration.cpp `pkg-config --cflags opencv`
	g++ -std=c++11 -Wall -fPIC -c calibration_wrap.cxx `pkg-config --cflags python`
	g++ -std=c++11 -shared calibration.o calibration_wrap.o `pkg-config --libs opencv` `pkg-config --libs python` -o _calibration.so

clean:
	rm -f ./*.o $(RM)
