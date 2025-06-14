RELEASE: compile link 
DEBUG: compile_debug link_debug

PROJECT = ItusKhoma
COMPILER = g++

# Form Build directory...
SOURCE_DIR =  ../
INCLUDE_PATH = ../SFML/include/

# It must be from the disk location...
LIBRARY_PATH = C:\\Codes\\ItusKhoma\\SFML\\lib



#RELEASE PREFERANCE...
compile:
	${COMPILER} -I${INCLUDE_PATH} -c ${SOURCE_DIR}*.cpp -DSFML_STATIC 

link:
	${COMPILER} *.o -o ${PROJECT} -L${LIBRARY_PATH}  -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main



#DEBUG PREFERANCE...
##################################################
#### ## # Only when you have big project # ## ####
##################################################
compile_debug:
	${COMPILER} -I${INCLUDE_PATH} -c ${SOURCE_DIR}*.cpp

link_debug:
	${COMPILER} *.o -o ${PROJECT} -L${LIBRARY_PATH}  -lsfml-graphics -lsfml-window -lsfml-system -lopengl32

