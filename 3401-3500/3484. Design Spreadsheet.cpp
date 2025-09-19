int buffer[26000];

class Spreadsheet {
    int getNumber(const string &cell, int &p) {
        int num = 0;
        while (cell[p] >= '0' && cell[p] <= '9') num = num * 10 + cell[p++] - '0';
        return num;
    }

    int &getCell(const string &cell, int &p) {
        int col = cell[p++] - 'A', row = getNumber(cell, p)-1;
        return buffer[row*26 + col];
    }

    int getCellOrConst(const string &cell, int &p) {
        if (cell[p] >= '0' && cell[p] <= '9') return getNumber(cell, p);
        return getCell(cell, p);
    }

public:
    Spreadsheet(int rows) {
        memset(buffer, 0, rows*26*sizeof *buffer);
    }
    
    void setCell(const string &cell, int value) {
        int p = 0;
        getCell(cell, p) = value;
    }
    
    void resetCell(const string &cell) {
        setCell(cell, 0);
    }
    
    int getValue(const string &formula) {
        int pos = 0;
        if (formula[pos++] != '=') cout << "Should start by '=' : " << formula << endl;
        int a = getCellOrConst(formula, pos);
        if (formula[pos++] != '+') cout << "Should split by '+' : " << formula << endl;
        int b = getCellOrConst(formula, pos);
        return a+b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
