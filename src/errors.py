from colorama import Fore
from sys import exit


class WumpuScriptError(Exception):
  """ Basic WumpuScript error. """

  def __init__(self, message: str, exit_code: int):
    print(f"wmps: {Fore.RED}ERROR{Fore.RESET}: {message}.")
    if exit_code > 0: exit(exit_code)
