#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#define Max 500
//1.  hàm in ma trận
//2. Kiểm tra xem đỉnh i có tô được màu đang xét hay không
int cotheto(int a[][Max], int Min, int n, int v[], int i, int somau)
{
    for(int j= Min; j< Min+n; j++)
        if(a[i][j]&&v[j]== somau) return 0;// nếu đỉnh i và đỉnh j kề nhau mà j
        // đã được tô màu c thì k tô được nữa
    return 1;
}
//3. dùng 1 màu tô cho tất cả các đỉnh có thể tô
// và trả về số đỉnh đã được tô
int to1mau(int a[][Max], int Min, int n, int v[], int somau)
{ // áp dụng thuật toán tham lam
    int dem = 0;// so dinh da duoc to
    for( int i= Min; i< Min+n; i++)
        if(!v[i]&& cotheto(a, Min, n, v, i, somau))
    {
        v[i]= somau;
        dem++;
    }
    return dem;
}
//4. Tô màu cho tất cả cá đỉnh của đồ thị và trả về số màu được sd
int tomau(int a[][Max], int Min, int n, int v[])
{
    for(int i= Min; i< Min+n; i++) v[i]= 0;// chưa có đỉnh nào được tô
    int somau = 0; int dem = 0;
    //chưa sử dụng màu nào, và cũng chưa có đỉnh nào được tô
    while (dem< n)
    {
        somau++;
        dem += to1mau(a, Min, n, v, somau);// tra ve số đỉnh đã được tô
    }
    return somau;
}
 int main ()
 {
     int a[Max][Max];// ma tran ke cua do thi
     int b[2][Max];     // ma tran danh sach cac canh cua do thi
     int n, m;
     int p, q;
     int t= 0;
     //1. doc ma tran ke cua do thi tu file dothi,txt
    // sau do gan vao mang a[][]

    ifstream dothi ("dothi.txt");
    if (dothi.is_open())
    {
        dothi >> n;// đọc vào số đỉnh từ đầu file
        dothi >> m;// đọc vào số cạnh từ số thứ 2
        while (!dothi.eof()) //Doc cho den cuoi file
        {
            dothi >> p;// lấy ra đỉnh đầu của cạnh
            dothi >> q;// lấy ra đỉnh thứ 2 của cùng cạnh đó
            a[p][q]=1;// lập ma trận danh sách kề
            a[q][p]=1;
            b[0][t]=p;// lập ma trận danh sách cạnh
            b[1][t]=q;
            t++;
        }
        dothi.close();
    }
    else cout << "Khong mo duoc file\n";

    // tìm đỉnh có nhãn bé nhất( chỉ để phục vụ xuất ra )
    int Min= b[0][0];
    for(int i= 0;i< 2;i++)
        for(int j= 0;j< m;j++)
    {
        if(b[i][j]<Min) Min= b[i][j];
    }
     /*in thử ra danh sách kề và danh sách cạnh để test
    for(int i=Min;i<Min+n;i++)
        {
        for(int j=Min;j<Min+n;j++)
        cout<<a[i][j]<< "  ";
        cout<< "\n";
        }
      for(int i=0;i<m;i++)
            {cout<<b[0][i]<<"  "<<b[1][i];
      cout<<"\n";
            } */

     int v[Max];
     tomau(a, Min, n, v);// kq la so mau da su dung
    /* cout << "\nso mau da su dung: "<< kq<< "\n";
     cout << "\nket qua to mau tung dinh la:\n";*/
     // in ra man hinh
    cout<< "graph dothi"<< endl<< endl;
    cout<< "{"<< endl<< endl;

     for(int i =Min; i< Min+n; i++)
     {   cout<< "     "<< i<<" [fillcolor=";
        if(v[i]==1) cout<<"red";
        if(v[i]==2) cout<<"blue";
        if(v[i]==3) cout<<"green";
        if(v[i]==4) cout<<"yellow";
        if(v[i]==5) cout<<"white";
        if(v[i]==6) cout<<"brown";
        if(v[i]==7) cout<<"grey";
        if(v[i]==8) cout<<"orange";
        if(v[i]==9) cout<<"pink";
        if(v[i]==10) cout<<"black";
        cout<< ", style=filled];"<<endl<<endl;
      }
       for(int i= 0;i< m; i++)
        {
        cout <<"     ";
        cout <<b[0][i];
        cout <<" -- ";
        cout <<b[1][i];
        cout <<";"<<endl;
        }
     cout<<endl<<"}";

     cout<< "\n";
     //cout<< kq;
     return 0;
 }

