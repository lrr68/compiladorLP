/* Acoes semanticas 
 * Cada metodo implementa a verificacao de uma acao semantica,
 * em caso de erro, chama a funcao erroSintatico e aborta o programa
 */

#include "types.h"
#include "ansin.h"

void defClasse(Classe);
void verificaTam(void);
void verificaClasee(void);

void defClasse(Classe classe)
{
	tokenAtual.classe = classe;
}

/* verifica se o tamanho dos arrays eh valido */
void verificaTam(void)
{
	int tam = str2int(tokenAtual.lexema);
	/* tipo char ocupa 1 byte portanto o array pode ter 4k posicoes */
	if (tokenAtual.tipo == TP_Char && tam > 4000) erroSintatico(ERRO_SINTATICO_TAM_VET);

	/* tipo integer ocupa 2 bytes portanto o array pode ter 4k/2 posicoes */
	if (tokenAtual.tipo == TP_Integer && tam > 2000) erroSintatico(ERRO_SINTATICO_TAM_VET);

	/* else 
	 * atualiza o registro lexico com o tamanho
	 */
	tokenAtual.tamanho = tam;
}

/* Verificacao de classe
 * atualiza na tabela de simbolos o tipo e a classe do elemento,
 * caso a classe ja esteja definida, significa que a variavel
 * ou constante ja foi declarada
 */
void verificaClasse(void)
{
	tokenAtual.endereco = pesquisarRegistro(tokenAtual.lexema);

	if (tokenAtual.endereco->simbolo.classe == 0) {
		tokenAtual.endereco->simbolo.tipo = tokenAtual.tipo;
		tokenAtual.endereco->simbolo.classe = tokenAtual.classe;
	} else {
		erroSintatico(ERRO_SINTATICO_JA_DECL);
	}
}

