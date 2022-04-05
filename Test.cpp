#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <algorithm>
#include <stdbool.h>
using namespace std;
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
using namespace std;
namespace zich {
    vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> arr = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    vector<double> arr0 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> arr1 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    vector<double> arr2 = {1,2,3,4,1,2,3,4,1,2,3,4};    //6x2
    vector<double> arr3 = {13, 0, 0,0, 3, 0,0, 0, 3,3,5,3}; //4x3
    vector<double> arr4 = {1,2,3,4,1,2,3,4,1,2};//2x5
    vector<double> arrC = {2, 2, 3, 1, 3, 3, 1, 2, 4};
    vector<double> arrd = {3, 4, 6, 2, 5, 6, 2, 4, 7};
    vector<double> arrF = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    vector<double> arr8 = {54, 1, 14, 14, 2, 14, 1, 17, 2};


    TEST_CASE("Good input") {
        SUBCASE("+"){
            Matrix a{identity, 3, 3}; //{1, 0, 0, 0, 1, 0, 0, 0, 1};
            Matrix b{arr1, 3, 3};     //{1, 2, 3, 1, 2, 3, 1, 2, 3};
            Matrix c{arrC, 3, 3};     //{2, 2, 3, 1, 3, 3, 1, 2, 4};
            Matrix d{arrd, 3, 3};     //{3, 4, 6, 2, 5, 6, 2, 4, 7};
            CHECK(((b+a)==c)==true);
            CHECK(((b+c)==d)==true);
        }
        SUBCASE("+="){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix c{arrC, 3, 3};
            Matrix d{arrd, 3, 3};
            CHECK(((b+=a)==c)==true);
            CHECK(((b+=c)==d)==true);
        }
        SUBCASE("+U"){
            Matrix a1{arr, 3, 3};
            Matrix A{identity, 3, 3};
            CHECK(((+a1)==a1)== true);
            CHECK(((+A)==A)==true);
        }
        SUBCASE("-="){
            Matrix a{identity, 3, 3}; //{1, 0, 0, 0, 1, 0, 0, 0, 1};
            Matrix b{arr1, 3, 3};     //{1, 2, 3, 1, 2, 3, 1, 2, 3};
            Matrix c{arrC, 3, 3};     //{2, 2, 3, 1, 3, 3, 1, 2, 4};
            Matrix d{arrd, 3, 3};     //{3, 4, 6, 2, 5, 6, 2, 4, 7};
            CHECK(((c-=b)==a)==true);
            CHECK(((d-=b)==c)==true);
        }
        SUBCASE("-"){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix c{arrC, 3, 3};
            Matrix d{arrd, 3, 3};
            CHECK(((c-b)==a)==true);
            CHECK(((d-b)==c)==true);
        }
        SUBCASE("-U"){
            Matrix a1{arr, 3, 3};
            Matrix A{identity, 3, 3};
            CHECK(((-a1)==(-1*a1))==true);
            CHECK(((-A)==(-1*A))== true);
        }
        SUBCASE("<"){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix r{arr8, 3, 3};
            CHECK(true==(a<b));
            CHECK(true==(a<r));
            CHECK(true==(b<r));
        }
        SUBCASE("<="){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix r{arr8, 3, 3};
            CHECK(true==(a<=b));
            CHECK(true==(a<r));
            CHECK(true==(b<r));
        }
        SUBCASE(">"){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix r{arr8, 3, 3};
            CHECK(true==(b>a));
            CHECK(true==(r>b));
            CHECK(true==(r>b));
        }
        SUBCASE(">="){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix r{arr8, 3, 3};
            CHECK(true==(b>=a));
            CHECK(true==(r>b));
            CHECK(true==(r>b));
        }

        SUBCASE("=="){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix c{arrC, 3, 3};
            Matrix d{arrd, 3, 3};
            Matrix A{identity, 3, 3};
            CHECK(false==(a==b));
            CHECK(false==(c==d));
            CHECK(true==(A==A));
        }
        SUBCASE("!="){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            Matrix c{arrC, 3, 3};
            Matrix d{arrd, 3, 3};
            CHECK(true==(a!=b));
            CHECK(true==(c!=d));
        }
        SUBCASE("*a"){
            Matrix a0{arr0, 3, 3};
            Matrix a1{arr, 3, 3};
            Matrix a{identity, 3, 3};
            CHECK(((2*a)==a1)==true);
            CHECK(((3*a)==a0)==true);
        }
        SUBCASE("*= -3"){
            Matrix a0{arr0, 3, 3};
            Matrix a1{arr, 3, 3};
            Matrix a{identity, 3, 3};
            CHECK(((a*=2)==a1)==true);
            CHECK(((a*=2)==a0)==true);
        }
        SUBCASE("m*m"){
            Matrix a0{arr0, 3, 3};
            Matrix a{identity, 3, 3};
            Matrix f{arrF, 3, 3};
            CHECK(((a0*a)==a0)==true);
            CHECK(((f*a)==f)==true);
        }


        SUBCASE("a++"){
            Matrix a0{arr0, 3, 3};
            Matrix a1{arr, 3, 3};
            Matrix a{identity, 3, 3};
            Matrix f{arrF, 3, 3};
            CHECK(((a++)==f)==true);
            CHECK(((a1++)==a0)==true);

        }
        SUBCASE("++a"){
            Matrix a{identity, 3, 3};
            Matrix f{arrF, 3, 3};
            CHECK(((++a)==a)==true);
            CHECK(((++f)==f)==true);

        }
        SUBCASE("--a"){
            Matrix a{identity, 3, 3};
            Matrix f{arrF, 3, 3};
            CHECK(((--a)==a)==true);
            CHECK(((--f)==f)==true);
        }
        SUBCASE("a--"){
            Matrix a{identity, 3, 3};
            Matrix f{arrF, 3, 3};
            CHECK(((f--)==a)==true);
        }

        SUBCASE("<<"){
            Matrix a{identity, 3, 3};
            Matrix b{arr1, 3, 3};
            CHECK_NOTHROW(cout<<a);
            CHECK_NOTHROW(cout<<b);
        }
        SUBCASE(">>"){
            Matrix a;
            Matrix b;
            CHECK_NOTHROW(cin>>a);
            CHECK_NOTHROW(cin>>b);
        }

}

TEST_CASE("Bad input") {
        SUBCASE("bad value"){
            CHECK_THROWS(Matrix (arr2, 20, 5));
            CHECK_THROWS( (Matrix (arr3, 4, 30)));
            CHECK_THROWS(  Matrix (arr3, 13, 3));
        }

       SUBCASE("m*m"){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            CHECK_THROWS((a*b));
            CHECK_THROWS((b*c));
            CHECK_THROWS((a*c));
        }
        SUBCASE("+"){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            CHECK_THROWS((a+b));
            CHECK_THROWS((b+c));
            CHECK_THROWS((a+c));
        }

        SUBCASE("-"){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            CHECK_THROWS((a-b));
            CHECK_THROWS((b-c));
            CHECK_THROWS((a-c));
        }
        SUBCASE("=="){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            Matrix d{arrd, 3, 3};
            bool boo;
            CHECK_THROWS(boo=a==b);
            CHECK_THROWS(boo=c==b);
            CHECK_THROWS(boo=d==b);
        }
        SUBCASE("<="){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            Matrix d{arrd, 3, 3};
            bool boo;
            CHECK_THROWS(boo=a<=b);
            CHECK_THROWS(boo=c<=b);
            CHECK_THROWS(boo=d<=b);
        }
        SUBCASE(">="){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            Matrix d{arrd, 3, 3};
            bool boo;
            CHECK_THROWS(boo=a>=b);
            CHECK_THROWS(boo=c>=b);
            CHECK_THROWS(boo=d>=b);
        }
        SUBCASE("<"){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            Matrix d{arrd, 3, 3};
            bool boo;
            CHECK_THROWS(boo=a<b);
            CHECK_THROWS(boo=c<b);
            CHECK_THROWS(boo=d<b);
        }
        SUBCASE(">"){
            Matrix a{identity, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix c{arr3, 4, 3};
            Matrix d{arrd, 3, 3};
            bool boo;
            CHECK_THROWS(boo=a>b);
            CHECK_THROWS(boo=c>b);
            CHECK_THROWS(boo=d>b);
        }
        SUBCASE("!="){
            Matrix a{arr3, 3, 3};
            Matrix a1{arr3, 3, 3};
            Matrix b{arr2, 6, 2};
            Matrix b2{arr2, 6, 2};
            bool boo;
            CHECK_THROWS(boo=b2!=b);
            CHECK_THROWS(boo=a1!=a);
        }
}
}