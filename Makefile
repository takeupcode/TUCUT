.PHONY: clean All

All:
	@echo "----------Building project:[ s-TUCUT - Debug ]----------"
	@"$(MAKE)" -f  "s-TUCUT.mk"
	@echo "----------Building project:[ t-TUCUT - Debug ]----------"
	@"$(MAKE)" -f  "t-TUCUT.mk" && "$(MAKE)" -f  "t-TUCUT.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ s-TUCUT - Debug ]----------"
	@"$(MAKE)" -f  "s-TUCUT.mk"  clean
	@echo "----------Cleaning project:[ t-TUCUT - Debug ]----------"
	@"$(MAKE)" -f  "t-TUCUT.mk" clean
