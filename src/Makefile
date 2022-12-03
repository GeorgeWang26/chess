CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD 
EXEC = chess
OBJECTS = bishop.o board.o chess.o human.o king.o knight.o main.o observer.o pawn.o piece.o player.o queen.o rook.o subject.o textrender.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}
