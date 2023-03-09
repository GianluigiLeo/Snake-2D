NAME_APP = Snake
NAME_APP_COMPILE = snake
LDGCCFLAGS = -Wall -std=c++11 -fmessage-length=0 -O0 -g3
LDOPENGLFLAGS = -lGL -lGLEW -lglfw

FILE_SOURCE_APP = src/*.cpp \
					src/App/*.cpp \
					src/Game/*.cpp \
					src/Core/Graphics/*.cpp \
					src/Core/Entity/*.cpp 

		

$(NAME_APP): $(FILE_SOURCE_APP) 
	g++ -o $(NAME_APP) $(FILE_SOURCE_APP) $(LDGCCFLAGS) $(LDOPENGLFLAGS) 

.PHONY: $(NAME_APP_COMPILE) clean

$(NAME_APP_COMPILE): $(NAME_APP)
	./$(NAME_APP)

clean:
	rm -f $(NAME_APP)
