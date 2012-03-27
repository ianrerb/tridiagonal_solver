OBJ= main.o EuropeanPut.o EuropeanCall.o NumericStrategy.o PIDEStrategy.o
SRC= ./src/
INC= ./inc/
CPL= g++ -c
LNK= g++ -o

main : $(OBJ)
	$(LNK) main $(OBJ)

main.o : main.cpp
	$(CPL) main.cpp

EuropeanPut.o : $(INC)Option.h
	$(CPL) $(SRC)EuropeanPut.cpp

EuropeanCall.o : $(INC)Option.h
	$(CPL) $(SRC)EuropeanCall.cpp

NumericStrategy.o : $(INC)NumericStrategy.h 
	$(CPL) $(SRC)NumericStrategy.cpp

PIDEStrategy.o : $(INC)PIDEStrategy.h
	$(CPL) $(SRC)PIDEStrategy.cpp

test :
	cd tests; ./testall

run :
	./main

.PHONY : clean
clean :
	-rm main $(OBJ)

