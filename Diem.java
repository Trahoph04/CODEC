public class Diem {
    private int x;
    private int y;

    public Diem() {
        this.x = 0;
        this.y = 0;
    }

    public Diem(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void hienThi() {
        System.out.println("Diem(" + x + ", " + y + ")");
    }

    public static void main(String[] args) {
        Diem d1 = new Diem();
        Diem d2 = new Diem(3, 4);

        d1.hienThi();
        d2.hienThi();
    }
}
