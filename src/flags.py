from sys import exit


class Flags:
  """ Represents given flags from the command line. """

  verbose = False
  help = """Usage: wmps [-flags] <main>
Flags:
  --verbose | Displays some information from the compiler.
  --help    | Displays this help message.
"""

  def __init__(self, _argv: list[str]) -> None:
    for a in [a[1:] for a in _argv if a[0] == '-']:
      match a:
        case "verbose": self.verbose = True

        case "help":
          print(self.help)
          exit(0)

        case unknown_flag: print("Unknown flag: '%s'" %unknown_flag)

    print(self.verbose)
