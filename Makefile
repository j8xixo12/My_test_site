build-pub_sub:
	@echo "Build pub/sub folder"
	@mkdir -p build
	@cd build; \
	cmake ../pub_sub; \
	make

run-pub_sub: build-pub_sub
	@./build/main
PHONY: clean
clean:
	rm -rf build