#include <stdio.h>
#include <stdlib.h>

/*TRABALHO 1 - SEGURANÇA DA INFORMAÇÃO (TCC - TCC00341)*/
//FERNANDO RODRIGUES E ANDRE LUIZ RODRIGUES (NAO SOMOS PRIMOS)//

int compara(const void *p1, const void *p2){ 
/*metodo utilizado para comparacao de elementos no qsort e adaptado para o sort de ocorrencias e ordem alfabetica descrito no enunciado*/
    const int *a = p1;
    const int *b = p2;
	if(a[0] == b[0])
		return ((a[1]) - (b[1]));
	return ((b[0]) - (a[0]));
}

int main(){

	int tam_frase_inicial, tam_frase_final, i, j, indice; //declarando variaveis utilizadas no programa

	scanf("%d", &tam_frase_inicial); //recebendo o tamanho da primeira frase dada
	getchar();
	char frase_inicial[tam_frase_inicial]; //declarando array de char para guardar a primeira frase
	
	scanf("%[^\n]", frase_inicial); //recebendo a primeira frase dada e guardando no seu respectivo array de caracteres
	
	int dicionario_inicial[26][2]; //inicializa um dicionario com 26 linhas e duas colunas
	
	//cada linha representa um array que contem o caracter referente e o numero de ocorrencias
	//dicionario_inicial[posicao_do_char_no_alfabeto][0 contem o numero de ocorrencias, 1 o codigo do caracter referente a essa linha]
	
	/*ex.: 
	dicionario_inicial[0][1] -> 'a'
	dicionario_inicial[0][0] -> numero de ocorrencias na frase dada, inicializado com 0
	*/
	
	for(i = 0; i < 26; ++i){ //preenchendo o dicionario com numero de ocorrencias igual a 0 e o caracter referente a linha dada
		dicionario_inicial[i][0] = 0;
		dicionario_inicial[i][1] = i + 97;
	}

	for(i = 0; i < tam_frase_inicial; i++){ //de acordo com a frase dada incrementa o numero de ocorrencias de cada caracter no dicionario
		if(frase_inicial[i] >= 97 && frase_inicial[i] <= 122){
			dicionario_inicial[frase_inicial[i] - 97][0]++; //vai, vai, incrementando
		}
	}
	
	qsort(dicionario_inicial, 26, sizeof(int) * 2, compara); //ordenando o dicionario de acordo com numero de ocorrencias e posicao do caracter no alfabeto
	
	scanf("%d", &tam_frase_final); //recebendo o tamanho da segunda frase dada
	getchar();	
	char frase_final[tam_frase_final]; //declarando array de char para guardar a segunda frase
	
	scanf("%[^\n]", frase_final); //recebendo a segunda frase dada e guardando no seu respectivo array de caracteres

	int dicionario_final[26][2]; //declarando/alocando espaco para o dicionario referente a segunda frase, funcionamento identico ao primeiro criado mais acima
	
	for(i = 0; i < 26; ++i){ //preenchendo o dicionario com numero de ocorrencias igual a 0 e o caracter referente a linha dada
		dicionario_final[i][0] = 0;
		dicionario_final[i][1] = i + 97;
	}

	for(i = 0; i < tam_frase_final; i++){ //de acordo com a frase dada incrementa o numero de ocorrencias de cada caracter no dicionario
		if(frase_final[i] >= 97 && frase_final[i] <= 122){
			dicionario_final[frase_final[i] - 97][0]++; //vai, vai, incrementando
		}
	}
	
	qsort(dicionario_final, 26, sizeof(int) * 2, compara); //ordenando o dicionario de acordo com numero de ocorrencias e posicao do caracter no alfabeto
	
	for(i = 0; i < tam_frase_final; i++){ //passando por cada caracter da frase a ser desencriptada
		for(j = 0; j < 26; ++j){ //passa por um dicionario inteiro
			if(dicionario_final[j][1] == frase_final[i]) indice = j; //encontrando a posicao em que o caracter atual se encontra no dicionario dessa mesma frase
		}
		if(frase_final[i] >= 97 && frase_final[i] <= 122) //caso seja uma letra comum e minuscula
			frase_final[i] = dicionario_inicial[indice][1]; //trocamos o caracter atual pelo encontrado no dicionario da primeira frase de acordo com o indice guardado anteriormente
	}

	printf("%s\n", frase_final); //printando a segunda frase ja modificada de acordo com as regras citadas acima

	return 0;
}

//EH O BICHO