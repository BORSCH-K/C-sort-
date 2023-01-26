#include <stdio.h>
#include <string.h>

// ᫨ﭨ� ���ᨢ�
void merge_words(char *orig, int *a, int *b, int *c, int n_1, int n_2){ 
// ��ꥤ���� ��� ���ᨢ� �����஢����� �� �����⠭�� � ���� ���ᨢ
// a, b - ��ꥤ��塞� ���ᨢ�, c - १���� 
// � � ��।����� ������, ����� ᮮ⢥����� ��ࢮ�� ᫮��! � ����� (� b ��ࢮ�� ᫮�� ᫥��饩 ��窨) 
// n_1 - ������⢮ ᫮� ��� i, n_2 - ������⢮ ᫮� ��� j
    // char s = ' ';
    int t; // ������ �⫨������ ����⮢
	int i = 0, j = 0, k = 0; // ᠬ� ���� �������஢���� ����� ���ᨢ� i ��� a, j ��� b; k_max = i+j, �.�. k - ����� ���ᨢ�
	while((i < n_1) && (j < n_2)){ // ���� � ���� ���ᨢ�� ���� �������஢���� ������
    // ����: '�' = -11889, '\0' = 0, ' ' = 32
        ////////// for (t = 0; a[t] == b[t] && a[t] != '\0' && b[t] != '\0'; t++); // ���� ࠧ��� ᨬ����� ��� ᫮��, ���஥ ����
        for (t = 0; orig[a[i] * 10 + t] == orig[b[j] * 10 + t] && orig[a[i] * 10 + t] != ' ' && orig[b[j] * 10 + t] != ' ' && t < 10; t++);
		if(orig[a[i] * 10 + t] < orig[b[j] * 10 + t]){ // ������ �������쭮�� ����� ���ᨢ�
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
	while(i < n_1) // ����� ������ � b �����稫��� - �㯮 �����뢠�� ��⠢訥�� ������ a
        // for(t = 0; t < 10; t++){
        c[k++] = a[i++];
        // }
		// c[k++] = a[i++];
	while(j < n_2) // ����� ������ � a �����稫��� - �㯮 �����뢠�� ��⠢訥�� ������ b
        // for(t = 0; t < 10; t++){
        c[k++] = b[j++];
                // c[k++] = a[i++];
        // }

}

// ���஢�� ᨬ�����
void sort_words(char *orig, int *a, int *b, int n){
//  orig - ��砫�� ���ᨢ ᨬ�����
//	a - ����㥬� ���ᨢ, b - �஬������, n - ������⢮ ����⮢
    int i, num_blok = n, num_el = 1, num_el_end = 1;
    int k_1, k_2, j; // �஬����筠� ��६�����
    int z = 0; // ������ ��ࢮ�� ����� ��᫥����� ����� 
    int t = 1; // ��� printf - ��⮬ 㤠����
    // i - ���稪, num_blok - ������⢮ ������/��祪, num_el - ������⢮ ����⮢ � ������, num_el_end - ������⢮ ����⮢ � ��᫥���� �����
    while(num_blok > 1){ // ���� ������⢮ ������ ����� 1, �.�. �� ���� ���ᨢ

        // printf("%i:\n", t++);
        // printf("_%i_\n", num_blok);
        if (num_blok % 2 == 1){ // �� ���⭮� ������⢥ ������, 2 ��᫥���� ᫨������
            k_1 = (num_blok - 2) * num_el; // ������ ��ࢮ�� ����� �।��᫥����� ����� // 6
            k_2 = (num_blok - 1) * num_el; // ������ ��ࢮ�� ����� ��᫥����� �����     // 8
            merge_words(orig, &a[k_1], &a[k_2], &b[k_1], num_el, num_el_end); // ᫨ﭨ� �।- � ��᫥����� ������
            num_el_end += num_el; // ���騢���� ����� ��᫥����� �����
            num_blok--;

            z = k_1; // 6

            // printf("���⭮� ������⢮ ������\n");
            // printf("k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", k_1, k_2, num_el_end, num_el);

            for(i = k_1; i < n; i++){ // ������ �����஢����� ����⮢
                    a[i] = b[i];
                    // printf("%c", a[i]);
            }
            // printf("----\n");

            // for(i = 0; i < n; i++){ // ������ �����஢����� ����⮢
            //         // a[i] = b[i];
            //         // printf("%c", a[i]);
            // }
            // printf("++++\n");
        }

		for(i = 0; i < num_blok/2; i--){ // ᫨ﭨ� ��� �⭮�� ������⢠ ������

            // k_1 = b[i] * num_el ; // ������ ��ࢮ�� ᨬ���� ��ࢮ�� ᫮�� �� �����
            // k_2 = b[i] * num_el + num_el; // ������ ��ࢮ�� ᨬ���� ��ண� ᫮�� �� �����

            k_1 = 2*i*num_el;          // ������ ��ࢮ�� ����� ��ࢮ�� ����� �� 2� ��ᬠ�ਢ����� ������
            k_2 = 2*i*num_el + num_el; // ������ ��ࢮ�� ����� ��ண� ����� �� 2� ��ᬠ�ਢ����� ������
            if (k_2 != z) // ��� ������ ���������� �����
                merge_words(orig, &a[k_1], &a[k_2], &b[k_1], num_el, num_el); // ���筮� ᫨ﭨ� � ��⮬ ����� ��᫥����� �����
            else{ // ��� ������ ࠧ��� �����
                merge_words(orig, &a[k_1], &a[k_2], &b[k_1], num_el, num_el_end);
                z = k_1; // ?
            }
            // ��������� �� ������ ���ᨢ�, १����, ������⢮ ����⮢ � a � b
            // printf("��⭮� ������⢮ ������\n");
            // printf("i = %i, k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", i, k_1, k_2, num_el_end, num_el);
            // printf("num_blok = %i\n", num_blok);

            // for(j = 0; j < n; j++){ // ������ �����஢����� ����⮢
            //         // a[i] = b[i];
            //         printf("%c", b[j]);
            // }
            // printf("___\n");
		}

		for(i = 0; i < n; i++){ // ������ �����஢����� ����⮢
			a[i] = b[i];
            // printf("%c", a[i]);
		} 	
        // printf("...\n");

        num_el_end += num_el; // ���騢���� ����� ��᫥����� �����
		num_el *= 2; // 㢥��祭�� ����� ࠧ����� � 2 ࠧ� (���ਬ��, 0 1 | 2 3 | 4 5 | 6 7 => 0 1 2 3 | 4 5 6 7)
        num_blok = num_blok / 2 + num_blok % 2; // ॠ�쭮� �����⢮ ������
        // printf("num_blok = %i, num_el_end = %i, num_el = %i\n", num_blok, num_el_end, num_el);
    }		
}

// ᫨ﭨ� ���ᨢ�
void merge_array(char *a, char *b, char *c, int n_1, int n_2){ 
// ��ꥤ���� ��� ���ᨢ� �����஢����� �� �����⠭�� � ���� ���ᨢ
// a, b - ��ꥤ��塞� ���ᨢ�, c - १����   ///, n - ������⢮ ����⮢ � ���ᨢ�� � � b
// n_1 - ������⢮ ����⮢ ��� i, n_2 - ������⢮ ����⮢ ��� j
	int i = n_1, j = n_2, k = n_1 + n_2; // ᠬ� ���� �������஢���� ����� ���ᨢ� i ��� a, j ��� b; k_max = i+j, �.�. k - ����� ���ᨢ�
	while((i > 0) && (j > 0)){ // ���� � ���� ���ᨢ�� ���� �������஢���� ������
		if(a[i] > b[j]) // ������ �������쭮�� ����� ���ᨢ�
			c[k--] = a[i--];
		else
			c[k--] = b[j--];
    }
	while(i > 0) // ����� ������ � b �����稫��� - �㯮 �����뢠�� ��⠢訥�� ������ a
		c[k--] = a[i--];
	while(j > 0) // ����� ������ � a �����稫��� - �㯮 �����뢠�� ��⠢訥�� ������ b
		c[k--] = b[j--];
}

// ���஢�� ᨬ�����
void sort_merge(char *a, char *b, int n){
//	a - ����㥬� ���ᨢ, b - �஬������, n - ������⢮ ����⮢
    int i, num_blok = n, num_el = 1, num_el_end = 1;
    int k_1, k_2, j; // �஬����筠� ��६�����
    int z = 0; // ������ ��ࢮ�� ����� ��᫥����� ����� 
    // int t = 1; // ��� printf - ��⮬ 㤠����
    // i - ���稪, num_blok - ������⢮ ������/��祪, num_el - ������⢮ ����⮢ � ������, num_el_end - ������⢮ ����⮢ � ��᫥���� �����
    while(num_blok > 1){ // ���� ������⢮ ������ ����� 1, �.�. �� ���� ���ᨢ

        // printf("%i:\n", t++);
        // printf("_%i_\n", num_blok);
        if (num_blok % 2 == 1){ // �� ���⭮� ������⢥ ������, 2 ��᫥���� ᫨������
            k_1 = (num_blok - 2) * num_el; // ������ ��ࢮ�� ����� �।��᫥����� ����� // 6
            k_2 = (num_blok - 1) * num_el; // ������ ��ࢮ�� ����� ��᫥����� �����     // 8
            merge_array(&a[k_1], &a[k_2], &b[k_1], num_el, num_el_end); // ᫨ﭨ� �।- � ��᫥����� ������
            num_el_end += num_el; // ���騢���� ����� ��᫥����� �����
            num_blok--;

            z = k_1; // 6

            // printf("���⭮� ������⢮ ������\n");
            // printf("k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", k_1, k_2, num_el_end, num_el);

            for(i = k_1; i < n; i++){ // ������ �����஢����� ����⮢
                    a[i] = b[i];
                    // printf("%c", a[i]);
            }
            // printf("----\n");

            // for(i = 0; i < n; i++){ // ������ �����஢����� ����⮢
            //         // a[i] = b[i];
            //         // printf("%c", a[i]);
            // }
            // printf("++++\n");
        }

		for(i = num_blok/2; i > 0 ; i--){ // ᫨ﭨ� ��� �⭮�� ������⢠ ������
 
            k_1 = n - (2*i*num_el + num_el);

            k_1 = 2*i*num_el - num_el + 1; // ������ ��᫥����� ����� �।��᫥����� ����� �� 2� ��ᬠ�ਢ�����
            k_2 = 2*i*num_el;  // ������ ��᫥����� ����� ��᫥����� ����� �� 2� ��ᬠ�ਢ����� 
            if (k_1 != z) // ��� ������ ���������� �����
                merge_array(&a[k_1], &a[k_2], &b[k_1], num_el, num_el); // ���筮� ᫨ﭨ� � ��⮬ ����� ��᫥����� �����
            else{ // ��� ������ ࠧ��� �����
                merge_array(&a[k_1], &a[k_2], &b[k_1], num_el, num_el_end);
                z = k_2;
            }
            // ��������� �� ������ ���ᨢ�, १����, ������⢮ ����⮢ � a � b
            // printf("��⭮� ������⢮ ������\n");
            // printf("i = %i, k_1 = %i, k_2 = %i, num_el_end = %i, num_el = %i\n", i, k_1, k_2, num_el_end, num_el);
            // printf("num_blok = %i\n", num_blok);

            // for(j = 0; j < n; j++){ // ������ �����஢����� ����⮢
            //         // a[i] = b[i];
            //         printf("%c", b[j]);
            // }
            // printf("___\n");
		}

		for(i = 0; i < n; i++){ // ������ �����஢����� ����⮢
			a[i] = b[i];
            // printf("%c", a[i]);
		} 	
        // printf("...\n");

        num_el_end += num_el; // ���騢���� ����� ��᫥����� �����
		num_el *= 2; // 㢥��祭�� ����� ࠧ����� � 2 ࠧ� (���ਬ��, 0 1 | 2 3 | 4 5 | 6 7 => 0 1 2 3 | 4 5 6 7)
        num_blok = num_blok / 2 + num_blok % 2; // ॠ�쭮� �����⢮ ������
        // printf("num_blok = %i, num_el_end = %i, num_el = %i\n", num_blok, num_el_end, num_el);
    }		
}

void main(){

    // ����砫�� ���ᨢ // �����⮭��� �ਣ����
    char orig_array[10][10] = {
                                // "9876543210",
                                "����", 
                                "⮢��",
                                "�⢠�",
                                // "09867",
                                "�����ᨭ",
                                "ᯠ�����",
                                "⠢�",
                                "����",
                                "᮫�",
                                "����",
                                "⠡��⪠"}; // <-- �訡��
    char copy_array[10][10]; // �஬������ ���ᨢ // ������ ��த��
    char temp_array[10][10]; // ����㥬� ���ᨢ // १����
    int ind[10] = {0,1,2,3,4,5,6,7,8,9}; // ������� ᫮�, ����� ᮮ⢥������ ᫮�� �� orig_array[][]
    int temp_ind[10] = {0,1,2,3,4,5,6,7,8,9};

    char words_array[10][10];

    int i, j; // 㭨���ᠫ�� ���稪�

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++){
            copy_array[i][j] = orig_array[i][j];
            // words_array[i][j] = orig_array[i][j];
        }



    int num_word; //num_word - ���稪 ᫮�
    int words = 10; // ������⢮ ᫮�

    for(num_word = 0; num_word < words; num_word++) {	// ���஢�� ��� ������� ᫮��
        for (i = 0; i < 10; i++)
        // for (i = 0; orig_array[num_word][i] != '\0'; i++) // �뢮� �ਣ����쭮�� ᫮��
            printf("%c", orig_array[num_word][i]);
		printf("\n");
                    

        // ���஢�� �㪢
        sort_merge(copy_array[num_word], temp_array[num_word], strlen(copy_array[num_word])+1);

                   
        for (i = 0; /*copy_array[num_word][i] != '\0' &&*/ i < 10; i++) // �뢮� �����஢������ ᫮��
            printf("%c", copy_array[num_word][i]);
        printf("\n\n");
	}

    // ���஢�� ᫮�
    // sort_words(&copy_array[0][0], &ind[0], &temp_ind[0], 10);

    // for (i = 0; i < 10; i++){ // �뢮� �����஢����� ᫮� �� ��䠢���
    //     for(j = 0; j < 10; j++)
    //         printf("%c", copy_array[ind[i]][j]);
    //     printf(" - ");
    //     for(j = 0; j < 10; j++)
    //         printf("%c", orig_array[ind[i]][j]);
    //     printf("\n");
    // } 
        
    // printf("\n");

    // int t; // ���稪
    // int k; // ������⢮ ᮢ������� � ᫮���
    // int u = 0; // ��।���⥫� ��� ��ࢮ�� ᫮�� ��� ������ �� ����ࠬ�

    // printf("����ࠬ��:\n");
    // for (i = 0; i < 9; i++){ // �뢮� �����஢����� ᫮� �� ��䠢���
    //     for(j = 0; copy_array[ind[i]][j] == copy_array[ind[i+1]][j] && j < 10; j++);// �᫨ ��砫�� ᨬ���� 2 �ᥤ��� ᫮� ᮢ������
    //         // u = 0;
    //     if (j == 10){
    //         while (j == 10){
    //             if (u == 0){
    //                 for (t = 0; (orig_array[ind[i]][t] != '\0') && (t < 10); t++) // �뢮� ������ ᫮��
    //                     printf("%c", orig_array[ind[i]][t]);
    //                 u = 1; // 㦥 �� ��ࢮ� ᫮��
    //             }
    //             else{
    //                 printf(" - ");
    //                 for (t = 0; (orig_array[ind[i]][t] != '\0') && (t < 10); t++) // �뢮� ������ ᫮��
    //                     printf("%c", orig_array[ind[i]][t]);
    //             }
    //             i++;
    //             for(j = 0; copy_array[ind[i]][j] == copy_array[ind[i+1]][j] && j < 10; j++);
    //         }
    //         printf(" - ");
    //         for (t = 0; orig_array[ind[i]][t] != '\0' && t < 10; t++) // �뢮� ������ ᫮��
    //             printf("%c", orig_array[ind[i]][t]);
    //         u = 0; // �㤥� ��뢮� ��ࢮ�� ᫮��, �.�. ��� "-" ��। ᫮���
    //         printf("\n");
    //         for(j = 0; copy_array[ind[i]][j] == copy_array[ind[i+1]][j] && j < 10; j++);
    //     }
        
    // } 

}