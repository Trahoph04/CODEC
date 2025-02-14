import java.util.*;

class PhanSo {
    private int tu;
    private int mau;

    // Hàm xây dựng mặc nhiên
    public PhanSo() {
        this.tu = 0;
        this.mau = 1;
    }

    // Hàm xây dựng có tham số
    public PhanSo(int tu, int mau) {
        if (mau == 0) {
            throw new IllegalArgumentException("Mẫu số không thể bằng 0");
        }
        this.tu = tu;
        this.mau = mau;
    }

    // Hàm nhập phân số
    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập tử số: ");
        this.tu = sc.nextInt();
        do {
            System.out.print("Nhập mẫu số (khác 0): ");
            this.mau = sc.nextInt();
        } while (this.mau == 0);
    }

    // Hiển thị phân số
    public void hienThi() {
        if (tu == 0) {
            System.out.println("0");
        } else if (mau == 1) {
            System.out.println(tu);
        } else {
            System.out.println(tu + "/" + mau);
        }
    }

    // Nghịch đảo phân số (thay đổi giá trị)
    public void nghichDao() {
        if (tu == 0) {
            throw new ArithmeticException("Không thể nghịch đảo phân số có tử số bằng 0");
        }
        int temp = tu;
        tu = mau;
        mau = temp;
    }

    // Trả về phân số nghịch đảo (không thay đổi giá trị gốc)
    public PhanSo giaTriNghichDao() {
        if (tu == 0) {
            throw new ArithmeticException("Không thể nghịch đảo phân số có tử số bằng 0");
        }
        return new PhanSo(mau, tu);
    }

    // Tính giá trị thực của phân số
    public double giaTriThuc() {
        return (double) tu / mau;
    }

    // So sánh phân số lớn hơn
    public boolean lonHon(PhanSo a) {
        return this.giaTriThuc() > a.giaTriThuc();
    }

    // Cộng hai phân số
    public PhanSo cong(PhanSo a) {
        return new PhanSo(this.tu * a.mau + a.tu * this.mau, this.mau * a.mau);
    }

    // Trừ hai phân số
    public PhanSo tru(PhanSo a) {
        return new PhanSo(this.tu * a.mau - a.tu * this.mau, this.mau * a.mau);
    }

    // Nhân hai phân số
    public PhanSo nhan(PhanSo a) {
        return new PhanSo(this.tu * a.tu, this.mau * a.mau);
    }

    // Chia hai phân số
    public PhanSo chia(PhanSo a) {
        return new PhanSo(this.tu * a.mau, this.mau * a.tu);
    }
}

public class SDPhanSo {
    public static void main(String[] args) {
        PhanSo a = new PhanSo(3, 7);
        PhanSo b = new PhanSo(4, 9);
        a.hienThi();
        b.hienThi();
        
        PhanSo x = new PhanSo();
        PhanSo y = new PhanSo();
        x.nhap();
        y.nhap();
        
        System.out.print("Nghịch đảo của x: ");
        x.giaTriNghichDao().hienThi();
        
        PhanSo tong = x.cong(y);
        System.out.print("Tổng của x và y: ");
        tong.hienThi();
    }
}
