# Copyright (c) 2019 Edwin Pratt
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

CC:=g++
FLAGS:=-W -Wall -Werror -Wextra -Wpedantic -pedantic

.PHONY: all, clean

all:
	$(foreach file, $(wildcard ./*.cpp), $(CC) $(FLAGS) $(file) -o $(basename $(file));)

clean:
	rm -fr *.out *.app *.exe
