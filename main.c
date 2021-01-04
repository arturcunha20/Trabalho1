#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char genero;
    int vencimeto;
    int id;
    int cargo;
    int clic_id;
}Funcionario;

typedef struct {
    char nome[50];
    int ano;
    int id;
}Clinica;

typedef struct {
    int id;
    int id_func;
    int id_clic;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
}Agenda;


//CLINICAS -------------------------------------------------------------------------------------------------------------
void InsertClinica()
{
    FILE *file,*fileC;
    int res,contClinicas;
    Clinica clic;
    fflush(stdin);

    fileC = fopen("../Clinicas.txt","r");
    while (!feof(fileC)) // feof devolve 0 ou 1
    {
        res = fscanf(fileC,"%d %s %d\n",&clic.id,&clic.nome,&clic.ano);
    }

    if(res<0)
    {
        contClinicas = 0;
    }
    else{
        contClinicas = clic.id;
    }
    fclose(fileC);

    printf("Diga o nome da clinica -> "); gets(clic.nome);

    for(int x=0;clic.nome[x] != '\0';x++)
    {
        if(clic.nome[x] == ' ')
        {
            clic.nome[x] = '_';
        }
    }

    printf("\nDiga o ano de fundacao -> "); scanf("%d",&clic.ano);

    clic.id = contClinicas + 1;
    printf("\n\n");
    file = fopen("../Clinicas.txt","a");
    fprintf(file,"%d %s %d\n",clic.id,clic.nome,clic.ano);
    fclose(file);
}

void ReadClinica()
{
    int res,contClinicas;
    FILE *file;
    Clinica clic;

    file = fopen("../Clinicas.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %s %d\n",&clic.id ,&clic.nome ,&clic.ano);

        for(int x=0;clic.nome[x] != '\0';x++)
        {
            if(clic.nome[x] == '_')
            {
                clic.nome[x] = ' ';
            }
        }

        printf("Id -> %d | Nome -> %s | Ano de Fundacao -> %d\n\n",clic.id ,clic.nome ,clic.ano);

    }

    printf("\n\n");
    contClinicas = clic.id;
    fclose(file);
}






//Funcionarios ---------------------------------------------------------------------------------------------------------
void InsertFuncionario()
{
    FILE *file,*fileF;
    int res,contFuncionarios,id,opcao;
    Funcionario func,funcl;
    Clinica clic;

    fileF = fopen("../funcionarios.txt","r");
    while (!feof(fileF))
    {
        res = fscanf(fileF,"%d %s %d %c %d %d %d\n",&funcl.id ,&funcl.nome ,&funcl.idade ,&funcl.genero ,&funcl.vencimeto,&funcl.cargo,&funcl.clic_id);
    }

    if(res<0)
    {
        contFuncionarios = 0;
    }
    else{
        contFuncionarios = funcl.id;
    }
    fclose(fileF);


    file = fopen("../Clinicas.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %s %d\n",&clic.id ,&clic.nome ,&clic.ano);

        for(int x=0;clic.nome[x] != '\0';x++)
        {
            if(clic.nome[x] == '_')
            {
                clic.nome[x] = ' ';
            }
        }
        printf("Id -> %d | Nome -> %s | Ano de Fundacao -> %d\n",clic.id ,clic.nome ,clic.ano);

        id = clic.id;

    }

    printf("\n\n");
    fclose(file);

    do {
        printf("Diga o numero (id) da clinica que pertence -> "); scanf("%d",&opcao);
    } while (opcao < 1 || opcao > id );
    id = opcao;

    printf("\n");
    fflush(stdin);
    printf("Diga o seu nome -> "); gets(func.nome);

    for(int x=0;func.nome[x] != '\0';x++)
    {
        if(func.nome[x] == ' ')
        {
            func.nome[x] = '_';
        }
    }

    printf("\nDiga a sua idade -> "); scanf("%d",&func.idade);

    do{
        printf("\nDiga a seu Genero (M/m - Masculino | F/f - Feminino | O/o - Outro ) -> "); scanf(" %c",&func.genero);
    } while (func.genero != 'M' && func.genero != 'm' && func.genero != 'F' && func.genero != 'f' && func.genero != 'O' && func.genero != 'o');

    printf("\nDiga a seu Vencimento -> "); scanf("%d",&func.vencimeto);
    do{
        printf("\nDiga o seu Cargo (0 - Medico | 1 - Enfermeiro | 2 - auxiliar) -> "); scanf("%d",&func.cargo);
    } while (func.cargo != 0 && func.cargo != 1 && func.cargo != 2);

    func.id = contFuncionarios + 1;

    file = fopen("../funcionarios.txt","a");
    fprintf(file,"%d %s %d %c %d %d %d\n",func.id,func.nome,func.idade,func.genero,func.vencimeto,func.cargo,id,file);
    fclose(file);
    printf("\n");
}

