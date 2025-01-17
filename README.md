# Projeto de Gerenciamento de Alunos e Compromissos

Este projeto em C é uma aplicação que permite o gerenciamento de informações de alunos, disciplinas e compromissos. Ele utiliza estruturas (`structs`) para organizar e armazenar os dados de forma eficiente, além de funções para cadastrar, validar e imprimir informações, com alocação dinâmica de memória para os vetores de alunos e compromissos.

---

## Estruturas Utilizadas

### Estruturas Básicas

1. **`td_data`**: Representa uma data com dia, mês e ano.
    ```c
    typedef struct {
        int dia;
        int mes;
        int ano;
    } td_data;
    ```

2. **`td_hora`**: Representa um horário com hora e minuto.
    ```c
    typedef struct {
        int hora;
        int min;
    } td_hora;
    ```

### Estruturas Compostas

3. **`td_disciplina`**: Representa uma disciplina com código, nome, notas e média.
    ```c
    typedef struct {
        int codigo_dis;
        char disciplina[100];
        float notas[4];
        float media;
    } td_disciplina;
    ```

4. **`td_aluno`**: Representa um aluno com RA, nome, data de matrícula, disciplinas, e-mail.
    ```c
    typedef struct {
        int ra;
        char nome[100];
        td_data matricula;
        td_disciplina disciplinas[4];
        char email[100];
    } td_aluno;
    ```

5. **`td_compromisso`**: Representa um compromisso com um aluno, data, horário e descrição.
    ```c
    typedef struct {
        td_aluno aluno;
        td_hora horario;
        td_data data;
        char descricao[300];
    } td_compromisso;
    ```

---

## Funcionalidades Principais

### Cadastro
1. **Cadastrar Aluno**
    - Cada aluno deve estar matriculado em ao menos 4 disciplinas.
    - Para cada disciplina, devem ser registradas 4 notas e sua média calculada.

2. **Cadastrar Compromisso**
    - Um aluno pode ter no máximo 2 compromissos por data.
    - Os horários dos compromissos não podem se sobrepor.

### Validação
3. **Validar Data**
    - Verifica se a data é válida antes de registrá-la.

4. **Validar Horário**
    - Verifica se o horário é válido antes de registrá-lo.

### Impressão
5. **Imprimir Dados de Alunos e Compromissos**
    - Dados de um aluno ou todos os alunos.
    - Compromissos ordenados por data, horário, ou RA.

### Alocação Dinâmica
6. **Gerenciar Vetores Dinamicamente**
    - Vetor de alunos:
        - Dimensão inicial: 10.
        - Aumenta em 10 sempre que preenchido.
    - Vetor de compromissos:
        - Dimensão inicial: 15.
        - Aumenta em 5 sempre que preenchido.

---

## Estrutura do Menu

1. Cadastrar disciplina
2. Cadastrar aluno
3. Cadastrar compromisso
4. Imprimir compromissos
    - a. De um aluno (ordenado por data e hora).
    - b. De todos os alunos (ordenado por RA, data e hora).
    - c. De uma data (ordenado por hora e RA).
    - d. De todas as datas (ordenado por data, hora e RA).
5. Imprimir dados de um aluno
6. Imprimir dados de todos os alunos (ordenado por RA)
7. Sair

---

## Observações Técnicas

- **Alocação Dinâmica**:
  - Funções específicas para alocar e realocar vetores de alunos e compromissos.

- **Ordenação**:
  - Utiliza a função `qsort` (disponível em `stdlib.h`) para ordenar vetores conforme critérios específicos.

- **Entradas Válidas**:
  - O programa utiliza funções para validar datas e horários antes de permitir o cadastro.

---

## Como Compilar e Executar

1. Compile o programa com um compilador C, como `gcc`:
    ```bash
    gcc -o gerenciamento_alunos main.c
    ```

2. Execute o programa:
    ```bash
    ./gerenciamento_alunos
    ```

---

## Requisitos do Ambiente

- Compilador C compatível com o padrão ANSI C (exemplo: GCC).
- Sistema operacional com suporte à biblioteca padrão C.
