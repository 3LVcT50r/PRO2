OPTCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: Categorias.o Jugador.o Lista_Jugadores.o Torneo.o Lista_Torneos.o program.o
	g++ -o program.exe program.o Categorias.o Jugador.o Lista_Jugadores.o Lista_Torneos.o Torneo.o
	tar -cvf practica.tar Categorias.hh Categorias.cc Jugador.hh Jugador.cc Lista_Jugadores.cc Lista_Jugadores.hh Torneo.cc Torneo.hh Lista_Torneos.cc Lista_Torneos.hh BinTree.hh Makefile program.cc html.zip

Categorias.o: Categorias.hh Categorias.cc
	g++ -c Categorias.cc $(OPTCIONS)

Jugador.o: Jugador.hh Jugador.cc
	g++ -c Jugador.cc $(OPTCIONS)

Lista_Jugadores.o: Lista_Jugadores.hh Lista_Jugadores.cc Jugador.cc
	g++ -c Lista_Jugadores.cc $(OPTCIONS)

Torneo.o: Torneo.hh Torneo.cc Jugador.cc Lista_Jugadores.cc Categorias.cc BinTree.hh
	g++ -c Torneo.cc $(OPTCIONS)

Lista_Torneos.o: Lista_Torneos.hh Lista_Torneos.cc Torneo.cc Categorias.cc Lista_Jugadores.cc
	g++ -c Lista_Torneos.cc $(OPTCIONS)

program.o: program.cc Categorias.cc Jugador.cc Lista_Jugadores.cc Torneo.cc Lista_Torneos.cc
	g++ -c program.cc $(OPTCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.tar