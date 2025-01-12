typedef struct
{
	int dia;
	int mes;
	int ano;
} td_data;

typedef struct
{
	int hora;
	int min;
} td_hora;

typedef struct
{
	int codigo_dis;
	char disciplina[100];
	float notas[4];
	float media;
} td_disciplina;

typedef struct
{
	int ra;
	char nome[100];
	td_data matrícula;
	td_disciplina disciplinas[4];
	char email[100];
} td_aluno;

typedef struct
{
	td_aluno aluno;
	td_hora horario;
	td_data data;
	char descricao[300];
} td_compromisso;
