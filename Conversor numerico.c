#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==========================================================================================
//==========================================================================================

typedef struct {
    int parte_inteira;
    double parte_frac;
    
    int binario[50];
    int bin_frac[50];
} s_numero; //struct para armazenar o decimal e binário

// =========================================================================================

//isso permite que o usr entre com uma string de forma facilitada
char inputS(char txt[100], char *var){
	printf("%s", txt);
	scanf(" %99[^\n]", var);
	

//exemplo de uso: inputS("digite seu nome: ", a), console: digite seu nome: _usr digita aq_
}

//==========================================================================================
//==========================================================================================


//igual ao inputS mas agora para inteiros ou floats e deve-se passar o endereço da var ex.: &b ou se b[1] então apenas b.
//a conversão para inteiro acontece fora desse bloco
float inputF(char txt[100], float *num){
	printf("%s", txt);
	scanf(" %f", num);	
}

void dividirDecimal(double decimal, s_numero *pnum) {
    pnum->parte_inteira = (int)decimal;
    pnum->parte_frac = decimal - (int)decimal;
    
}  //função para dividir a parte inteira e a parte fracionaria do decimal.

// ============================================================================================================================
// ============================================================================================================================

void trocar_base_hexa(int valor_hexa[], int ilaco) {
	// essa função troca os valores entre 10 e 15 dos decimais para os caracteres entre A e F dos hexadecimais
	// além da troca ela imprime todo o decimal convertido em hexadecimal
	// valor_hexa é o vetor que está guardado os decimais inteiros a serem convertidos
	// ilaco é o tamanho dele 
	
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

// ============================================================================================================================
// ============================================================================================================================

void converterDec_Bin(s_numero *pnum) {
    int i; 
	double resto;
    int cont = 0; 			//contador para inverter o binário
	double fracao;
    int limite; //para o complemento de 2;
    
	if(pnum->parte_inteira >=0) {
	
	    //laço para as divisões sucessivas por dois.
	    for(i=0; pnum->parte_inteira != 0; i++) {
	    	
	        resto = pnum->parte_inteira % 2; 				 // resto recebe o ponteiro apontado para a variavel 'parte_inteira' na struct
	        pnum->parte_inteira = pnum->parte_inteira / 2;  //o valor da 'parte_inteira' é dividid
	        pnum->binario[i] = resto;						//os valores do resto da divisão é armazenado na variável 'binario' na struct
	        cont++;		//incremento do contador
	    }
	    
	    pnum->binario[i] = 0;  //garante que o binario fique com 0 no começo, indicando ele ser positivo
	    
	    //laço for para imprimir na ordem correta;
	    for(i = cont ; i>=0; i--) {
	    	printf("%d", pnum->binario[i]);
		}
		
	    printf(",");
	    
	    
	    // ============================================================================================================================
	    // ============================================================================================================================
	    
	   
	    //laço para as multiplicações sucessivas por 2;
	    for(i=0; i < 4; i++) {
	    	
	    	fracao = pnum->parte_frac * 2;  	//'fração' recebe o ponteiro apontado para a variavel 'parte_frac' da struct vezes 2
	    	pnum->bin_frac[i] = (int)fracao;  	//variável 'bin_frac' da struct recebe apenas a parte inteira da variavel 'fração'
	    
	    	pnum->parte_frac *= 2;				//parte fracionária é multiplicada por 2 para voltar na fração
			pnum->parte_frac = fracao - pnum->bin_frac[i];  //parte fracionária perde a parte inteira (EX.: 1 - 1 = 0; 0 - 0 = 0)
			
			printf("%d", pnum->bin_frac[i]);
		}
	} else if(pnum->parte_inteira < 0) {
		
		
	//DAQUI PRA FRENTE É A PARTE CASO O USUARIO ESCOLHA UM NUMERO NEGATIVO, ASSIM O BINARIO É 
	//TRANSFORMADO EM COMPLEMENTO DE 2
		
		pnum->parte_inteira -= (pnum->parte_inteira*2); //isso garante que o negativo se torne positivo
		pnum->parte_frac -= (pnum->parte_frac*2);
		//por estar na condição if ( < 0) é adicionado o binario no final;
		
		//laço para as divisões sucessivas por dois.
	    for(i=0; pnum->parte_inteira != 0; i++) {
	    	
	        resto = pnum->parte_inteira % 2; 				 // resto recebe o ponteiro apontado para a variavel 'parte_inteira' na struct
	        pnum->parte_inteira = pnum->parte_inteira / 2;  //o valor da 'parte_inteira' é dividid
	        pnum->binario[i] = resto;						//os valores do resto da divisão é armazenado na variável 'binario' na struct
	        cont++;		//incremento do contador
	    }
	    
	    pnum->binario[i] = 0; //o ultimo valor recebe 0 para representar o bit de sinal 'positivo'
	    
	    
	    
	    
	    // ============================================================================================================================
	    // ============================================================================================================================
	    
		//reset do contador para utilizá-lo abaixo.
		
		
	    //laço para as multiplicações sucessivas por 2;
	    // condição de i < 4 pois será impresso apenas 4 bits de fracionário
	    for(i=0; i < 4; i++) {
	    	
	    	fracao = pnum->parte_frac * 2;  	//'fração' recebe o ponteiro apontado para a variavel 'parte_frac' da struct vezes 2
	    	pnum->bin_frac[i] = (int)fracao;  	//variável 'bin_frac' da struct recebe apenas a parte inteira da variavel 'fração'
	    
	    	pnum->parte_frac *= 2;				//parte fracionária é multiplicada por 2 para voltar na fração
			pnum->parte_frac = fracao - pnum->bin_frac[i];  //parte fracionária perde a parte inteira (EX.: 1 - 1 = 0; 0 - 0 = 0)	
			
		} 
		
		
		// 1° for para a inversão do fracionário
		// checar onde tem 1 para inverter os números após esse 1
		for(i=0; i < 4; i++) {
			if(pnum->bin_frac[i] == 1) {
				limite = i;
				break;
			}
		}
		
		//primeiro a impressão do inteiro (tudo invertido)
		
	
		
		
		for(i = 0; i<=cont; i++) {	
	    	if(pnum->binario[i] == 0) {
	    		pnum->binario[i] = 1;
			} else if(pnum->binario[i] == 1) {
				pnum->binario[i] = 0;
			}
		}
		
		 for(i = cont; i>=0; i--) {
	    	printf("%d", pnum->binario[i]);
		} //impressão junto com a parte fracionaria
		
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
	} //do else if
}  //da função

// ============================================================================================================================
// ============================================================================================================================

void converter_Dec_Hexa(double num_decimal) {
	// esta função serve para fazer as divisões inteiras sucessivas por 16 para obter os restos 
	// num_decimal é o valor digitado pelo usuário (está em double pois preciso fazer a parte fracionaria)
	int i, cont;
	int resto;     
	int hexad[32];
	int divisor = (int)num_decimal;
	
	
	for(i=0; divisor != 0; i++) {
		
		resto = divisor % 16;
		divisor /= 16;
		hexad[i] = resto;
		cont++;
	}
	cont -= 1; //isso serve pois na impressao estava saindo um vetor não atribuido, gerando lixo de memoria
	trocar_base_hexa(hexad, cont);  //função anterior para a impressão.
 
}


//==========================================================================================
//==========================================================================================

//conversor, ele utiliza o strtol para transformar as bases, ele retorna um long long int 
//entradas aceitaveis: hex: num e -num, octa: num e -num, bin: 1° digito será o bit de sinal(podendo ser
//substituido por + ou -) se for 0 o numero é positivo se for 1 será negativo, se for 1 ele será tratado 
//segundo o complemento de 2, se for 0 ou + será tratado normalmente, se for - será tratado normalmente.
 
long long int Transforma_base_HOB_decimal(char num[32], int base){
	//strtol retorna long int, então para garantir o retorno correto usa-se uma var long para gerar long long int
	long num_transformado;
	
	//aqui testamos se o numero é um binario
	if (base == 2){
		
		// se o numero for digitado no formato de complemento de dois, nós o converteremos para um formato aceitavel
		if (num[0] == '1'){
			num[0] = '-';
			int i, lim, tamanho_lista= strlen(num);
			
			//apartir daq fazemos a operação reversa a do complemento de 2
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
			
			//numero long long int
			return num_transformado;
		}
		else{
			
			//caso o numero seja binario mas não está em complemento de 2 ele é tradado de forma padrão
			num_transformado = strtol(num, NULL, base);
			return num_transformado;
		}
	}
			
	else{
		
		//caso não seja binario ele é tratado de forma padrão
		num_transformado = strtol(num, NULL, base);
		return num_transformado;
	}
}

//==========================================================================================
//==========================================================================================


//aplicção de exemplo:
main(){
	char a[32];
	float b;
	int c;
	long long int d;
	while (1){
		inputS("digite um numero: ", a);
		printf("numero digitado: %s \n", a);
	
		inputF("digite uma base numerica: ", &b);
		printf("base digitada: %.0f\n", b);
		c = b;
		d = Transforma_base_HOB_decimal(a, c);
	
		printf("numero original: %s, numero transformado: %lld \n\n", a, d);
	}
	
	
	
	
	
}
