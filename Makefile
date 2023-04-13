.PHONY: clean All

All:
	@echo "----------Building project:[ s-TUCUT - Debug ]----------"
	@"$(MAKE)" -f  "s-TUCUT.mk"
clean:
	@echo "----------Cleaning project:[ s-TUCUT - Debug ]----------"
	@"$(MAKE)" -f  "s-TUCUT.mk" clean
