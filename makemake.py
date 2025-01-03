import os

root = "src"

objs = "OBJ="
targets = ""
for subdir, dirs, files in os.walk(root):
    src = subdir.replace('\\', '/')
    for file in files:
        output = f"$(OUT)/{file.replace('.cpp', '.o')}"
        targets += f"{output}: {src}/{file}\n"
        targets += f"\t$(CC) $(CFLAGS) $(DEBUG_FLAGS) {src}/{file} $(INCLUDE) -o {output}\n"
        objs += f"{output} "

full_content = f"""# Generated by makemake.py
CC=g++.exe
INCLUDE=-Iinc
CFLAGS=-c
DEBUG_FLAGS=-Wall
OUT=out
EXE=game.exe

all: debug
debug: $(OUT)/$(EXE)
run:
\t$(OUT)/$(EXE)

{objs}

{targets}
$(OUT)/$(EXE): $(OBJ)
\t$(CC) $(OBJ) -o $(OUT)/$(EXE)

clean:
\trm $(OUT)/*
"""

with open("Makefile", "w") as makefile:
    makefile.write(full_content)
