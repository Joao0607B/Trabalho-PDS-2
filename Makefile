execution: build/main.o build/usuario.o sensor.o comodo.o 
	c++ build/main.o build/usuario.o build/sensor.o build/comodo.o -o execution
	
build/comodo.o: src/Classes/comodo.cpp include/comodo.hpp
	c++ src/Classes/comodo.cpp -c -I include -o comodo.o
	
build/sensor.o: src/Classes/sensor.cpp include/sensor.hpp
	c++ src/Classes/sensor.cpp -c -I include -o sensor.o

build/usuario.o: src/Classes/usuario.cpp include/usuario.hpp
	c++ src/Classes/usuario.cpp -c -I include -o usuario.o

build/main.o: src/main.cpp 
	c++ src/main.cpp -c -I include -o build/main.o

clean:
	rm build/*.o execution
