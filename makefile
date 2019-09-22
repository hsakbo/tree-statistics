build: main
	./exe

main: main1.cpp
	g++ -Wall -g main1.cpp -o exe
