build-pub_sub:
	@echo "Build pub/sub folder"
	@mkdir -p build
	@cd build; \
	cmake ../pub_sub; \
	make

run-pub_sub: build-pub_sub
	@./build/main

build-oop_in_c:
	@echo "Build oop_in_c folder"
	@mkdir -p build
	@cd build; \
	cmake ../oop_in_c; \
	make

run-oop_in_c: build-oop_in_c
	@./build/main

build-Matrix:
	@echo "Build Matrix folder"
	@mkdir -p build
	@cd build; \
	cmake ../Matrix; \
	make

run-Matrix: build-Matrix
	@./build/main

build-builder:
	@echo "Build builder folder"
	@mkdir -p build
	@cd build; \
	cmake ../builder; \
	make

run-builder: build-builder
	@./build/main

run: build
	@./build/main
	
PHONY: clean
clean:
	rm -rf build