# build: bin/main.o bin/autocompletar.o bin/termo.o include/listaordenada.h
# 	g++ -o bin/main src/termo.cpp src/autocompletar.cpp src/main.cpp -I./include

# all: bin/main.o bin/autocompletar.o bin/termo.o include/listaordenada.h
# 	g++ -o main listaordenada.o termo.o autocompletar.o main.o -I./include

# bin/main.o: bin/autocompletar.o bin/termo.o include/listaordenada.h
# 	g++ -o bin/main.o -c src/main.cpp -I./include

# bin/autocompletar.o: bin/termo.o src/autocompletar.cpp include/autocompletar.h include/listaordenada.h
# 	g++ -o bin/autocompletar.o -c src/autocompletar.cpp -I./include

# bin/termo.o: src/termo.cpp include/termo.h
# 	g++ -o bin/termo.o -c src/termo.cpp -I./include

# clean: 
# 	rm -f *.o *.out bin/*

CXX = g++
CXXFLAGS = -std=c++11 -I./include

# Diretórios
BINDIR = bin
SRCDIR = src
INCDIR = include

# Arquivos de origem e de objetos
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/autocompletar.cpp $(SRCDIR)/termo.cpp
OBJECTS = $(BINDIR)/main.o $(BINDIR)/autocompletar.o $(BINDIR)/termo.o

# Arquivo final
TARGET = $(BINDIR)/autocompletar

# Alvo principal
build: $(TARGET)

# Regras para compilar o executável final
$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(CXXFLAGS)

# Regras para compilar os arquivos de objeto
$(BINDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/autocompletar.h $(INCDIR)/termo.h $(INCDIR)/listaordenada.h
	$(CXX) -o $(BINDIR)/main.o -c $(SRCDIR)/main.cpp $(CXXFLAGS)

$(BINDIR)/autocompletar.o: $(SRCDIR)/autocompletar.cpp $(INCDIR)/autocompletar.h $(INCDIR)/listaordenada.h $(INCDIR)/termo.h
	$(CXX) -o $(BINDIR)/autocompletar.o -c $(SRCDIR)/autocompletar.cpp $(CXXFLAGS)

$(BINDIR)/termo.o: $(SRCDIR)/termo.cpp $(INCDIR)/termo.h
	$(CXX) -o $(BINDIR)/termo.o -c $(SRCDIR)/termo.cpp $(CXXFLAGS)

# Limpeza
clean:
	rm -f $(BINDIR)/*.o $(TARGET)
