PRGNAME     = cdinfo.elf
CC			= gcc

OBJS		= main.o util.o

CFLAGS		= -O0 -g3 -I. -Ifont -DEMPTY_ARRAY_SIZE=2048 -Iiso9660

CXXFLAGS = $(CFLAGS)

LDFLAGS     =  -lc -lgcc -lm -lcdio -liso9660


# Rules to make executable
$(PRGNAME): $(OBJS)  
	$(CC) $(CFLAGS)  -o $(PRGNAME) $^ $(LDFLAGS)

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -std=gnu99 -c -o $@ $<

clean:
	rm -f $(PRGNAME) *.o font/*.o
