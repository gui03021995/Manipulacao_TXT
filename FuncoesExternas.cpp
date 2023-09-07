string getString(string texto)
{
    string valor;
    cout << texto;
    fflush(stdin);  // Limpa "buffer" do teclado
    getline(cin,valor);
    return valor;
}

int getInteiro(string texto)
{
    int valor;
    cout << texto;
    cin >> valor;
    return valor;
}

float getFloat(string texto)
{
    float valor;
    cout << texto;
    cin >> valor;
    return valor;
}

bool simOuNao(string texto)
{
    char  sn;
    cout << texto;
    cout << "\nDigite 's' para SIM ou 'n' para NÃO: ";
    cin >> sn;
    if(sn=='s' || sn=='S')
    {
        return true;
    }else{
        return false;
    }
}

void txtVermelho(string texto)
{
    system("color 3");
    cout << texto;
    system("color f");
}

void titulo(string t)
{
    system("cls");
    cout << "=== " << t << " ===\n\n";
}


void setTextColor(int padrao=0)
{
    /*
        ESTA FUNÇÃO DEPENDE DA INCLUSÃO DA
        BIBLIOTECA CONIO.C
    */

    system("cls");
    if(!padrao)
    {
        textcolor(14);
        system("cls");
        return;
    }else{
        for(int i=0;i<30;i++)
        {
            textcolor(i);
            cout << "TESTE DE COR - " << i << "\n";
        }
        cout << "\nDEFINIR COR PADRÃO: ";
        cin >> padrao;
        textcolor(padrao);
        cout << "\nCOR PADRÃO DEFINIDA COM SUCESSO\n";
        system("pause");
        system("cls");
    }
}

int stringParaInt(string s)
{
    int tempI;

    // de string para char
    char *temp = new char[s.length()+1];
    memcpy(temp, s.c_str(), s.length() + 1);

    // de char para int
    tempI = atoi(temp);

    return tempI;
}

float stringParaFloat(string s)
{
    float tempF;

    // de string para char
    char *temp = new char[s.length()+1];
    memcpy(temp, s.c_str(), s.length() + 1);

    // de char para float
    tempF = atof(temp);

    return tempF;
}

