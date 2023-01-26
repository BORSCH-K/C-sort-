#include <stdio.h>
#include <string.h>

// слияние массива
void merge_words(char *orig, int *a, int *b, int *c, int n_1, int n_2){ 
// Объединяет два массива отсортированных по возрастанию в один массив
// a, b - объединяемые массивы, c - результат 
// в а передается индекс, который соответствует первому слову! в блоке (в b первому слову следущей пачки) 
// n_1 - количество слов для i, n_2 - количество слов для j
    // char s = ' ';
    int t; // индекс отличающихся элементов
	int i = 0, j = 0, k = 0; // самый левый неотсортированный элемент массива i для a, j для b; k_max = i+j, т.е. k - длина массива
	while((i < n_1) && (j < n_2)){ // пока в двух массивах есть неотрортированные элементы
    // коды: 'я' = -11889, '\0' = 0, ' ' = 32
        ////////// for (t = 0; a[t] == b[t] && a[t] != '\0' && b[t] != '\0'; t++); // поиск разных символов или слова, которое короче
        for (t = 0; orig[a[i] * 10 + t] == orig[b[j] * 10 + t] && orig[a[i] * 10 + t] != ' ' && orig[b[j] * 10 + t] != ' ' && t < 10; t++);
		if(orig[a[i] * 10 + t] < orig[b[j] * 10 + t]){ // запись минимального элемента массива
            // for(t = 0; t < 10; t++){
            c[k++] = a[i++];
            // }
        }
		else{
            // for(t = 0; t < 10; t++){
            c[k++] = b[j++];
            // }
        }
    }
	while(i < n_1) // когда элементы в b закончились - тупо записывает оставшиеся элементы a
        // for(t = 0; t < 10; t++){
        c[k++] = a[i++];
        // }
		// c[k++] = a[i++];
	while(j < n_2) // когда элементы в a закончились - тупо записывает оставшиеся элементы b
        // for(t = 0; t < 10; t++){
        c[k++] = b[j++];
                // c[k++] = a[i++];
        // }

}

// сортировка символов
void sort_words(char *orig, int *a, int *b, int n){
//  orig - начальный массив символов
//	a - сортируемый массив, b - промежуточный, n - количество элементов
    int i, num_blok = n, num_el = 1, num_el_end = 1;
    int k_1, k_2, j; // промежуточная переменная
    int z = 0; // индекс первого элемента последнего блока 
    int t = 1; // для printf - потом удалить
    // i - счетчик, num_blok - количество блоков/пачек, num_el - количество элементов в блоках, num_el_end - количество элементов в последнем блоке
    while(num_blok > 1){ // пока количество блоков больше 1, т.е. не один массив

        // printf("%i:\n", t++);
        // printf("_%i_\n", num_blok);
        if (num_blok % 2 == 1){ // при нечетном количестве блоков, 2 последних сливаются
            k_1 = (num_blok - 2) * num_el; // индекс первого элемента предпоследнего блока // 6
            k_2 = (num_blok - 1) * num_el; // индекс первого элемента последнего блока     // 8
            merge_words(orig, &a[k_1], &a[k_2], &b[k_1], num_el, num_el_end); // слияние пред- и последнего блоков
            num_el_end += num_el; // наращивание длины последнего блока
            num_blok--;

            z = k_1; // 6

            // printf("Нечетное количество блоков\n");
            // printf("k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", k_1, k_2, num_el_end, num_el);

            for(i = k_1; i < n; i++){ // запись отсортированных элементов
                    a[i] = b[i];
                    // printf("%c", a[i]);
            }
            // printf("----\n");

            // for(i = 0; i < n; i++){ // запись отсортированных элементов
            //         // a[i] = b[i];
            //         // printf("%c", a[i]);
            // }
            // printf("++++\n");
        }

		for(i = 0; i < num_blok/2; i--){ // слияние для четного количества блоков

            // k_1 = b[i] * num_el ; // индекс первого символа первого слова из блока
            // k_2 = b[i] * num_el + num_el; // индекс первого символа второго слова из блока

            k_1 = 2*i*num_el;          // индекс первого элемента первого блока из 2х рассматриваемых блоков
            k_2 = 2*i*num_el + num_el; // индекс первого элемента второго блока из 2х рассматриваемых блоков
            if (k_2 != z) // для блоков одинаковой длины
                merge_words(orig, &a[k_1], &a[k_2], &b[k_1], num_el, num_el); // обычное слияние с учетом длины последнего блока
            else{ // для блоков разной длины
                merge_words(orig, &a[k_1], &a[k_2], &b[k_1], num_el, num_el_end);
                z = k_1; // ?
            }
            // положения из одного массива, результат, количество элементов в a и b
            // printf("Четное количество блоков\n");
            // printf("i = %i, k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", i, k_1, k_2, num_el_end, num_el);
            // printf("num_blok = %i\n", num_blok);

            // for(j = 0; j < n; j++){ // запись отсортированных элементов
            //         // a[i] = b[i];
            //         printf("%c", b[j]);
            // }
            // printf("___\n");
		}

		for(i = 0; i < n; i++){ // запись отсортированных элементов
			a[i] = b[i];
            // printf("%c", a[i]);
		} 	
        // printf("...\n");

        num_el_end += num_el; // наращивание длины последнего блока
		num_el *= 2; // увеличение длины разбивки в 2 раза (Например, 0 1 | 2 3 | 4 5 | 6 7 => 0 1 2 3 | 4 5 6 7)
        num_blok = num_blok / 2 + num_blok % 2; // реальное количетво блоков
        // printf("num_blok = %i, num_el_end = %i, num_el = %i\n", num_blok, num_el_end, num_el);
    }		
}