void ReadFuncionarios()
{
    int res,contFuncionarios;
    char genero[30],cargo[10],nomeClic[50];
    FILE *file,*fileClic;
    Funcionario funcl;
    Clinica clic;

    file = fopen("../funcionarios.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %s %d %c %d %d %d\n",&funcl.id ,&funcl.nome ,&funcl.idade ,&funcl.genero ,&funcl.vencimeto, &funcl.cargo,&funcl.clic_id);

        for(int x=0;funcl.nome[x] != '\0';x++)
        {
            if(funcl.nome[x] == '_')
            {
                funcl.nome[x] = ' ';
            }
        }


        switch (funcl.genero) {
            case 'F': strcpy(genero,"Feminino");break;
            case 'f': strcpy(genero,"Feminino");break;
            case 'M': strcpy(genero,"Masculino");break;
            case 'm': strcpy(genero,"Masculino");break;
            case 'O': strcpy(genero,"Outro");break;
            case 'o': strcpy(genero,"Outro");break;
        }

        switch (funcl.cargo) {
            case 0:
                switch (funcl.genero) {
                    case 'F': strcpy(cargo,"Medica"); break;
                    case 'f': strcpy(cargo,"Medica"); break;
                    case 'M': strcpy(cargo,"Medico"); break;
                    case 'm': strcpy(cargo,"Medico"); break;
                } break;
            case 1:
                switch (funcl.genero) {
                    case 'F': strcpy(cargo,"Enfermeira"); break;
                    case 'f': strcpy(cargo,"Enfermeira"); break;
                    case 'M': strcpy(cargo,"Enfermeiro"); break;
                    case 'm': strcpy(cargo,"Enfermeiro"); break;
                } break;

            case 2:case 'F': strcpy(cargo,"Auxiliar"); break;

        }

        fileClic = fopen("../Clinicas.txt","r");
        while (!feof(fileClic))
        {
            res = fscanf(fileClic,"%d %s %d\n",&clic.id ,&clic.nome ,&clic.ano);
            if(clic.id == funcl.clic_id)
            {
                for(int x=0;clic.nome[x] != '\0';x++)
                {
                    if(clic.nome[x] == '_')
                    {
                        clic.nome[x] = ' ';
                    }
                }
                strcpy(nomeClic,clic.nome);
            }


        }

        fclose(fileClic);


        printf("Id-> %d | Nome-> %s | Genero-> %c",funcl.id ,funcl.nome ,funcl.genero);
        printf(" | Idade-> %d | Vencimento-> %d | Cargo-> %s | Clinica-> %s\n\n",funcl.idade ,funcl.vencimeto,cargo,nomeClic);
    }
    contFuncionarios = funcl.id;
    fclose(file);
}

