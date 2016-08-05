bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return;
    }
}

/*
6_30.cpp:1:25: error: unknown type name 'string'
bool str_subrange(const string &str1, const string &str2)
                        ^
6_30.cpp:1:45: error: unknown type name 'string'
bool str_subrange(const string &str1, const string &str2)
                                            ^
6_30.cpp:8:13: error: non-void function 'str_subrange' should return a value [-Wreturn-type]
            return;
            ^
3 errors generated.
*/