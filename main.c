#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/functions.h"

int main()
{
	unsigned short opcao;
	td_aluno alunos[10];
	td_compromisso compromissos[15];
	unsigned short tamanho_vetor_alunos = 10;
	unsigned short indice_vetor_alunos = 0;
	unsigned short tamanho_vetor_compromissos = 15;
	unsigned short indice_vetor_compromissos = 0;

	while (opcao != 6)
	{
		imprime_menu(&opcao);

		switch (opcao)
		{
		case 1:
			cadastra_aluno(alunos, &indice_vetor_alunos);
			break;
		case 2:
			if (indice_vetor_alunos == 0)
			{
				printf("\nNenhum aluno cadastrado.\n");
				pause();
				break;
			}

			cadastra_compromisso(compromissos, alunos, indice_vetor_alunos, &indice_vetor_compromissos);

			break;
		case 3:
			imprime_compromissos(compromissos, indice_vetor_compromissos);
			break;
		case 4:
		{
			clear();

			unsigned int ra;

			printf("Digite o RA do aluno: ");
			scanf("%u", &ra);

			for (int i = 0; i < indice_vetor_alunos; i++)
			{
				if (alunos[i].ra == ra)
				{
					imprime_aluno(alunos[i]);
					pause();
					break;
				}

				if (i == indice_vetor_alunos - 1)
				{
					printf("\nAluno não encontrado.");
					pause();
					break;
				}
			}
		}
		break;

		case 5:
			imprime_alunos(alunos, indice_vetor_alunos);
			pause();
			break;

		case 6:
			break;

		default:
			printf("\nOpção inválida!\n");
			pause();
			break;
		}

		if (indice_vetor_alunos != 0 && indice_vetor_alunos % 10 == 0)
		{
			tamanho_vetor_alunos += 10;
			realoca_vetor_alunos(alunos, tamanho_vetor_alunos);
		}

		if (indice_vetor_compromissos != 0 && indice_vetor_compromissos % 15 == 0)
		{
			indice_vetor_compromissos += 5;
			realoca_vetor_compromissos(compromissos, tamanho_vetor_compromissos);
		}
	}

	return 0;
}