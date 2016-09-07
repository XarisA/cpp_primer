class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    
    // char g() { return priv_mem; }        // inaccessible
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
};

struct Prot_Derv : protected Base {
    int f1() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
    // int use_base() { return prot_men; }
};

struct Derived_from_Protected : public Prot_Derv { };