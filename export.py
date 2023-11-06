from os import system, scandir, getcwd, makedirs
from platform import system as sys_name
from sys import argv


TARGET, VERSION = '', "0.0.1"
OS, ZIP, OUTPATH, ASM = sys_name().lower(), '', '', "bin/assembly"
PWD = getcwd()
SYS: str | None


match OS:
  case "darwin": SYS = "macos"
  case "linux": SYS = "linux"
  case "windows": SYS = "windows"
  case _: SYS = None


if SYS is None: raise Exception("Unknown OS.")

TARGET = "wmps.exe" if SYS == "windows" else "wmps"
OUTPATH = "bin/%s" %SYS
ZIP = f"release/{VERSION}/WumpuScript-{SYS}.zip"

makedirs(OUTPATH, exist_ok=True)
makedirs(ASM, exist_ok=True)


def get_source_files() -> list[str]:
  source_files: list[str] = []

  for f in scandir("%s/src" %PWD):
    if f.is_file() and f.name.endswith(".c"): source_files.append(f"src/{f.name}")
    elif f.is_dir():
      for g in scandir(f"src/{f.name}"):
        if g.is_file() and g.name.endswith(".c"): source_files.append(f"src/{f.name}/{g.name}")

  return source_files

def compile(_source_files: list[str]) -> None:
  print("Compiling: %s" %' '.join(_source_files))

  # Compile to `bin/SYS/wmps('.exe' if Windows)`.
  system(f"gcc -Wall -Wextra -O2 -g -o {OUTPATH}/{TARGET} {' '.join(_source_files)}")
  print("Finished compiling!\n-------------------------")

  print("Dumping assembly...")

  # Dump assembly code in `bin/assembly/<file>.s`.
  for sf in _source_files: system(f"gcc -S {sf} -o {ASM}/{sf.split('/')[-1][:-2]}.s")
  print("Finished dumping!\n-------------------------")

def package() -> None:
  print("Packaging...")
  # Code to package.
  print("Finished packaging!\n-------------------------")

def test() -> None:
  print("Testing...\n-------------------------")

  bot = "test/bot/main.wmps"
  system(f"{PWD}/{OUTPATH}/{TARGET} {bot}" if SYS == "windows" else f"{OUTPATH}/{TARGET} {bot}")
  print("-------------------------\nTest finished!\n-------------------------")


if __name__ == "__main__": package() if len(argv) > 1 and argv[1] == "--zip" else compile(get_source_files()); test()
