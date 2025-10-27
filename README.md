# Sistema de Gerenciamento de Tarefas (C)

Este programa permite criar, listar, remover, salvar e marcar tarefas como concluídas diretamente pelo terminal.  
Foi desenvolvido em **C** e pode ser compilado e executado em qualquer sistema com suporte ao **GCC**.

---

## 📦 Como obter o código

Você pode baixar o código de duas formas: **fazendo fork** (para modificar) ou **clonando diretamente o repositório** (para apenas usar).

### 1. Fazer Fork (GitHub)
1. Acesse o repositório original no GitHub.  
2. Clique em **Fork** (no canto superior direito).  
3. O projeto será copiado para a sua conta.  
4. Clone o fork para sua máquina:
   ```bash
   git clone https://github.com/yvvessel/To-do-list.git
Entre na pasta do projeto:

bash
Copiar código
cd todo
2. Clonar diretamente
Se quiser apenas executar o código:

bash
Copiar código
git clone https://github.com/yvvessel/To-do-list.git
cd todo
⚙️ Compilação e Execução
Compile o código com o GCC:

bash
Copiar código
gcc todo.c -o todo
Depois, execute o programa:

bash
Copiar código
./todo
Se existir um arquivo tasks.txt no diretório, o programa carregará automaticamente as tarefas salvas anteriormente.

🧭 Menu Principal
Ao executar o programa, o seguinte menu é exibido:


Copiar código
1 - Adicionar tarefa
2 - Listar todas as tarefas
3 - Listar por categoria
4 - Remover tarefa
5 - Marcar como concluído
6 - Salvar tarefas
7 - Sair
🧩 Funcionalidades
1. Adicionar tarefa
Permite cadastrar uma nova tarefa informando:

Nome da tarefa

Prazo de conclusão

Descrição ou objetivos

Categoria

Status (0 = pendente, 1 = em andamento, 2 = concluída)

Se o usuário digitar um valor inválido no status, o programa pedirá novamente.

2. Listar todas as tarefas
Mostra todas as tarefas com:

Nome

Prazo

Descrição

Categoria

Status (“Concluída” ou “Pendente”)

Se não houver tarefas cadastradas, o programa avisará.

3. Listar por categoria
Filtra as tarefas com base em uma categoria digitada.
Se a categoria não existir, aparece a mensagem:

nginx
Copiar código
Categoria não encontrada!
4. Remover tarefa
Mostra as tarefas com seus respectivos índices.
Digite o índice da tarefa que deseja remover.
Após a remoção, o programa reorganiza a lista automaticamente.

5. Marcar como concluída
Mostra todas as tarefas e seus índices.
Digite o índice da tarefa que deseja marcar como concluída.

6. Salvar tarefas
Salva todas as tarefas no arquivo tasks.txt.
O arquivo é sobrescrito a cada salvamento.

7. Sair
Encerra o programa.
Atenção: se sair sem salvar, as alterações não serão mantidas.

🗂 Estrutura do arquivo tasks.txt
As tarefas são salvas no formato:

Copiar código
Nome;Prazo;Descrição;Status;Concluída;Categoria
O programa lê automaticamente esse arquivo ao iniciar, carregando as tarefas existentes.

📝 Observações
Sempre salve antes de sair, para evitar perda de dados.

Categorias diferenciam maiúsculas e minúsculas (“Estudos” ≠ “estudos”).

O programa suporta até 100 tarefas por execução.

O arquivo tasks.txt é criado automaticamente ao salvar pela primeira vez.