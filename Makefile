proj-dir=CS302-final-project

$(proj-dir)/main:
	$(MAKE) -C $(proj-dir)
.PHONY: $(proj-dir)/main

run: $(proj-dir)/main
	cd $(proj-dir) && ./main
.PHONY: run

clean:
	$(MAKE) -C $(proj-dir) clean
.PHONY: clean