void InsertAgenda()
{
    Agenda ag;
    Clinica clic;
    Funcionario func;
    FILE *file,*fileC,*fileF;
    int res,contAgenda,opcao,id,bissexto;
    char cargoF[50];

    fflush(stdin);
    file = fopen("../Agenda.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %d %d %d %d %d %d %d\n",&ag.id,&ag.id_func,&ag.id_clic,&ag.dia,&ag.mes,&ag.ano,&ag.hora,&ag.minutos);
    }
    fclose(file);

    if(res<0)
    {
        contAgenda = 0;
    }
    else{
        contAgenda = ag.id;
    }


    fileF = fopen("../funcionarios.txt","r");
    while (!feof(fileF))
    {
        res = fscanf(fileF,"%d %s %d %c %d %d %d\n",&func.id,&func.nome,&func.idade,&func.genero,&func.vencimeto,&func.cargo,&func.clic_id);

        for(int x=0;func.nome[x] != '\0';x++)
        {
            if(func.nome[x] == '_')
            {
                func.nome[x] = ' ';
            }
        }

        fileC = fopen("../Clinicas.txt","r");
        while (!feof(fileC)) {
            res = fscanf(fileC, "%d %s %d\n", &clic.id, &clic.nome, &clic.ano);

            if(clic.id == func.clic_id)
            {
                for(int x=0;clic.nome[x] != '\0';x++)
                {
                    if(clic.nome[x] == '_')
                    {
                        clic.nome[x] = ' ';
                    }
                }

                switch (func.cargo) {
                    case 0:
                        switch (func.genero) {
                            case 'F': strcpy(cargoF,"Medica"); break;
                            case 'f': strcpy(cargoF,"Medica"); break;
                            case 'M': strcpy(cargoF,"Medico"); break;
                            case 'm': strcpy(cargoF,"Medico"); break;
                        } break;
                    case 1:
                        switch (func.genero) {
                            case 'F': strcpy(cargoF,"Enfermeira"); break;
                            case 'f': strcpy(cargoF,"Enfermeira"); break;
                            case 'M': strcpy(cargoF,"Enfermeiro"); break;
                            case 'm': strcpy(cargoF,"Enfermeiro"); break;
                        } break;
                    case 2:case 'F': strcpy(cargoF,"Auxiliar"); break;
                }

                printf("Id -> %d | Nome -> %s | Clinica -> %s | Cargo -> %s\n",func.id ,func.nome ,clic.nome,cargoF);
            }

        }

        id = func.id;
        fclose(fileC);
    }
    printf("\n");

    fclose(fileF);
    do {
        printf("\nDiga o numero (id) da clinica que pertence -> "); scanf("%d",&opcao);
    } while (opcao < 1 || opcao > id );

    ag.id_func = opcao;

    fileF = fopen("../funcionarios.txt","r");
    while (!feof(fileF)) {
        res = fscanf(fileF, "%d %s %d %c %d %d %d\n", &func.id, &func.nome, &func.idade, &func.genero, &func.vencimeto,&func.cargo, &func.clic_id, fileF);
        if(func.id == opcao)
        {
            ag.id_clic = func.clic_id;
        }
    }
    fclose(fileF);


    printf("\nData (Dia/Mes/Ano) -> ");
    printf("\nDiga Ano -> "); scanf("%d",&ag.ano);
    printf("\nDiga Mes -> "); scanf("%d",&ag.mes);
    if(ag.mes == 1 || ag.mes == 3 || ag.mes == 5 || ag.mes == 7 || ag.mes == 8 || ag.mes == 10 || ag.mes == 12)
    {
        do {
            printf("\nDiga Dia -> "); scanf("%d",&ag.dia);
        } while (ag.dia < 1 || ag.dia > 31);
    }
    else
    {
        if(ag.mes == 4 || ag.mes == 6 || ag.mes == 9 || ag.mes == 11)
        {
            do {
                printf("\nDiga Dia -> "); scanf("%d",&ag.dia);
            } while (ag.dia < 1 || ag.dia > 30);
        }
        else
        {
            if (ag.ano % 400 == 0) {
                bissexto = 1;
            }
            else if ((ag.ano % 4 == 0) && (ag.ano % 100 != 0)) {
                bissexto = 1;
            }
            else {
                bissexto = 0;
            }

            if(bissexto == 1)
            {
                do {
                    printf("\nDiga Dia -> "); scanf("%d",&ag.dia);
                } while (ag.dia < 1 || ag.dia > 29);
            }
            else{
                do {
                    printf("\nDiga Dia -> "); scanf("%d",&ag.dia);
                } while (ag.dia < 1 || ag.dia > 28);
            }
        }
    }


    printf("\n\nHora (Hora:Minutos) -> ");

    do {
        printf("\nDiga a hora-> "); scanf("%d",&ag.hora);
    } while (ag.hora < 0 || ag.hora > 23);

    do {
        printf("\nDiga os minutos -> "); scanf("%d",&ag.minutos);
    } while (ag.minutos < 0 || ag.minutos > 59);


    ag.id = contAgenda + 1;
    printf("\n\n");

    file = fopen("../Agenda.txt","a");
    fprintf(file,"%d %d %d %d %d %d %d %d\n",ag.id,ag.id_func,ag.id_clic,ag.dia,ag.mes,ag.ano,ag.hora,ag.minutos);
    fclose(file);
}

