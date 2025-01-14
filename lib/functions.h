#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "td_structs.h"

bool valida_data(td_data data);
bool valida_horario(td_hora horario);
void pause();

void cadastra_aluno(td_aluno alunos[], unsigned short *indice)
{
	system("clear");
	printf("Nome do aluno ................: ");
	getchar();
	scanf("%[^\n]", &alunos[(int)*indice].nome);
	printf("RA ...........................: ");
	scanf("%u", &alunos[(int)*indice].ra);

	do
	{
		printf("Data de matrícula (dd/mm/aaaa): ");
		getchar();
		scanf("%d/%d/%d", &alunos[(int)*indice].matricula.dia, &alunos[(int)*indice].matricula.mes, &alunos[(int)*indice].matricula.ano);
	} while ((!valida_data(alunos[(int)*indice].matricula)));

	printf("E-mail .......................: ");
	scanf("%s", &alunos[(int)*indice].email);

	printf("Disciplinas ..................:\n");
	for (unsigned short i = 0; i < 4; i++)
	{
		float media = 0.0f;

		printf("	Disciplina ......: ");
		getchar();
		scanf("%[^\n]", &alunos[(int)*indice].disciplinas[i].disciplina);
		printf("	Código disciplina: ");
		scanf("%d", &alunos[(int)*indice].disciplinas[i].codigo_dis);

		printf("	Notas ...........:\n");
		for (unsigned short j = 0; j < 4; j++)
		{
			printf("		Nota %d: ", j + 1);
			scanf("%f", &alunos[(int)*indice].disciplinas[i].notas[j]);
			media += alunos[(int)*indice].disciplinas[i].notas[j];
		}

		media /= 4.0f;
		alunos[(int)*indice].disciplinas[i].media = media;
		printf("\n");
	}

	printf("\n");

	*indice = *indice + 1;
}

void cadastra_compromisso(td_compromisso compromissos[], td_aluno aluno[], unsigned short indice_alunos, unsigned short *indice_compromissos)
{
	unsigned int ra;

	system("clear");

	printf("Digite o RA do aluno: ");
	scanf("%u", &ra);

	for (int i = 0; i < indice_alunos; i++)
	{
		if (aluno[i].ra == ra)
		{
			printf("\nNome do aluno ..................: %s\n", aluno[i].nome);
			compromissos[*indice_compromissos].aluno = aluno[i];
			break;
		}

		if (i == indice_alunos - 1)
		{
			printf("\nAluno não encontrado!\n");
			pause();
			return;
		}
	}

	printf("Descrição do compromisso .......: ");
	getchar();
	scanf("%[^\n]", &compromissos[(int)*indice_compromissos].descricao);

	do
	{
		printf("Data do compromisso (dd/mm/aaaa): ");
		getchar();
		scanf("%02d/%02d/%04d", &compromissos[(int)*indice_compromissos].data.dia, &compromissos[(int)*indice_compromissos].data.mes, &compromissos[(int)*indice_compromissos].data.ano);
	} while ((!valida_data(compromissos[(int)*indice_compromissos].data)));

	do
	{
		printf("Hora do compromisso (hh:mm) ....: ");
		getchar();
		scanf("%02d:%02d", &compromissos[(int)*indice_compromissos].horario.hora, &compromissos[(int)*indice_compromissos].horario.min);
	} while ((!valida_horario(compromissos[(int)*indice_compromissos].horario)));

	*indice_compromissos = *indice_compromissos + 1;
}

void imprime_aluno(td_aluno aluno)
{
	printf("Nome ......: %s\n", aluno.nome);
	printf("RA ........: %d\n", aluno.ra);
	printf("matricula .: %02d/%02d/%04d\n", aluno.matricula.dia, aluno.matricula.mes, aluno.matricula.ano);
	printf("E-mail ....: %s\n", aluno.email);
	printf("Disciplinas:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\n	Código ...: %d\n", aluno.disciplinas[i].codigo_dis);
		printf("	Disciplina: %s\n", aluno.disciplinas[i].disciplina);

		printf("	Notas:\n");
		for (int j = 0; j < 4; j++)
			printf("		Nota %d: %0.2f\n", j + 1, aluno.disciplinas[i].notas[j]);

		printf("    	Média.....: %0.2f\n", aluno.disciplinas[i].media);
	}
}

int compara_alunos(const void *a, const void *b)
{
	const td_aluno *alunoA = (const td_aluno *)a;
	const td_aluno *alunoB = (const td_aluno *)b;

	return alunoA->ra - alunoB->ra;
}

void imprime_alunos(td_aluno alunos[], unsigned short n)
{
	system("clear");

	qsort(alunos, n, sizeof(td_aluno), compara_alunos);

	for (int i = 0; i < n; i++)
	{
		imprime_aluno(alunos[i]);

		if (i < n - 1)
			printf("---------------------------------------------------------------\n");
	}
}

void imprime_menu(unsigned short *opcao)
{
	system("clear");

	printf("1 - Cadastrar aluno\n");
	printf("2 - Cadastrar compromisso\n");
	printf("3 - Imprimir compromissos\n");
	printf("4 - Imprimir dados de um aluno\n");
	printf("5 - Imprimir os dados de todos os alunos\n");
	printf("6 - Sair\n");
	printf("\nEscolha uma opção: ");
	scanf("%d", opcao);
}

void imprime_menu_compromissos(char *opcao)
{
	printf("    a - de um aluno\n");
	printf("    b - de todos os alunos\n");
	printf("    c - de uma data\n");
	printf("    d - de todas as datas\n");
	printf("    e - retornar\n");
	printf("\nEscolha uma opção: ");
	scanf(" %c", opcao);
}

