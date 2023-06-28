#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sisterma
{
    	printf("voc� escolheu o registro!\n\n");
		//in�cio da cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
		
		FILE *file; //cria o arquivo
		file = 	fopen(arquivo, "w"); //cria o arquivo
		fprintf(file, "cpf:");
		fprintf(file,cpf); //salva no arquivo(file) o valor da vari�vel(cpf)
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //"a" = atualizar o arquivo
		fprintf(file,"\n");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, "nome:");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\n");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, "sobrenome:");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\n");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, "cargo:");
		fprintf (file, cargo);
		fclose(file);
		
		system("cls");
		
		int opcao=0;
		
		printf("\nDeseja voltar ao menu ou registrar mais usu�rios?\n\n");
		printf("\t1 - Registrar mais nomes\n");
		printf("\t2 - Voltar ao menu\n");
		printf("\nOp��o: ");
		
		scanf("%d", &opcao);
		
		switch(opcao)
   		{
    		case 1:
    		system("cls");
    		registro();
			break;
			   
			case 2:
			system("cls");
			printf("\nVoc� escolheu voltar ao menu\n\n");
			break;
			
		}
		system("pause");
	
}

int consulta()
{
   		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		   
		printf("voc� escolheu consultar os nomes!\n\n");
   		
   		char cpf[40];
   		char conteudo[200];
   		
   		printf("Digite o CPF a ser consultado: ");
   		scanf("%s", cpf);
   		
   		FILE *file;
   		file = fopen(cpf, "r"); //"r" = read => ler o arquivo
   		
   		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
   		
   		if(file == NULL)
   		{
   			printf("N�o foi poss�vel abrir o arquivo, n�o localizado\n");
   			fclose(file);
	    }
   		
   		while(fgets(conteudo, 200, file) != NULL)
   		{
   			printf("%s", conteudo);
   	   		printf("\n\n");
		}
		
   		fclose(file);
   		system("pause");	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("Voc� escolheu deletar usu�rio!\n\n");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

		if(file == NULL)
			{
			printf("\nO usu�rio n�o se encontra no sistema!\n\n");
			fclose(file);
			}
	
		if(file != NULL)
			{
			printf("\nO usu�rio foi deletado com sucesso!\n");
			fclose(file);
			remove(cpf);
			}

	system("pause");
		
}


int main()
{ 
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo as vari�veis
	int laco=1;
	char logindigitado[10]="b";
	char senhadigitada[10]="a"; //"a" = apenas um valor, vai ser mudado depois
	int comparacao;
	int comparacao2; //comparar as vari�veis
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de Administrador\n\n");
	printf("Digite seu login: ");
	scanf("%s",logindigitado);
	
	printf("\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(logindigitado, "admin");
	comparacao2 = strcmp(senhadigitada, "admin2"); //strcmp = compara��o de strings; definindo senha "admin"
	
	if(comparacao == 0 && comparacao2 == 0) //"== 0" = se a senha digitada foi igual a comparacao
	{
	
		for(laco=1;laco=1;) //definindo o la�o
		{
	
			system("cls");
				
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar os nomes\n");
	   		printf("\t3 - Deletar os nomes\n\n"); 
	   		printf("\t4 - Sair do sistema\n\n"); 
	   		printf("Op��o: "); //final do menu
	   
	    	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	    
	    	system("cls"); //respons�vel por limpar a tela
	    
	    	switch(opcao)
	   		{
	    		case 1:
	    		registro(); //chamada da fun��o "registro"
				break;
				   
				case 2:
	    		consulta();
				break;
				   	 
				case 3:
	    		deletar();
				break;	 
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
	    		printf("n�o existe essa op��o\n\n");
	   			system("pause");
				break;     
			}
		}
	}
	else
		{
			system("cls");
			printf("Login e/ou Senha incorreta(s)\n\n");
			system("pause");
			system("cls");
			main();
		}
	
}

