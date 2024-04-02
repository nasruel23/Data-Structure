#include <iostream>
#include <string>
using namespace std;

// untuk menyimpan informasi alamat
struct Alamat {
    string jalan;
    string kota;
    string negara;
    int kodePos;
};
// untuk menyimpan informasi tanggal
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};
// untuk menyimpan biodata orang
class Orang {
    public:
    void setNama(string namaLengkap) {
        this->namaLengkap = namaLengkap;
    }
    string getNama() {
        return namaLengkap;
    }
    void setTanggal(Tanggal tanggalLahir) {
        this->tanggalLahir = tanggalLahir;
    }
    Tanggal getTanggal() {
        return tanggalLahir;
    }
    void setAlamat(Alamat alamatRumah) {
        this->alamatRumah = alamatRumah;
    }
    Alamat getAlamat() {
        return alamatRumah;
    }
    private:
    string namaLengkap;
    Tanggal tanggalLahir;
    Alamat alamatRumah;
};

int main() {
    Orang dataOrang;

    // Inisialisasi
    dataOrang.setNama("Lin Yi");
    Tanggal tanggalLahir = {11, 1, 1999};
    dataOrang.setTanggal(tanggalLahir);
    Alamat alamatRumah = {"Shenyang", "Liaoning", "China", 12345};
    dataOrang.setAlamat(alamatRumah);

    // Menampilkan biodata
    cout << "=========================" << endl;
    cout << "BIODATA DIRI" << endl;
    cout << "Nama: " << dataOrang.getNama() << endl;
    cout << "Tanggal Lahir: " << dataOrang.getTanggal().hari << "/" <<
    dataOrang.getTanggal().bulan << "/" << dataOrang.getTanggal().tahun << endl;
    cout << "Alamat: " << dataOrang.getAlamat().jalan << ", " <<
    dataOrang.getAlamat().kota << ", " << dataOrang.getAlamat().negara << ", " << dataOrang.getAlamat().kodePos << endl;

    return 0;
}