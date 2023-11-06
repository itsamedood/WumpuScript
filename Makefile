COMPILER=PyInstaller
MAIN=src/main.py
DISTPATH=bin
OUT=wmps
FLAGS=--onefile --distpath $(DISTPATH) --name $(OUT)

.PHONY: test compile

test:
	@$(DISTPATH)/$(OUT) --verbose

compile:
	@echo Compiling...
	$(COMPILER) $(FLAGS) $(MAIN)
	@echo Done.
