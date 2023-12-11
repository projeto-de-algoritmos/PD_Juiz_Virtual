#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    // Função principal para calcular o tamanho máximo das fatias
    int maxSizeSlices(std::vector<int>& slices) {
        int n = slices.size();
        // Matriz para armazenar os resultados intermediários da programação dinâmica
        std::vector<std::vector<int>> dp(n, std::vector<int>(n/3 + 1, -1));

        // Calcula a soma máxima para o primeiro caso
        int caso1 = calcularRecursivo(0, n-2, n / 3, slices, dp);

        // Reinicia a matriz dp para o segundo caso
        for (auto& valor : dp)
            std::fill(valor.begin(), valor.end(), -1);

        // Calcula a soma máxima para o segundo caso
        int caso2 = calcularRecursivo(1, n-1, n / 3, slices, dp);

        // Retorna o máximo entre os dois casos
        return std::max(caso1, caso2);
    }

    // Função recursiva para calcular a soma máxima
    int calcularRecursivo(int i, int fim, int n, std::vector<int>& slices, std::vector<std::vector<int>>& dp) {
        // Verifica as condições de parada
        if (i > fim || n == 0) {
            return 0;
        }

        // Se o resultado já foi calculado, retorna o valor armazenado
        if (dp[i][n] != -1) return dp[i][n];

        // Escolhe a fatia atual e calcula recursivamente para as próximas slices
        int escolher = slices[i] + calcularRecursivo(i+2, fim, n-1, slices, dp);
        // Não escolhe a fatia atual e calcula recursivamente para as próximas slices
        int naoEscolher = 0 + calcularRecursivo(i+1, fim, n, slices, dp);

        // Armazena o resultado na matriz dp e retorna o máximo entre as escolhas
        return dp[i][n] = std::max(escolher, naoEscolher);
    }
};


