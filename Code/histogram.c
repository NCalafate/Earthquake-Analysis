#include "histogram.h"

void HISTOGRAM(PtList list) {
    
    // Utilizador diz quantos países pretende pesquisar.
    int countryn = 0, errcheck = 0;
    while(countryn < 1 || countryn > 3) {
        if(errcheck != 0) printf("Error! Make sure the number is between 1 and three (INCLUSIVE).\n");
        printf("Number of countries you wish to search [1 to 3]: ");
        readInteger(&countryn);
        errcheck++;
    }

    // Utilizador insere os códigos dos países que pretende pesquisar.
    StringWrap* codes = (StringWrap*)malloc(countryn * sizeof(StringWrap));
    int c = 1, codeCounter = 0;
    char temp[3], bf;
    printf("Please insert the codes of the countries you wish to search.\n");
    while(c != countryn + 1) {
        printf("Insert code for country %d: ", c);
        readString(temp, 3);
        getchar();
        codes[codeCounter++] = stringWrapCreate(temp);
        c++;
    }

    // Array temporário dos dados de terramotos dos países.
    CountryQuakes* aggdata = (CountryQuakes*)malloc(codeCounter * sizeof(CountryQuakes));

    ListElem elem;
    int listsz = 0;
    listSize(list, &listsz);
    for(int i = 0; i < codeCounter; i++) {

        // Inicializam-se os valores de aggdata.
        strcpy(aggdata[i].countryCode, codes[i].text);
        aggdata[i].magnValues[0] = 0;
        aggdata[i].magnValues[1] = 0;
        aggdata[i].magnValues[2] = 0;
        aggdata[i].magnValues[3] = 0;
        aggdata[i].magnValues[4] = 0;
        aggdata[i].magnValues[5] = 0;

        for(int j = 0; j < listsz; j++) {
            listGet(list, j, &elem);

            // Se o código do terramoto for igual ao inserido.
            if(strcasecmp(elem.countryCode, aggdata[i].countryCode) == 0) {

                // Adiciona-se um terramoto aos valores correspondentes das magnitudes.
                if(elem.magnitude <= 6) {
                    aggdata[i].magnValues[0]++;
                } else if(elem.magnitude <= 6.5) {
                    aggdata[i].magnValues[1]++;
                } else if(elem.magnitude <= 7) {
                    aggdata[i].magnValues[2]++;
                } else if(elem.magnitude <= 7.5) {
                    aggdata[i].magnValues[3]++;
                } else if(elem.magnitude <= 8) {
                    aggdata[i].magnValues[4]++;
                } else {
                    aggdata[i].magnValues[5]++;
                }
            }
        }
    }

    // Verificação de validade.
    for(int i = 0; i < codeCounter; i++) {
        if(
            aggdata[i].magnValues[0] == 0 &&
            aggdata[i].magnValues[1] == 0 &&
            aggdata[i].magnValues[2] == 0 &&
            aggdata[i].magnValues[3] == 0 &&
            aggdata[i].magnValues[4] == 0 &&
            aggdata[i].magnValues[5] == 0
        ) printf("No earthquake data found for country [%s].\nEither it doesn't exist or it has no earthquakes.\nIt will be displayed in the table anyways...\n", aggdata[i].countryCode);
    }

    /* NOTA IMPORTANTE */
    // Durante o desenvolvimento foi reparado que os hashtags do exemplo no enunciado são diferentes. No entanto não sabemos se é intencional.
    // Aplica-se para o número 2093 e 470 no JP do enunciado, que têm 7 hashtags de diferença entre si, que seguindo incrementações de 3 em 3 seria impossível. 
    // Também pensámos que poderia ser fracional.
    // No entanto, ao utilizarmos incrementações de um hashtag a cada 0.33 da parte decimal do resultado do log2, a tabela continua ser diferente.
    char magns[6][20] = {"<= 6\0","]6.0, 6.5]\0","]6.5, 7.0]\0","]7.0, 7.5]\0","]7.5, 8.0]\0","> 8\0"};
    printf("CODE | MAGNITUDE     | NUMBER OF EARTHQUAKES (LOGARITHMIC SCALE)\n");
    // 6 é o número de intervalos de magnitudes.
    for(int i = 0; i < 6; i++) {
        printf("---------------------------------------------------------------------------\n");
        for(int j = 0; j < codeCounter; j++) {
            printf("%-5s| %-14s| ", aggdata[j].countryCode, magns[i]);
            int hashtags = (int) log2(aggdata[j].magnValues[i]);
            if(aggdata[j].magnValues[i] == 1) {
                printf("###");
            } else if (aggdata[j].magnValues[i] != 0) {
                for(int j = 0; j <= hashtags; j++) printf("###");
            }
            if(aggdata[j].magnValues[i] == 0) printf("0\n");
            else printf(" %d\n", aggdata[j].magnValues[i]);
        }
    }
    free(codes);
    free(aggdata);    
}