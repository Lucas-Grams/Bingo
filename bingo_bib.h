// Biblioteca para o jogo bingo_em_C ==>

void sorteio(int cartela1[3][5], int cartela2[3][5], int cartela3[3][5], char player1[30], char player2[30], char player3[30])
{
	int num[6][10], num_sort[6][10], cont[3], existe = 0, winner = 0;
	srand(time(NULL));

	for (int i = 0; i < 3; i++)	// laço para zerar o vetor contador dos players.
	{
		cont[i] = 0;
	}

	for (int x = 0; x < 6; x++)	// matriz para gerar os 60 números aleatórios.
	{
		for (int y = 0; y < 10; y++)
		{
			num[x][y] = rand() % 60 + 1;

			for (int p = 0; p < 6; p++)	// matriz para verificar a existência de um número já sorteado na cartela resposta.
			{
				for (int w = 0; w < 10; w++)
				{
					if (num[x][y] == num_sort[p][w])	// condicional que compara se "num" existe  em "num_sort"(cartela resposta).
					{
						existe = 1;	// se hover um número repetido, retorna um;
					}

					while (existe == 1)	// se retornar um, então sorteia um novo número até continuar zero e sair do "while".
					{
						existe = 0;
						num[x][y] = rand() % 60 + 1;
						for (int r = 0; r < 6; r++)	// matriz para verificar novamente se existe "num" na cartela resposta.
						{
							for (int s = 0; s < 10; s++)
							{
								if (num[x][y] == num_sort[r][s])
								{
									existe = 1;
								}
							}
						}
					}
				}
			}

			num_sort[x][y] = num[x][y];	// atribui "num" para "num_sort"(cartela respota).
		}
	}

	while (winner == 0)	// laço para controlar o(s) ganhador(es).
	{
		for (int i = 0; i < 6; i++)	// matriz que printa o "num_sort"
		{
			for (int j = 0; j < 10; j++)
			{
				printf("\n");
				printf("numero sorteado: %d\n", num_sort[i][j]);

				for (int p = 0; p < 3; p++)	// matriz que printa as cartelas dos players e verifica se "num_sort" existe nas cartelas dos players.
				{
					for (int w = 0; w < 5; w++)
					{
						if (num_sort[i][j] == cartela1[p][w])	// condicional que controla a existência de "num_sort" em "cartela(1,2,3).
						{
							cont[0]++;	// vetor contador para os números existentes na cartela do  player.
							cartela1[p][w] = 0;	// se houver "num_sort", marca zero
							if (cont[0] == 15)	// condicional que diz que: se contador chegar a 15(preencher a cartela do player), o player ganha
							{
								printf("BINGOOO JOGADOR 1 VENCEU - ");
								puts(player1);
								winner = 1;	// Variável que controla a saída do laço "while".
							}
						}

						if (num_sort[i][j] == cartela2[p][w])
						{
							cont[1]++;
							cartela2[p][w] = 0;
							if (cont[1] == 15)
							{
								printf("BINGOOO JOGADOR 2 VENCEU - ");
								puts(player2);
								winner = 1;
							}
						}

						if (num_sort[i][j] == cartela3[p][w])
						{
							cont[2]++;
							cartela3[p][w] = 0;
							if (cont[2] == 15)
							{
								printf("BINGOOO JOGADOR 3 VENCEU - ");
								puts(player3);
								winner = 1;
							}
						}
					}
				}

				printf("\n");

				puts(player1);	// printa o nick player.
				for (int k = 0; k < 3; k++)	// printa a cartela do respectivo player acima para mostrar onde se preenchem os zeros.
				{
					for (int l = 0; l < 5; l++)
					{
						printf("%d\t", cartela1[k][l]);
					}

					printf("\n");
				}

				printf("\n");
				puts(player2);
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 5; l++)
					{
						printf("%d\t", cartela2[k][l]);
					}

					printf("\n");
				}

				printf("\n");
				puts(player3);
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 5; l++)
					{
						printf("%d\t", cartela3[k][l]);
					}

					printf("\n");
				}

				printf("cont A: %d\n", cont[0]);	// contabiliza os acertos de cada player.
				printf("cont B: %d\n", cont[1]);
				printf("cont C: %d\n", cont[2]);

				if (winner == 1)	//  condicional que controla o fim do bingo.
				{
					break;
				}

				getchar();
				system("clear");

			}
		}
	}
}

void cartelas(char player1[30], char player2[30], char player3[30])
{
	int cartela1[3][5], cartela2[3][5], cartela3[3][5];
	srand(time(NULL));

	for (int i = 0; i < 3; i++)	// matriz para jogar os números aleatórios para dentro das cartelas dos players.
	{
		for (int j = 0; j < 5; j++)
		{
			cartela1[i][j] = 0;
			cartela1[i][j] = rand() % 60 + 1;	// ran() responável por gerar números aleatórios ente 1 e 60.

		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cartela2[i][j] = 0;
			cartela2[i][j] = rand() % 60 + 1;

		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cartela3[i][j] = 0;
			cartela3[i][j] = rand() % 60 + 1;

		}
	}

	puts(player1);	// print do player e abaixo o print da sua respectiva cartela.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", cartela1[i][j]);
		}

		printf("\n");
	}

	getchar();
	puts(player2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", cartela2[i][j]);
		}

		printf("\n");
	}

	getchar();
	puts(player3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", cartela3[i][j]);
		}

		printf("\n");
	}

	getchar();

	sorteio(cartela1, cartela2, cartela3, player1, player2, player3);	// chama a função sorteio e passa por parâmetro as três cartelas e os players(nicks).

}

void bingo()
{
	char player1[30], player2[30], player3[30], codename1[15], codename2[15];
	int retorno;
	srand(time(NULL));

	printf("Insira o nick do player 1:");	// leitura dos players.
	gets(player1);	// entrada da string player.
	printf("Insira o nick do player 2:");
	gets(player2);
	printf("Insira o nick do player 3:");
	gets(player3);

	retorno = strcmp(player1, player2);
	if (retorno == 0)	// condicional para verificar se há nicks repetidos.
	{
		printf("Nick repetido, player 2 adicione um codenome:");
		gets(codename1);
		strcat(player2, codename1);
	}

	retorno = strcmp(player3, player1);
	if (retorno == 0)
	{
		printf("Nick repetido, player 3 adicione um codenome:");
		gets(codename2);
		strcat(player3, codename2);
	}

	retorno = strcmp(player3, player2);
	if (retorno == 0)
	{
		printf("Nick repetido, player 3 adicione um codenome:");
		gets(codename2);
		strcat(player3, codename2);
	}

	cartelas(player1, player2, player3);	// chama a função cartela e passa os nicks dos players por parâmetro.
}