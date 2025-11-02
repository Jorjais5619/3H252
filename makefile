run : bin/acuario
	./bin/acuario

bin/acuario : src/acuario.cpp
	c++ -Iinclude src/acuario.cpp -o bin/acuario -lftxui-screen