// слияние массива
void merge_array(char *a, char *b, char *c, int n_1, int n_2){ 
// Объединяет два массива отсортированных по возрастанию в один массив
// a, b - объединяемые массивы, c - результат   ///, n - количество элементов в массивах а и b
// n_1 - количество элементов для i, n_2 - количество элементов для j
	int i = n_1, j = n_2, k = n_1 + n_2; // самый левый неотсортированный элемент массива i для a, j для b; k_max = i+j, т.е. k - длина массива
	while((i > 0) && (j > 0)){ // пока в двух массивах есть неотрортированные элементы
		if(a[i] > b[j]) // запись минимального элемента массива
			c[k--] = a[i--];
		else
			c[k--] = b[j--];
    }
	while(i > 0) // когда элементы в b закончились - тупо записывает оставшиеся элементы a
		c[k--] = a[i--];
	while(j > 0) // когда элементы в a закончились - тупо записывает оставшиеся элементы b
		c[k--] = b[j--];
}

// сортировка символов
void sort_merge(char *a, char *b, int n){
//	a - сортируемый массив, b - промежуточный, n - количество элементов
    int i, num_blok = n, num_el = 1, num_el_end = 1;
    int k_1, k_2, j; // промежуточная переменная
    int z = 0; // индекс первого элемента последнего блока 
    // int t = 1; // для printf - потом удалить
    // i - счетчик, num_blok - количество блоков/пачек, num_el - количество элементов в блоках, num_el_end - количество элементов в последнем блоке
    while(num_blok > 1){ // пока количество блоков больше 1, т.е. не один массив

        // printf("%i:\n", t++);
        // printf("_%i_\n", num_blok);
        if (num_blok % 2 == 1){ // при нечетном количестве блоков, 2 последних сливаются
            k_1 = (num_blok - 2) * num_el; // индекс первого элемента предпоследнего блока // 6
            k_2 = (num_blok - 1) * num_el; // индекс первого элемента последнего блока     // 8
            merge_array(&a[k_1], &a[k_2], &b[k_1], num_el, num_el_end); // слияние пред- и последнего блоков
            num_el_end += num_el; // наращивание длины последнего блока
            num_blok--;

            z = k_1; // 6

            // printf("Нечетное количество блоков\n");
            // printf("k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", k_1, k_2, num_el_end, num_el);

            for(i = k_1; i < n; i++){ // запись отсортированных элементов
                    a[i] = b[i];
                    // printf("%c", a[i]);
            }
            // printf("----\n");

            // for(i = 0; i < n; i++){ // запись отсортированных элементов
            //         // a[i] = b[i];
            //         // printf("%c", a[i]);
            // }
            // printf("++++\n");
        }

		for(i = num_blok/2; i > 0 ; i--){ // слияние для четного количества блоков
 
            k_1 = n - (2*i*num_el + num_el);

            k_1 = 2*i*num_el - num_el + 1; // индекс последнего элемента предпоследнего блока из 2х рассматриваемых
            k_2 = 2*i*num_el;  // индекс последнего элемента последнего блока из 2х рассматриваемых 
            if (k_1 != z) // для блоков одинаковой длины
                merge_array(&a[k_1], &a[k_2], &b[k_1], num_el, num_el); // обычное слияние с учетом длины последнего блока
            else{ // для блоков разной длины
                merge_array(&a[k_1], &a[k_2], &b[k_1], num_el, num_el_end);
                z = k_2;
            }
            // положения из одного массива, результат, количество элементов в a и b
            // printf("Четное количество блоков\n");
            // printf("i = %i, k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", i, k_1, k_2, num_el_end, num_el);
            // printf("num_blok = %i\n", num_blok);

            // for(j = 0; j < n; j++){ // запись отсортированных элементов
            //         // a[i] = b[i];
            //         printf("%c", b[j]);
            // }
            // printf("___\n");
		}

		for(i = 0; i < n; i++){ // запись отсортированных элементов
			a[i] = b[i];
            // printf("%c", a[i]);
		} 	
        // printf("...\n");

        num_el_end += num_el; // наращивание длины последнего блока
		num_el *= 2; // увеличение длины разбивки в 2 раза (Например, 0 1 | 2 3 | 4 5 | 6 7 => 0 1 2 3 | 4 5 6 7)
        num_blok = num_blok / 2 + num_blok % 2; // реальное количетво блоков
        // printf("num_blok = %i, num_el_end = %i, num_el = %i\n", num_blok, num_el_end, num_el);
    }		
}

