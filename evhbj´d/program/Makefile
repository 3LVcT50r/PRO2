OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
INCLUSIONS = /home/victor/UNI/Pro2/PRACTICA

program.exe: program.o Categorias.o Lista_Torneos.o Lista_Jugadores.o Torneo.o Jugador.o Makefile BinTree.hh
	g++ -o program.exe program.o Categorias.o Lista_Torneos.o Lista_Jugadores.o Torneo.o Jugador.o
	tar -cvf practica.tar Makefile program.exe program.cc Categorias.hh Categorias.cc Jugador.hh Jugador.cc Lista_Jugadores.hh Lista_Jugadores.cc Torneo.hh Torneo.cc Lista_Torneos.hh Lista_Torneos.cc BinTree.hh

Categorias.o: Categorias.cc Categorias.hh 
	g++ -c Categorias.cc $(OPCIONS)

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)

Lista_Jugadores.o: Lista_Jugadores.cc Lista_Jugadores.hh Jugador.hh Jugador.cc
	g++ -c Lista_Jugadores.cc $(OPCIONS)

Torneo.o: Torneo.cc Torneo.hh Lista_Jugadores.hh Lista_Jugadores.cc
	g++ -c Torneo.cc -I$(INCLUSIONS) $(OPCIONS)

Lista_Torneos: Lista_Torneos.cc Lista_Torneos.hh Categorias.hh Categorias.cc Torneo.hh Torneo.cc
	g++ -c Lista_Torneos.cc $(OPCIONS)

main.o: program.cc Lista_Jugadores.hh Lista_Torneos.hh Torneo.hh Jugador.hh Categorias.hh 
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.tar