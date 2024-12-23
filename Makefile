CC=cl.exe
CFLAGS=/O2
DEBUG_FLAGS=/Od
SRC=src/*.cpp

OUT_DEBUG=/Fo"out/x64/debug/"
OUT_RELEASE=/Fo"out/x64/release/"

EXE_DEBUG=/Fe"out/x64/debug/game.exe"
EXE_RELEASE=/Fe"out/x64/release/game.exe"

all: dirs debug

dirs:
	if not exist out mkdir out\x64\debug out\x64\release

debug:
	$(CC) $(DEBUG_FLAGS) $(SRC) $(OUT_DEBUG) $(EXE_DEBUG)

release:
	$(CC) $(CFLAGS) $(SRC) $(OUT_RELEASE) $(EXE_RELEASE)

clean:
	rmdir /S /Q out
