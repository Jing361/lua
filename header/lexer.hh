#ifndef __LEXER_HH__
#define __LEXER_HH__

#include<vector>
#include<functional>
#include<string>
#include<map>

#include"shared.hh"

class lexer{
public:
  typedef std::vector<token> vec_token;

private:
  vec_token mTokens;

public:
  lexer();

  void lex( const std::string& text );

  vec_token::const_iterator cbegin() const;
  vec_token::const_iterator cend() const;

  vec_token::iterator begin();
  vec_token::iterator end();
};

#endif

