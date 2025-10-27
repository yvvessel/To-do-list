# To-do-list

Guia de Uso — Sistema de Gerenciamento de Tarefas

Este programa permite criar, listar, remover, salvar e marcar tarefas como concluídas diretamente pelo terminal.

Início

Compile o programa normalmente:

gcc tarefas.c -o tarefas


Execute o programa:

./tarefas


Se existir um arquivo tasks.txt no mesmo diretório, o programa carregará automaticamente as tarefas salvas anteriormente.

Menu Principal

Ao iniciar, o seguinte menu será exibido:

1 - Adicionar tarefa
2 - Listar todas as tarefas
3 - Listar por categoria
4 - Remover tarefa
5 - Marcar como concluído
6 - Salvar tarefas
7 - Sair

Funcionalidades
1. Adicionar tarefa

Permite criar uma nova tarefa informando os seguintes dados:

Nome da tarefa: um título curto, como “Estudar C”.

Prazo de conclusão: data ou período.

Descrição: detalhes ou objetivos da tarefa.

Categoria: para organização (por exemplo, “Trabalho” ou “Estudos”).

Status: número representando o estado da tarefa (ex: 0 = pendente, 1 = em andamento, 2 = concluída).

Se o valor inserido no status for inválido (como uma letra), o programa pedirá novamente até receber um número válido.

2. Listar todas as tarefas

Mostra todas as tarefas cadastradas com as seguintes informações:

Nome

Prazo

Descrição

Categoria

Status (Concluída ou Pendente)

Se não houver tarefas cadastradas, o programa informará isso.

3. Listar por categoria

Filtra as tarefas com base em uma categoria informada pelo usuário.
Ao digitar o nome da categoria, o programa exibirá apenas as tarefas correspondentes.
Caso nenhuma seja encontrada, aparecerá a mensagem “Categoria não encontrada”.

4. Remover tarefa

Exibe a lista de tarefas com seus respectivos índices.
Digite o índice da tarefa que deseja remover.
Após isso, o programa reorganiza automaticamente a lista.

5. Marcar como concluída

Mostra todas as tarefas e seus índices.
Digite o índice da tarefa concluída e o programa marcará como “Concluída”.

6. Salvar tarefas

Salva todas as tarefas no arquivo tasks.txt.
Cada vez que essa opção é usada, o arquivo é sobrescrito com as tarefas atuais.

7. Sair

Encerra o programa.
É importante lembrar que, se o programa for encerrado sem usar a opção “Salvar tarefas”, as alterações não serão registradas no arquivo.

Arquivo tasks.txt

As tarefas são armazenadas no seguinte formato:

Nome;Prazo;Descrição;Status;Concluída;Categoria


O programa lê esse arquivo automaticamente ao iniciar, carregando as tarefas anteriores.

Observações

Utilize a opção “Salvar tarefas” antes de sair, para não perder alterações.

As categorias são sensíveis à diferença entre maiúsculas e minúsculas (“Estudos” e “estudos” são consideradas diferentes).

O programa suporta até 100 tarefas ao mesmo tempo.