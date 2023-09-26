#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>



int Brute_Force(char parent[], char child[]);
int countSpace(char *s);

void deleteSpaceHead(char *s);
void deleteSpaceTTail(char *s);
void deleteQ(char *s, int q);
void deleteSpaceBetween(char *s);
void standardizedString(char *s);

void changeChar(char *s);
void changeChuHoa(char *s);
void changeChuThuong(char *s);
char *tachChuoi(char *s, int dau, int cuoi);
void changeChar(char *s);

void tachChuoi(char *s, char *holot, char *ten);

void lietKe_TanSuat(char s[]);

void xoaKiTu(char s[], int k);
int xoaTuTrongChuoi(char s[], char word[]);

int main()
{
    char s[100];
    char *find;

    printf("\nNhap vao chuoi bat ki: ");
    fgets(s, sizeof(s), stdin);
    // Loại bỏ ký tự '\n' cuối cùng nếu tồn tại
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    // printf("\nSo khoang trang trong chuoi la: %d", countSpace(s));
    
    // standardizedString(s);

    // changeChar(s);

    // printf("\nChuoi: [%s]", s);

    // char holot[50];
    // char ten[20];
    // tachChuoi(s, holot, ten);
    // printf("\nChuoi ho va ten: %s", s);
    // printf("\nChuoi ho lot: %s", holot);
    // printf("\nChuoi ten: %s", ten);

    // lietKe_TanSuat(s);

    char word[100];
    printf("\nNhap tu muon xoa trong chuoi '%s': ", s);
    scanf("%s", word);

    if (xoaTuTrongChuoi(s, word) == 0)
    {
        printf("\nTrong mang khong ton tai chuoi %s", word);
    }
    else
    {
        printf("\nDa xoa thanh cong!\nChuoi hien tai la: %s", s);
    }

    return 1;


    // -------------------------------------
    /* char s[100]; // Mảng ký tự để lưu trữ chuỗi
    char *holot, *ten;

    printf("Nhap vao chuoi bat ki: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Loi khi nhap chuoi.\n");
        return 1;
    }

    // Loại bỏ ký tự '\n' cuối cùng nếu tồn tại
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    // Cấp phát bộ nhớ cho holot và ten
    holot = (char *)malloc(len + 1);
    ten = (char *)malloc(len + 1);

    if (holot == NULL || ten == NULL) {
        printf("Loi khi cap phat bo nho.\n");
        return 1;
    }

    // Tiến hành các xử lý khác như standardizedString và changeChar
    standardizedString(s);
    changeChar(s);

    printf("Chuoi: [%s]\n", s);

    // Gọi hàm tachChuoi
    tachChuoi(s, holot, ten);

    printf("Chuoi ho va ten: %s\n", s);
    printf("Chuoi ho lot: %s\n", holot);
    printf("Chuoi ten: %s\n", ten);

    // Giải phóng bộ nhớ
    free(holot);
    free(ten);

    return 0; */


}

// Tìm sâu con trong chuỗi
int Brute_Force(char parent[], char child[])
{
    int parent_len = strlen(parent);
    int child_len = strlen(child);

    int STOP = parent_len - child_len;
    int START = 0;
    while (START <= STOP)
    {
        int check = 0;
        while(check < child_len && parent[START + check] == child[check])
        {
            check ++;
        }

        if (check == child_len)
            return START;
        START ++;
    }

    return -1;
}

// Đếm bao nhiêu khoảng trắng trong chuỗi
int countSpace(char *s)
{
    int count = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == ' ')
            count ++;
    }

    return count;
}

// Xoá khoảng trắng thừa trong chuỗi
// Xoá đầu
void deleteSpaceHead(char *s)
{
    int n = strlen(s);
    int dotting = 0;

    while (s[dotting] == ' ')
    {
        dotting ++;
    }

    for(int i = 0; i < n - dotting; i ++)
    {
        s[i] = s[dotting + i];
    }
    s[n - dotting] = '\0';

}
// Xoá cuối
void deleteSpaceTTail(char *s)
{
    int n = strlen(s);
    while(s[n - 1] == ' ')
        n --;

    s[n] = '\0';
}
// Xoá giữa
void deleteQ(char *s, int q)
{
    int n = strlen(s);
    for (int i = q; i < n - 1; i ++)
    {
        s[i] = s[i + 1];
    }
    s[n - 1] = '\0';
}

void deleteSpaceBetween(char *s)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            deleteQ(s, i);
            i--;
        }
    }
}

void standardizedString(char *s)
{
    deleteSpaceHead(s);
    deleteSpaceTTail(s);
    deleteSpaceBetween(s);
}

// Đổi những kí tự đầu tiên của mỗi từ thành chữ in hoa và những từ không phải đầu câu sang chữ thường
void changeChuHoa(char *s)
{
    int n = strlen(s);
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 32;

    for(int i = 0; i < n; i ++)
    {
        if (s[i] == ' ' && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
            s[i + 1] -= 32;
    }
}

void changeChar(char *s)
{
    strlwr(s);
    changeChuHoa(s);
}

// Tìm kiếm tên trong chuỗi họ tên


// Cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
void tachChuoi(char *s, char *holot, char *ten)
{
    int ten_len = 0;
    int holot_len = 0;
    int s_len = strlen(s);

    int check = s_len - 1;
    while(s[check] != ' ')
    {
        check --;
    }

    for (int i = check + 1; i < s_len; i ++)
    {
        ten[ten_len] = s[i];
        ten_len ++;
    }
    ten[ten_len] = '\0';

    for(int i = 0; i <= check; i ++)
    {
        holot[holot_len] = s[i];
        holot_len ++;
    }
    holot[holot_len] = '\0'; 
}


// Liệt kê tần suất xuất hiện của mỗi kí tự trong chuỗi
void lietKe_TanSuat(char s[])
{
    int n = strlen(s);
    int a[256] = {0};

    for (int i = 0; i < n; i ++)
    {
        char curentChar = s[i];
        a[(int)curentChar] ++;
    }

    for (int i = 0; i < 256;  i ++)
    {
        if (a[i] > 0)
        {
            printf("\nKi tu '%c' xuat hien %d lan", (char)i, a[i]);
        }
    }
}

// Xoá 1 từ được yêu cầu trong chuỗi
void xoaKiTu(char s[], int k)
{
    int n = strlen(s);
    for (int i = k; i < n - 1; i ++)
    {
        s[i] = s[i + 1];
    }
    s[n -1] = '\0';
}

int xoaTuTrongChuoi(char s[], char word[])
{
    int s_len = strlen(s);
    int word_len = strlen(word);
    int start = Brute_Force(s, word);
    if (start == -1)
        return 0;
    
    for (int i = start; i < start + word_len; i ++)
    {
        xoaKiTu(s, start);
    }
    standardizedString(s);

    return 1;
}