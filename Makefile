a.out: main.o Interprete.o DiccionarioProductos.o Producto.o TablaHash.o
	g++ -std=c++11 main.o Interprete.o DiccionarioProductos.o Producto.o TablaHash.o -o a.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Interprete.o: Interprete.cpp
	g++ -std=c++11 -c Interprete.cpp

DiccionarioProductos.o: DiccionarioProductos.cpp
	g++ -std=c++11 -c DiccionarioProductos.cpp

Producto.o: Producto.cpp
	g++ -std=c++11 -c Producto.cpp

TablaHash.o: TablaHash.cpp
	g++ -std=c++11 -c TablaHash.cpp

clean:
	rm -f *.o a.out *.tar
