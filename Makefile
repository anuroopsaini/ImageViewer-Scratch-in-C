CC = gcc
CFLAGS = -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lSDL2

imageviewer: imageviewer.c
	$(CC) imageviewer.c -o imageviewer $(CFLAGS) $(LDFLAGS)

clean:
	rm -f imageviewer