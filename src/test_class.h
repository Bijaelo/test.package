
#ifndef test_h
#define test_h

#include <string>
using std::string;
class test_class{
private:
  const string s1, s2, s3, s4;
  const bool bool1, bool2;

public:
  test_class(const string&,
             const string&,
             const string&,
             const string&,
             const bool _bool1, const bool _bool2);
  SEXP getbools();
};

#endif
