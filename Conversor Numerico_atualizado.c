#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


/*==========================================================================================*/
/*==========================================================================================*/

/* =================== ISSO AQ TUDO E A PARTE DO GUSTAVO( nao me julgem ) =================*/

typedef struct {
    int parte_inteira;
    double parte_frac;
    
    int binario[50];
    int bin_frac[50];
} s_numero; /*struct para armazenar o decimal e binario*/

/*==========================================================================================*/
/*==========================================================================================*/

void dividirDecimal(double decimal, s_numero *pnum) {
    pnum->parte_inteira = (int)decimal;
    pnum->parte_frac = decimal - (int)decimal;
    
}  /*fun??o para dividir a parte inteira e a parte fracionaria do decimal.*/

/* ============================================================================================================================*/
/* ============================================================================================================================*/

void trocar_base_hexa(int valor_hexa[], int ilaco) {
	/* essa funcao troca os valores entre 10 e 15 dos decimais para os caracteres entre A e F dos hexadecimais */
	/* al?m da troca ela imprime todo o decimal convertido em hexadecimal */
	/* valor_hexa e o vetor que esta guardado os decimais inteiros a serem convertidos */
	/* ilaco e o tamanho dele  */
	
	for(ilaco; ilaco >= 0; ilaco--) {
	
		switch(valor_hexa[ilaco]) {
			case 10: {
				printf("A");
				break;
			}
			case 11: {
				printf("B");
				break;
			}
			case 12: {
				printf("C");
				break;
			}
			case 13: {
				printf("D");
				break;
			}
			case 14: {
				printf("E");
				break;
			}
			case 15: {
				printf("F");
				break;
			}
			default:
				printf("%d", valor_hexa[ilaco]);
		}
		
	}
		
}

/* ============================================================================================================================*/
/* ============================================================================================================================*/

void converterDec_Bin(s_numero *pnum) {
    int i; 
	double resto;
    int cont = 0; 			/*contador para inverter o binario*/
	double fracao;
    int limite; /*para o complemento de 2;*/
    
	if(pnum->parte_inteira >=0) {
	
	    /*laço para as divisoes sucessivas por dois.*/
	    for(i=0; pnum->parte_inteira != 0; i++) {
	    	
	        resto = pnum->parte_inteira % 2; 				 /* resto recebe o ponteiro apontado para a variavel 'parte_inteira' na struct */
	        pnum->parte_inteira = pnum->parte_inteira / 2;  /*o valor da 'parte_inteira' e dividido*/
	        pnum->binario[i] = resto;						/*os valores do resto da divisao e armazenado na variavel 'binario' na struct*/
	        cont++;		/*incremento do contador*/
	    }
	    
	    pnum->binario[i] = 0;  /*garante que o binario fique com 0 no comeco, indicando ele ser positivo*/
	    
	    /*laco for para imprimir na ordem correta;*/
	    for(i = cont ; i>=0; i--) {
	    	printf("%d", pnum->binario[i]);
		}
		
	} else if(pnum->parte_inteira < 0) {
		
		
	/*DAQUI PRA FRENTE e A PARTE CASO O USUARIO ESCOLHA UM NUMERO NEGATIVO, ASSIM O BINARIO e */
	/*TRANSFORMADO EM COMPLEMENTO DE 2*/
		
		pnum->parte_inteira -= (pnum->parte_inteira*2); /*isso garante que o negativo se torne positivo*/
		pnum->parte_frac -= (pnum->parte_frac*2);
		/*por estar na condicao if ( < 0) e adicionado o binario no final;*/
		
		/*laco para as divisoes sucessivas por dois.*/
	    for(i=0; pnum->parte_inteira != 0; i++) {
	    	
	        resto = pnum->parte_inteira % 2; 				 /* resto recebe o ponteiro apontado para a variavel 'parte_inteira' na struct */
	        pnum->parte_inteira = pnum->parte_inteira / 2;  /*o valor da 'parte_inteira' e dividid*/
	        pnum->binario[i] = resto;						/*os valores do resto da divisao e armazenado na variavel 'binario' na struct*/
	        cont++;		/*incremento do contador*/
	    }
	    
	    pnum->binario[i] = 0; /*o ultimo valor recebe 0 para representar o bit de sinal 'positivo'*/
	    
	    
		
		/* 1 for para a inversao do inteiro */
		/* checar onde tem 1 para inverter os numeros apos esse 1 */
		for(i=0; i < cont; i++) {
			if(pnum->binario[i] == 1) {
				limite = i;
				break;
			}
		}
		
		for(i = limite + 1; i<=cont; i++) {	
	    	if(pnum->binario[i] == 0) {
	    		pnum->binario[i] = 1;
			} else if(pnum->binario[i] == 1) {
				pnum->binario[i] = 0;
			}
		}
		
		  for(i = cont; i>=0; i--) {
	    	printf("%d", pnum->binario[i]);
		} 
		
	} /*do else if*/
}  /*da funcao*/

