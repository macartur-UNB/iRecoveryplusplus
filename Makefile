CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -I./include -Wl,-fuse-ld=gold
CXXALL =	-lreadline
CXXCSS =	-I"./include" -I"/usr/local/include" -L"/usr/local/lib"
CXXWIN =	-lusb -I"./include" -I"C:\MinGW\include" -L"C:\MinGW\lib"
CXXNIX =	-lusb-1.0
CXXOSX =	-lusb-1.0 -framework CoreFoundation -framework IOKit

DIRS =		./src ./include
TARGET =	./bin/iRecovery

EXTRA_FILES = 	./Makefile ./images/irecvpp-black.jpg ./images/irecvpp.png
SOURCE :=	$(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.cpp))
HEADERS :=	$(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.h))

all:	
	@echo 'iRecovery++, requires you run make with a platform argument (win, linux, mach, backup).'

start:
	@echo ''
	@echo 'Building iRecovery++'
	@echo ''
	@rm -rf ./bin;

linux:	start $(SOURCE)
	@mkdir ./bin;
	$(CXX) -o $(TARGET) $(SOURCE) $(CXXCSS) $(CXXALL) $(CXXNIX) $(CXXFLAGS)
	
mach:	start $(SOURCE)
	@mkdir ./bin;
	$(CXX) -o $(TARGET) $(SOURCE) $(CXXCSS) $(CXXALL) $(CXXOSX) $(CXXFLAGS)

win:	start $(SOURCE)
	@mkdir ./bin;
	$(CXX) -o $(TARGET) $(SOURCE) $(CXXALL) $(CXXWIN)

backup: $(SOURCE) $(HEADERS) $(EXTRA_FILES)
	@if [ ! -e ./backup ]; then mkdir ./backup; fi;
	@zip ./backup/`date +%d-%m-%y_%H.%M`.zip $(SOURCE) $(HEADERS) $(EXTRA_FILES)

