#ifndef _LEXAN_H
#define _LEXAN_H

	#define ER_LEX -11
	#define ER_LEX_EOF -12
	#define ER_LEX_INVD -13
	#define ER_LEX_N_ID -14
	#define ACEITACAO_LEX 13
	#define C_INVALIDO letra != '/' &&\
			!ehBranco(letra)&&\
			!ehDigito(letra)&&\
			!ehLetra(letra) &&\
			letra != '_'    &&\
			letra != '.'    &&\
			letra != '<'    &&\
			letra != '>'    &&\
			letra != '"'    &&\
			letra != ','    &&\
			letra != ';'    &&\
			letra != '+'    &&\
			letra != '-'    &&\
			letra != '('    &&\
			letra != ')'    &&\
			letra != '{'    &&\
			letra != '}'    &&\
			letra != '['    &&\
			letra != ']'    &&\
			letra != '%'    &&\
			letra != '='    &&\
			letra != ':'    &&\
			letra != '\''   &&\
			letra != '.'    \
	
	//define DEBUG_LEX
	#ifdef DEBUG_LEX
		#define DEBUGLEX(...) printf(__VA_ARGS__);
	#else
		#define DEBUGLEX(...)
	#endif
	
	extern struct registroLex regLex;
	extern FILE *progFonte;
	extern int erro;
	extern int lex;
	
	/* Analisador léxico */
	void lexan(void);
#endif
