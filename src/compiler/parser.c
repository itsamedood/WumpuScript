#include <stdlib.h>
#include "parser.h"
#include "tokens.h"

void parse_tokens(enum Token *tokens, size_t tokencount)
{
  for (size_t i = 0; i < tokencount; i++)
  {
    enum Token token = tokens[i];
    switch (token)
    {
      /* Letters. */
      case L_A: break;
      case U_A: break;
      case L_B: break;
      case U_B: break;
      case L_C: break;
      case U_C: break;
      case U_D: break;
      case L_D: break;
      case U_E: break;
      case L_E: break;
      case U_F: break;
      case L_F: break;
      case U_G: break;
      case L_G: break;
      case U_H: break;
      case L_H: break;
      case U_I: break;
      case L_I: break;
      case U_J: break;
      case L_J: break;
      case U_K: break;
      case L_K: break;
      case U_L: break;
      case L_L: break;
      case U_M: break;
      case L_M: break;
      case U_N: break;
      case L_N: break;
      case U_O: break;
      case L_O: break;
      case U_P: break;
      case L_P: break;
      case U_Q: break;
      case L_Q: break;
      case U_R: break;
      case L_R: break;
      case U_S: break;
      case L_S: break;
      case U_T: break;
      case L_T: break;
      case U_U: break;
      case L_U: break;
      case U_V: break;
      case L_V: break;
      case U_W: break;
      case L_W: break;
      case U_X: break;
      case L_X: break;
      case U_Y: break;
      case L_Y: break;
      case U_Z: break;
      case L_Z: break;

      /* Numbers. */
      case ZERO: break;
      case ONE: break;
      case TWO: break;
      case THREE: break;
      case FOUR: break;
      case FIVE: break;
      case SIX: break;
      case SEVEN: break;
      case EIGHT: break;
      case NINE: break;

      /* Symbols. */
      case L_PAREN: break;
      case R_PAREN: break;
      case L_BRACE: break;
      case R_BRACE: break;
      case L_BRACKET: break;
      case R_BRACKET: break;
      case PLUS: break;
      case HYPHEN: break;
      case ASTERISK: break;
      case FORWARD_SLASH: break;
      case PERCENT: break;
      case LESS_THAN: break;
      case GREATER_THAN: break;
      case TILDE: break;
      case CAROT: break;
      case AMPERSAND: break;
      case EXCLAMATION: break;
      case QUESTION: break;
      case UNDERSCORE: break;
      case PERIOD: break;
      case COMMA: break;
      case COLON: break;
      case SEMICOLON: break;
      case D_QUOTE: break;
      case S_QUOTE: break;
      case BACKTICK: break;
      case PIPELINE: break;
      case AT: break;
      case HASH: break;
      case DOLLAR: break;
      case BACKSLASH: break;

      /* Other. */
      case WHITESPACE: break;
      case TAB: break;
      case NEWLINE: break;
      case UNKNOWN: break;
    }
  }
}
