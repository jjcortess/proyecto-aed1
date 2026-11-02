a.out: main.o Interprete.o DiccionarioProductos.o Producto.o
	g++ main.o Interprete.o DiccionarioProductos.o Producto.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

Interprete.o: Interprete.cpp
	g++ -c Interprete.cpp

DiccionarioProductos.o: DiccionarioProductos.cpp
	g++ -c DiccionarioProductos.cpp

Producto.o: Producto.cpp
	g++ -c Producto.cpp

clean:
	rm -f *.o a.out *.tar
