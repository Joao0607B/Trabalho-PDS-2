execution: build/main.o build/usuario.o sensor.o quarto.o cozinha.o banheiro.o sala.o garagem.o
	c++ build/main.o build/usuario.o build/sensor.o build/quarto.o build/cozinha.o build/banheiro.o build/sala.o build/garagem.o -o execution
	
build/garagem.o: src/Classes/garagem.cpp include/garagem.hpp
	c++ src/Classes/garagem.cpp -c -I include -o garagem.o

build/sala.o: src/Classes/sala.cpp include/sala.hpp
	c++ src/Classes/sala.cpp -c -I include -o sala.o

build/banheiro.o: src/Classes/banheiro.cpp include/banheiro.hpp
	c++ src/Classes/banheiro.cpp -c -I include -o banheiro.o

build/cozinha.o: src/Classes/cozinha.cpp include/cozinha.hpp
	c++ src/Classes/cozinha.cpp -c -I include -o cozinha.o

build/quarto.o: src/Classes/quarto.cpp include/quarto.hpp
	c++ src/Classes/quarto.cpp -c -I include -o quarto.o
	
build/sensor.o: src/Classes/sensor.cpp include/sensor.hpp
	c++ src/Classes/sensor.cpp -c -I include -o sensor.o

build/usuario.o: src/Classes/usuario.cpp include/usuario.hpp
	c++ src/Classes/usuario.cpp -c -I include -o usuario.o

build/main.o: src/main.cpp 
	c++ src/main.cpp -c -I include -o build/main.o

clean:
	rm build/*.o execution
