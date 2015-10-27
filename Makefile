CFLAGS= -std=c11 -O3
EXEC=   docidgen
SOURCE= docidgen.c

build: $(EXEC)

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXEC) $(SOURCE)

clean:
	rm -f $(EXEC)

rebuild: clean build
