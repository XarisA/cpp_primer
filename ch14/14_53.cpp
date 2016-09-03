class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);
    operator int() const { return val; }
private:
    int val;
};

int main() {
    SmallInt s1;
    double d = s1 + SmallInt(3.14);         // this code can compile, but generates a warning
}