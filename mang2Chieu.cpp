#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<iostream>
#include<map>

using namespace std;

#define MAXCOL 100
#define MAXROW 100

struct Pair
{
    int key;
    int value;
};


void nhapMang(int a[][MAXCOL], int &m, int &n);
void xuatMang(int a[][MAXCOL], int m, int n);
int layChuSoDau(int a);
int tong_ptu_ChuSoDau_le(int a[][MAXCOL], int m, int n);
bool ktra_SoHoanThien(int a);
int lietKe_SoHoanThien(int a[][MAXCOL], int m, int n);
int tongBien(int a[][MAXCOL], int m, int n);


int tongCotk(int a[][MAXCOL], int m, int n, int k);
int timMin(int a[], int n);
void lietKe_cotTongMin(int a[][MAXCOL], int m, int n);

bool ktra_SHT(int a);
int timMax(int a[], int n);
int dem_SHT_dongk(int a[][MAXCOL], int m, int n, int k);
void lietKe_Dong_soSHT_Max(int a[][MAXCOL], int m, int n);

void giaTriApear_max(int a[][MAXCOL], int m, int n);

int indexOf(Pair PairArray[], int PairArray_len, int key);
int findMax_PairArray(Pair PairArray[], int PairArray_len);
void valueAppearMax (int a[][MAXCOL], int m, int n);

int main()
{
    int a[MAXROW][MAXCOL];
    int m, n;
    nhapMang(a, m, n);
    xuatMang(a, m, n);
    // printf("\nTong cac phan tu co chu so dau le: %d", tong_ptu_ChuSoDau_le(a, m, n));

    // printf("\nCac phan tu la so hoan thien trong mang:");
    // lietKe_SoHoanThien(a, m, n);

    // printf("\nTong cac phan tu o bien cua ma tran: %d", tongBien(a, m, n));

    // lietKe_cotTongMin(a, m, n);

    // lietKe_Dong_soSHT_Max(a, m, n);

    // giaTriApear_max(a, m, n);

    valueAppearMax(a, m, n);
}

// Nhập mảng 2 chiều
void nhapMang(int a[][MAXCOL], int &m, int &n)
{
    printf("\nNhap vao so dong cua mang: ");
    scanf_s("%d", &m);
    printf("\nNhap vao so cot cua mang: ");
    scanf_s("%d", &n);

    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            printf("\na[%d][%d] = ", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }
}

// Xuất mảng
void xuatMang(int a[][MAXCOL], int m, int n)
{
    printf("\nMang 2 chieu co gia tri: \n");

    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

// Tổng các phần tử có chữ số đầu lẻ
int layChuSoDau(int a)
{
    while (a > 10)
        a /= 10;
    return a;
}

int tong_ptu_ChuSoDau_le(int a[][MAXCOL], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (layChuSoDau(a[i][j]) % 2 != 0)
                sum += a[i][j];
        }
    }
    return sum;
}

// Liệt kê phần tử hoàn thiện trong mảng
bool ktra_SoHoanThien(int a)
{
    int sum = 0;
    for (int i = 1; i < a; i ++)
    {
        if (a % i == 0)
            sum += i;
    }
    if (sum == a)
        return true;
    return false;
}

int lietKe_SoHoanThien(int a[][MAXCOL], int m, int n)
{
    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (ktra_SoHoanThien(a[i][j]) == true)
                printf("%4d", a[i][j]);
        }
    }
}

// Tổng các giá trị nằm ở biên ma trận
int tongBien(int a[][MAXCOL], int m, int n)
{
    int sum = 0;
    for (int j = 0; j < n; j ++)
    {
        sum += a[0][j];
        sum += a[m - 1][j];
    }

    for (int i = 1; i < m - 1; i ++)
    {
        sum += a[i][0];
        sum += a[i][n - 1];
    }

    return sum;
}

// Liệt kê cột có tổng nhỏ nhất
int tongCotk(int a[][MAXCOL], int m, int n, int k)
{
    int sum = 0;
    for(int i = 0; i < m; i ++)
    {
        sum += a[i][k];
    }

    return sum;
}

int timMin(int a[], int n) // Trả về vị trí
{
    int min = 0;
    for (int i = 1; i < n; i ++)
    {
        if (a[min] > a[i])
            min = i;
    }

    return min;
}

void lietKe_cotTongMin(int a[][MAXCOL], int m, int n)
{
    int tong[MAXCOL];
    for (int j = 0; j < n; j ++)
    {
        tong[j] = tongCotk(a, m, n, j);
    }

    int viTri_CotMin = timMin(tong, n);
    printf("\nCac cot co gia tri %d la cot nho nhat: %d", tong[viTri_CotMin], viTri_CotMin);

    for (int iTong = (viTri_CotMin + 1); iTong < n; iTong ++)
    {
        if (tong[iTong] == tong[viTri_CotMin])
            printf(", %d", iTong);
    }
}

