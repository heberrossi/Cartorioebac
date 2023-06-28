#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sisterma
{
    	printf("você escolheu o registro!\n\n");
		//início da criação de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das strings
		
		FILE *file; //cria o arquivo
		file = 	fopen(arquivo, "w"); //cria o arquivo
		fprintf(file, "cpf:");
		fprintf(file,cpf); //salva no arquivo(file) o valor da variável(cpf)
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
		
		printf("\nDeseja voltar ao menu ou registrar mais usuários?\n\n");
		printf("\t1 - Registrar mais nomes\n");
		printf("\t2 - Voltar ao menu\n");
		printf("\nOpção: ");
		
		scanf("%d", &opcao);
		
		switch(opcao)
   		{
    		case 1:
    		system("cls");
    		registro();
			break;
			   
			case 2:
			system("cls");
			printf("\nVocê escolheu voltar ao menu\n\n");
			break;
			
		}
		system("pause");
	
}

int consulta()
{
   		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		   
		printf("você escolheu consultar os nomes!\n\n");
   		
   		char cpf[40];
   		char conteudo[200];
   		
   		printf("Digite o CPF a ser consultado: ");
   		scanf("%s", cpf);
   		
   		FILE *file;
   		file = fopen(cpf, "r"); //"r" = read => ler o arquivo
   		
   		printf("\nEssas são as informações do usuário: \n\n");
   		
   		if(file == NULL)
   		{
   			printf("Não foi possível abrir o arquivo, não localizado\n");
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
	
	printf("Você escolheu deletar usuário!\n\n");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

		if(file == NULL)
			{
			printf("\nO usuário não se encontra no sistema!\n\n");
			fclose(file);
			}
	
		if(file != NULL)
			{
			printf("\nO usuário foi deletado com sucesso!\n");
			fclose(file);
			remove(cpf);
			}

	system("pause");
		
}


int main()
{ 
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo as variáveis
	int laco=1;
	char logindigitado[10]="b";
	char senhadigitada[10]="a"; //"a" = apenas um valor, vai ser mudado depois
	int comparacao;
	int comparacao2; //comparar as variáveis
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de Administrador\n\n");
	printf("Digite seu login: ");
	scanf("%s",logindigitado);
	
	printf("\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(logindigitado, "admin");
	comparacao2 = strcmp(senhadigitada, "admin2"); //strcmp = comparação de strings; definindo senha "admin"
	
	if(comparacao == 0 && comparacao2 == 0) //"== 0" = se a senha digitada foi igual a comparacao
	{
	
		for(laco=1;laco=1;) //definindo o laço
		{
	
			system("cls");
				
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
			printf("### Cartório da EBAC ###\n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar os nomes\n");
	   		printf("\t3 - Deletar os nomes\n\n"); 
	   		printf("\t4 - Sair do sistema\n\n"); 
	   		printf("Opção: "); //final do menu
	   
	    	scanf("%d", &opcao); //armazenando a escolha do usuário
	    
	    	system("cls"); //responsável por limpar a tela
	    
	    	switch(opcao)
	   		{
	    		case 1:
	    		registro(); //chamada da função "registro"
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
	    		printf("não existe essa opção\n\n");
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

