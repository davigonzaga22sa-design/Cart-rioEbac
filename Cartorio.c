#include <stdio.h> //iblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variavel/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variavel/string

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);//Responsavel por copiar os valores das string

    printf("Digite o nome a ser cadastrado: ");//coletando informações do usuário
    scanf("%s", nome);//%s responsavel refere-se a string

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    FILE *file;
    file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever

    if(file == NULL)
    {
        printf("Erro ao criar arquivo!\n");
        return 1;
    }

    fprintf(file,"%s,%s,%s,%s", cpf, nome, sobrenome, cargo); //Responsavel por incluir os resgistros no arquivo

    fclose(file);//Fecha o arquivo

    printf("\nRegistro salvo com sucesso!\n");
    system("Pause");
			
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");//responsavel por abrir o arquivo e o "r" significa consultar

    if(file == NULL)
    {
        printf("Não foi possivel encontrar o registro!\n");
        system("pause");
        return 1;
    }

    fgets(conteudo,200,file);

    char *token;

    token = strtok(conteudo, ",");
    printf("\nCPF: %s\n", token);

    token = strtok(NULL, ",");
    printf("Nome: %s\n", token);

    token = strtok(NULL, ",");
    printf("Sobrenome: %s\n", token);

    token = strtok(NULL, ",");
    printf("Cargo: %s\n", token);

    printf("\n");

    fclose(file);

    system("pause");

	
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    FILE *file;

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    file = fopen(cpf, "r");

    if (file == NULL)//Responsavel por validar se o registro possui dados arquivados no sistema
    {
        printf("\nRegistro nao encontrado! O usuario nao esta cadastrado no sistema.\n");
        system("pause");
        return 0;
    }
    else//retorno se o regitro foi deletado e/ou prblema para deletar o registro
    {
        fclose(file);

        if (remove(cpf) == 0)
        {
            printf("\nRegistro deletado com sucesso!\n");
        }
        else
        {
            printf("\nErro ao deletar o registro!\n");
        }

        system("pause");
        return 1;
    }
}

int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("## Catório da EBAC ##\n\n");
	printf("login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");//comando limpa tela
		for(laco=1;laco=1;) //Inicio Loop 
		{
			//system("cls");//comando limpa tela
			
			setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem	
			
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");		
			printf("Opção: "); //Fim do menu
				
			scanf("%d", &opcao); // armazenando a escolha do usuário
		
			system("cls");//comando limpa tela
		
			switch(opcao) //inicio da seleção
			{
				case 1:
				registro();
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
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
				
			} //fim da seleção
		
		}//fim loop
	}
	
	else
		printf("Senha Incorreta!");
}	
