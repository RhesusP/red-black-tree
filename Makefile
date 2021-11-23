all : exec

exec : main.o ARN.o ABR.o Noeud.o
	g++ -g -Wall main.o ARN.o ABR.o Noeud.o -o main.out

main.o : main.cpp ARN.h ABR.h Noeud.h
	g++ -g -Wall -c main.cpp

ARN.o : ARN.h ARN.cpp ARN.h
	g++ -g -Wall -c ARN.cpp 

ABR.o : ABR.h ABR.cpp Noeud.h
	g++ -g -Wall -c ABR.cpp

Noeud.o : Noeud.h Noeud.cpp
	g++ -g -Wall -c Noeud.cpp

clean:
	rm *.o
	rm *.out