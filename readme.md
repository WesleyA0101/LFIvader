 # 🛡️ **LFIvader**  

![Editor: Vim](https://img.shields.io/badge/Editor-Vim-green.svg?logo=vim&logoColor=white) 
[![Build Status](https://img.shields.io/badge/Status-Stable-green.svg)]() 
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE) 
[![Language: C](https://img.shields.io/badge/Language-C-lightblue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  


**LFIvader** é uma ferramenta poderosa para **detectar vulnerabilidades de Local File Inclusion (LFI)** em servidores web. Desenvolvida para ser confiável e eficiente, é uma aliada indispensável para profissionais de segurança em auditorias e testes de intrusão.

---

## **📖 Sobre o Projeto**

O LFI (Local File Inclusion) é uma vulnerabilidade comum em aplicações web que permite a inclusão de arquivos sensíveis do servidor através de entradas malvalidadas.  
O **LFIvader** automatiza a detecção desses pontos críticos, utilizando vetores conhecidos para identificar possíveis.

### **Principais Diferenciais**:
- **Automação Completa**: Varredura detalhada de URLs com múltiplos vetores de ataque.
- **Resultados Precisos**: Relatórios organizados e salvos automaticamente para referência futura.
- **Interface Intuitiva**: Usabilidade pensada para profissionais e iniciantes.
- **Multiplataforma**: Suporte para Linux e Windows.

---

## **🚀 Recursos**

✅ **Varredura Inteligente**: Testa automaticamente vetores conhecidos para vulnerabilidades de LFI.  
✅ **Relatórios Detalhados**: Salva resultados em arquivos locais, com formatação clara e acessível.  
✅ **Modularidade**: Fácil de integrar e personalizar para auditorias específicas.  
✅ **Desempenho Superior**: Desenvolvido em C para garantir velocidade e eficiência.  

---

## **🛠️ Requisitos do Sistema**

- **Sistema Operacional**:  
  - Linux ou Windows.
- **Compilador**:  
  - GCC (Linux) ou MinGW (Windows).
- **Dependências**:  
  - [libcurl](https://curl.se/libcurl/): Biblioteca para requisições HTTP.  
  - [unistd.h](https://pubs.opengroup.org/onlinepubs/009695399/functions/unistd.h.html) (apenas Linux).  
  - Outras: `stdio.h`, `stdlib.h`, `string.h`.

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

## 📁 Instalando como Comando Global

Para facilitar o uso da ferramenta, você pode instalá-la como um comando global no seu sistema. Siga os passos abaixo:

1. **Compile o executável da ferramenta**:
    - No Linux:
        ```bash
        gcc -o LFIvader LFIvader.c -lcurl
        ```
    - No Windows:
        (Não aplicável diretamente. Recomendado criar um script de instalação para ambientes Windows).

2. **Copie o executável para um diretório global**:
    No Linux, copie o arquivo compilado para o diretório `/usr/local/bin`, que está no **PATH** padrão:
    ```bash
    sudo cp LFIvader /usr/local/bin/
    ```

3. **Verifique se foi instalado corretamente**:
    Execute o comando abaixo para confirmar:
    ```bash
    LFIvader
    ```

    Se a ferramenta executar corretamente, significa que a instalação foi bem-sucedida!

4. **Caso queira desinstalar**:
    Basta remover o arquivo do diretório global:
    ```bash
    sudo rm /usr/local/bin/LFIvader
    ```

*Agora você pode usar o comando `LFIvader` diretamente de qualquer lugar no terminal sem precisar especificar o caminho completo.*

**Observação**: Se você deseja adicionar essa funcionalidade no **Windows**, precisará configurar um script para mover o executável para um diretório do PATH ou instruir os usuários a adicionar o caminho manualmente.

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

<div align="center"> <strong>⭐ Se você gostou deste projeto, não se esqueça de dar uma estrela no repositório! ⭐</strong> </div>


