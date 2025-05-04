#include <stdio.h>
#include <string.h>
#define MAXN 1000010

// �����໰����
char swear_words[6][10] = {"ɵ��", "������", "�����", "fuck", "shit", "asshole"};
int kmp[MAXN];
int j;
char a[MAXN];

// ����ַ��� b �Ƿ����ַ��� a ���Ӵ�
int check_swearing(const char* a, const char* b) {
    int la = strlen(a);
    int lb = strlen(b);

    // ���� KMP �� next ����
    j = 0;
    for (int i = 1; i < lb; i++) {
        while (j > 0 && b[i] != b[j]) {
            j = kmp[j - 1];
        }
        if (b[j] == b[i]) {
            j++;
        }
        kmp[i] = j;
    }

    j = 0;
    for (int i = 0; i < la; i++) {
        while (j > 0 && b[j] != a[i]) {
            j = kmp[j - 1];
        }
        if (b[j] == a[i]) {
            j++;
        }
        if (j == lb) {
            return 0; // �ҵ��໰������ 0
        }
    }
    return 1; // δ�ҵ��໰������ 1
}
int find_swearing(){
	int found = 0;
    for (int i = 0; i < 6; i++) {
        if (check_swearing(a, swear_words[i]) == 0) {
            found = 1;
            break;
        }
    }
    return found;
} 


int main() {
    // ��ȡ�ַ��� a
    printf("��Ϣ��");
    fgets(a, MAXN, stdin);
    a[strcspn(a, "\n")] = 0;  // ȥ�����з�
    if (find_swearing()) {
        printf("������Ϣ�����跢��\n");
    } else {
        printf("��Ϣ�ɷ���\n");
    }

    return 0;
}    