void ReadAgenda()
{
    int res;
    char nomeFunc[50],nomeClic[50];
    FILE *file,*fileC,*fileF;
    Clinica clic;
    Funcionario func;
    Agenda ag;


    file = fopen("../Agenda.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %d %d %d %d %d %d %d\n",&ag.id,&ag.id_func,&ag.id_clic,&ag.dia,&ag.mes,&ag.ano,&ag.hora,&ag.minutos);
        fileF = fopen("../funcionarios.txt","r");
        while (!feof(fileF))
        {
            res = fscanf(fileF,"%d %s %d %c %d %d %d\n",&func.id ,&func.nome ,&func.idade ,&func.genero ,&func.vencimeto,&func.cargo,&func.clic_id);

            if(func.id == ag.id_func)
            {
                for(int x=0;func.nome[x] != '\0';x++)
                {
                    if(func.nome[x] == '_')
                    {
                        func.nome[x] = ' ';
                    }
                }
                strcpy(nomeFunc,func.nome);
            }
        }
        fclose(fileF);

        fileC = fopen("../Clinicas.txt","r");
        while (!feof(fileC))
        {
            res = fscanf(fileC,"%d %s %d\n",&clic.id ,&clic.nome ,&clic.ano);

            if(clic.id == ag.id_clic)
            {
                for(int x=0;clic.nome[x] != '\0';x++)
                {
                    if(clic.nome[x] == '_')
                    {

                        clic.nome[x] = ' ';
                    }
                }
                strcpy(nomeClic,clic.nome);
            }
        }
        fclose(fileC);

        printf("Id -> %d | Nome Funcionario -> %s | Nome Clinica -> %s | Data -> %d/%d/%d | Hora -> %d:%d\n\n",ag.id ,nomeFunc ,nomeClic,ag.dia,ag.mes,ag.ano,ag.hora,ag.minutos);

    }
    printf("\n\n");
    fclose(file);
}


