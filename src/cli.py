from errors import WumpuScriptError
from flags import Flags
from sys import argv


class Cli:
  """ Handles stuff from the command line, like flags. """

  @staticmethod
  def read_argv() -> tuple[Flags, str]:
    args = argv[1:] if len(argv) > 1 else []
    if len(args) < 1: raise WumpuScriptError("no arguments", 1)

    return (Flags(argv), argv[-1])
