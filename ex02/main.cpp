// #include <iostream>
// #include <vector>
// #include <algorithm>

// // Fonction pour trier et fusionner des paires
// void fordJohnsonSort(std::vector<int>& vec) {
//     if (vec.size() <= 1) return;

//     // std::vector<int> temp(vec.size());
// 	std::vector<std::pair<int, int>> pairs; 
//     int n = vec.size();
//     int mid = n / 2;

//     // Étape 1 : Trier les paires
// 	for (int i = 0; i < mid; ++i) {
// 		if (vec[2 * i] > vec[2 * i + 1]) {
// 			std::swap(vec[2 * i], vec[2 * i + 1]);
// 		}
// 		pairs.emplace_back(vec[2 * i], vec[2 * i + 1]);
// 	}

// 	for (int i = 0; i < mid; ++i) {
// 		if (pairs[i].first > pairs[i + 1].first) {
// 			std::swap(vec[2 * i], vec[2 * i + 1]);
// 		}
// 		pairs.emplace_back(vec[2 * i], vec[2 * i + 1]);
// 	}

//     // Copier les premiers éléments triés dans le tableau temporaire
//     for (int i = 0; i < pairs; ++i) {
//         temp[i] = vec[2 * i];
//     }
//     if (n % 2 != 0) {
//         temp[pairs] = vec[n - 1]; // Ajouter le dernier élément si le nombre d'éléments est impair
//     }

//     // Étape 2 : Fusionner les éléments triés
//     for (int i = 0; i < pairs; ++i) {
//         temp[pairs + 1 + i] = vec[2 * i + 1];
//     }

//     std::inplace_merge(temp.begin(), temp.begin() + pairs + (n % 2), temp.end());

//     // Étape 3 : Réinsérer les éléments dans le vecteur original
//     for (int i = 0; i < n; ++i) {
//         vec[i] = temp[i];
//     }
// }

// int main() {
//     std::vector<int> data;
// 	data.push_back(38);
// 	data.push_back(27);
// 	data.push_back(43);
// 	data.push_back(3);
// 	data.push_back(9);
// 	data.push_back(82);
// 	data.push_back(10);

//     fordJohnsonSort(data);

//     for (std::vector<int>::iterator it = data.begin(); it != data.end(); it++)
// 	{
//         std::cout << *it << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

// Fonction pour fusionner deux vecteurs triés
void merge(std::vector<int> &result, const std::vector<int> &left, const std::vector<int> &right) {
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            ++i;
        } else {
            result.push_back(right[j]);
            ++j;
        }
    }
    // Ajout des éléments restants
    while (i < left.size()) {
        result.push_back(left[i]);
        ++i;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        ++j;
    }
}

// Fonction pour implémenter l'algorithme de tri Ford-Johnson
void fordJohnsonSort(std::vector<int> &arr) {
    if (arr.size() <= 1) return;

    // Diviser en paires
    std::vector<std::vector<int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(arr[i]);
        if (i + 1 < arr.size()) {
            pair.push_back(arr[i + 1]);
        }
        std::sort(pair.begin(), pair.end());
        pairs.push_back(pair);
    }

    // Fusionner les paires triées
    while (pairs.size() > 1) {
        std::vector<std::vector<int> > newPairs;
        for (size_t i = 0; i < pairs.size(); i += 2) {
            if (i + 1 < pairs.size()) {
                std::vector<int> merged;
                merge(merged, pairs[i], pairs[i + 1]);
                newPairs.push_back(merged);
            } else {
                newPairs.push_back(pairs[i]);
            }
        }
        pairs = newPairs;
    }

    // Copier le résultat final trié dans le vecteur original
    arr = pairs[0];
}

int main() {

    std::vector<int> arr;
	arr.push_back(38);
	arr.push_back(27);
	arr.push_back(43);
	arr.push_back(3);
	arr.push_back(9);
	arr.push_back(82);
	arr.push_back(10);

    std::cout << "Avant le tri: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    fordJohnsonSort(arr);

    std::cout << "Après le tri: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
