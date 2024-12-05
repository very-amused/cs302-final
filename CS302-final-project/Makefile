CXX=g++
sfml-flags=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -lsfml-network
LDFLAGS=$(sfml-flags)

src-files=$(shell find -name '*.cpp')
obj-files=$(src-files:.cpp=.cpp.o)

main: $(obj-files)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o$@ $^

release: CXXFLAGS+=-O3
release: main
.PHONY: release

%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o$@ $<

clean:
	rm -f $(obj-files) main
.PHONY: clean