/* ============================================================================================================================*/
/* ============================================================================================================================*/

void converter_Dec_Hexa(double num_decimal) {
	/* esta funçao serve para fazer as divisoes inteiras sucessivas por 16 para obter os restos  */
	/* num_decimal é o valor digitado pelo usuario (esta em double pois preciso fazer a parte fracionaria) */
	int i, cont = 0;
	int resto;     
	int hexad[32];
	int divisor = (int)num_decimal;
	
	
	
	for(i=0; divisor != 0; i++) {
		
		resto = divisor % 16;
		divisor /= 16;
		hexad[i] = resto;
		cont++;
	}
	cont -= 1 ;/*isso serve pois na impressao estava saindo um vetor nao atribuido, gerando lixo de memoria*/
	trocar_base_hexa(hexad, cont);  /*funcao anterior para a impressao.*/
 
}

/*==========================================================================================*/
/*==========================================================================================*/











/* ==========   DAQUI PRA BAIXO E A PARTE DO DANIEL =============*/



/*isso permite que o usr entre com uma string de forma facilitada*/
char inputS(char txt[100], char *var){
	printf("%s", txt);
	scanf(" %99[^\n]", var);
	

/*exemplo de uso: inputS("digite seu nome: ", a), console: digite seu nome: _usr digita aq_*/
}

/*igual ao inputS mas agora para inteiros ou floats e deve-se passar o endereço da var ex.: &b ou se b[1] entao apenas b.*/
/*a conversao para inteiro acontece fora desse bloco*/
float inputF(char txt[100], float *num){
	printf("%s", txt);
	scanf(" %f", num);	
}



/*conversor, ele utiliza o strtol para transformar as bases, ele retorna um long long int */
/*entradas aceitaveis: hex: num e -num, octa: num e -num, bin: primeiro digito sera o bit de sinal(podendo ser*/
/*substituido por + ou -) se for 0 o numero e positivo se for 1 sera negativo, se for 1 ele sera tratado */
/*segundo o complemento de 2, se for 0 ou + sera tratado normalmente, se for - sera tratado normalmente.*/
 
long long int Transforma_base_HOB_decimal(char num[32], int base){
	/*strtol retorna long int, entao para garantir o retorno correto usa-se uma var long para gerar long long int*/
	long num_transformado;
	
	/*aqui testamos se o numero e um binario*/
	if (base == 2){
		
		/* se o numero for digitado no formato de complemento de dois, nos o converteremos para um formato aceitavel */
		if (num[0] == '1'){
			num[0] = '-';
			int i, lim, tamanho_lista= strlen(num);
			
			/*apartir daq fazemos a operacao reversa a do complemento de 2*/
			for (i=tamanho_lista-1; i>0; i--){
				if (num[i]=='1'){
					lim = i;
					break;
				}
			}
			
			for (i=1; i< tamanho_lista; i++ ){
				if (i<lim && num[i]=='1'){
					num[i] = '0';
				}
				
				else if (i<lim && num[i]=='0'){
					num[i] = '1';
				}
				
				else{
					break;
				}
			}
			num_transformado = strtol(num, NULL, base);
			
			/*numero long long int*/
			return num_transformado;
		}
		else{
			
			/*caso o numero seja binario mas nao esta em complemento de 2 ele e tradado de forma padrao*/
			num_transformado = strtol(num, NULL, base);
			return num_transformado;
		}
	}
			
	else{
		
		/*caso nao seja binario ele e tratado de forma padrao*/
		num_transformado = strtol(num, NULL, base);
		return num_transformado;
	}
}

