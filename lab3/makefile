C = icc
CXX = icpc
CFLAGS = #-Wall -std=c99 -openmp -O3 -g -I.
CXXFLAGS = -Wall -openmp -O3 -g
#overkill on the flags, but that doesn't hurt anything
LDFLAGS = -lrt -lpthread 

#replace this if you want to change the output name
TARGET = lab3_part1
TARGET2= lab3_part2

#any headers go here
INCLUDES = 
INCLUDES2 = 

#any .c or .cpp files go here
SOURCE = lab3_part1.c
SOURCE2 = lab3_part2.c

#default is to compile
default:	compile compile2

#depends on all of you source and header files

compile: ${SOURCE} ${INCLUDES}
#this assumes you actually are linking all of the source files together
	${CC} ${CFLAGS} ${SOURCE} -o ${TARGET} ${LDFLAGS}

compile2: ${SOURCE2} ${INCLUDES2}
#this assumes you actually are linking all of the source files together
	${CC} ${CFLAGS} ${SOURCE2} -o ${TARGET2} ${LDFLAGS}

debug: ${SOURCE} ${INCLUDES}
	${CC} ${CFLAGS} ${SOURCE} -o ${TARGET} ${LDFLAGS} -DDEBUG

clean:
	rm -rf ${TARGET} ${TARGET2}