void Resumo()
{
    int somaE=0,somaM=0,somaA=0,res,contE=0,contM=0,contA=0,maxFunc,i=0,maxClic;
    float mediaM=0,mediaE=0,mediaA=0;
    char nomeClic[50];
    FILE *file,*fileC;
    Funcionario funcV;
    Clinica clicV;

    file = fopen("../funcionarios.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %s %d %c %d %d %d\n",&funcV.id ,&funcV.nome ,&funcV.idade ,&funcV.genero ,&funcV.vencimeto,&funcV.cargo,&funcV.clic_id);
    }
    fclose(file);
    maxFunc = funcV.id;

    fileC = fopen("../Clinicas.txt","r");
    while (!feof(fileC)) // feof devolve 0 ou 1
    {
        res = fscanf(fileC,"%d %s %d\n",&clicV.id,&clicV.nome,&clicV.ano);
    }
    maxClic = clicV.id;
    fclose(fileC);




    Funcionario func[maxFunc];
    Clinica clic[maxClic];

    file = fopen("../funcionarios.txt","r");
    while (!feof(file))
    {
        res = fscanf(file,"%d %s %d %c %d %d %d\n",&func[i].id ,&func[i].nome ,&func[i].idade ,&func[i].genero ,&func[i].vencimeto,&func[i].cargo,&func[i].clic_id);
        i++;
    }
    fclose(file);

    i=0;
    fileC = fopen("../Clinicas.txt","r");
    while (!feof(fileC))
    {
        res = fscanf(fileC,"%d %s %d\n",&clic[i].id,&clic[i].nome,&clic[i].ano);
        i++;
    }
    fclose(fileC);
    printf("Media Idades->\n");
    for(i=0;i<maxClic;i++)
    {
        somaE=0,somaM=0,somaA=0,contE=0,contM=0,contA=0,mediaM=0,mediaE=0,mediaA=0;;
        for(int j=0;j<maxFunc;j++)
        {
            if(clic[i].id == func[j].clic_id)
            {
                switch (func[j].cargo) {
                    case 0:
                        somaM = somaM + func[j].idade;
                        contM++;
                        break;
                    case 1:
                        somaE = somaE + func[j].idade;
                        contE++;
                        break;
                    case 2:
                        somaA = somaA + func[j].idade;
                        contA++;
                        break;
                }
            }
        }

        if(contA != 0 || contE != 0 || contM != 0 )
        {
            if(contA != 0)
            {
                mediaA = somaA/contA;
            }

            if(contE != 0)
            {
                mediaE = somaE/contE;
            }
            if(contM != 0)
            {
                mediaM = somaM/contM;
            }
            for (int x = 0; clic[i].nome[x] != '\0'; x++) {
                if (clic[i].nome[x] == '_') {
                    clic[i].nome[x] = ' ';
                }
            }
            strcpy(nomeClic, clic[i].nome);
            printf("Clinica -> %s | Medicos -> %.2f | Enfermeiros -> %.2f | Auxiliares -> %.2f\n", nomeClic,mediaM, mediaE, mediaA);

        }
    }
    printf("\n\n");
}


int main() {
    int opcao,opcaoE;
    do {
        printf("1 - Funcinarios\n2 - Clinicas\n3 - Agenda\n4 - Resumo\n0 - Sair\nOpcao -> "); scanf("%d",&opcao);
        printf("\n");
        switch (opcao) {
            case 1:
                do {
                    printf("1 - Inserir Funcinario\n2 - Ver Funcinarios\n0 - Voltar\nOpcao -> "); scanf("%d",&opcaoE);
                    printf("\n");
                    switch (opcaoE) {
                        case 1: InsertFuncionario(); break;
                        case 2: ReadFuncionarios(); break;
                    }
                } while (opcaoE < 1 && opcaoE > 2 || opcaoE != 0);
                printf("\n");
                break;

            case 2:  do {
                    printf("1 - Inserir Clinica\n2 - Ver Clinicas\n0 - Voltar\nOpcao -> "); scanf("%d",&opcaoE);
                    printf("\n");
                    switch (opcaoE) {
                        case 1: InsertClinica(); break;
                        case 2: ReadClinica(); break;
                    }
                } while (opcaoE < 1 && opcaoE > 2 || opcaoE != 0);
                printf("\n");
                break;

            case 3:
                do {
                    printf("1 - Inserir Agenda\n2 - Ver Agenda\n0 - Voltar\nOpcao -> "); scanf("%d",&opcaoE);
                    printf("\n");
                    switch (opcaoE) {
                        case 1: InsertAgenda(); break;
                        case 2: ReadAgenda(); break;
                    }
                } while (opcaoE < 1 && opcaoE > 2 || opcaoE != 0);
                printf("\n");
                break;

            case 4: Resumo();break;

            case 0: printf("Ate uma proxima");break;
        }
    } while (opcao < 1 && opcao > 4 || opcao != 0);
    return 0;
}
