class Base {
public:
    Base() = default;
    Base(const Base&);
    Base(int);
};

class D1 : public Base {
public:
    D1(int i) : Base(i) { }
};

class D2 : public Base {
public:
    D2(int i) : Base(i) { }
};

class D3 : public Base {
public:
    D3(int i) : Base(i) { }
};