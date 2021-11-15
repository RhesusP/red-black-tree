all : main.out

main.out : main.o ARN.o noeud.o 
	g++ -g -W -Wall main.cpp ARN.cpp noeud.cpp -o main.out

clean:
	rm *.o
	rm *.out