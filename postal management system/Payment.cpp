#include "Payment.h"

Payment::Payment() : bill(0), stamp5(0), stamp10(0), stamp20(0), stamp50(0), stamp100(0) {}

int Payment::calculateBill(int weight) {
    if (weight <= 0) return 0;
    if (weight == 1) return bill = 100;
    if (weight <= 3) return bill = 175;
    if (weight <= 5) return bill = 250;
    if (weight <= 10) return bill = 375;
    if (weight <= 15) return bill = 500;
    if (weight <= 20) return bill = 625;
    if (weight <= 25) return bill = 750;
    if (weight <= 30) return bill = 875;
    return bill = 0; // handle weight > 30
}

void Payment::calculateStamps(int bill) {
    int total = 0, s100 = 0, s50 = 0, s20 = 0, s10 = 0, s5 = 0;

    std::ifstream fin("Payment.txt");
    if (fin.is_open()) {
        fin >> total >> s100 >> s50 >> s20 >> s10 >> s5;
        fin.close();
    }

    total += bill;

    stamp100 = bill / 100; bill %= 100;
    stamp50 = bill / 50;  bill %= 50;
    stamp20 = bill / 20;  bill %= 20;
    stamp10 = bill / 10;  bill %= 10;
    stamp5  = bill / 5;   bill %= 5;

    s100 += stamp100;
    s50  += stamp50;
    s20  += stamp20;
    s10  += stamp10;
    s5   += stamp5;

    std::ofstream fout("Payment.txt");
    if (fout.is_open()) {
        fout << total << " " << s100 << " " << s50 << " " << s20 << " " << s10 << " " << s5 << std::endl;
        fout.close();
    }
}

Payment::~Payment() {}
