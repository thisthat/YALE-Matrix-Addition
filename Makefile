FLAG_C11 = -std=c++11 -stdlib=libc++
CC = g++
FLAGS = -O3 -pthread $(FLAG_C11) -g
NAME = YSFMMoltiplication
all: compile clean

compile: Main.o YSMF.o
	$(CC) YSMF.o  Main.o -o $(NAME) $(FLAGS)

YSMF.o: YSMF.cpp YSMF.hpp
	$(CC) $(FLAGS) -c $<

Main.o: Main.cpp Main.hpp
	$(CC) $(FLAGS) -c $<


clean:
	rm *.o

demo: compile
	./$(NAME)

Test.o: Test.cpp Main.hpp
	$(CC) $(FLAGS) -c $<

test:  YSMF.o Test.o
	$(CC) YSMF.o Test.o  -o $(NAME) $(FLAGS)
