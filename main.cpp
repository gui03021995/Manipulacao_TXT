
#include <iostream>
#include <conio.c>


using namespace std;

#include "FuncoesExternas.cpp"
#define TR 1000
#define MR 256

// DECLARAR STRUCT

typedef struct Arquivo
{
	string ano;              //campos da Struct
    string id;
    string nome_escola;
    string tipo;
    string rede;
    string zona;
    string estado;
    string n_escola;
    string cidade;
    string endereco;
    string situacao;
    
};

Arquivo Registros[TR];

void lerDados();
void consultarDados();
//void ordernarEscola();

int main()
{
    setlocale(LC_ALL,"");
    int opcao, vetor[TR];

    do
    {
        system("cls");
        cout << "1 - LER DADOS DO ARQUIVO\n";
        cout << "2 - CONSULTAR DADOS\n";
        cout << "3 - Ordernar e salvar em ordem alfabetica por nome de escola\n";
        cout << "0 - SAIR DO PROGRAMA\n\n";
        cout << "OPÇÃO: ";
        cin >> opcao;
        switch(opcao)
        {
            case 1:  lerDados();break;
            case 2:  consultarDados();break;
            //case 3:  ordernarEscola();break;
            case 0:  cout << "FINALIZANDO...\n";break;
            default: cout << "OPÇÃO INVÁLIDA. TENTE NOVAMENTE\n";
                     system("pause>null");
        }
    }while(opcao);

    system("pause");
    return 0;
}

void lerDados()
{
    titulo("LENDO OS DADOS EXISTENTES NO ARQUIVO CSV");

    int i, j, campo;
    string acumular;
    char linha[MR];  //maior registro em uma linha no arquivo ()

    j  = 0;        //será o índice do vetor
    campo = 0;        //será o contador dos campos da struct

    // abrir o arquivo com os registros em texto (CSV)
    FILE *arquivo;
    arquivo = fopen("CADASTRO_MATRICULAS_REGIAO_SUDESTE_MG_2012.csv","r");  // r = read , leitura
    acumular="";
    
    while(!feof(arquivo))
    {
    	fgets(linha,MR,arquivo);
    	cout << linha << "\n";
    	
    	for(i=0;i<strlen(linha);i++)
    	{
    		if(linha[i]!=';')  // acumula enquanto não é ponto e vírgula
    		{
    			acumular = acumular + linha[i];
    		//	cout << acumular << "\n";
			}else{
			
				switch(campo)
				{
					case 0: Registros[j].ano = acumular;
					break;
					case 1: Registros[j].id = acumular;
					break;
					case 2: Registros[j].nome_escola = acumular;
					break;
					case 3: Registros[j].tipo = acumular;
					break;
					case 4: Registros[j].rede = acumular;
					break;
					case 5: Registros[j].zona = acumular;
					break;
					case 6: Registros[j].estado = acumular;
					break;
					case 7: Registros[j].n_escola = acumular;
					break;
					case 8: Registros[j].cidade = acumular;
					break;
                    case 9: Registros[j].endereco = acumular;
					break;
					case 10: Registros[j].situacao = acumular;
					break;
				}
				acumular ="";
				campo++;
			} 
		}
		Registros[j].id = acumular;
		j++;
		campo = 0;
		acumular = "";
    	
	}
	system("pause");
	fclose(arquivo);
}

void consultarDados()
{
    titulo("CONSULTAR DADOS");
    int consulta;
    
    cout << "CHAVE PARA CONSULTA: ";
    cin >> consulta;
    
    cout << "========================================\n";
    cout << "Numero de registro....: "  << consulta << "\n";
    cout << "Ano...............: "  << Registros[consulta].ano << "\n";
    cout << "id..........: "  << Registros[consulta].id << "\n";
    cout << "Tipo.............: "  << Registros[consulta].tipo << "\n";
    cout << "Rede de ensino.................: "  << Registros[consulta].rede << "\n";
    cout << "Zona de residência....: "  << Registros[consulta].zona << "\n";
    cout << "nome da escola..............: "  << Registros[consulta].n_escola << "\n";
    cout << "cidade..............: "  << Registros[consulta].cidade << "\n";
    cout << "endereco..............: "  << Registros[consulta].endereco << "\n";
    cout << "situacao..............: "  << Registros[consulta].situacao << "\n";
    cout << "========================================\n";
    system("pause");   
    
}
/*
void ordenarEscola()
{
    int i, j, acc;
    FILE *lerascii;
    lerascii = fopen("CADASTRO_MATRICULAS_REGIAO_SUDESTE_MG_2012.csv","r");
    
        for(i=0; i<42; i++)
        {
                fscanf(lerascii, "%d\n", &lerascii[i]);
        }
        lerascii = fopen("ordem_crescente.txt","w");
        
          for(i=0;i<42;i++)
          {
             for(j=0; j<42; j++)
             {
                if(lerascii[i]>lerascii[j])
                {
                   acc = Registros[i];
                   Registros[i]=Registros[j];
                   Registros[j] = acc; 
             }
          }
          fprint(lerascii,"%d\n",vet[i]);
        }
          fclose(lerascii);
    }
    */
