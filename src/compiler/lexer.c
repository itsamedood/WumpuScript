#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "tokens.h"

enum Token *tokenize(char *code)
{
  enum Token *tokens = malloc(strlen(code)+1 * sizeof(char));

  for (size_t i = 0; i < strlen(code); i++)
  {
    char cc = code[i];

    // Letters.
    if (cc == 'a')      tokens[i] = L_A;
    else if (cc == 'A')  tokens[i] = U_A;
    else if (cc == 'b')  tokens[i] = L_B;
    else if (cc == 'B')  tokens[i] = U_B;
    else if (cc == 'c')  tokens[i] = L_C;
    else if (cc == 'C')  tokens[i] = U_C;
    else if (cc == 'd')  tokens[i] = L_D;
    else if (cc == 'D')  tokens[i] = U_D;
    else if (cc == 'e')  tokens[i] = L_E;
    else if (cc == 'E')  tokens[i] = U_E;
    else if (cc == 'f')  tokens[i] = L_F;
    else if (cc == 'F')  tokens[i] = U_F;
    else if (cc == 'g')  tokens[i] = L_G;
    else if (cc == 'G')  tokens[i] = U_G;
    else if (cc == 'h')  tokens[i] = L_H;
    else if (cc == 'H')  tokens[i] = U_H;
    else if (cc == 'i')  tokens[i] = L_I;
    else if (cc == 'I')  tokens[i] = U_I;
    else if (cc == 'j')  tokens[i] = L_J;
    else if (cc == 'J')  tokens[i] = U_J;
    else if (cc == 'k')  tokens[i] = L_K;
    else if (cc == 'K')  tokens[i] = U_K;
    else if (cc == 'l')  tokens[i] = L_L;
    else if (cc == 'L')  tokens[i] = U_L;
    else if (cc == 'm')  tokens[i] = L_M;
    else if (cc == 'M')  tokens[i] = U_M;
    else if (cc == 'n')  tokens[i] = L_N;
    else if (cc == 'N')  tokens[i] = U_N;
    else if (cc == 'o')  tokens[i] = L_O;
    else if (cc == 'O')  tokens[i] = U_O;
    else if (cc == 'p')  tokens[i] = L_P;
    else if (cc == 'P')  tokens[i] = U_P;
    else if (cc == 'q')  tokens[i] = L_Q;
    else if (cc == 'Q')  tokens[i] = U_Q;
    else if (cc == 'r')  tokens[i] = L_R;
    else if (cc == 'R')  tokens[i] = U_R;
    else if (cc == 's')  tokens[i] = L_S;
    else if (cc == 'S')  tokens[i] = U_S;
    else if (cc == 't')  tokens[i] = L_T;
    else if (cc == 'T')  tokens[i] = U_T;
    else if (cc == 'u')  tokens[i] = L_U;
    else if (cc == 'U')  tokens[i] = U_U;
    else if (cc == 'v')  tokens[i] = L_V;
    else if (cc == 'V')  tokens[i] = U_V;
    else if (cc == 'w')  tokens[i] = L_W;
    else if (cc == 'W')  tokens[i] = U_W;
    else if (cc == 'x')  tokens[i] = L_X;
    else if (cc == 'X')  tokens[i] = U_X;
    else if (cc == 'y')  tokens[i] = L_Y;
    else if (cc == 'Y')  tokens[i] = U_Y;
    else if (cc == 'z')  tokens[i] = L_Z;
    else if (cc == 'Z')  tokens[i] = U_Z;

    // Numbers.
    else if (cc == '0')  tokens[i] = ZERO;
    else if (cc == '1')  tokens[i] = ONE;
    else if (cc == '2')  tokens[i] = TWO;
    else if (cc == '3')  tokens[i] = THREE;
    else if (cc == '4')  tokens[i] = FOUR;
    else if (cc == '5')  tokens[i] = FIVE;
    else if (cc == '6')  tokens[i] = SIX;
    else if (cc == '7')  tokens[i] = SEVEN;
    else if (cc == '8')  tokens[i] = EIGHT;
    else if (cc == '9')  tokens[i] = NINE;

    // Symbols.
    else if (cc == '(')  tokens[i] = L_PAREN;
    else if (cc == ')')  tokens[i] = R_PAREN;
    else if (cc == '{')  tokens[i] = L_BRACE;
    else if (cc == '}')  tokens[i] = R_BRACE;
    else if (cc == '[')  tokens[i] = L_BRACKET;
    else if (cc == ']')  tokens[i] = R_BRACKET;
    else if (cc == '+')  tokens[i] = PLUS;
    else if (cc == '-')  tokens[i] = HYPHEN;
    else if (cc == '*')  tokens[i] = ASTERISK;
    else if (cc == '/')  tokens[i] = FORWARD_SLASH;
    else if (cc == '%')  tokens[i] = PERCENT;
    else if (cc == '<')  tokens[i] = LESS_THAN;
    else if (cc == '>')  tokens[i] = GREATER_THAN;
    else if (cc == '~')  tokens[i] = TILDE;
    else if (cc == '^')  tokens[i] = CAROT;
    else if (cc == '&')  tokens[i] = AMPERSAND;
    else if (cc == '!')  tokens[i] = EXCLAMATION;
    else if (cc == '?')  tokens[i] = QUESTION;
    else if (cc == '_')  tokens[i] = UNDERSCORE;
    else if (cc == '.')  tokens[i] = PERIOD;
    else if (cc == ',')  tokens[i] = COMMA;
    else if (cc == ':')  tokens[i] = COLON;
    else if (cc == ';')  tokens[i] = SEMICOLON;
    else if (cc == '"')  tokens[i] = D_QUOTE;
    else if (cc == '\'') tokens[i] = S_QUOTE;
    else if (cc == '`')  tokens[i] = BACKTICK;
    else if (cc == '|')  tokens[i] = PIPELINE;
    else if (cc == '@')  tokens[i] = AT;
    else if (cc == '#')  tokens[i] = HASH;
    else if (cc == '$')  tokens[i] = DOLLAR;
    else if (cc == '\\') tokens[i] = BACKSLASH;

    // Other.
    else if (cc == ' ')  tokens[i] = WHITESPACE;
    else if (cc == '\t') tokens[i] = TAB;
    else if (cc == '\n') tokens[i] = NEWLINE;
    else                 tokens[i] = UNKNOWN;

    // printf("CC = %c\n", cc);
    printf("TOKEN = %d\n", tokens[i]);
  }

  return tokens;
}
