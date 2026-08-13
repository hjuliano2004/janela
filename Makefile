# Compiladores
CC = gcc
CXX = g++

# Flags de compilação
CFLAGS   = -Wall -O2
CXXFLAGS = -Wall -O2

# Busca todos os arquivos .c e .cpp recursivamente
SRC_C   := $(shell find . -name '*.c')
SRC_CPP := $(shell find . -name '*.cpp')
SRC     := $(SRC_C) $(SRC_CPP)

# Objetos correspondentes
OBJ     := $(SRC:.c=.o)
OBJ     := $(OBJ:.cpp=.o)

# Nome do executável
TARGET = programa

# Regra principal
all: $(TARGET)

# Linkagem final (com Wayland)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ -lwayland-client

# Regras de compilação
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJ) $(TARGET)
