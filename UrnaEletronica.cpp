#include <stdio.h>
#include <conio.h>
int main()
{
	int input, NV, V, SN, E, S;
	float PC1, PC2, PC3, PEB, PNULO, C1, C2, C3, NULO, EB, PC1B, PC2B, PC3B, PEBB, PNULOB;
	C1 = 0;
	C2 = 0;
	C3 = 0;
	EB = 0;
	NULO = 0;
	PNULO = 0.0;
	PC1 = 0.0;
	PC2 = 0.0;
	PC3 = 0.0;
	PEB = 0.0;
	SN = 0;
	S = 0;
	NV = 1;
	/* ESCOLHA */
	do
	{
		printf("Insira a senha\n");
		scanf("%d", &input);
		if (input == 4002)
		{
			/* SENHA */
			do
			{
				printf("1-Para votar\n2-Para sair\n");
				scanf("%d", &E);
				if (E == 1)
				{
					do
					{
						printf("Vote em um candidato:\n");
						printf("Leonidas 300\nOptimus Prime 42\nMickey Mouse 10\nEm Branco 00\n");
						scanf("%d", &V);
						if (V == 10)
						/* MICKEY */
						{
							do
							{
								printf("Voce votou em Mickey Mouse, confirmar?\n1 Sim\n2 Nao\n");
								scanf("%d", &SN);
								if (SN == 1)
								{
									C1 = C1 + 1;
									printf("Voto confirmado\n");
								}
								else
								{
									if (SN == 2)
										printf("Vote novamente,");
									else
										printf("Valor invalido,");
								}
							} while ((SN != 1) && (SN != 2));
						}
						/* Leonidas */
						else
						{
							if (V == 300)
							{
								do
								{
									printf("Voce votou em Leonidas, confirmar?\n1 Sim\n2 Nao\n");
									scanf("%d", &SN);
									if (SN == 1)
									{
										C2++;
										printf("Voto confirmado\n");
									}
									else
									{
										if (SN == 2)
											printf("Vote novamente,");
										else
											printf("Valor invalido,");
									}
								} while ((SN != 1) && (SN != 2));
							}
							/* Optimus */
							else
							{
								if (V == 42)
								{
									do
									{
										printf("Voce votou em Opitimus, confirmar?\n1 Sim\n2 Nao\n");
										scanf("%d", &SN);
										if (SN == 1)
										{
											C3++;
											printf("Voto confirmado\n");
										}
										else
										{
											if (SN == 2)
												printf("Vote novamente,");
											else
												printf("Valor invalido,");
										}
									} while ((SN != 1) && (SN != 2));
								}
								/* Branco */
								else
								{
									if (V == 00)
									{
										do
										{
											printf("Voto em Branco, confirmar?\n1 Sim\n2 Nao\n\n");
											scanf("%d", &SN);
											if (SN == 1)
											{
												EB++;
												printf("Voto confirmado\n");
											}
											else
											{
												if (SN == 2)
													printf("Vote novamente,");
												else
													printf("Valor invalido,");
											}
										} while ((SN != 1) && (SN != 2));
									}
									/* nulo */
									else
									{
										do
										{
											printf("Voto nulo, confirmar?\n 1 Sim\n2 Nao\n\n");
											scanf("%d", &SN);
											if (SN == 1)
											{
												NULO++;
												printf("Voto confirmado\n");
											}
											else
											{
												if (SN == 2)
													printf("Vote novamente,");
												else
													printf("Valor invalido,");
											}
										} while ((SN != 1) && (SN != 2));
									}
								}
							}
						}
					} while (SN == 2);
				}
				/* errou a senha e pediu para sair */
				else
				{
					if (E == 2)
					{
						do
						{
							printf("Insira a senha\n");
							scanf("%d", &input);
							if (input == 4002)
								printf("Saindo\n\n\n");
							else
								printf("Puxa! nao foi dessa vez,mas nao desista, tente novamente :(\n");
						} while (input != 4002);
					}
					else
						printf("Valor invalido\n");
				}
			} while (E != 2);
			/* errou a senha */
		}
		else
			printf("ERROOUUU, tente novamente\n");
	} while (input != 4002);
	/* escreva a quantidade de votos */
	S = C1 + C2 + C3 + EB + NULO;
	if (S != 0)
		NV = S;
	PC1 = C1 / NV * 100;
	PC2 = C2 / NV * 100;
	PC3 = C3 / NV * 100;
	PEB = EB / NV * 100;
	PNULO = NULO / NV * 100;
	PC1B = PC1;
	PC2B = PC2;
	PC3B = PC3;
	PEBB = PEB;
	PNULOB = PNULO;
	if ((PC1 > PC2) && (PC1 > PC3))
		PC1 = PC1 + PEB;
	else if ((PC2 > PC1) && (PC2 > PC3))
		PC2 = PC2 + PEB;
	else if ((PC3 > PC1) && (PC3 > PC2))
		PC3 = PC3 + PEB;
	else
	{
		PEB = PEB / 3;
		PC1 = PC1 + PEB;
		PC2 = PC2 + PEB;
		PC3 = PC3 + PEB;
	}
	if (S == 0)
		NV = 0;
	printf("Votos Mickey M = %.1f\n", C1);
	printf("Votos Leonidas = %.1f\n", C2);
	printf("Votos Optimus P = %.1f\n", C3);
	printf("Votos Nulo = %.1f\n", NULO);
	printf("Votos em Branco = %.1f\n", EB);
	printf("Quantidade de votos: %d\n\n\n", S);
	printf("Porcentagem anterior Mickey M = %.1f%%\n", PC1B);
	printf("Porcentagem anterior Leonidas = %.1f%%\n", PC2B);
	printf("Porcentagem anterior Optimus P = %.1f%%\n", PC3B);
	printf("Porcentagem anterior Nulo = %.1f%%\n", PNULOB);
	printf("Porcentagem anterior em branco = %.1f%%\n\n\n", PEBB);
	printf("Porcentagem Final Mickey M = %.1f%%\n", PC1);
	printf("Porcentagem Final Leonidas = %.1f%%\n", PC2);
	printf("Porcentagem Final Optimus P = %.1f%%\n", PC3);
	printf("Porcentagem Final Nulo = %.1f%%\n\n\n", PNULO);
	if ((PC1 > PC2) && (PC1 > PC3))
		printf("Mickey foi o vencedor com %.1f%% dos votos", PC1);
	if ((PC2 > PC1) && (PC2 > PC3))
		printf("Leonidas foi o vencedor com %.1f%% dos votos ", PC2);
	if ((PC3 > PC1) && (PC3 > PC2))
		printf("Optimus Prime foi o vencedor com %.1f%% dos votos", PC3);

	while (1)
		if (kbhit())
			break;
}
