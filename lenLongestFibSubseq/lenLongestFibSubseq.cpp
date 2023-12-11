#include <vector>
#include <algorithm>

class Solucao {
public:
    int lenLongestFibSubseq(std::vector<int>& a) {
        int n = a.size();
        // Matriz dp para armazenar o comprimento da subsequência Fibonacci-like
        // que termina em a[direita] e a[i].
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 2));
        int maximo = 0;

        // Itera sobre todos os elementos do array a partir do terceiro.
        for (int i = 2; i < n; i++) {
            int esquerda = 0, direita = i - 1;

            // Busca pares de índices (esquerda, direita) que formam uma subsequência Fibonacci-like.
            while (esquerda < direita) {
                int soma = a[esquerda] + a[direita];

                if (soma == a[i]) {
                    // Atualiza o comprimento da subsequência Fibonacci-like.
                    dp[direita][i] = dp[esquerda][direita] + 1;
                    // Verifica se é a maior subsequência até agora.
                    maximo = std::max(maximo, dp[direita][i]);
                    esquerda++;
                    direita--;
                } else if (soma < a[i]) {
                    esquerda++;
                } else {
                    direita--;
                }
            }
        }

        // Retorna o comprimento da maior subsequência.
        return maximo;
    }
};
