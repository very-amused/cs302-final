CXX=g++
CXXFLAGS+=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -lsfml-network

src-files=$(shell find -name '*.cpp')
obj-files=$(src-files:.cpp=.cpp.o)

main: $(obj-files)
	$(CXX) $(CXXFLAGS) -o$@ $^

%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o$@ $<

clean:
	rm -f $(obj-files)
.PHONY: clean
