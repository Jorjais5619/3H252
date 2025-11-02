run : bin/animacion
	./bin/animacion

bin/animacion : src/animacion.cpp
	c++ -Iinclude src/animacion.cpp -o bin/animacion -lftxui-screen