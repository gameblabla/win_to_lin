PRGNAME     = test.elf
CC			= gcc

OBJS		= main.o

CFLAGS		= -O0 -g3 -I. -Ifont -DEMPTY_ARRAY_SIZE=2048 -Iiso9660

CXXFLAGS = $(CFLAGS)

LDFLAGS     =  -lc -lgcc -lm -ldl -lSDL2 -lopenal -lasound -lpng -lgbm -ldrm -ludev -lpng -pthread -levdev


# Rules to make executable
$(PRGNAME): $(OBJS)  
	$(CC) $(CFLAGS)  -o $(PRGNAME) $^ $(LDFLAGS)

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -std=gnu99 -c -o $@ $<

clean:
	rm -f $(PRGNAME) *.o font/*.o