void main(){

    // изначальный массив // неповтонимый оригинал
    char orig_array[10][10] = {
                                // "9876543210",
                                "автор", 
                                "товар",
                                "отвар",
                                // "09867",
                                "апельсин",
                                "спаниель",
                                "тавро",
                                "моль",
                                "соль",
                                "лось",
                                "табуретка"}; // <-- ошибка
    char copy_array[10][10]; // промежуточный массив // жалкая пародия
    char temp_array[10][10]; // сортируемый массив // результат
    int ind[10] = {0,1,2,3,4,5,6,7,8,9}; // индексы слов, которым соответствуют слова из orig_array[][]
    int temp_ind[10] = {0,1,2,3,4,5,6,7,8,9};

    char words_array[10][10];

    int i, j; // универсальные счетчики

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++){
            copy_array[i][j] = orig_array[i][j];
            // words_array[i][j] = orig_array[i][j];
        }



    int num_word; //num_word - счетчик слов
    int words = 10; // количество слов

    for(num_word = 0; num_word < words; num_word++) {	// сортировка для каждого слова
        for (i = 0; i < 10; i++)
        // for (i = 0; orig_array[num_word][i] != '\0'; i++) // вывод оригинального слова
            printf("%c", orig_array[num_word][i]);
		printf("\n");
                    

        // сортировка букв
        sort_merge(copy_array[num_word], temp_array[num_word], strlen(copy_array[num_word])+1);

                   
        for (i = 0; /*copy_array[num_word][i] != '\0' &&*/ i < 10; i++) // вывод отсортированного слова
            printf("%c", copy_array[num_word][i]);
        printf("\n\n");
	}

    // сортировка слов
    // sort_words(&copy_array[0][0], &ind[0], &temp_ind[0], 10);

    // for (i = 0; i < 10; i++){ // вывод отсортированных слов по алфавиту
    //     for(j = 0; j < 10; j++)
    //         printf("%c", copy_array[ind[i]][j]);
    //     printf(" - ");
    //     for(j = 0; j < 10; j++)
    //         printf("%c", orig_array[ind[i]][j]);
    //     printf("\n");
    // } 
        
    // printf("\n");

    // int t; // счетчик
    // int k; // количество совпадений в словах
    // int u = 0; // определитель для первого слова для каждой их анаграмм

    // printf("Анаграммы:\n");
    // for (i = 0; i < 9; i++){ // вывод отсортированных слов по алфавиту
    //     for(j = 0; copy_array[ind[i]][j] == copy_array[ind[i+1]][j] && j < 10; j++);// если начальные символы 2 соседних слов совподают
    //         // u = 0;
    //     if (j == 10){
    //         while (j == 10){
    //             if (u == 0){
    //                 for (t = 0; (orig_array[ind[i]][t] != '\0') && (t < 10); t++) // вывод одного слова
    //                     printf("%c", orig_array[ind[i]][t]);
    //                 u = 1; // уже не первое слово
    //             }
    //             else{
    //                 printf(" - ");
    //                 for (t = 0; (orig_array[ind[i]][t] != '\0') && (t < 10); t++) // вывод одного слова
    //                     printf("%c", orig_array[ind[i]][t]);
    //             }
    //             i++;
    //             for(j = 0; copy_array[ind[i]][j] == copy_array[ind[i+1]][j] && j < 10; j++);
    //         }
    //         printf(" - ");
    //         for (t = 0; orig_array[ind[i]][t] != '\0' && t < 10; t++) // вывод одного слова
    //             printf("%c", orig_array[ind[i]][t]);
    //         u = 0; // будет ввывод первого слова, т.е. без "-" перед словом
    //         printf("\n");
    //         for(j = 0; copy_array[ind[i]][j] == copy_array[ind[i+1]][j] && j < 10; j++);
    //     }
        
    // } 

}