/*==========================================================================================*/
/*==========================================================================================*/









/* ========== DAQUI PRA BAIXO A PARTE DA IZA =========== */

/* Funcao que converte uma string em binario (sem sinal) para decimal */
double binario_para_decimal(char binario[]){
	double decimal = 0.0;   /* Acumula o valor decimal final */
	double potencia = 1.0;  /* Representa 2^0, 2^1, 2^2... conforme anda da direita para a esquerda */
	int tamanho = strlen(binario); /* Quantidade de caracteres da string bin?ria */
	int i;
	int inicio = 0;
    int sinal = 1;
    int posseparador = -1;
    int fiminteira = tamanho;	
	if(binario[0] == '-'){
		sinal = -1;
		inicio = 1;
	}
	
/* 1. CALCULO DA PARTE INTEIRA (antes da virgula/ponto)
   Percorre a string da direita para a esquerda:
   - Comeca em 'fiminteira - 1' (ultimo digito antes da virgula ou fim da string)
   - Vai ate 'inicio' (indice 0 se for positivo, ou indice 1 para pular o sinal '-') */
for(i = fiminteira - 1; i >= inicio; i--){
    if(binario[i] == '1'){
        decimal = decimal + potencia; /* Soma a potencia de 2 atual (1, 2, 4, 8...) */
    } else if (binario[i] != '0'){
        /* Se nao for '1' nem '0', o usuario digitou algo invalido (letra, espaco, etc.) */
        return -999999.0; /* Retorna codigo de erro */
    }
    potencia = potencia * 2.0; /* Dobra a potencia para a proxima casa a esquerda */
}

/* 2. CALCULO DA PARTE QUEBRADA (depois da virgula/ponto)
   So entra aqui se 'posseparador' for diferente de -1 (ou seja, se achou '.' ou ',') */
if(posseparador != -1){
    potencia = 0.5; /* A primeira casa apos a virgula vale 2^-1, que e 0.5 */
    
    /* IMPORTANTE: Comeca em 'posseparador + 1' para pular o proprio caractere '.' ou ',' */
    for(i = posseparador + 1; i < tamanho; i++){
        if(binario[i] == '1'){
            decimal += potencia; /* Soma a fracao (0.5, 0.25, 0.125...) */
        } else if (binario[i] != '0'){
            /* Se houver letra ou uma segunda virgula depois da primeira, retorna erro */
            return -999999.0;
        }
        potencia = potencia / 2.0; /* Divide por 2 para a proxima casa a direita */
    }
}

/* 3. FINALIZACAO
   Multiplica o resultado acumulado por 'sinal' (1 para positivo ou -1 para negativo) */
return decimal * sinal;
}
















