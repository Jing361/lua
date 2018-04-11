#include<string>
#include<iostream>
#include<sstream>

#include"lexer.hh"
#include"shared.hh"

using namespace std;

static classification classify( char c ){
  if( ( c == '-' ) ||
      ( c == '=' ) ||
      ( c == '<' ) ||
      ( c == '>' ) ||
      ( c == '|' ) ||
      ( c == '&' ) ||
      ( c == '*' ) ||
      ( c == '/' ) ){
    return classification::OPERATOR;
  } else if( isdigit( c ) ){
    return classification::INTEGER;
  } else if( isalpha( c ) ){
    return classification::IDENT;
  } else if( isspace( c ) ){
    return classification::SPACE;
  } else if( c == '(' || c == ')' ){
    return classification::PAREN;
  } else if( c == -1 ){
    return classification::EoF;
  } else if( c == ';' ){
    return classification::SEMI;
  } else if( ( c == '{' ) || ( c == '}' ) ){
    return classification::BRACKET;
  } else if( c == ',' ){
    return classification::COMMA;
  } else {
    return classification::NONE;
  }
}

lexer::lexer(){
}

void lexer::lex( const string& text ){
  unsigned long row = 0;
  unsigned long column = 0;
  stringstream ss( text );
  string word;

  while( ss >> word ){
    for( auto c : word ){
      //if( c ==
    }
  }

  for( unsigned int i = 0; i < text.size(); ++i ){
    string tok;
    classification cls = classification::NONE;
    ++column;

    cls = classify( text[i] );

    if( cls == classification::NONE ){
      cout << "Invalid character: '" << text[i] << "'." << endl;
      continue;
    }

    while( ( classify( text[i] ) == cls ) && ( i < text.size() ) ){
      tok += text[i++];
      ++column;
    }
    --i;
    --column;

    if( cls == classification::IDENT ){
      if( tok == "extern" ){
        cls = classification::EXTERN;
      } else if( tok == "if" ){
        cls = classification::IF;
      } else if( tok == "else" ){
        cls = classification::ELSE;
      } else {
        cls = classification::TYPE;
      }
    }

    if( cls != classification::SPACE && tok != "" ){
      mTokens.emplace_back( cls, tok, row, column );
    } else if( !tok.empty() && ( tok[0] == '\n' || tok[0] == '\r' ) ){
      column = 0;
      ++row;
    }
  }

  mTokens.emplace_back( classification::EoF, "", row, column );
}

lexer::vec_token::const_iterator lexer::cbegin() const{
  return mTokens.cbegin();
}

lexer::vec_token::const_iterator lexer::cend() const{
  return mTokens.cend();
}

lexer::vec_token::iterator lexer::begin(){
  return mTokens.begin();
}

lexer::vec_token::iterator lexer::end(){
  return mTokens.end();
}

