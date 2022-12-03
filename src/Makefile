CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD 
EXEC = chessProgram
OBJECTS = main.o chess.o piece.o observer.o subject.o textrender.o king.o queen.o rook.o bishop.o knight.o pawn.o player.o board.o human.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}