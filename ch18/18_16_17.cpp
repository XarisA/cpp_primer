namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;

// position 1

// using Exercise::dvar;
// using Exercise::ivar;       // conflict
// using Exercise::limit;

// using namespace Exercise;       // ambiguous ivar

void manip() {
    // position 2

    // using Exercise::dvar;   // conflict
    using Exercise::ivar;       
    using Exercise::limit;

    //using namespace Exercise;  // ambiguous ivar

    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}

int main() {

}