/*aplicao de exemplo:*/
int main(){
	char a[32];
	float b;
	int c;
	long long int d;
	 
	 setlocale(LC_ALL, "Portuguese"); /* Configura acentuacao/idioma para portugues */
	int opcao;            /* 'opcao' guarda a escolha do menu; 'resultado' recebe o retorno da conversao */
	long long int decimal_para_octal; /* Armazena o numero decimal informado na opcao 7 */
	char resposta[10] = "sim", resposta_nova[10] = "sim"; /* Controlam se o usuario quer continuar */
	char bin[65];                    /* Buffer para ate 64 bits + caractere nulo '\0' */
	double resultado;
	
	printf("Gostaria de fazer alguma convers?o meu nobre: ");
	scanf("%9s", resposta); /* Le ate 9 caracteres evitando estourar o array 'resposta' */

		
	/* Enquanto a resposta inicial for "sim" ou "SIM" */
	while(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0){
		
		do{
	 		printf("\nPerfeito :) !!!!\n");
	 		/* Exibe as opcoes do menu de conversoes */
	 		printf(" 1. Decimal para Binario\n");
            printf(" 2. Decimal para Octal\n");
            printf(" 3. Decimal para Hexadecimal\n");
            printf(" 4. Binario para Decimal\n");
            printf(" 5. Binario para Octal\n");
            printf(" 6. Binario para Hexadecimal\n");
            printf(" 7. Octal para Decimal\n");
            printf(" 8. Octal para Binario\n");
            printf(" 9. Octal para Hexadecimal\n");
            printf("10. Hexadecimal para Decimal\n");
            printf("11. Hexadecimal para Binario\n");
            printf("12. Hexadecimal para Octal\n");
            printf("0. Sair do menu de conversao\n");
            printf("\nEscolhe ai qual conversao tu quer meu consagrado :) !!!!\n");
            scanf("%d", &opcao); /* Le a opcao escolhida pelo usuario */
            system("cls");
            
            
                switch(opcao){
                case 1: /* Decimal para Binario */
                {
                    double dec_bin;
                    s_numero num_bin;
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o numero decimal para transformar em binario: ");
                    scanf("%lf", &dec_bin);
                    system("cls");
                    dividirDecimal(dec_bin, &num_bin);
                    printf("Seu numero para transformacao e: %lf\n", dec_bin);
                    printf("E esse e seu numero transformado em binario: ");
                    converterDec_Bin(&num_bin);
                    printf("\n");
                    break;
                }

                	case 2: /* Na mensagem pede decimal para octal (embora o menu liste 7 como Octal para Decimal) */
			      printf("Digite o numero que voce quer transformar de decimal para octal: ");
					scanf("%lld", &decimal_para_octal); /* L? o n?mero decimal */
					system("cls"); /* Limpa a tela no Windows */
					
					if(decimal_para_octal > 0){
					    /* Nota: fazer cast para (unsigned int) pode truncar um long long int grande */
					    printf("Seu numero para transformacao e: %lld", (unsigned int)decimal_para_octal);
					    printf("\nE esse e seu numero transformado: %llo\n", decimal_para_octal); /* Imprime em octal com %llo */
					} else {
					    printf("Seu numero para transformacao e: %lld", decimal_para_octal);
					    printf("\nE esse e seu numero transformado: %llo\n", decimal_para_octal);
					}
	              break;

                case 3: /* Decimal para Hexadecimal */
                {
                    double dec_hex;
                    printf("\nTop :) !!!!\n");
                    printf("Digite o numero decimal para transformar em hexadecimal: ");
                    scanf("%lf", &dec_hex);
                    system("cls");
                    printf("Seu numero para transformacao e: %.0lf\n", dec_hex);
                    printf("E esse e seu numero transformado em hexadecimal: ");
                    converter_Dec_Hexa(dec_hex);
                    printf("\n");
                    break;
                }

                case 4: /* Binario para Decimal */
                  	printf("\nBeleza :) !!!!\n");
					printf("Digite o numero que voce quer transformar de binario pra decimal: ");
					scanf("%64s", bin); 
					system("cls");      
					
					resultado = binario_para_decimal(bin); 
					
					if (resultado == -999999.0) {
					    printf("\nEi, esse aqui pode nao >:c\n"); 
					} else {
					    printf("Seu numero para transformacao e: %s\n", bin);
					   
					    printf("E esse e seu numero transformado: %g\n", resultado);
					}

                    break;

                case 5: /* Bin?rio para Octal */
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o numero binario para transformar em octal: ");
                    scanf("%64s", bin);
                    system("cls");
                    d = binario_para_decimal(bin);
                    if (d == -1) {
                        printf("\nEi, esse aqui pode nao >:c\n");
                    } else {
                        printf("Seu numero para transformacao e: %s\n", bin);
                        printf("E esse e seu numero transformado: %llo\n", d);
                    }
                    break;

                case 6: /* Bin?rio para Hexadecimal */
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o numero binario para transformar em hexadecimal: ");
                    scanf("%64s", bin);
                    system("cls");
                    d = binario_para_decimal(bin);
                    if (d == -1) {
                        printf("\nEi, esse aqui pode não >:c\n");
                    } else {
                        printf("Seu numero para transformacao e: %s\n", bin);
                        printf("E esse e seu numero transformado em hexadecimal: ");
                        converter_Dec_Hexa((double)d);
                        printf("\n");
                    }
                    break;

                case 7: /* Octal para Decimal */
                    printf("\nShow :) !!!!\n");
                    printf("Digite o numero octal para transformar em decimal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu numero para transformacao e: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 8);
                    printf("E esse e seu numero transformado em decimal: %lld\n", d);
                    break;

                case 8: /* Octal para Bin?rio */
                {
                    s_numero num_oct_bin;
                    printf("\nShow :) !!!!\n");
                    printf("Digite o numero octal para transformar em binario: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu numero para transformacao e: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 8);
                    dividirDecimal((double)d, &num_oct_bin);
                    printf("E esse e seu numero transformado em binario: ");
                    converterDec_Bin(&num_oct_bin);
                    printf("\n");
                    break;
                }

                case 9: /* Octal para Hexadecimal */
                    printf("\nShow :) !!!!\n");
                    printf("Digite o numero octal para transformar em hexadecimal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu numero para transformacao e: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 8);
                    printf("E esse e seu numero transformado em hexadecimal: ");
                    converter_Dec_Hexa((double)d);
                    printf("\n");
                    break;

                case 10: /* Hexadecimal para Decimal */
                    printf("\nMassa :) !!!!\n");
                    printf("Digite o numero hexadecimal para transformar em decimal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu numero para transformacao e: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 16);
                    printf("E esse e seu numero transformado em decimal: %lld\n", d);
                    break;

                case 11: /* Hexadecimal para Bin?rio */
                {
                    s_numero num_hex_bin;
                    printf("\nMassa :) !!!!\n");
                    printf("Digite o numero hexadecimal para transformar em binario: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu numero para transformacao e: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 16);
                    dividirDecimal((double)d, &num_hex_bin);
                    printf("E esse e seu numero transformado em binario: ");
                    converterDec_Bin(&num_hex_bin);
                    printf("\n");
                    break;
                }

                case 12: /* Hexadecimal para Octal */
                    printf("\nMassa :) !!!!\n");
                    printf("Digite o numero hexadecimal para transformar em octal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu numero para transformacao e: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 16);
                    printf("E esse e seu numero transformado em octal: %llo\n", d);
                    break;

                case 0:
                    printf("Encerrando menu de conversoes...\n");
                    break;

                default:
                    printf("Opcao invalida! Escolha entre 0 e 12.\n");
                    break;
            }


            /* Pergunta se deseja fazer outra convers?o dentro do la?o 'do...while' */
            printf("\nGostaria de fazer mais alguma conversao?\n");
			scanf("%9s", resposta_nova);
			if(strcmp(resposta_nova, "sim") == 0 || strcmp(resposta_nova, "SIM") == 0){
				continue; /* Volta para o inicio do 'do...while' */
			} else {
				break; /* Sai do 'do...while' */
			}

        } while (opcao != 0); /* Se o usuario digitou 0 e respondeu "sim" acima, o 'do...while' ainda repetiria uma vez */

        strcpy(resposta, "não"); /* Garante que o 'while' externo encerre apos sair do 'do...while' */
  }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 /* Parte do codigo para casos que o fernando n?o ensinou mas pode pedir nas perguntas*/
 
 
 
 /*========GUSTAVO=========*/
 
 /*  Parte fracionaria do decimal para binario */
 
 /* Dentro da funcao 
 void converter_Dec_Bin() {
 	
	printf(",");
	laco para as multiplicacoes sucessivas por 2;
	for(i=0; i < 4; i++) {
	    	
	    fracao = pnum->parte_frac * 2;  	'fracao' recebe o ponteiro apontado para a variavel 'parte_frac' da struct vezes 2
	   	pnum->bin_frac[i] = (int)fracao;  	variavel 'bin_frac' da struct recebe apenas a parte inteira da variavel 'fracao'
	    
	    pnum->parte_frac *= 2;				parte fracionaria e multiplicada por 2 para voltar na fracao
		pnum->parte_frac = fracao - pnum->bin_frac[i];  parte fracionaria perde a parte inteira (EX.: 1 - 1 = 0; 0 - 0 = 0)
			
		printf("%d", pnum->bin_frac[i]);
	} 
}
		*/
 
 /* Parte fracionaria do decimal NEGATIVO para binario (sim, tem diferenca) */
 
 /* Dentro da funcao na parte else if (num_decimal < 0)
 void converter_Dec_Bin() {

 laco para as multiplicacoes sucessivas por 2;
	     condicao de i < 4 pois sera impresso apenas 4 bits de fracionario
	    for(i=0; i < 4; i++) {
	    	
	    	fracao = pnum->parte_frac * 2;  	'fracao' recebe o ponteiro apontado para a variavel 'parte_frac' da struct vezes 2
	    	pnum->bin_frac[i] = (int)fracao;  	variavel 'bin_frac' da struct recebe apenas a parte inteira da variavel 'fracao'
	    
	    	pnum->parte_frac *= 2;				parte fracionaria e multiplicada por 2 para voltar na fracao
			pnum->parte_frac = fracao - pnum->bin_frac[i];  parte fracionaria perde a parte inteira (EX.: 1 - 1 = 0; 0 - 0 = 0)			
			
		}
		
		1 for para a inversao do fracionario 
		checar onde tem 1 para inverter os n?meros ap?s esse 1 
		for(i=0; i < 4; i++) {
			if(pnum->bin_frac[i] == 1) {
				limite = i;
				break;
			}
		}
		
		primeiro a impressao do inteiro (tudo invertido)
	
		for(i = 0; i<=cont; i++) {	
	    	if(pnum->binario[i] == 0) {
	    		pnum->binario[i] = 1;
			} else if(pnum->binario[i] == 1) {
				pnum->binario[i] = 0;
			}
		}
		
		 for(i = cont; i>=0; i--) {
	    	printf("%d", pnum->binario[i]);
		} 
		impressao junto com a parte fracionaria
		printf(",");
		   
		   
		for(i = limite; i< 4; i++) {	
	    	if(pnum->bin_frac[i] == 0) {
	    		pnum->bin_frac[i] = 1;
			} else if(pnum->bin_frac[i] == 1) {
				pnum->bin_frac[i] = 0;
			}
		}
		
		 for(i = 3; i>=0; i--) {
	    	printf("%d", pnum->bin_frac[i]);
		}  
}
 
 */
 
 
 
 
 
 
 
 /*========IZA=========*/

/*Decimal para octal negativo e quebrado*\

/*Fun??o
void decimal_quebrado_para_octal(){
	int casas,i;
	double fracao;
	if(fracao <=0 || casas <= 0)return;
	
	for (i=0;i < casas;i++){
		fracao *=8;
		int digito = (int)fracao;
		printf("%d",digito);
		fracao -= digito;
		
		if(fracao == 0) break;
	}
}*\



/*switch case
double valorAbsoluto = fabs(decimal_para_octal);
long long parteInteira = (long long)valorAbsoluto;
double parteQuebrada = valorAbsoluto - parteInteira;

if (parteQuebrada > 0) {
    printf("Seu n?mero quebrado para transforma??o ?: %g", decimal_para_octal);
    printf("\nE esse ? seu n?mero transformado: ");
    
    if (decimal_para_octal < 0) printf("-");
    
    printf("%llo", parteInteira);
    decimal_quebrado_para_octal(parteQuebrada, 5);
    printf("\n");
} 
else {
    long long numeroNormal = (long long)decimal_para_octal;
    
    if (numeroNormal >= 0) {
        printf("Seu n?mero para transforma??o ?: %lld", numeroNormal);
        printf("\nE esse ? seu n?mero transformado: %llo\n", numeroNormal);
    } else {
        printf("Seu n?mero para transforma??o ?: %lld", numeroNormal);
        printf("\nE esse ? seu n?mero transformado: -%llo\n", parteInteira);
    }
}
*/
