TARGETS := main
FLAGS := -lGL -lGLU -lglut

all: $(TARGETS)

check: $(TARGETS)
	./main

main: graphics1.o octagon.o rectangle.o pentagon.o triangle.o point.o circle.o button.o shape.o color.o slider.o line.o
	g++ -o $(TARGETS) graphics1.o octagon.o rectangle.o pentagon.o triangle.o point.o circle.o button.o shape.o color.o line.o slider.o $(FLAGS)

rectangle.o: rectangle.cpp rectangle.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c rectangle.cpp rectangle.h $(FLAGS)

octagon.o: octagon.cpp octagon.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c octagon.cpp octagon.h $(FLAGS)

circle.o: circle.cpp circle.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c circle.cpp circle.h $(FLAGS)

triangle.o: triangle.cpp triangle.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c triangle.cpp triangle.h $(FLAGS)

pentagon.o: pentagon.cpp pentagon.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c pentagon.cpp pentagon.h $(FLAGS)

point.o: point.cpp point.h
	g++ -c point.cpp point.h $(FLAGS)

button.o: button.cpp button.h rectangle.cpp rectangle.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c button.cpp button.h $(FLAGS)

shape.o: shape.cpp shape.h
	g++ -c shape.cpp shape.h $(FLAGS)

line.o: line.cpp line.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c line.cpp line.h $(FLAGS)

color.o: color.cpp color.h
	g++ -c color.cpp color.h $(FLAGS)

graphics1.o: graphics1.cpp
	g++ -c graphics1.cpp $(FLAGS)

slider.o: slider.cpp slider.h shape.cpp shape.h point.h point.cpp color.h color.cpp
	g++ -c slider.cpp slider.h $(FLAGS)

clean:
	-rm -f *~
	-rm -f $(TARGETS)
	-rm -f *.o
	-rm -f *.gch
