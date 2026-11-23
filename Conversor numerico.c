#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


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
	cont -= 1 ;//isso serve pois na impressao estava saindo um vetor não atribuido, gerando lixo de memoria
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

// Função que converte uma string em binário (sem sinal) para decimal
long long binario_para_decimal(char binario[]){
	long long decimal = 0;   // Acumula o valor decimal final
	long long potencia = 1;  // Representa 2^0, 2^1, 2^2... conforme anda da direita para a esquerda
	int tamanho = strlen(binario); // Quantidade de caracteres da string binária
	int i;
	
	// Percorre a string do último caractere (menos significativo) até o primeiro (mais significativo)
	for(i = tamanho - 1; i >= 0; i--){
		if(binario[i] == '1'){
			decimal = decimal + potencia; // Soma a potência de 2 correspondente à posição do '1'
		} else if (binario[i] != '0'){
			// Se não for '1' nem '0', há caractere inválido (nota: "return =-1;" tem erro de sintaxe; o correto é "return -1;")
			return -1;
		}
		potencia = potencia * 2; // Atualiza a potência de 2 para o próximo dígito à esquerda
	}
	return decimal; // Retorna o valor convertido em decimal
}

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
}

//aplicção de exemplo:
int main(){
	char a[32];
	float b;
	int c;
	long long int d;
	 
	 setlocale(LC_ALL, "Portuguese"); // Configura acentuação/idioma para português
	int opcao, resultado;            // 'opcao' guarda a escolha do menu; 'resultado' recebe o retorno da conversão
	long long int decimal_para_octal; // Armazena o número decimal informado na opção 7
	char resposta[10] = "sim", resposta_nova[10] = "sim"; // Controlam se o usuário quer continuar
	char bin[65];                    // Buffer para até 64 bits + caractere nulo '\0'
	
	printf("Gostaria de fazer alguma conversão meu nobre: ");
	scanf("%9s", resposta); // Lê até 9 caracteres evitando estourar o array 'resposta'

		
	// Enquanto a resposta inicial for "sim" ou "SIM"
	while(strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0){
		
		do{
	 		printf("\nPerfeito :) !!!!\n");
	 		// Exibe as opções do menu de conversões
	 		printf(" 1. Decimal para Binário\n");
            printf(" 2. Decimal para Octal\n");
            printf(" 3. Decimal para Hexadecimal\n");
            printf(" 4. Binário para Decimal\n");
            printf(" 5. Binário para Octal\n");
            printf(" 6. Binário para Hexadecimal\n");
            printf(" 7. Octal para Decimal\n");
            printf(" 8. Octal para Binário\n");
            printf(" 9. Octal para Hexadecimal\n");
            printf("10. Hexadecimal para Decimal\n");
            printf("11. Hexadecimal para Binário\n");
            printf("12. Hexadecimal para Octal\n");
            printf("0. Sair do menu de conversão\n");
            printf("\nEscolhe aí qual conversão tu quer meu consagrado :) !!!!\n");
            scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
            system("cls");
            
            
                switch(opcao){
                case 1: // Decimal para Binário
                {
                    double dec_bin;
                    s_numero num_bin;
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o número decimal para transformar em binário: ");
                    scanf("%lf", &dec_bin);
                    system("cls");
                    dividirDecimal(dec_bin, &num_bin);
                    printf("Seu número para transformação é: %lf\n", dec_bin);
                    printf("E esse é seu número transformado em binário: ");
                    converterDec_Bin(&num_bin);
                    printf("\n");
                    break;
                }

                	case 2: // Na mensagem pede decimal para octal (embora o menu liste 7 como Octal para Decimal)
			        printf("\nShow :) !!!!\n");
				    printf("Digite o número que você quer transformar de decimal para octal: ");
				    scanf("%lf", &decimal_para_octal); // Lê tanto número inteiro quanto quebrado
				    system("cls"); // Limpa a tela no Windows
			
				    // Separa a parte inteira e a parte quebrada usando valor absoluto
				    double valorAbsoluto = fabs(decimal_para_octal);
				    long long parteInteira = (long long)valorAbsoluto;
				    double parteQuebrada = valorAbsoluto - parteInteira;
	
	    // IF para verificar se o número é QUEBRADO
				    if (parteQuebrada > 0) {
				        printf("Seu número quebrado para transformação é: %g", decimal_para_octal);
				        printf("\nE esse é seu número transformado: ");
				        
				        if (decimal_para_octal < 0) printf("-"); // Mantém o sinal se for negativo
				        
				        printf("%llo", parteInteira);           // Imprime a parte normal em octal
				        decimal_quebrado_para_octal(parteQuebrada, 5);  // Chama o void para a parte quebrada
				        printf("\n");
				    } 
				    // ELSE para quando o número for NORMAL (inteiro)
				    else {
				        long long numeroNormal = (long long)decimal_para_octal;
				        
				        if (numeroNormal >= 0) {
				            printf("Seu número para transformação é: %lld", numeroNormal);
				            printf("\nE esse é seu número transformado: %llo\n", numeroNormal);
				        } else {
				            printf("Seu número para transformação é: %lld", numeroNormal);
				            printf("\nE esse é seu número transformado: -%llo\n", parteInteira);
				        }
				    }
	    break;

                case 3: // Decimal para Hexadecimal
                {
                    double dec_hex;
                    printf("\nTop :) !!!!\n");
                    printf("Digite o número decimal para transformar em hexadecimal: ");
                    scanf("%lf", &dec_hex);
                    system("cls");
                    printf("Seu número para transformação é: %.0lf\n", dec_hex);
                    printf("E esse é seu número transformado em hexadecimal: ");
                    converter_Dec_Hexa(dec_hex);
                    printf("\n");
                    break;
                }

                case 4: // Binário para Decimal
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o número que você quer transformar de binário para decimal: ");
                    scanf("%64s", bin);
                    system("cls");
                    resultado = binario_para_decimal(bin);
                    if (resultado == -1) {
                        printf("\nEi, esse aqui pode não >:c\n");
                    } else {
                        printf("Seu número para transformação é: %s\n", bin);
                        printf("E esse é seu número transformado: %d\n", resultado);
                    }
                    break;

                case 5: // Binário para Octal
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o número binário para transformar em octal: ");
                    scanf("%64s", bin);
                    system("cls");
                    d = binario_para_decimal(bin);
                    if (d == -1) {
                        printf("\nEi, esse aqui pode não >:c\n");
                    } else {
                        printf("Seu número para transformação é: %s\n", bin);
                        printf("E esse é seu número transformado em octal: %llo\n", d);
                    }
                    break;

                case 6: // Binário para Hexadecimal
                    printf("\nBeleza :) !!!!\n");
                    printf("Digite o número binário para transformar em hexadecimal: ");
                    scanf("%64s", bin);
                    system("cls");
                    d = binario_para_decimal(bin);
                    if (d == -1) {
                        printf("\nEi, esse aqui pode não >:c\n");
                    } else {
                        printf("Seu número para transformação é: %s\n", bin);
                        printf("E esse é seu número transformado em hexadecimal: ");
                        converter_Dec_Hexa((double)d);
                        printf("\n");
                    }
                    break;

                case 7: // Octal para Decimal
                    printf("\nShow :) !!!!\n");
                    printf("Digite o número octal para transformar em decimal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu número para transformação é: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 8);
                    printf("E esse é seu número transformado em decimal: %lld\n", d);
                    break;

                case 8: // Octal para Binário
                {
                    s_numero num_oct_bin;
                    printf("\nShow :) !!!!\n");
                    printf("Digite o número octal para transformar em binário: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu número para transformação é: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 8);
                    dividirDecimal((double)d, &num_oct_bin);
                    printf("E esse é seu número transformado em binário: ");
                    converterDec_Bin(&num_oct_bin);
                    printf("\n");
                    break;
                }

                case 9: // Octal para Hexadecimal
                    printf("\nShow :) !!!!\n");
                    printf("Digite o número octal para transformar em hexadecimal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu número para transformação é: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 8);
                    printf("E esse é seu número transformado em hexadecimal: ");
                    converter_Dec_Hexa((double)d);
                    printf("\n");
                    break;

                case 10: // Hexadecimal para Decimal
                    printf("\nMassa :) !!!!\n");
                    printf("Digite o número hexadecimal para transformar em decimal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu número para transformação é: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 16);
                    printf("E esse é seu número transformado em decimal: %lld\n", d);
                    break;

                case 11: // Hexadecimal para Binário
                {
                    s_numero num_hex_bin;
                    printf("\nMassa :) !!!!\n");
                    printf("Digite o número hexadecimal para transformar em binário: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu número para transformação é: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 16);
                    dividirDecimal((double)d, &num_hex_bin);
                    printf("E esse é seu número transformado em binário: ");
                    converterDec_Bin(&num_hex_bin);
                    printf("\n");
                    break;
                }

                case 12: // Hexadecimal para Octal
                    printf("\nMassa :) !!!!\n");
                    printf("Digite o número hexadecimal para transformar em octal: ");
                    scanf("%31s", a);
                    system("cls");
                    printf("Seu número para transformação é: %s\n", a);
                    d = Transforma_base_HOB_decimal(a, 16);
                    printf("E esse é seu número transformado em octal: %llo\n", d);
                    break;

                case 0:
                    printf("Encerrando menu de conversões...\n");
                    break;

                default:
                    printf("Opção inválida! Escolha entre 0 e 12.\n");
                    break;
            }


            // Pergunta se deseja fazer outra conversão dentro do laço 'do...while'
            printf("\nGostaria de fazer mais alguma conversão?\n");
			scanf("%9s", resposta_nova);
			if(strcmp(resposta_nova, "sim") == 0 || strcmp(resposta_nova, "SIM") == 0){
				continue; // Volta para o início do 'do...while'
			} else {
				break; // Sai do 'do...while'
			}

        } while (opcao != 0); // Se o usuário digitou 0 e respondeu "sim" acima, o 'do...while' ainda repetiria uma vez

        strcpy(resposta, "não"); // Garante que o 'while' externo encerre após sair do 'do...while'
  }
 } 




	
	
	


	
	

