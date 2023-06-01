from os import system, name, scandir, getenv
from sys import argv


MAIN, BINARY, VERSION = "src/main.py", "wmps", "0.0.1"
OS, ZIP, OUTPATH = name, '', ''
CWD = ''
SYS: str | None


match OS:
    case "posix":
        SYS = "macos"
        CWD = getenv("PWD")

    case "linux":
        SYS = "linux"
        CWD = getenv("PWD")

    case "win32":
        SYS = "windows"
        CWD = getenv("CWD")

    case _: SYS = None


OUTPATH = "bin/%s" %SYS
ZIP = f"release/{VERSION}/WumpuScript-{SYS}.zip"
SRC_FILES = ["src/%s" %f.name for f in scandir("%s/src" %CWD) if f.name[-2:] == ".c"]


def compile():
    print("🛠 Compiling... 🛠\n-----------------")

    if (SYS == "win32"): ...
    else:
        print(f"gcc -o {OUTPATH}/{BINARY} {' '.join(SRC_FILES)}")
        system(f"gcc -o {OUTPATH}/{BINARY} {' '.join(SRC_FILES)}")

    print("🛠️ Finished compiling! 🛠️\n------------------------")


def package():
    print("📦 Packaging... 📦\n------------------")
    # Code to package.
    print("📦 Finished packaging! 📦\n-------------------------")


if __name__ == "__main__": package() if len(argv) > 1 and argv[1] == "--zip" else compile()
