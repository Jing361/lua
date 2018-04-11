#ifndef __SHARED_TYPES_HH__
#define __SHARED_TYPES_HH__

#include<utility>
#include<string>
#include<set>

enum class classification{
  NONE,
  IDENT,
  OPERATOR,
  INTEGER,
  SPACE,
  PAREN,
  EoF,
  SEMI,
  EXTERN,
  COMMA,
  BRACKET,
  IF,
  ELSE,
  TYPE,
};

struct token{
  classification type;
  std::string tok;
  unsigned long row;
  unsigned long column;

  token( classification c, const std::string& s, unsigned long r, unsigned long o ):
    type( c ),
    tok( s ),
    row( r ),
    column( o ){
  }
};

#endif

