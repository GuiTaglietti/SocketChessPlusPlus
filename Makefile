# Variáveis
CXX = g++
CXXFLAGS = -O2
TARGET = program
SRC = SocketChess++/src/table/teste.cpp \
      SocketChess++/src/table/table.cpp \
      SocketChess++/src/chessengine/pawn.cpp \
      SocketChess++/src/chessengine/king.cpp \
      SocketChess++/src/chessengine/queen.cpp \
      SocketChess++/src/chessengine/knight.cpp \
      SocketChess++/src/chessengine/rook.cpp \
      SocketChess++/src/chessengine/bishop.cpp \
	  SocketChess++/src/chessengine/nullpiece.cpp

# Regras
all: clean $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
