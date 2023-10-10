OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_Categorias.o Cjt_Jugadores.o Cjt_Torneos.o Torneo.o Jugador.o
	g++ -o program.exe program.o Cjt_Categorias.o Cjt_Jugadores.o Cjt_Torneos.o Torneo.o Jugador.o
	
Cjt_Categorias.o:  Cjt_Categorias.cc Cjt_Categorias.hh
	g++ -c Cjt_Categorias.cc $(OPCIONS)
	
Cjt_Jugadores.o:  Cjt_Jugadores.cc Cjt_Jugadores.hh
	g++ -c Cjt_Jugadores.cc $(OPCIONS)
	
Cjt_Torneos.o:  Cjt_Torneos.cc Cjt_Torneos.hh
	g++ -c Cjt_Torneos.cc $(OPCIONS)
	
Torneo.o:  Torneo.cc Torneo.hh
	g++ -c Torneo.cc $(OPCIONS)

Jugador.o:  Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
