all: build execute clean

build: compile link

compile:
	@ mkdir build -p
	@ cd build && g++ -c ../src/main.cpp

link:
	@ g++ ./build/* -o pifetch

execute:
	@ ./pifetch

clean:
	@ rm -rf build
	@ rm pifetch
