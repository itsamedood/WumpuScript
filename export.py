from os import system, scandir, getenv, mkdir
from os.path import exists
from platform import system as sys_name
from sys import argv


TARGET, VERSION = "wmps", "0.0.1"
OS, ZIP, OUTPATH = sys_name().lower(), '', ''
CWD = ''
SYS: str | None


match OS:
    case "darwin":
        SYS = "macos"
        CWD = getenv("PWD")

    case "linux":
        SYS = "linux"
        CWD = getenv("PWD")

    case "windows":
        SYS = "windows"
        CWD = getenv("CWD")

    case _: SYS = None


OUTPATH = "bin/%s" %SYS
ZIP = f"release/{VERSION}/WumpuScript-{SYS}.zip"
SRC_FILES = ["src/%s" %f.name for f in scandir("%s/src" %CWD) if f.name[-2:] == ".c"]


if not exists(OUTPATH): mkdir(OUTPATH)

def compile():
    print("🛠 Compiling: %s 🛠" %' '.join(SRC_FILES))
    system(f"gcc -o {OUTPATH}/{TARGET} {' '.join(SRC_FILES)}")

    print("🛠️ Finished compiling! 🛠️\n------------------------")


def package():
    print("📦 Packaging... 📦\n------------------")
    # Code to package.
    print("📦 Finished packaging! 📦\n-------------------------")


if __name__ == "__main__": package() if len(argv) > 1 and argv[1] == "--zip" else compile()
