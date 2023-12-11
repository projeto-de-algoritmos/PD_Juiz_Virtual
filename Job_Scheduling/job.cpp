#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> jobs(n);

    // Criar um vetor 2D para armazenar o início, fim e lucro de cada trabalho
    for (int i = 0; i < n; i++) {
        jobs[i] = {startTime[i], endTime[i], profit[i]};
    }

    // Ordenar os trabalhos com base no tempo de término
    sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
    });

    // Vetor para armazenar o lucro máximo para cada trabalho
    vector<int> dp(n);
    dp[0] = jobs[0][2];

    // Iterar pelos trabalhos a partir do segundo
    for (int i = 1; i < n; i++) {
        int includeCurrent = jobs[i][2]; // Lucro se o trabalho atual for incluído
        int lastNonOverlapping = -1; // Índice do último trabalho que não se sobrepõe

        // Realizar uma busca binária para encontrar o último trabalho não sobreposto
        auto it = upper_bound(jobs.begin(), jobs.begin() + i, jobs[i][0],
            [](const int& val, const auto& job) {
                return val < job[1];
            });

        if (it != jobs.begin()) {
            lastNonOverlapping = distance(jobs.begin(), prev(it));
            includeCurrent += dp[lastNonOverlapping];
        }

        // Lucro se o trabalho atual for excluído
        int excludeCurrent = dp[i - 1];

        // Atualizar o vetor dp com o máximo entre incluir e excluir o trabalho atual
        dp[i] = max(includeCurrent, excludeCurrent);
    }

    // Retornar o lucro máximo calculado para o último trabalho no vetor dp
    return dp[n - 1];
}

};

