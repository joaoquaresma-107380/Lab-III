#include "ValidacaoPassageiro.h"

/*int validacaoSintaticaPassageiro(char** tokens) {
    int n = 0;

    // Validação do género
    if (tokens[5] == NULL)n++;
    else if(tokens[5][0] != 'M' && tokens[5][0] != 'F' && tokens[5][0] != 'O') n++;
    
    // validaçao data
    if ((validacaoData(tokens[3]) == 0)) {
            n++;
        }

    // Validação do email
    if(tokens[6] == NULL) {
        n++;
        return n;
    }

    char* aux_email = strdup(tokens[6]);
    char* aux_email_original = aux_email;
    char* username = strsep(&aux_email,"@");

    if(username == NULL) n++;

    else{
        // Verifica se no username só tem caracteres de a-z, 0-9 ou .
        int tamanho_username = strlen(username);

        for(int i = 0; i<tamanho_username;i++){
            if((username[i] < 48 || username[i] > 57) 
            && (username[i] < 97 || username[i] > 122)
            && username[i] != 46) n++;
        }

        // Verifica se o domain está correto

        if(aux_email == NULL) n++;

        else{
            char* lstring = strsep(&aux_email,".");
            if(lstring == NULL) n++;

            else{
                int tamanho_lstring = strlen(lstring);

                for(int i = 0; i < tamanho_lstring; i++){
                    if(lstring[i] < 97 || lstring[i] > 122) n++;
                }

                if(aux_email == NULL) n++;
                
                else{
                    int tamanho_rstring = strlen(aux_email);

                    if(tamanho_rstring < 2 || tamanho_rstring > 3) n++;
    
                    for(int i = 0; i < tamanho_rstring; i++){
                        if(aux_email[i] < 97 || aux_email[i] > 122) n++;
                    }
                }
            }
    }
    }
    
    free(aux_email_original);
    return n;
}*/

int validacaoSintaticaPassageiro(char** tokens) {
    int n = 0;
    // validar email
    int i = 0; int j = 0;int r = 0;

    for(;tokens[6][i]!='@' && i<strlen(tokens[6]);i++) {
        if(!((tokens[6][i]>=97 && tokens[6][i]<=122) || (tokens[6][i]>=48 && tokens[6][i]<=57))) {
        n++;
        }
    }
    if (i>=strlen(tokens[6])) n++;
    else {
        for(;tokens[6][j+i]!='.' && j+i<strlen(tokens[6]);j++) {
            if(!(tokens[6][j+i]>=97 && tokens[6][j+i]<=122)) n++;
        }
        if (j<1 || j+i>=strlen(tokens[6])) n++;
        else {
            for(;r+i+j!=(strlen(tokens[6]));r++) {
                if(!(tokens[6][r+i+j]>=97 && tokens[6][r+i+j]<=122)) n++;
            }
            if (r<1 || r>2) n++;
        }
    }
    // validaçao data
    if ((validacaoData(tokens[3]) == 0)) {
            n++;
        }
    return n;
}
