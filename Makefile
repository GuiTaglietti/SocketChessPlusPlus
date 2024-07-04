# Variáveis
CXX = g++
CXXFLAGS = -O2
TARGET = program
SRC = SocketChess++/src/table/teste.cpp SocketChess++/src/table/table.cpp SocketChess++/src/chessengine/pawn.cpp

# Regras
all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
