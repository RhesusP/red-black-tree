all : main.out

main.out : main.o ARN.o noeud.o ABR.o
	g++ -g -W -Wall main.cpp ARN.cpp noeud.cpp ABR.cpp -o main.out

clean:
	rm *.o
	rm *.out