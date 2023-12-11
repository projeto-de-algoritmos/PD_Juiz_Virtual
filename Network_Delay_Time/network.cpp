#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Inicializa um vetor para armazenar as distâncias mínimas de K para todos os nós
        vector<int> dist(N, INT_MAX);
        dist[K - 1] = 0; // A distância de K para K é 0

        // Aplica o algoritmo de Bellman-Ford
        for (int i = 0; i < N; ++i) {
            for (const auto& time : times) {
                if (dist[time[0] - 1] != INT_MAX && dist[time[0] - 1] + time[2] < dist[time[1] - 1]) {
                    dist[time[1] - 1] = dist[time[0] - 1] + time[2];
                }
            }
        }

        // Verifica a existência de ciclos negativos
        if (any_of(dist.begin(), dist.end(), [](int d) { return d == INT_MAX; })) {
            return -1;
        }

        // Retorna a distância máxima de K para qualquer outro nó
        return *max_element(dist.begin(), dist.end());
    }
};