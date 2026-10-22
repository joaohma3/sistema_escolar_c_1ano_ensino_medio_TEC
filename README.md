LEIA-ME — SISTEMA DE GERENCIAMENTO ESCOLAR EM C
INSTALAÇÃO E TESTES PELO TERMINAL DO VISUAL STUDIO CODE (WINDOWS)

Este é o sistema que desenvolvemos nas três aulas. Agora vamos preparar o computador, compilar nosso código e testar todas as funcionalidades. Já temos o Visual Studio Code instalado: não precisamos instalá-lo novamente.

IMPORTANTE: Todos os comandos abaixo devem ser digitados no TERMINAL do Visual Studio Code, usando PowerShell. Não digite os comandos dentro do arquivo .c.

1. ABRIR NOSSO PROJETO
1) Abra o Visual Studio Code.
2) Clique em Arquivo > Abrir Pasta e selecione a pasta em que salvamos nosso projeto.
3) Confirme que o arquivo sistema_escolar_completo(1).c está nessa pasta.
4) Abra Terminal > Novo Terminal. Confira se o terminal é PowerShell (se não for, selecione PowerShell no menu ao lado do botão +).

2. VERIFICAR SE O COMPILADOR GCC JÁ ESTÁ INSTALADO
No terminal, execute:
gcc --version
Se aparecer uma versão do GCC, vá direto para a ETAPA 5.
Se aparecer a mensagem de que 'gcc' não é reconhecido, continue na ETAPA 3.

3. INSTALAR O QUE FALTA PELO PRÓPRIO TERMINAL DO VS CODE
Primeiro, verifique se o gerenciador de programas do Windows está disponível:
winget --version
Se aparecer uma versão, instale o MSYS2 pelo terminal:
winget install --id MSYS2.MSYS2 -e --accept-package-agreements --accept-source-agreements
Aguarde o término. Se o Windows pedir autorização, confirme. O MSYS2 normalmente será instalado em C:\msys64.
ATENÇÃO: Se 'winget' não for reconhecido, não é possível garantir uma instalação totalmente pelo terminal com esses comandos. Peça ajuda ao professor ou responsável pelo laboratório para habilitar o App Installer/winget. Não cole comandos desconhecidos encontrados na internet.

4. INSTALAR O GCC USANDO O TERMINAL DO VS CODE

Ainda no PowerShell do VS Code, execute os comandos a seguir, UM POR VEZ.
Atualizar os pacotes do MSYS2:
& 'C:\msys64\usr\bin\bash.exe' -lc 'pacman -Syu --noconfirm'

Se a atualização avisar que é necessário fechar/reiniciar o ambiente MSYS2, execute o mesmo comando novamente no terminal do VS Code até a atualização terminar. Se houver erro de bloqueio de arquivos, feche outros terminais MSYS2 e tente novamente.
Instalar o compilador GCC para Windows:
& 'C:\msys64\usr\bin\bash.exe' -lc 'pacman -S --needed --noconfirm mingw-w64-ucrt-x86_64-gcc'

Agora adicione o GCC ao PATH desta sessão do terminal:
$env:Path = 'C:\msys64\ucrt64\bin;' + $env:Path

Teste:

gcc --version

Se aparecer a versão do GCC, está pronto! Para que o GCC seja reconhecido também nos próximos terminais do seu usuário, execute:
$p = [Environment]::GetEnvironmentVariable('Path','User')
if (($p -split ';') -notcontains 'C:\msys64\ucrt64\bin') { [Environment]::SetEnvironmentVariable('Path', (($p.TrimEnd(';') + ';C:\msys64\ucrt64\bin').TrimStart(';')), 'User') }

Depois disso, feche e abra novamente o Visual Studio Code para carregar o PATH atualizado.

5. COMPILAR NOSSO SISTEMA
No terminal do VS Code, confirme que estamos na pasta onde está o arquivo .c. Para ver os arquivos da pasta, execute:
dir

Se o arquivo tiver exatamente o nome sistema_escolar_completo(1).c, compile com:
gcc -std=c11 -Wall -Wextra 'sistema_escolar_completo(1).c' -o sistema_escolar.exe

Se renomeamos o arquivo para sistema_escolar_completo.c, use:
gcc -std=c11 -Wall -Wextra sistema_escolar_completo.c -o sistema_escolar.exe

ATENÇÃO: O nome do arquivo no comando precisa ser igual ao nome que aparece na pasta. As aspas são necessárias no exemplo que contém parênteses.
Se o terminal voltar sem apresentar erros, o programa foi compilado e o arquivo sistema_escolar.exe foi criado.

6. EXECUTAR NOSSO SISTEMA
Digite no terminal:

.\sistema_escolar.exe

Nosso menu deverá aparecer com as opções:

1  - Cadastrar aluno
2  - Listar alunos
3  - Buscar aluno
4  - Registrar notas
5  - Consultar notas
6  - Mostrar situacao do aluno
7  - Registrar ocorrencia
8  - Consultar ocorrencias
9  - Estatisticas da turma
10 - Sair

OBSERVAÇÕES IMPORTANTES

- Nosso sistema foi desenvolvido em linguagem C e funciona no terminal; ele não abre uma página de internet.
- O VS Code é o editor; o GCC é o compilador necessário para transformar o código em programa executável.
- Os dados dos alunos e ocorrências ficam na memória durante a execução. Ao encerrar o programa, os cadastros não são gravados em arquivo; por isso, precisam ser digitados novamente em uma nova execução.
- Se o computador for da escola e não permitir instalações, solicite autorização ao professor ou responsável pelo laboratório.

PRONTO! Agora conseguimos compilar, executar e apresentar o sistema que desenvolvemos nas aulas.
