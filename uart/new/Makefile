
TARGET = $(notdir $(CURDIR))
objs := $(patsubst %c, %o, $(shell ls *.c))
$(TARGET)_:$(objs)
	$(CC) -o $@ $^
%.o:%.c
	$(CC) -c -o $@ $<
clean:
	rm -f  $(TARGET)_ *.all *.o
