out = ./out/app.exe
src = ./src/*.cpp
entities = ./src/entities/*.cpp
utils = ./utils/*.cpp
lib_dir = ./lib

include_dir = ./include
libs = -lraylib -lopengl32 -lgdi32 -lwinmm

default:
	clear
	@echo
	@echo ============================================
	@echo ============ COMPILANDO PROJETO ============
	@echo ============================================
	g++ $(src) $(entities) $(utils) -o $(out) -L $(lib_dir) -I $(include_dir) $(libs) -std=c++17 -Wall
	
	@echo ============ EXECUTANDO PROJETO ============
	./out/app.exe

execute:
	.\out\app.exe