proj-dir=CS302-final-project

$(proj-dir)/main:
	$(MAKE) -C $(proj-dir)

clean:
	$(MAKE) -C $(proj-dir) clean
.PHONY: clean
