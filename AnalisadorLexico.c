#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

// FUNÇÕES QUE VERIFICAM QUAIS OS TIPOS DOS TOKENS 

void isIndentificador(char *token, int cont)
{
  if (token[0] == 'A' || token[0] == 'B' || token[0] == 'C' || token[0] == 'D' ||
      token[0] == 'E' || token[0] == 'F' || token[0] == 'G' || token[0] == 'H' || 
      token[0] == 'I' || token[0] == 'J' || token[0] == 'K' || token[0] == 'L' || 
      token[0] == 'M' || token[0] == 'N' || token[0] == 'O' || token[0] == 'P' || 
      token[0] == 'Q' || token[0] == 'R' || token[0] == 'S' || token[0] == 'T' || 
      token[0] == 'U' || token[0] == 'V' || token[0] == 'W' || token[0] == 'X' || 
      token[0] == 'Y' || token[0] == 'Z' ||
      token[0] == 'a' || token[0] == 'b' || token[0] == 'c' || token[0] == 'd' ||
      token[0] == 'e' || token[0] == 'f' || token[0] == 'g' || token[0] == 'h' || 
      token[0] == 'i' || token[0] == 'j' || token[0] == 'k' || token[0] == 'l' || 
      token[0] == 'm' || token[0] == 'n' || token[0] == 'o' || token[0] == 'p' || 
      token[0] == 'q' || token[0] == 'r' || token[0] == 's' || token[0] == 't' || 
      token[0] == 'u' || token[0] == 'v' || token[0] == 'w' || token[0] == 'x' || 
      token[0] == 'y' || token[0] == 'z' )
  {
    //cont++;
    printf("%s e um lexema mapeado para o token <id,%i>\n", token, cont);
  } 
  
}
void isOpAtribuicao(char *token)
{

  if (*token == '=')
  {
    printf("O simbolo de atribuicao %s e um lexema mapeado para o token <%s>.\n", token, token);
  }
  
}
void isOperadores(char *token)
{
  if (*token == '+' || *token == '-' || *token == '*' || *token == '/')
  {
    printf("%s e um lexema mapeado em um token <%s>.\n", token, token);
  }
  
}
void isNumero(char *token)
{
   if (*token == '1' || *token == '2' || *token == '3' || 
       *token == '4' || *token == '5' || *token == '6' ||
       *token == '7' || *token == '8' || *token == '9' || 
       *token == '0')
  {
    printf("%s e um lexema mapeado em um token <%s>\n", token, token);
  }
}

int main()
{
  char *p;
  char conteudoArquivo[256];
  int cont = 1;
  
  // LENDO UM ARQUIVO TXT
  FILE *file = fopen("teste.txt", "r");
  if (file == NULL)
  {
    printf("Arquivos está vazio");
    return 0;
  }
  
  printf("\n\n\n");

  //    DENTRO DESSE WHILE A FUNÇÃO "fgets" LER OS DADOS DO ARQUIVOS E 
  //    PASSA PARA A VERIAVEL "conteudoArquivo"

  while (fgets(conteudoArquivo, 256, file) != NULL)
  {

    //      ESSE TRECHO DO CODIGO USA A FUNÇÃO STRTOK QUE SEPARA UMA STRING
    //      EM PEDAÇOS BASEADO EM UM DELIMITADOR, QUE NO CASO USAMOS O " " (ESPAÇO),
    //      OU SEJA, A CADA DELIMITADOR(ESPAÇO) O STRTOK GERA UMA NOVA STRING

    p = strtok(conteudoArquivo, " ");
    isIndentificador(p, cont);
    isOpAtribuicao(p);
    isOperadores(p);
    isNumero(p);
  
    while (conteudoArquivo != NULL)
    {
      p = strtok(NULL, " ");
      isIndentificador(p, cont++);
      isOpAtribuicao(p);
      isOperadores(p);
      isNumero(p);
    }
  }

  
  printf("\n\n\n");

  return 0;
}