void imprime_compromisso(td_compromisso compromisso)
{
	printf("\nNome do aluno ..........: %s\n", compromisso.aluno.nome);
	printf("Descrição do compromisso: %s\n", compromisso.descricao);
	printf("Data do compromisso ....: %02d/%02d/%04d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
	printf("Hora do compromisso ....: %02d:%02d\n", compromisso.horario.hora, compromisso.horario.min);
}

int compara_compromissos_alunos(const void *a, const void *b)
{
	const td_compromisso *compromissoA = (const td_compromisso *)a;
	const td_compromisso *compromissoB = (const td_compromisso *)b;

	if (compromissoA->aluno.ra != compromissoB->aluno.ra)
		return compromissoA->aluno.ra - compromissoB->aluno.ra;

	if (compromissoA->data.ano != compromissoB->data.ano)
		return compromissoA->data.ano - compromissoB->data.ano;
	if (compromissoA->data.mes != compromissoB->data.mes)
		return compromissoA->data.mes - compromissoB->data.mes;
	if (compromissoA->data.dia != compromissoB->data.dia)
		return compromissoA->data.dia - compromissoB->data.dia;

	if (compromissoA->horario.hora != compromissoB->horario.hora)
		return compromissoA->horario.hora - compromissoB->horario.hora;

	return compromissoA->horario.min - compromissoB->horario.min;
}

int compara_compromissos_datas(const void *a, const void *b)
{
	const td_compromisso *compromissoA = (const td_compromisso *)a;
	const td_compromisso *compromissoB = (const td_compromisso *)b;

	if (compromissoA->data.ano != compromissoB->data.ano)
		return compromissoA->data.ano - compromissoB->data.ano;
	if (compromissoA->data.mes != compromissoB->data.mes)
		return compromissoA->data.mes - compromissoB->data.mes;
	if (compromissoA->data.dia != compromissoB->data.dia)
		return compromissoA->data.dia - compromissoB->data.dia;

	if (compromissoA->horario.hora != compromissoB->horario.hora)
		return compromissoA->horario.hora - compromissoB->horario.hora;

	if (compromissoA->horario.min != compromissoB->horario.min)
		return compromissoA->horario.min - compromissoB->horario.min;

	if (compromissoA->aluno.ra != compromissoB->aluno.ra)
		return compromissoA->aluno.ra - compromissoB->aluno.ra;
}

void imprime_compromissos(td_compromisso compromissos[], unsigned short n)
{
	char opcao;

	imprime_menu_compromissos(&opcao);

	if (opcao == 'a' || opcao == 'b')
		qsort(compromissos, n, sizeof(td_compromisso), compara_compromissos_alunos);

	if (opcao == 'c' || opcao == 'd')
		qsort(compromissos, n, sizeof(td_compromisso), compara_compromissos_datas);

	switch (opcao)
	{
	case 'a':
	{
		system("clear");

		unsigned int ra;
		bool tem_compromisso = false;

		system("clear");

		printf("Digite o RA do aluno: ");
		scanf("%u", &ra);

		for (int i = 0; i < n; i++)
		{
			if (compromissos[i].aluno.ra == ra)
			{
				if (i != 0)
					printf("---------------------------------------------------------------");

				tem_compromisso = true;
				imprime_compromisso(compromissos[i]);
			}
		}

		if (!tem_compromisso)
			printf("\nAluno sem compromissos!");

		pause();
	}
	break;
	case 'b':
		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				printf("---------------------------------------------------------------");

			imprime_compromisso(compromissos[i]);
		}

		pause();
		break;
	case 'c':
	{
		system("clear");

		td_data data;
		bool tem_compromisso = false;

		printf("Digite a data: ");
		do
		{
			scanf("%02d/%02d/%04d", &data.dia, &data.mes, &data.ano);
		} while (!(valida_data(data)));

		system("clear");
		for (int i = 0; i < n; i++)
		{
			if (compromissos[i].data.ano == data.ano && compromissos[i].data.mes == data.mes && compromissos[i].data.dia == data.dia)
			{
				if (i != 0)
					printf("---------------------------------------------------------------");

				tem_compromisso = true;
				imprime_compromisso(compromissos[i]);
			}

			if (i == n - 1 && !tem_compromisso)
			{
				printf("\nData sem compromissos!\n");
				pause();
			}
		}

		pause();
	}
	break;
	// case 'd':
	// 	imprime_compromissos_datas(compromissos, n);
	// break;
	case 'e':
		return;
	default:
		printf("\nOpção inválida!!!\n\n");
		pause();
		break;
	}
}

td_aluno *realoca_vetor_alunos(td_aluno alunos[], unsigned short tamanho)
{
	return realloc(alunos, (int)tamanho * sizeof(td_aluno));
}

td_compromisso *realoca_vetor_compromissos(td_compromisso compromissos[], unsigned short tamanho)
{
	return realloc(compromissos, (int)tamanho * sizeof(td_compromisso));
}

bool valida_data(td_data data)
{
	if (data.dia <= 0 || data.dia > 31 || data.mes <= 0 || data.mes > 12 || data.ano <= 1900 || data.ano >= 2100)
	{
		printf("\nData inválida!!!\n\n");
		return false;
	}

	return true;
}

bool valida_horario(td_hora horario)
{
	if (horario.hora < 0 || horario.hora > 23 || horario.min < 0 || horario.min > 59)
	{
		printf("\nHorário inválido!!!\n\n");
		return false;
	}

	return true;
}

void pause()
{
	getchar();
	getchar();
}
