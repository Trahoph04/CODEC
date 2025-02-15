import java.util.Scanner;

class CanBo {
    private String maSo, hoTen, ngaySinh;
    private int thamNien;
    private char xepLoai;

    public CanBo() {}

    public void nhap(Scanner sc) {
        System.out.print("Mã số: ");
        this.maSo = sc.nextLine();
        System.out.print("Họ tên: ");
        this.hoTen = sc.nextLine();
        System.out.print("Ngày sinh: ");
        this.ngaySinh = sc.nextLine();
        System.out.print("Thâm niên: ");
        this.thamNien = sc.nextInt();
        System.out.print("Xếp loại (A/B/C): ");
        this.xepLoai = sc.next().charAt(0);
        sc.nextLine();
    }

    public double tinhKhenThuong() {
        if (xepLoai == 'A') {
            return thamNien * 1000000;
        } else if (xepLoai == 'B') {
            return thamNien * 500000;
        }
        return 0;
    }

    public void hienThi() {
        System.out.printf("%-10s %-20s %-12s %3d năm %2c %10.2f VND\n", 
                          maSo, hoTen, ngaySinh, thamNien, xepLoai, tinhKhenThuong());
    }

    public boolean duocKhenThuong() {
        return xepLoai == 'A' || xepLoai == 'B';
    }
}

class DanhSachCanBo {
    private CanBo[] danhSach;
    private int soLuong;

    public DanhSachCanBo(int n) {
        danhSach = new CanBo[n];
        soLuong = n;
    }

    public void nhapDanhSach(Scanner sc) {
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhập thông tin cán bộ thứ " + (i + 1) + ":");
            danhSach[i] = new CanBo();
            danhSach[i].nhap(sc);
        }
    }

    public void hienThiDanhSachKhenThuong() {
        System.out.println("\nDanh sách cán bộ được khen thưởng:");
        double tongTien = 0;
        for (CanBo cb : danhSach) {
            if (cb.duocKhenThuong()) {
                cb.hienThi();
                tongTien += cb.tinhKhenThuong();
            }
        }
        System.out.printf("\nTổng số tiền khen thưởng: %.2f VND\n", tongTien);
    }
}

public class KhenThuongCanBo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập số lượng cán bộ: ");
        int n = sc.nextInt();
        sc.nextLine();

        DanhSachCanBo danhSachCanBo = new DanhSachCanBo(n);
        danhSachCanBo.nhapDanhSach(sc);
        danhSachCanBo.hienThiDanhSachKhenThuong();
    }
}