// Liệt kê dòng có nhiều số hoàn thiện nhất
bool ktra_SHT(int a)
{
    int sum = 0;
    for (int i = 1; i < a; i ++)
    {
        if (a % i == 0)
        sum += i;
    }

    if (sum == a)
        return true;
    return false;
}

int timMax(int a[], int n) // Trả về vị trí
{
    int max = 0;
    for (int i = 1; i < n; i ++)
    {
        if (a[max] < a[i])
            max = i;
    }

    return max;
}

int dem_SHT_dongk(int a[][MAXCOL], int m, int n, int k)
{
    int dem = 0;
    int check = false;
    for (int i = 0; i < n; i++)
    {
        if (ktra_SHT(a[k][i]) == true)
        {
            check = true;
            dem ++;
        }
    }

    if (check == true)
        return dem;
    return -1;
}

void lietKe_Dong_soSHT_Max(int a[][MAXCOL], int m, int n)
{
    int soSHT[MAXROW];
    bool check = false;
    for (int i = 0; i < m; i ++)
    {
        soSHT[i] = dem_SHT_dongk(a, m, n, i);
        if (soSHT[i] > 0)
        {
            check = true;
        }
    }

    if (check == false)
    {
        printf("\nKhong ton tai so hoan thien trong mang 2 chieu");
        return;
    }

    int viTri_dong_soSHT_Max = timMax(soSHT, n);
    printf("\nCac dong co so luong so hoan thien max: %d", viTri_dong_soSHT_Max);
    for (int i = viTri_dong_soSHT_Max + 1; i < m; i ++)
    {
        if (soSHT[i] == soSHT[viTri_dong_soSHT_Max])
            printf(", %d", i);
    }
}

// Tìm giá trị xuất hiện nhiều nhất trong mảng (nếu có nhiều giá trị cũng xuất hiện nhiều nhất thì in ra hết)
// Ý tưởng: 
//  + sử dụng struct tạo cấu trúc để lưu giá trị và tần suất (key và value)
//  + sử dụng thư viện có sẵn: map
// Note: khi đưa ra giải thuật nên tách biệt nó với ngôn ngữ. Có nghĩa với giải thuật này thì áp dụng cho bất kì ngôn nào cũng có thể hỗ trợ

// C1: sử dụng thư viện map: tái sử dụng hàm timMax ở trên
void giaTriApear_max(int a[][MAXCOL], int m, int n)
{
    map<int, int> myMap;
    // Đổ các giá trị từ ma trận vào myMap
    for(int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (myMap.find(a[i][j]) == myMap.end())
                myMap[a[i][j]] = 1;
            else
                myMap[a[i][j]] ++;
        }
    }

    map<int, int>::iterator appearMax = myMap.begin();
    for (const auto &pair: myMap)
    {
        if (pair.second > appearMax->second)
            appearMax = myMap.find(pair.first);
    }

    for (map<int, int>::iterator i = appearMax; i != myMap.end(); i ++)
    {
        if (i->second == appearMax->second)
            printf("\nGia tri %d xuat hien nhieu nhat voi %d lan", i->first, i->second);
    }
}

// C2: tạo struct với key, value

int indexOf(Pair PairArray[], int PairArray_len, int key) //Hàm trả về vị trí của phần tử key truyền vào
{
    for (int i = 0; i < PairArray_len; i++)
    {
        if (PairArray[i].key == key)
            return i;
    }

    return -1;
}

int findMax_PairArray(Pair PairArray[], int PairArray_len)
{
    int max = 0;
    for (int i = 1; i < PairArray_len; i ++)
    {
        if (PairArray[max].value < PairArray[i].value)
            max = i;
    }

    return max;
}


void valueAppearMax (int a[][MAXCOL], int m, int n)
{
    Pair PairArray[MAXCOL*MAXROW] = {0}; //Tạo mảng để lưu giá trị vào tần suất xuất hiện
    int PairArray_len = 0;

    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            int index = indexOf(PairArray, PairArray_len, a[i][j]);
            if (index == -1)
            {
                PairArray[PairArray_len].key = a[i][j];
                PairArray[PairArray_len].value ++;
                PairArray_len++;
            }
            else
                PairArray[index].value ++;
        }
    }

    int indexAppearMax = findMax_PairArray(PairArray, PairArray_len);
    printf("\nCac gia tri xuat hien nhieu nhat trong mang: ");
    for (int i = indexAppearMax; i < PairArray_len; i ++)
    {
        if (PairArray[i].value == PairArray[indexAppearMax].value)
            printf("\nGia tri %d voi %d lan xuat hien", PairArray[i].key, PairArray[i].value);
    }


}


