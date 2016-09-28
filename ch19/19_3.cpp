class A { };
class B : public A { };
class C : public B { };
class D : public B, public A { };

int main() {

    // OK
    //A *pa = new C;
    //B *pb = dynamic_cast<B*>(pa);

    // fail: pb doesn't point to a derived type
    // B *pb = new B;
    // C *pc = dynamic_cast<C*>(pb);

    // OK
    //A *pa = new D;
    //B *pb = dynamic_cast<B*>(pa);

    return 0;
}