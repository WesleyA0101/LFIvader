# 🛡️ **LFIvader**  

![Editor: Vim](https://img.shields.io/badge/Editor-Vim-green.svg?logo=vim&logoColor=white) 
[![Build Status](https://img.shields.io/badge/Status-Stable-green.svg)]() 
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE) 
[![Language: C](https://img.shields.io/badge/Language-C-lightblue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  


> **LFIvader** é uma ferramenta para detectar vulnerabilidades do tipo Local File Inclusion (LFI) em servidores web.  
> Projetada com foco em precisão e eficiência, ela é ideal para uso em ambientes profissionais e auditorias de segurança.

---

## **📜 Visão Geral**

Local File Inclusion (LFI) é uma vulnerabilidade em aplicações web que permite a inclusão de arquivos do servidor através de entradas malvalidadas.  
O **LFIvader** realiza varreduras automáticas em URLs alvo, testando uma lista abrangente de vetores conhecidos para encontrar vulnerabilidades e exibir os resultados com formatação clara.

---

## **✨ Recursos**

- **Detecção Automática**: Testa diversos vetores LFI conhecidos.
- **Resultados Formatados**: Exibe os dados vulneráveis de forma organizada.
- **Relatórios Detalhados**: Salva os resultados automaticamente em arquivos locais.
- **Compatibilidade Multiplataforma**: Funciona em sistemas Linux e Windows.

---

## **⚡ Requisitos**

- **Sistema Operacional**: Linux ou Windows.
- **Compilador**: GCC ou MinGW (para Windows).
- **Bibliotecas Necessárias**:
  - [libcurl](https://curl.se/libcurl/)
  - [unistd.h](https://pubs.opengroup.org/onlinepubs/009695399/functions/unistd.h.html) (Linux)
  - [stdio.h](https://en.wikipedia.org/wiki/C_standard_library)
  - [stdlib.h](https://en.wikipedia.org/wiki/C_standard_library)
  - [string.h](https://en.wikipedia.org/wiki/C_standard_library)

---

## **🚀 Como Usar**

1. **Clone o Repositório**:
    ```bash
    git clone https://github.com/WesleyA0101/LFIvader.git
    cd LFIvader
    ```

2. **Compile o Código**:
    - No Linux:
        ```bash
        gcc -o LFIvader LFIvader.c -lcurl
        ```
    - No Windows:
        ```bash
        gcc -o LFIvader.exe LFIvader.c -lcurl
        ```

3. **Execute a Ferramenta**:
    - No Linux:
        ```bash
        ./LFIvader
        ```
    - No Windows:
        ```bash
        LFIvader.exe
        ```

4. **Siga as Instruções**:
    - Insira a URL do alvo no formato `https://www.example.com`.
    - Acompanhe o progresso dos testes e revise os resultados salvos no arquivo `resultados_lfi.txt`.

---

## **📝 Exemplo de Uso**

- Entrada:
    ```
    https://www.example.com
    ```
- Saída:
    ```plaintext
    Vulnerabilidade LFI encontrada: https://www.example.com/?page=../../../../etc/passwd
    -----------------------------------------------------------
    root:x:0:0:root:/root:/bin/bash
    daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
    ...
    -----------------------------------------------------------
    Resultados salvos em 'resultados_lfi.txt'.
    ```


---

## **⚠️ Aviso de Uso**

Esta ferramenta foi desenvolvida exclusivamente para testes de segurança em ambientes próprios ou com autorização explícita do proprietário.  
**⚠️ Uso não autorizado é estritamente proibido e pode violar leis locais e internacionais.**

---

## **📜 Licença**

Este projeto é licenciado sob os termos da licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais informações.

---

## **🤝 Contribuições**

Contribuições são bem-vindas!  
Siga os passos abaixo para colaborar:
1. Faça um **fork** do projeto.
2. Crie um **branch** para a sua funcionalidade ou correção:
    ```bash
    git checkout -b feature/nova-funcionalidade
    ```
3. Envie suas alterações:
    ```bash
    git push origin feature/nova-funcionalidade
    ```
4. Abra um **Pull Request**.

---

## **🌟 Agradecimentos**

Este projeto foi desenvolvido por **Wesley Alexsander**.  
Visite meu perfil no GitHub para explorar outros projetos:  
[**GitHub: WesleyA0101**](https://github.com/WesleyA0101)

---

## **🔗 Links Importantes**

- [Documentação do cURL](https://curl.se/libcurl/c/)
- [Introdução a LFI](https://owasp.org/www-community/attacks/Path_Traversal)




