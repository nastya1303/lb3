#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    bool task = true;
    int choose = 0, idz = 0, idzChoose = -1;

    while (choose != -1) {
        cout << "\n\n\nИз данных заданий, выберете то, которое хотите выполнить: \n"
                "1.Программа, которая используя арифметику указателей, заполняет квадратичную целочисленную матрицу порядка N (6,8,10) случайными числами от 1 до  N*N согласно схемам.\n"
                "2.Программа, которая получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами.\n"
                "3.Программа, которая используя арифметику указателей, сортирует элементы пузырьком.\n"
                "4.Программа, которая уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число.\n"
                "5.Идивидуальное домашнее задание.\n\n\n";

        cout << "Задание: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 and choose != 5 and choose != 0)
            cout << "Такого варианта ответа нет \n";

        else
            switch (choose) {
                case 0: {
                    cout << "Пока \n\n";
                    choose = -1;
                    break;
                }

                case 1: {
                    int N;
                    cout << "Выберете размер матрицы(6,8,10): ";
                    cin >> N;
                    int arr[N][N];

                    srand(time(NULL));

                    int *ptr = &arr[0][0];

                    for (int i = 0; i < N * N; i++) {
                        //*(ptr + i) = 0;
                        *(ptr + i) = rand() % (N * N) + 1;
                    }

                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << "\n";

                    int Xstr = 0, Xfin = 0, Ystr = 0, Yfin = 0;

                    int k = 1;
                    int i = 0;
                    int j = 0;

                    while (k <= N * N) {
                        *(ptr + (i * N + j)) = rand() % (N * N) + 1;
                        if (i == Xstr && j < N - Yfin - 1)
                            ++j;
                        else if (j == N - Yfin - 1 && i < N - Xfin - 1)
                            ++i;
                        else if (i == N - Xfin - 1 && j > Ystr)
                            --j;
                        else
                            --i;

                        if ((i == Xstr + 1) && (j == Ystr) && (Ystr != N - Yfin - 1)) {
                            ++Xstr;
                            ++Xfin;
                            ++Ystr;
                            ++Yfin;
                        }
                        ++k;
                    }

                    for (int x = 0; x < N; ++x) {
                        for (int y = 0; y < N; ++y)
                            cout << arr[x][y] << " ";
                        cout << "\n";
                    }
                    cout << "\n" << "\n";


                    for (int i = 0; i < N * N; i++) {
                        //*(ptr + i) = 0;
                        *(ptr + i) = rand() % (N * N) + 1;
                    }
                    for (int x = 0; x < N; ++x) {
                        for (int y = 0; y < N; ++y)
                            cout << arr[x][y] << " ";
                        cout << "\n";
                    }
                    cout << "\n";
                    for (int ik = 0; ik < N; ik++) {
                        for (int jk = 0; jk < N; jk++) {
                            int value = ik * N + jk + 1;

                            Настя, [15.12.2023, 20:57:48]:
                            if (ik % 2 == 0) {
                                *(ptr + jk * N + ik) = value;
                            } else {
                                *(ptr + ((N - jk - 1) * N + ik)) = value;
                            }
                        }
                    }
                    for (int x = 0; x < N; ++x) {
                        for (int y = 0; y < N; ++y)
                            cout << arr[x][y] << " ";
                        cout << "\n";
                    }
                    break;
                }

                case 2: {
                    int N;
                    cout << "Выберете размер матрицы(6,8,10): ";
                    cin >> N;
                    int arr[N][N];

                    srand(time(NULL));

                    int *ptr = &arr[0][0];

                    for (int i = 0; i < N * N; i++) {
                        //*(ptr + i) = i+1;
                        *(ptr + i) = rand() % (N * N) + 1;
                    }

                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << '\n';

                    int copya[N][N];
                    int *ptra = &copya[0][0];
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptra + i * N + (j + N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptra + (i + N / 2) * N + j) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptra + i * N + (j - N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptra + (i - N / 2) * N + j) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << copya[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << '\n';


                    int copyb[N][N];
                    int *ptrb = &copyb[0][0];
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptrb + (i + N / 2) * N + (j + N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptrb + (i - N / 2) * N + (j - N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N/2; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptrb + (i + N / 2) * N + (j - N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = 0; j < N/2; j++) {
                            *(ptrb + (i - N / 2) * N + (j + N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << copyb[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << '\n';

                    
                    int copyc[N][N];
                    int *ptrc = &copyc[0][0];
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptrc + (i + N / 2) * N + j) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptrc + (i - N / 2) * N + j) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptrc + (i - N / 2) * N + j) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptrc + (i + N / 2) * N + j) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << copyc[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << '\n';


                    int copyd[N][N];
                    int *ptrd = &copyd[0][0];
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptrd + i * N + (j + N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N / 2; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptrd + i * N + (j - N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = N / 2; j < N; j++) {
                            *(ptrd + i * N + (j - N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = N / 2; i < N; i++) {
                        for (int j = 0; j < N / 2; j++) {
                            *(ptrd + i * N + (j + N / 2)) = *(ptr + i * N + j);
                        }
                    }
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << copyd[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break;
                }

                case 3: {
                    int N;
                    cout << "Выберете размер матрицы(6,8,10): ";
                    cin >> N;
                    int arr[N][N];

                    srand(time(NULL));

                    int *ptr = &arr[0][0];

                    for (int i = 0; i < N * N; i++) {
                        //*(ptr + i) = i+1;
                        *(ptr + i) = rand() % (N * N) + 1;
                    }

                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << '\n';
                    for (int i = 0; i < N * N; i++) {
                        for (int j = 0; j < N * N - 1 - i; j++) {
                            if (*(ptr + j) > *(ptr + j + 1)) {
                                int arr1 = *(ptr + j);
                                *(ptr + j) = *(ptr + j + 1);
                                *(ptr + j + 1) = arr1;
                            }
                        }
                    }
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break;
                }

                case 4: {
                    int N = 0;
                    cout << "Выберете размер матрицы(6,8,10): ";
                    cin >> N;
                    int my_number = 0;
                    char sign = 0;
                    cout << "Введите число: ";
                    std::cin >> my_number;
                    cout << "Введите знак операции: ";
                    std::cin >> sign;
                    int arr[N][N];

                    srand(time(NULL));

                    int *ptr = &arr[0][0];

                    for (int i = 0; i < N * N; i++) {
                        //*(ptr + i) = i + 1;
                        *(ptr + i) = rand() % (N * N) + 1;
                    }

                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    cout << "\n";

                    switch (sign) {
                        case '+': {
                            for (int i = 0; i < N; i++) {
                                for (int j = 0; j < N; j++) {
                                    arr[i][j] += my_number;
                                    std::cout << arr[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                            break;
                        }
                        case '-': {
                            for (int i = 0; i < N; i++) {
                                for (int j = 0; j < N; j++) {
                                    arr[i][j] -= my_number;
                                    std::cout << arr[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                            break;
                        }
                        case '/': {
                            for (int i = 0; i < N; i++) {
                                for (int j = 0; j < N; j++) {
                                    arr[i][j] /= my_number;
                                    std::cout << arr[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                            break;
                        }
                        case '*': {
                            for (int i = 0; i < N; i++) {
                                for (int j = 0; j < N; j++) {
                                    arr[i][j] *= my_number;
                                    std::cout << arr[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                            break;
                        }

                    }
                    break;
                }

                case 5: {
                    int arr[3][3];
                    srand(time(0));
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            arr[i][j] = rand() % 61 - 30;
                        }
                    }
                    cout << "Полученная матрица:" << endl;
                    for(int i=0; i<3; i++){
                        for(int j=0; j<3; j++){
                            cout << arr[i][j] << " ";
                        }
                        cout << endl;
                    }
                    int det = arr[0][0] * arr[1][1] * arr[2][2] - arr[0][0] * arr[1][2] * arr[2][1]
                              - arr[0][1] * arr[1][0] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0]
                              + arr[0][2] * arr[1][0] * arr[2][1] - arr[0][2] * arr[1][1] * arr[2][0];
                    cout << "Определитель матрицы: " << det << endl;
                    break;
                }
            }
    }
    return 0;
}
