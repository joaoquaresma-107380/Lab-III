CC = gcc

LDFLAGS= `pkg-config --libs glib-2.0` -lm

CFLAGS= -Wall -Iinclude `pkg-config --cflags glib-2.0`

programa-principal: src/programa-principal.o src/Aeroporto.o src/Manager_Aeroportos.o src/Data.o src/Reserva.o src/Manager_Reservas.o src/Voo.o src/Manager_Voos.o src/Manager_Aeronaves.o src/Manager_Passageiros.o src/Passageiro.o src/Aeronave.o src/AeroportoParser.o src/AeronaveParser.o src/PassageiroParser.o src/ReservaParser.o src/Util_Ficheiro.o src/UtilsParser.o src/ValidacaoAeronave.o src/ValidacaoAeroporto.o src/ValidacaoPassageiro.o src/ValidacaoReserva.o src/ValidacaoVoo.o src/VooParser.o src/ComandoParser.o src/Queries.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

src/programa-principal.o : src/programa-principal.c 
src/Aeroporto.o : src/Aeroporto.c 
src/Manager_Aeroportos.o : src/Manager_Aeroportos.c
src/Data.o : src/Data.c 
src/Reserva.o : src/Reserva.c 
src/Manager_Reservas.o : src/Manager_Reservas.c 
src/Voo.o : src/Voo.c 
src/Manager_Voos.o : src/Manager_Voos.c
src/Manager_Aeronaves.o : src/Manager_Aeronaves.c 
src/Manager_Passageiros.o : src/Manager_Passageiros.c 
src/Passageiro.o : src/Passageiro.c 
src/Aeronave.o : src/Aeronave.c
src/AeroportoParser.o : src/AeroportoParser.c 
src/AeronaveParser.o : src/AeronaveParser.c 
src/PassageiroParser.o : src/PassageiroParser.c 
src/ReservaParser.o : src/ReservaParser.c 
src/Util_Ficheiro.o : src/Util_Ficheiro.c 
src/UtilsParser.o : src/UtilsParser.c 
src/ValidacaoAeronave.o : src/ValidacaoAeronave.c 
src/ValidacaoAeroporto.o : src/ValidacaoAeroporto.c 
src/ValidacaoPassageiro.o : src/ValidacaoPassageiro.c 
src/ValidacaoReserva.o : src/ValidacaoReserva.c 
src/ValidacaoVoo.o : src/ValidacaoVoo.c 
src/VooParser.o : src/VooParser.c 
src/ComandoParser.o : src/ComandoParser.c 
src/Queries.o : src/Queries.c 

all: programa-principal

clean:
	rm -f programa-principal src/*.o

