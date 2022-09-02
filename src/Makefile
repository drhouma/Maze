
PRO_FILENAME=Maze
INSTALL_DIR=application
TECH_SUPPORT_DIR=$(INSTALL_DIR)/tech_support
TAR_NAME=MAZE.tar
MODEL_SRC=model/maze/*.cpp model/cave/*.cpp model/core/*.cpp
SRC=model/maze/*.cpp controller/*.cpp view/*.cpp matrix/*.cpp
HDR=model/*.h controller/*.h view/*.h

all: dist install dvi tests

.PHONY: build dist all install uninstall

install: $(INSTALL_DIR) rebuild
ifeq ($(shell uname),Darwin)
	-@cp -r ./build/$(PRO_FILENAME).app $(INSTALL_DIR)/
	@rm -rf $(PRO_FILENAME).app
else
	-@cp -r ./build/$(PRO_FILENAME) $(INSTALL_DIR)/
	@rm -rf $(PRO_FILENAME)
endif
	@make clean

uninstall:
ifeq ($(shell uname),Darwin)
	@rm -rf $(INSTALL_DIR)/$(PRO_FILENAME).app
else
	@rm -rf $(INSTALL_DIR)/$(PRO_FILENAME)
endif

rebuild: clean createBuild createTempMakefile build

build: createBuild
	@make -C ./build
	@-./build/$(PRO_FILENAME).app/Contents/MacOS/$(PRO_FILENAME)

clean: 
	@-rm -rf build *.out

distclean: clean
	@-rm -rf $(INSTALL_DIR)

createTempMakefile:
	cmake -B./build

run:
ifeq ($(shell uname),Darwin)
	@-./$(INSTALL_DIR)/$(PRO_FILENAME).app/Contents/MacOS/$(PRO_FILENAME)
else
	@-./$(INSTALL_DIR)/$(PRO_FILENAME)
endif

dist: $(INSTALL_DIR)
	@tar -cvf $(INSTALL_DIR)/$(TAR_NAME) ./
	@gzip $(INSTALL_DIR)/$(TAR_NAME)

dvi: $(INSTALL_DIR)/$(TECH_SUPPORT_DIR)
ifeq ($(shell uname),Darwin)
	@open https://github.com/sav1nbrave4code/Maze
else
	@xdg-open https://github.com/sav1nbrave4code/Maze
endif

$(INSTALL_DIR)/$(TECH_SUPPORT_DIR):
	@-mkdir $(TECH_SUPPORT_DIR)

$(INSTALL_DIR):
	-mkdir $(INSTALL_DIR)

createBuild:
	-mkdir build

linter:
	cp ../materials/linters/CPPLINT.cfg ./
	-@python3 ../materials/linters/cpplint.py --filter=-build/include_subdir model/maze/*.cpp model/core/*.cpp model/cave/*.cpp controller/*.cpp view/main_window.cpp view/*.cpp
	rm CPPLINT.cfg

cppcheck:
	@cppcheck --enable=all --language=c++ --suppress=unusedFunction --suppress=missingInclude model/maze/*.cpp model/core/*.cpp model/cave/*.cpp controller/*.cpp view/main_window.cpp view/*.cpp $(HDR)

tests:
ifeq ($(shell uname),Darwin)
	@g++ $(MODEL_SRC) -o tests.out -lgtest -std=c++17
else
	@g++ $(MODEL_SRC) -o tests.out -lgtest -lpthread -std=c++17
endif
	@./tests.out
